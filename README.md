# Environment for building NuttX on ArchLinux

Install the following packages using pacman:

    base-devel
    gmp
    libmpc
    mpfr
    gperf
    gdb

Install ncurses:\
https://aur.archlinux.org/packages/ncurses5-compat-libs/

Install kconfig-frontends:\
https://aur.archlinux.org/packages/kconfig-frontends/

Build arm-none-eabi toolchain from sources.\
You can use this script as a guide:\
https://gist.github.com/CFD2/75cae9c7c00bc7ea0cf77ef32d74b30e
(@TODO: find a better place to store this gist)


# INSTALLATION

## Downloading from Repositories

### Cloning the Repository

**NuttX needs to reside in a path that contains no spaces.**

Create a directory ***nuttxspace*** and navigate to it.

Here are instructions for cloning the core NuttX RTOS and semi-optional apps):

    git clone https://github.com/ccxtechnologies/nuttx.git nuttx
    git clone https://github.com/apache/incubator-nuttx-apps.git apps

This will result in the following directory structure:
+ nuttxspace/
    - nuttx/
    - apps/


# CONFIGURING NUTTX

Navigate to nuttxspace/nuttx/\
Execute:

    ./tools/configure.sh -l ccx:nsh

  *-l* is for Linux environment

  *ccx* is the board-name directory located under\
  `{TOPDIR}/boards/<arch-name>/<chip-name>/<board-name>/`

  *nsh* is the config-name directory under\
  `{TOPDIR}/boards/<arch-name>/<chip-name>/<board-name>/configs/<config-name>/`


Now we need to change some settings in menuconfig.
Execute:

    make menuconfig

Inside menuconfig navigate to:

    Build Setup -> Binary Output Formats ->
      Select "Raw Binary format" and press "y" to enable this setting.

    System Type ->
      Select "Use DTCM" and press "y" to enable this setting.

    Board Selection ->
      Select "Board LED Status Support" and press "n" to disable this
      setting.

Press ESC-ESC to exit from menuconfig. You will be prompted to save
changes.



# BUILDING NUTTX

## Building

NuttX builds in-place in the source tree.  You do not need to create
any special build directories.  Assuming that your Make.defs is setup
properly for your tool chain and that PATH environment variable contains
the path to where your cross-development tools are installed, the
following steps are all that are required to build NuttX:

    cd {TOPDIR}
    make

## Build Targets and Options

### Build Targets

Below is a summary of the build targets available in the top-level
NuttX Makefile:

  * `all`

    The default target builds the NuttX executable in the selected output
    formats.

  * `clean`

    Removes derived object files, archives, executables, and temporary
    files, but retains the configuration and context files and directories.

  * `distclean`

    Does 'clean' then also removes all configuration and context files.
    This essentially restores the directory structure to its original,
    unconfigured stated.

Application housekeeping targets.  The APPDIR variable refers to the user
application directory.  A sample `apps/` directory is included with NuttX,
however, this is not treated as part of NuttX and may be replaced with a
different application directory.  For the most part, the application
directory is treated like any other build directory in the `Makefile` script.
However, as a convenience, the following targets are included to support
housekeeping functions in the user application directory from the NuttX
build directory.

  * `apps_clean`

    Perform the clean operation only in the user application directory

  * `apps_distclean`

    Perform the distclean operation only in the user application directory.
    The apps/.config file is preserved so that this is not a "full" distclean
    but more of a configuration "reset" for the application directory.

  * `export`

    The export target will package the NuttX libraries and header files into
    an exportable package.  Caveats: (1) These needs some extension for the KERNEL
    build. (2) The logic in tools/mkexport.sh only supports GCC and, for example,
    explicitly assumes that the archiver is 'ar'

  * `download`

    This is a helper target that will rebuild NuttX and download it to the target
    system in one step.  The operation of this target depends completely upon
    implementation of the DOWNLOAD command in the user Make.defs file.  It will
    generate an error an error if the DOWNLOAD command is not defined.

The following targets are used internally by the make logic but can be invoked
from the command under certain conditions if necessary.

  * `depend`

    Create build dependencies. (NOTE:  There is currently no support for build
    dependencies under Cygwin using Windows-native toolchains.)

  * `context`

    The context target is invoked on each target build to assure that NuttX is
    properly configured.  The basic configuration steps include creation of the
    the `config.h` and `version.h` header files in the `include/nuttx` directory and
    the establishment of symbolic links to configured directories.

  * `clean_context`

    This is part of the `distclean` target.  It removes all of the header files
    and symbolic links created by the context target.

### Build Options

Of course, the value any make variable an be overridden from the make command
line.  However, there is one particular variable assignment option that may
be useful to you:

  * `V=1`

    This is the build "verbosity flag."  If you specify `V=1` on the make command
    line, you will see the exact commands used in the build. This can be very
    useful when adding new boards or tracking down compile time errors and
    warnings (Contributed by Richard Cochran).

# Running NuttX

## Flashing the image onto SD Card

Once NuttX is built, the image file nuttx.bin is placed in `{TOPDIR}`.

Please keep in mind that both ***ccx*** and ***imrt1064-evk*** board configs can only generate
the bootable image intended to be run from the SDCard (and then copied to DTCM).

Use dd to copy the image to the microSD Card.

Erase the first 4K (replace "yourblockdevice" with the proper block device name
for the SDCard):

    dd if=/dev/zero of=/dev/yourblockdevice count=4 bs=1K

Navigate to `{TOPDIR}`

Flash nuttx.bin onto the SDCard (replace "yourblockdevice" with the proper block
device name for the SDCard):

    dd if=nuttx.bin of=/dev/yourblockdevice seek=1 bs=1K
