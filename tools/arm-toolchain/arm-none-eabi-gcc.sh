#! /usr/bin/env bash
# Fork of https://gist.github.com/cjmeyer/4251208
# @TODO: check for dependencies
# @TODO: impelement scenario for separate installation of binutils instead of installing everything from scratch.
#Dependencies (Ubuntu):
#build-essential
#libgmp-dev
#libmpfr-dev
#libmpc-dev
#texinfo
#libncurses5-dev
#termcap
#
#Dependencies (ArchLinux):
#base-devel package group
#ncurses5-compat-libs (AUR)
#termcap (AUR)
#gmp
#libmpc
#mpfr

# Target and build configuration.
TARGET=arm-none-eabi
PREFIX=/opt/arm-none-eabi-10.2.0

# Sources to build from.
BINUTILS=binutils-2.35.1
GCC=gcc-10.2.0
NEWLIB=newlib-4.1.0
GDB=gdb-10.1

# Grab the souce files...but only if they don't already exist.
if [ ! -e ${BINUTILS}.tar.xz ]; then
    echo "Grabbing ${BINUTILS}.tar.xz"
    curl ftp://ftp.gnu.org/gnu/binutils/${BINUTILS}.tar.xz -o ${BINUTILS}.tar.xz
fi
if [ ! -e ${GCC}.tar.xz ]; then
    echo "Grabbing ${GCC}.tar.xz"
    curl ftp://ftp.gnu.org/gnu/gcc/${GCC}/${GCC}.tar.xz -o ${GCC}.tar.xz
fi
if [ ! -e ${NEWLIB}.tar.gz ]; then
    echo "Grabbing ${NEWLIB}.tar.gz"
    curl ftp://sourceware.org/pub/newlib/${NEWLIB}.tar.gz -o ${NEWLIB}.tar.gz
fi
if [ ! -e ${GDB}.tar.xz ]; then
    echo "Grabbing ${GDB}.tar.xz"
    curl ftp://ftp.gnu.org/gnu/gdb/${GDB}.tar.xz -o ${GDB}.tar.xz
fi

# Extract the sources.
echo -n "extracting binutils... "
tar -Jxf ${BINUTILS}.tar.xz
echo "done"
echo -n "extracting gcc... "
tar -Jxf ${GCC}.tar.xz
echo "done"
echo -n "extracting newlib... "
tar -zxf ${NEWLIB}.tar.gz
echo "done"
echo -n "extracting gdb... "
tar -Jxf ${GDB}.tar.xz
echo "done"

# Build a set of compatible Binutils for this architecture.  Need this before
# we can build GCC.
mkdir binutils-build
cd binutils-build
../${BINUTILS}/configure --target=${TARGET} --prefix=${PREFIX} --disable-nls \
    --enable-interwork --enable-multilib --disable-werror
make all install 2>&1 | tee ../make.log
cd ..

# Add the new Binutils to the path for use in building GCC and Newlib.
export PATH=$PATH:${PREFIX}:${PREFIX}/bin

# Build and configure GCC with the Newlib C runtime. Note that the 'with-gmp',
# 'with-mpfr' and 'with-libconv-prefix' are needed only for Mac OS X using the
# MacPorts system.
cd ${GCC}
# The following symbolic links are only needed if building Newlib as well.
ln -s ../${NEWLIB}/newlib .
ln -s ../${NEWLIB}/libgloss .
mkdir ../gcc-build
cd ../gcc-build
../${GCC}/configure --target=${TARGET} --prefix=${PREFIX} \
    --with-newlib --with-gnu-as --with-gnu-ld --disable-nls --disable-libssp \
    --disable-gomp --disable-libstcxx-pch --enable-threads --disable-shared \
    --disable-libmudflap --enable-interwork --enable-languages=c,c++
make all install 2>&1 | tee -a ../make.log
# Use the following instead if only building and installing GCC (i.e. without Newlib).
#make all-gcc install-gcc 2>&1 | tee -a ../make.log
cd ..

# Build GDB.
mkdir gdb-build
cd gdb-build
../${GDB}/configure --target=${TARGET} --prefix=${PREFIX} \
    --disable-interwork --enable-multilib --disable-werror
make all install 2>&1 | tee -a ../make.log
cd ..

# We are done, let the user know were the new compiler and tools are.
echo ""
echo "Cross GCC for ${TARGET} installed to ${PREFIX}"
echo ""
