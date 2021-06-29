# NuttX Build Instructions

## Prerequisites

Install the following packages:

    pacman -S base-devel
    pacman -S gmp
    pacman -S libmpc
    pacman -S mpfr
    pacman -S gperf
    pacman -S gdb
    yay -S ncurses5-compat-libs
    yay -S kconfig-frontends

Build arm-none-eabi toolchain from sources.\
You can use this script as a guide:\
https://github.com/ccxtechnologies/nuttx/blob/master/tools/arm-toolchain/arm-none-eabi-gcc.sh

NOTE: You may want to change the installation location by changing the PREFIX variable in this script.
The default location is /opt which will most lilely require root permissions.

    wget https://raw.githubusercontent.com/ccxtechnologies/nuttx/master/tools/arm-toolchain/arm-none-eabi-gcc.sh
    chmod +x arm-none-eabi-gcc.sh
    ./arm-none-eabi-gcc.sh
    
This script creates multiple directories when building the toolchain, to remove them:

    rm -fr binutils-2.35.1.tar.xz binutils-2.35.1 binutils-build gcc-10.2.0 gcc-10.2.0.tar.xz gcc-build gdb-10.1 gdb-10.1.tar.xz gdb-build make.log newlib-4.1.0 newlib-4.1.0.tar.gz

## Clone the Repository

Clone the core NuttX RTOS and apps:

    mkdir nuttxspace
    cd nuttxspace/
    git clone https://github.com/ccxtechnologies/nuttx.git nuttx
    git clone https://github.com/ccxtechnologies/nuttx-apps.git apps

## Configuring NuttX

Execute:

    cd nuttx/
    ./tools/configure.sh -l ccx:netnsh
    make olddefconfig

## Building Nuttx
To start the building process simply type:

    make

## Flashing the image onto SD Card

Use micro SD to SD adapter to insert your micro SD Card into built-in SD Card Reader.
Execute:

    lsblk

If `mmcblk0` is listed, then your microSD Card is being detected and you can proceed.
Copy the built image to microSD Card:

    dd if=/dev/zero of=/dev/mmcblk0 count=4 bs=1K
    dd if=nuttx.bin of=/dev/mmcblk0 seek=1 bs=1K
