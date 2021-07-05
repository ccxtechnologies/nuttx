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

To configure NuttX for booting off the microSD Card, type:

    cd nuttx/
    ./tools/configure.sh -l ccx:default
    make olddefconfig

To configure NuttX for booting off the SIP Flash XiP, type:

    cd nuttx/
    ./tools/configure.sh -l ccx:defaultflash
    make olddefconfig

NOTE: Hardware modifications are needed for booting off SIP Flash.

## Building Nuttx
To start the building process simply type:

    make

## Flashing the image onto SD Card

Use micro SD to SD adapter to insert your micro SD Card into built-in SD Card Reader.
Execute:

    lsblk

If `mmcblk0` is listed, then your microSD Card is being detected and you can proceed.
Copy the built binary image to microSD Card:

    dd if=/dev/zero of=/dev/mmcblk0 count=4 bs=1K
    dd if=nuttx.bin of=/dev/mmcblk0 seek=1 bs=1K

## Flashing the image onto SIP Flash

Use [NXP MCUXpresso Secure Provisioning Tool](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-secure-provisioning-tool:MCUXPRESSO-SECURE-PROVISIONING) to load NuttX .elf image onto the SIP Flash.

Turn on the board in serial download boot configuration mode.

Make the following selections in the top menu of the application GUI:
 - Processor: MIMXRT1064
 - Boot type: Unsigned
 - Boot device: flex-spi-nor/W25Q32JV
 - Connection: UART.
 
 In the connection menu, select applicable COM port and baud rate (115200).

Locate the built NuttX ELF image "nuttx" located under nuttxspace/nuttx/. Add file extension ".elf" to it.

Select Build Image tab of MCUXpresso Secure Provisioning Tool. Under "Source Executable File" select nuttx.elf from the file browser and press "Build Image" button.

Once built, proceed to Write Image tab, select "Use built image option" and ensure that the nuttx_nopadding.bin appears in "Image Path" field. Press "Write Image" button and wait for successful completion. Change the boot configuration for booting off the SIP Flash.
