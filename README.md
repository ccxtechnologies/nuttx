# NuttX Build Instructions

## Prerequisites

Install the following packages:

Apache NuttX (Incubating) is a real-time operating system (RTOS) with an
emphasis on standards compliance and small footprint.  Scalable from 8-bit
to 32-bit microcontroller environments, the primary governing standards in
NuttX are POSIX and ANSI standards. Additional standard APIs from Unix and
other common RTOSs (such as VxWorks) are adopted for functionality not
available under these standards, or for functionality that is not
appropriate for deeply-embedded environments (such as fork()).

Extensive documentation can be found on the project wiki:
  <https://cwiki.apache.org/NUTTX/NuttX>

## Incubation Status

Apache NuttX (Incubating) is an effort undergoing Incubation at The Apache
Software Foundation (ASF), sponsored by the Incubator.  For more on our
incubation effort, please see the file DISCLAIMER-WIP, in the same
directory as this README.

For brevity, the rest of this file will refer to it as Apache NuttX or
simply NuttX.

# COMMUNITY

Every volunteer project obtains its strength from the people involved in
it.  We invite you to participate as much or as little as you choose.

We encourage you to:

  - Use our project and provide feedback.
  - Provide us with use-cases.
  - Report bugs and submit patches.
  - Contribute code or documentation.

## Getting Help

The best place to get help is the developer's mailing list.  Please see
the following section:

## Mailing Lists

Get help using NuttX or contribute to the project on our mailing lists:

  * <dev@nuttx.apache.org> is for people who want to contribute code to NuttX.
    * To subscribe, send an email to <dev-subscribe@nuttx.apache.org>.
    * To unsubscribe, send an email to <dev-unsubscribe@nuttx.apache.org>.
    * View the archives at:
      <https://www.mail-archive.com/dev@nuttx.apache.org/>

  * <commits@nuttx.apache.org> is a read-only list that notifies subscribers
  about commit messages and patches to NuttX.
    * To subscribe, send an email to <commits-subscribe@nuttx.apache.org>.
    * To unsubscribe, send an email to <commits-unsubscribe@nuttx.apache.org>.
    * View the archives at:
      <https://www.mail-archive.com/commits@nuttx.apache.org/>

## Reporting Security Issues

Found a vulnerability? See our security policy [here](.github/SECURITY.md).

## Issue Tracker

### Bug Reports:

Found bug? Send an email to the dev list: <dev@nuttx.apache.org>

Before submitting an issue, please:

  - Verify that the bug does in fact exist.

  - Search the mailing list archives to verify there is no existing issue
    reporting the bug you've found.

  - Consider tracking down the bug yourself in the NuttX source code and
    submitting a patch along with your bug report.  This is a great time
    saver for the NuttX developers and helps ensure the bug will be fixed
    quickly.

### Feature Requests:

Enhancement requests for new features are also welcome. The more concrete
and rational the request is, the greater the chance it will incorporated
into future releases.

## Source Code

The project sources are in two Git repositories.  The core OS is in
incubator-nuttx and the apps repository is in incubator-nuttx-apps.  These
are housed in GitBox on ASF servers and also mirrored at GitHub.  These
are kept in sync, so you can use whichever option you prefer.

  - NuttX core OS repository:

    - Primary:
      <https://gitbox.apache.org/repos/asf?p=incubator-nuttx.git>

    - GitHub Mirror:
      <https://github.com/apache/incubator-nuttx>

  - Apps repository:

    - Primary:
      <https://gitbox.apache.org/repos/asf?p=incubator-nuttx-apps.git>

    - GitHub Mirror:
      <https://github.com/apache/incubator-nuttx-apps>

## Website Source Code

The project website sources are accessible via the website source code
  repository which is also mirrored in GitHub:

- Primary:
  <https://gitbox.apache.org/repos/asf?p=incubator-nuttx-website.git>

- GitHub Mirror:
  <https://github.com/apache/incubator-nuttx-website>

# ENVIRONMENTS

  NuttX requires a POSIX development environment such as you would find under
  Linux or macOS.  NuttX may also be installed and built on Windows system
  if you also provide such a POSIX development environment.  Options for a
  POSIX development environment under Windows include:

  - An installation of Linux on a virtual machine (VM) in Windows.  I have
    not been happy using a VM myself.  I have had stability problems with
    open source VMs and commercial VMs cost more than I want to spend.
    Sharing files with Linux running in a VM is awkward;  sharing devices
    connected to the Windows box with Linux in a VM is, at the very least,
    confusing;  Using Windows tools (such as Segger J-Link) with files
    built under the Linux VM is not a possibility.

  - The Cygwin environment.  Instructions for installation of Cygwin on a
    Windows system are provided in the following paragraph, "Installing
    Cygwin".  Cygwin is a mature, well-tested, and very convenient
    environment.  It is especially convenient if you  need to
    integrate with Windows tools and files.  Downsides are that the
    installation time is very long and the compile times are slow.

  - Ubuntu/Bash shell under Windows 10.  This is a new option under
    Windows 10.  See the section "Ubuntu Bash under Windows 10" below.
    This is an improvement over Cygwin if your concern is compile time;
    its build performance is comparable to native Linux, certainly better
    than the Cygwin build time.  It also installs in a tiny fraction of
    the time as Cygwin, perhaps 20 minutes for the basic Ubuntu install
    (vs. more than a day for the complete Cygwin install).

    There have been even more recent ports of Linux environment to
    Windows.  I need to update this section to include some mention of
    these alternatives.

  - The MSYS environment.  MSYS derives from an older version of Cygwin
    simplified and adapted to work more naturally in the Windows
    environment.  See <http://www.mingw.org/wiki/MSYS> if you are
    interested in using MSYS.  The advantages of the MSYS environment is
    that it is better integrted with the native Windows environment and
    lighter weight; it uses only a  minimal number of add-on POSIX-land
    tools.

    The download link in that Wiki takes you to the SourceForge download
    site.  The SourceForge MSYS project has been stagnant for some time.
    The MSYS project has more recently moved to
    <http://odsn.net/projects/sfnet_mingwbundle>.  Downloads of current .zip
    files are available there but no instructions for the installation.

  - MSYS2 appears to be a re-write of MSYS based on a newer version of
    Cygwin.  Is it available at <https://www.msys2.org>.  A windows
    installer is available at that site along with very good installation
    instructions.  The download is relatively quick (at least compared to
    Cygwin) and the 'pacman' package management tool supports supports
    simple system updates.  For example, 'pacman -S git' will install the
    GIT command line utilities.

  - Other POSIX environments.  Check out:

    - UnxUtils: <https://sourceforge.net/projects/unxutils/>,
      <https://en.wikipedia.org/wiki/UnxUtils>
    - MobaXterm: <https://mobaxterm.mobatek.net/>
    - Gow: <https://github.com/bmatzelle/gow/wiki>

    **Disclaimer**:  In principle, these should work.  However, I have never
    used any of these environments and cannot guarantee that there is
    not some less-than-obvious issues.

NuttX can also be installed and built on a native Windows system, but with
some potential tool-related issues (see the discussion "Native Windows
Build" under "Building NuttX" below).  GNUWin32 is used to provide
compatible native windows tools.

## Installing Cygwin

Installing Cygwin on your Windows PC is simple, but time consuming.  See
<http://www.cygwin.com/> for installation instructions. Basically you just
need to download a tiny setup.exe program and it does the real, network
installation for you.

Some Cygwin installation tips:

  1. Install at `C:\cygwin`

  2. Install **everything**:  "Only the minimal base packages from the
     Cygwin distribution are installed by default. Clicking on categories
     and packages in the setup.exe package installation screen will
     provide you with the ability to control what is installed or updated.
     Clicking on the "Default" field next to the "All" category will
     provide you with the opportunity to install every Cygwin package.
     Be advised that this will download and install hundreds of megabytes
     to your computer."

If you use the "default" installation, you will be missing many
of the Cygwin utilities that you will need to build NuttX.  The
build will fail in numerous places because of missing packages.

NOTE: The last time I installed **everything**, the download was
about 5GiB.  The server I selected was also very slow so it took
over a day to do the whole install!

NOTE: You don't really have to install **everything** but I cannot
answer the question "Then what should I install?"  I don't know
the answer to that and so will continue to recommend installing
**everything**.

You should certainly be able to omit "Science", "Math", and
"Publishing".  You can try omitting KDE, Gnome, GTK, and other
graphics packages if you don't plan to use them.

Perhaps a minimum set would be those packages listed below for the
"Ubuntu Bash under Windows 10" installation?

**UPDATE**:  Sergey Frolov had success with the following minimal
Cygwin configuration:

   1. After starting the Cygwin installer, keep the recommended
      packages that are pre-selected in the default configuration.

   2. Using the installation tools, add the following packages:

          make (GNU make)  bison        libgmp3-dev
          gcc-core         byacc        libmpfr-dev
          gcc-g++          gperf        libmpc-dev
          flex             gdb          automake-1.15
          libncurses-dev   libgmp-dev   curl

After installing Cygwin, you will get lots of links for installed
tools and shells.  I use the RXVT native shell.  It is fast and reliable
and does not require you to run the Cygwin X server (which is neither
fast nor reliable).  Unless otherwise noted, the rest of these
instructions assume that you are at a bash command line prompt in
either Linux or in Cygwin shell.

## Using MSYS

MSYS is an environment the derives from Cygwin.  Thus, most things said
about Cygwin apply equally to MSYS.  This section will, then, focus on
the differences when using MSYS, specifically MSYS2.

Here is it assumed that you have already downloaded and installed MSYS2
from https://www.msys2.org using the windows installer available at that
location.  It is also assumed that you have brought in the necessary
tools using the 'pacman' package management tool Tools needed including:

    pacman -S git
    pacman -S make
    pacman -S gcc
    pacman -S gdb

And possibly others depending upon your usage.  Then you will need to
build and install kconfig-frontends per the instructions of the top-level
README.txt file in the tools repository.  This requires the following
additional tools:

    pacman -S bison
    pacman -S curl
    pacman -S gperf
    pacman -S gdb
    yay -S ncurses5-compat-libs
    yay -S kconfig-frontends

Build arm-none-eabi toolchain from sources.\
You can use this script as a guide:\
https://github.com/ccxtechnologies/nuttx/blob/master/tools/arm-toolchain/arm-none-eabi-gcc.sh

    chmod +x arm-none-eabi-gcc.sh
    ./arm-none-eabi-gcc.sh

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

At least one configuration (eagle100) requires additional command line
arguments on the make command.  Read
`{TOPDIR}/boards/<arch-name>/<chip-name>/<board-name>/README.txt` to see
if that applies to your target.

## Re-building

Re-building is normally simple -- just type make again.

But there are some things that can "get you" when you use the Cygwin
development environment with Windows native tools.  The native Windows
tools do not understand Cygwin's symbolic links, so the NuttX make system
does something weird:  It copies the configuration directories instead of
linking to them (it could, perhaps, use the NTFS `mklink` command, but it
doesn't).

A consequence of this is that you can easily get confused when you edit
a file in one of the linked (i.e., copied) directories, re-build NuttX,
and then not see your changes when you run the program.  That is because
build is still using the version of the file in the copied directory, not
your modified file!

Older versions of NuttX did not support dependencies in this
configuration.  So a simple work around this annoying behavior in this
case was the following when you re-build:

     make clean_context all

This 'make' command will remove of the copied directories, re-copy them,
then make NuttX.

However, more recent versions of NuttX do support dependencies for the
Cygwin build.  As a result, the above command will cause everything to be
rebuilt (because it removes and will cause recreating the
`include/nuttx/config.h` header file).  A much less gracefully but still
effective command in this case is the following for the ARM configuration:

    rm -rf arch/arm/src/chip arch/arm/src/board

This "kludge" simple removes the copied directories.  These directories
will be re-created when you do a normal 'make' and your edits will then be
effective.

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

## Native Windows Build

The beginnings of a Windows native build are in place but still not often
used as of this writing.  The build was functional but because of lack of
use may find some issues to be resolved with this build configuration.

The windows native build logic initiated if CONFIG_WINDOWS_NATIVE=y is
defined in the NuttX configuration file:

This build:

  - Uses all Windows style paths
  - Uses primarily Windows batch commands from cmd.exe, with
  - A few extensions from GNUWin32

In this build, you cannot use a Cygwin or MSYS shell. Rather the build must
be performed in a Windows console window. Here is a better terminal than the
standard issue, CMD.exe terminal:  ConEmu which can be downloaded from:
<https://sourceforge.net/projects/conemu/> or <https://conemu.github.io/>.

Build Tools.  The build still relies on some Unix-like commands.  I use
the GNUWin32 tools that can be downloaded from <http://gnuwin32.sourceforge.net/>
using the *Download all* selection.  Individual packages can be download
instead if you know what you are doing and want a faster download (No, I
can't tell you which packages you should or should not download).

NOTE:  It should be possible to use Cygwin or MSYS2 in place of the GNUWin32
tools.  There are, however, complexities in doing that because those tools
depend on the shell environment and use DLLs that are not found (at least
not without the correct setup).

Host Compiler:  I use the MingGW GCC compiler which can be downloaded from
<http://www.mingw.org/>.  If you are using GNUWin32, then it is recommended
the you not install the optional MSYS components as there may be conflicts.

Kconfig-frontends:  See the section entitled "NuttX Configuration Tool
under DOS" for information about installing the `kconfig-frontend` tools to
run natively under Windows.

This capability should still be considered a work in progress because:

  1. It has not been verified on all targets and tools, and
  2. it still lacks some of the creature-comforts of the more mature
     environments.

## Installing GNUWin32

  The Windows native build will depend upon a few Unix-like tools that can be
  provided either by MSYS or GNUWin32.  The GNUWin32 are available from
  <http://gnuwin32.sourceforge.net/>.  GNUWin32 provides ports of tools with a
  GPL or similar open source license to modern MS-Windows (Microsoft Windows
  2000 / XP / 2003 / Vista / 2008 / 7).  See
  <http://gnuwin32.sourceforge.net/packages.html> for a list of all of the tools
  available in the GNUWin32 package.

  The SourceForge project is located here:
  <http://sourceforge.net/projects/gnuwin32/>.  The project is still being
  actively supported (although some of the Windows ports have gotten very old).

  Some commercial toolchains include a subset of the GNUWin32 tools in the
  installation.  My recommendation is that you download the GNUWin32 tools
  directly from the sourceforge.net website so that you will know what you are
  using and can reproduce your build environment.

  GNUWin32 Installation Steps:

  The following steps will download and execute the GNUWin32 installer.

1. Download `GetGNUWin32-x.x.x.exe` from
   <http://sourceforge.net/projects/getgnuwin32/files/>.  This is the
   installer.  The current version as of this writing is 0.6.3.

2. Run the installer.

3. Accept the license.

4. Select the installation directory.  My recommendation is the
   directory that contains this README file (`<this-directory>`).

5. After running `GetGNUWin32-0.x.x.exe`, you will have a new directory
   `<this-directory>/GetGNUWin32`

   Note that the GNUWin32 installer didn't install GNUWin32.  Instead, it
   installed another, smarter downloader.  That downloader is the GNUWin32
   package management tool developed by the Open SSL project.

   The following steps probably should be performed from inside a DOS shell.

6. Change to the directory created by `GetGNUWin32-x.x.x.exe`

      cd GetGNUWin32

7. Execute the download.bat script.  The download.bat script will download
   about 446 packages!  Enough to have a very complete Linux-like environment
   under the DOS shell.  This will take awhile.  This step only downloads
   the packages and the next step will install the packages.

      download

8. This step will install the downloaded packages.  The argument of the
   install.bat script is the installation location.  C:\gnuwin32 is the
   standard install location:

     install C:\gnuwin32

  **NOTE**:  This installation step will install *all* GNUWin32 packages... far
  more than you will ever need.  If disc space is a problem for you, you might
  need to perform a manual installation of the individual ZIP files that you
  will find in the `<this directory>/GetGNUWin32/packages` directory.

9. Make sure that you add the GNUWin32 tools to your path variable:

         set PATH=C:\gnuwin32\bin;%PATH%

  **WARNING**:  Make sure you have `C:\MinGW\bin` in your path before any other
  directory that contains `libiconv-2.dll`. Apparently the `as.exe` in some
  MinGW distributions are dependent on that DLL, and having an old
  version of it in the path somewhere (for example GnuWin32 tools) will
  cause as.exe to pick up the older version that doesn't have the entry
  point it's looking for.

# CYGWIN BUILD PROBLEMS

## Performance

Build performance under Cygwin is really not so bad, certainly not as good
as a Linux build.  However, often you will find that the performance is
not just bad but terrible.  If you are seeing awful performance.. like two
or three compilations per second.. the culprit is usually your Windows
Anti-Virus protection interfering with the build tool program execution.

I use Cygwin quite often and I use Windows Defender.  In order to get good
build performance, I routinely keep the Windows Defender "Virus & Threat
Protections Settings" screen up:  I disable "Real-Time Protection" just
before entering 'make' then turn "Real-Time Protection" back on when the
build completes.  With this additional nuisance step, I find that build
performance under Cygwin is completely acceptable.

## Strange Path Problems

If you see strange behavior when building under Cygwin then you may have
a problem with your PATH variable.  For example, if you see failures to
locate files that are clearly present, that may mean that you are using
the wrong version of a tool.  For example, you may not be using Cygwin's
'make' program at /usr/bin/make.  Try:

    which make
    /usr/bin/make

When you install some toolchains (such as Yargarto or CodeSourcery tools),
they may modify your PATH variable to include a path to their binaries.
At that location, they may have GNUWin32 versions of the tools.  So you
might actually be using a version of make that does not understand Cygwin
paths.

The solution is either:

  1. Edit your PATH to remove the path to the GNUWin32 tools, or

  2. Put /usr/local/bin, /usr/bin, and /bin at the front of your path:

         export PATH=/usr/local/bin:/usr/bin:/bin:$PATH

## Window Native Toolchain Issues

There are many popular Windows native toolchains that may be used with NuttX.
Examples include CodeSourcery (for Windows), devkitARM, and several vendor-
provided toolchains.  There are several limitations with using a and Windows
based toolchain in a Cygwin environment.  The three biggest are:

  1. The Windows toolchain cannot follow Cygwin paths.  Path conversions are
     performed automatically in the Cygwin makefiles using the 'cygpath' utility
     but you might easily find some new path problems.  If so, check out 'cygpath -w'

  2. Windows toolchains cannot follow Cygwin symbolic links.  Many symbolic links
     are used in NuttX (e.g., include/arch).  The make system works around these
     problems for the Windows tools by copying directories instead of linking them.
     But this can also cause some confusion for you:  For example, you may edit
     a file in a "linked" directory and find that your changes had no effect.
     That is because you are building the copy of the file in the "fake" symbolic
     directory.  If you use a Windows toolchain, you should get in the habit of
     making like this:

         make clean_context all

     An alias in your .bashrc file might make that less painful.  The rebuild
     is not a long as you might think because there is no dependency checking
     if you are using a native Windows toolchain.  That bring us to #3:

## General Pre-built Toolchain Issues

To continue with the list of "Window Native Toolchain Issues" we can add
the following.  These, however, are really just issues that you will have
if you use any pre-built toolchain (vs. building the NuttX toolchain from
the NuttX buildroot package):

There may be incompatibilities with header files, libraries, and compiler
built-in functions detailed below.  For the most part, these issues
are handled in the existing make logic.  But if you are breaking new ground,
then you may encounter these:

  1. Header Files.  Most pre-built toolchains will build with a foreign C
     library (usually newlib, but maybe uClibc or glibc if you are using a
     Linux toolchain).  This means that the header files from the foreign
     C library will be built into the toolchain.  So if you `#include <stdio.h>`,
     you will get the stdio.h from the incompatible, foreign C library and
     not the nuttx `stdio.h` (at `nuttx/include/stdio.h`) that you wanted.

     This can cause confusion in the builds and you must always be
     sure the `-nostdinc` is included in the `CFLAGS`.  That will assure that
     you take the include files only from

  2. Libraries.  What was said above header files applies to libraries.
     You do not want to include code from the libraries of any foreign
     C libraries built into your toolchain.  If this happens you will get
     perplexing errors about undefined symbols.  To avoid these errors,
     you will need to add `-nostdlib` to your `CFLAGS` flags to assure that
     you only take code from the NuttX libraries.

     This, however, may causes other issues for libraries in the toolchain
     that you do want (like `libgcc.a` or `libm.a`).  These are special-cased
     in most Makefiles, but you could still run into issues of missing
     libraries.

  3. Built-Ins.  Some compilers target a particular operating system.
     Many people would, for example, like to use the same toolchain to
     develop Linux and NuttX software.  Compilers built for other
     operating systems may generate incompatible built-in logic and,
     for this reason, `-fno-builtin` should also be included in your
     C flags

     And finally you may not be able to use NXFLAT.

  4. NXFLAT. If you use a pre-built toolchain, you will lose all support
     for NXFLAT.  NXFLAT is a binary format described in
     Documentation/NuttXNxFlat.html.  It may be possible to build
     standalone versions of the NXFLAT tools; there are a few examples
     of this in the buildroot repository at <https://bitbucket.org/nuttx/buildroot>
     However, it is possible that there could be interoperability issues
     with your toolchain since they will be using different versions of
     binutils and possibly different ABIs.

## Building Original Linux Boards in Cygwin

Some default board configurations are set to build under Linux and others
to build under Windows with Cygwin.  Various default toolchains may also
be used in each configuration.  It is possible to change the default
setup.  Here, for example, is what you must do in order to compile a
default Linux configuration in the Cygwin environment using the
CodeSourcery for Windows toolchain.  After instantiating a "canned"
NuttX configuration, run the target 'menuconfig' and set the following
items:

    Build Setup->Build Host Platform->Windows
    Build Setup->Windows Build Environment->Cygwin
    System Type->Toolchain Selection->CodeSourcery GNU Toolchain under Windows

In Windows 7 it may be required to open the Cygwin shell as Administrator
("Run As" option, right button) you find errors like "Permission denied".

## Recovering from Bad Configurations

Many people make the mistake of configuring NuttX with the "canned"
configuration and then just typing `make` with disastrous consequences;
the build may fail with mysterious, uninterpretable, and irrecoverable
build errors.  If, for example, you do this with an unmodified Linux
configuration in a Windows/Cgwin environment, you will corrupt the
build environment.  The environment will be corrupted because of POSIX vs
Windows path issues and with issues related to symbolic links.  If you
make the mistake of doing this, the easiest way to recover is to just
start over: Do `make distclean` to remove every trace of the corrupted
configuration, reconfigure from scratch, and make certain that the set
the configuration correctly for your platform before attempting to make
again.

Just fixing the configuration file after you have instantiated the bad
configuration with 'make' is not enough.

# DOCUMENTATION

Additional information can be found in the Documentation/ directory and
also in README files that are scattered throughout the source tree.  The
documentation is in HTML and can be access by loading the following file
into your Web browser:

    Documentation/index.html

NuttX documentation is also available online at <https://apache.nuttx.org>.

Below is a guide to the available README files in the NuttX source tree:

    nuttx/
     |
     |- arch/
     |   |
     |   |- arm/
     |   |   `- src
     |   |       |- common
     |   |       |   `- README_lwl_console.txt
     |   |       |- lpc214x
     |   |       |    `-README.txt
     |   |       `- stm32l4
     |   |           `- README.txt
     |   |- renesas/
     |   |   |- include/
     |   |   |   `-README.txt
     |   |   |- src/
     |   |   |   `-README.txt
     |   |- x86/
     |   |   |- include/
     |   |   |   `-README.txt
     |   |   `- src/
     |   |       `-README.txt
     |   `- z80/
     |   |   `- src/
     |   |       |- z80/README.txt
     |   |       `- z180/README.txt, z180_mmu.txt
     |   `- README.txt
     |- audio/
     |   `-README.txt
     |- boards/
     |   |- arm/
     |   |   |- a1x/
     |   |   |   `- pcduino-a10/
     |   |   |       `- README.txt
     |   |   |- am335x/
     |   |   |   `- beaglebone-black/
     |   |   |       `- README.txt
     |   |   |- c5471/
     |   |   |   `- c5471evm/
     |   |   |       `- README.txt
     |   |   |- cxd56xx/
     |   |   |   `- spresense/
     |   |   |       `- README.txt
     |   |   |- dm320/
     |   |   |   `- ntosd-dm320/
     |   |   |       |- doc/README.txt
     |   |   |       `- README.txt
     |   |   |- efm32/
     |   |   |   |- efm32-g8xx-stk/
     |   |   |   |   `- README.txt
     |   |   |   |- efm32gg-stk3700/
     |   |   |   |   `- README.txt
     |   |   |   `- olimex-efm32g880f128-stk/
     |   |   |       `- README.txt
     |   |   |- imx6/
     |   |   |   `- sabre-6quad/
     |   |   |       `- README.txt
     |   |   |- imxrt/
     |   |   |   |- imxrt1050-evk/
     |   |   |   |   `- README.txt
     |   |   |   |- imxrt1060-evk/
     |   |   |   |   `- README.txt
     |   |   |   `- teensy-4.x/
     |   |   |       `- README.txt
     |   |   |- kinetis/
     |   |   |   |- freedom-k28f/
     |   |   |   |   `- README.txt
     |   |   |   |- freedom-k64f/
     |   |   |   |   `- README.txt
     |   |   |   |- freedom-k66f/
     |   |   |   |   `- README.txt
     |   |   |   |- kwikstik-k40/
     |   |   |   |   `- README.txt
     |   |   |   |- teensy-3.x/
     |   |   |   |   `- README.txt
     |   |   |   |- twr-k60n512/
     |   |   |   |   `- README.txt
     |   |   |   `- twr-k64f120m/
     |   |   |       `- README.txt
     |   |   |- kl/
     |   |   |   |- freedom-kl25z/
     |   |   |   |   `- README.txt
     |   |   |   |- freedom-kl26z/
     |   |   |   |   `- README.txt
     |   |   |   `- teensy-lc/
     |   |   |       `- README.txt
     |   |   |- lc823450/
     |   |   |   `- lc823450-xgevk/
     |   |   |       `- README.txt
     |   |   |- lpc17xx_40xx/
     |   |   |   |- lincoln60/
     |   |   |   |   `- README.txt
     |   |   |   |- lpc4088-devkit/
     |   |   |   |   `- README.txt
     |   |   |   |- lpc4088-quickstart/
     |   |   |   |   `- README.txt
     |   |   |   |- lpcxpresso-lpc1768/
     |   |   |   |   `- README.txt
     |   |   |   |- lx_cpu/
     |   |   |   |   `- README.txt
     |   |   |   |- mbed/
     |   |   |   |   `- README.txt
     |   |   |   |- mcb1700/
     |   |   |   |   `- README.txt
     |   |   |   |- olimex-lpc1766stk/
     |   |   |   |   `- README.txt
     |   |   |   |- open1788/
     |   |   |   |   `- README.txt
     |   |   |   |- pnev5180b/
     |   |   |   |   `- README.txt
     |   |   |   |- u-blox-c027/
     |   |   |   |   `- README.txt
     |   |   |   `- zkit-arm-1769/
     |   |   |       `- README.txt
     |   |   |- lpc214x/
     |   |   |   |- mcu123-lpc214x/
     |   |   |   |   `- README.txt
     |   |   |   `- zp214xpa/
     |   |   |       `- README.txt
     |   |   |- lpc2378/
     |   |   |   `- olimex-lpc2378/
     |   |   |       `- README.txt
     |   |   |- lpc31xx/
     |   |   |   |- ea3131/
     |   |   |   |   `- README.txt
     |   |   |   |- ea3152/
     |   |   |   |   `- README.txt
     |   |   |   `- olimex-lpc-h3131/
     |   |   |       `- README.txt
     |   |   |- lpc43xx/
     |   |   |   |- bambino-200e/
     |   |   |   |   `- README.txt
     |   |   |   |- lpc4330-xplorer/
     |   |   |   |   `- README.txt
     |   |   |   |- lpc4337-ws/
     |   |   |   |   `- README.txt
     |   |   |   |- lpc4357-evb/
     |   |   |   |   `- README.txt
     |   |   |   `- lpc4370-link2/
     |   |   |       `- README.txt
     |   |   |- lpc54xx/
     |   |   |   `- lpcxpresso-lpc54628/
     |   |   |       `- README.txt
     |   |   |- max326xx/
     |   |   |   `- max32660-evsys/
     |   |   |       `- README.txt
     |   |   |- moxart/
     |   |   |   `- moxa/
     |   |   |- nrf52/
     |   |   |   `- nrf52-generic/
     |   |   |       `- README.txt
     |   |   |- nuc1xx/
     |   |   |   `- nutiny-nuc120/
     |   |   |       `- README.txt
     |   |   |- s32k1xx/
     |   |   |   |- s32k118evb/
     |   |   |   |   `- README.txt
     |   |   |   |- s32k146evb/
     |   |   |   |   `- README.txt
     |   |   |   `- s32k148evb/
     |   |   |       `- README.txt
     |   |   |- sam34/
     |   |   |   |- arduino-due/
     |   |   |   |   `- README.txt
     |   |   |   |- flipnclick-sam3x/
     |   |   |   |   `- README.txt
     |   |   |   |- sam3u-ek/
     |   |   |   |   `- README.txt
     |   |   |   |- sam4cmp-db/
     |   |   |   |   `- README.txt
     |   |   |   |- sam4e-ek/
     |   |   |   |   `- README.txt
     |   |   |   |- sam4l-xplained/
     |   |   |   |   `- README.txt
     |   |   |   |- sam4s-xplained/
     |   |   |   |   `- README.txt
     |   |   |   `- sam4s-xplained-pro/
     |   |   |       `- README.txt
     |   |   |- sama5/
     |   |   |   |- sama5d2-xult/
     |   |   |   |   `- README.txt
     |   |   |   |- giant-board/
     |   |   |   |   `- README.md
     |   |   |   |- sama5d3x-ek/
     |   |   |   |   `- README.txt
     |   |   |   |- sama5d3-xplained/
     |   |   |   |   `- README.txt
     |   |   |   `- sama5d4-ek/
     |   |   |       `- README.txt
     |   |   |- samd2l2/
     |   |   |   |- arduino-m0/
     |   |   |   |   `- README.txt
     |   |   |   |- samd20-xplained/
     |   |   |   |   `- README.txt
     |   |   |   |- samd21-xplained/
     |   |   |   |   `- README.txt
     |   |   |   `- saml21-xplained/
     |   |   |       `- README.txt
     |   |   |- samd5e5/
     |   |   |   `- metro-m4/
     |   |   |      `- README.txt
     |   |   |- samv7/
     |   |   |   |- same70-xplained/
     |   |   |   |   `- README.txt
     |   |   |   `- samv71-xult/
     |   |   |      `- README.txt
     |   |   |- stm32/
     |   |   |   |- axoloti/
     |   |   |   |   `- README.txt
     |   |   |   |- b-g474e-dpow1/
     |   |   |   |   `- README.txt
     |   |   |   |- clicker2-stm32/
     |   |   |   |   `- README.txt
     |   |   |   |- cloudctrl/
     |   |   |   |   `- README.txt
     |   |   |   |- fire-stm32v2/
     |   |   |   |   `- README.txt
     |   |   |   |- hymini-stm32v/
     |   |   |   |   `- README.txt
     |   |   |   |- maple/
     |   |   |   |   `- README.txt
     |   |   |   |- mikroe-stm32f4/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f103rb/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f207zg/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f302r8/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f303re/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f303ze/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f334r8/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f410rb/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f446re/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f4x1re/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-l152re/
     |   |   |   |   `- README.txt
     |   |   |   |- olimexino-stm32/
     |   |   |   |- olimex-stm32-e407/
     |   |   |   |   `- README.txt
     |   |   |   |- olimex-stm32-h405/
     |   |   |   |   `- README.txt
     |   |   |   |- olimex-stm32-h407/
     |   |   |   |   `- README.txt
     |   |   |   |- olimex-stm32-p107/
     |   |   |   |- olimex-stm32-p207/
     |   |   |   |   `- README.txt
     |   |   |   |- olimex-stm32-p407/
     |   |   |   |   `- README.txt
     |   |   |   |- omnibusf4/
     |   |   |   |   `- README.txt
     |   |   |   |- photon/
     |   |   |   |   `- README.txt
     |   |   |   |- shenzhou/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32_tiny/
     |   |   |   |   `- README.txt
     |   |   |   |- stm3210e-eval/
     |   |   |   |   `- README.txt
     |   |   |   |- stm3220g-eval/
     |   |   |   |   `- README.txt
     |   |   |   |- stm3240g-eval/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32butterfly2/
     |   |   |   |- stm32f103-minimum/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f334-disco/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f3discovery/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f411e-disco/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f429i-disco/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f4discovery/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32ldiscovery/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32vldiscovery/
     |   |   |   |   `- README.txt
     |   |   |   `- viewtool-stm32f107/
     |   |   |       `- README.txt
     |   |   |- stm32f0l0g0/
     |   |   |   |- b-l072z-lrwan1/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f072rb/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-f091rc/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-g070rb/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-g071rb/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-l073rz/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f051-discovery/
     |   |   |   |   `- README.txt
     |   |   |   `- stm32f072-discovery/
     |   |   |       `- README.txt
     |   |   |- stm32f7/
     |   |   |   |- nucleo-144/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f746g-disco/
     |   |   |   |   |- configs/fb/README.txt
     |   |   |   |   |- configs/nxdemo/README.txt
     |   |   |   |   |- configs/nxterm/README.txt
     |   |   |   |   `- README.txt
     |   |   |   |- stm32f746-ws/
     |   |   |   `- stm32f769i-disco/
     |   |   |       `- README.txt
     |   |   |- stm32h7/
     |   |   |   `- nucleo-h743zi/
     |   |   |       `- README.txt
     |   |   |- stm32l4/
     |   |   |   |- b-l475e-iot01a/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-l432kc/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-l452re/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-l476rg/
     |   |   |   |   `- README.txt
     |   |   |   |- nucleo-l496zg/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32l476-mdk/
     |   |   |   |   `- README.txt
     |   |   |   |- stm32l476vg-disco/
     |   |   |   |   `- README.txt
     |   |   |   `- stm32l4r9ai-disco/
     |   |   |       `- README.txt
     |   |   |- str71x/
     |   |   |   `- olimex-strp711/
     |   |   |       `- README.txt
     |   |   |- tiva/
     |   |   |   |- dk-tm4c129x/
     |   |   |   |   `- README.txt
     |   |   |   |- eagle100/
     |   |   |   |   `- README.txt
     |   |   |   |- ekk-lm3s9b96/
     |   |   |   |   `- README.txt
     |   |   |   |- launchxl-cc1310/
     |   |   |   |   `- README.txt
     |   |   |   |- launchxl-cc1312r1/
     |   |   |   |   `- README.txt
     |   |   |   |- lm3s6432-s2e/
     |   |   |   |   `- README.txt
     |   |   |   |- lm3s6965-ek/
     |   |   |   |   `- README.txt
     |   |   |   |- lm3s8962-ek/
     |   |   |   |   `- README.txt
     |   |   |   |- lm4f120-launchpad/
     |   |   |   |   `- README.txt
     |   |   |   |- tm4c123g-launchpad/
     |   |   |   |   `- README.txt
     |   |   |   `- tm4c1294-launchpad/
     |   |   |       `- README.txt
     |   |   |- tms570/
     |   |   |   |- launchxl-tms57004/
     |   |   |   |   `- README.txt
     |   |   |   `- tms570ls31x-usb-kit/
     |   |   |       `- README.txt
     |   |   `- xmc4/
     |   |       `- xmc4500-relax/
     |   |           `- README.txt
     |   |- avr/
     |   |   |- at32uc3/
     |   |   |   `- avr32dev1/
     |   |   |       `- README.txt
     |   |   |- at90usb/
     |   |   |   |- micropendous3/
     |   |   |   |   `- README.txt
     |   |   |   `- teensy-2.0/
     |   |   |       `- README.txt
     |   |   `- atmega/
     |   |       |- amber/
     |   |       |   `- README.txt
     |   |       |- arduino-mega2560/
     |   |       |   `- README.txt
     |   |       `- moteino-mega/
     |   |           `- README.txt
     |   |- hc/
     |   |   `- m9s12/
     |   |       |- demo9s12ne64/
     |   |       |   `- README.txt
     |   |       `- ne64badge/
     |   |           `- README.txt
     |   |- mips/
     |   |   |- pic32mx/
     |   |   |   |- mirtoo/
     |   |   |   |   `- README.txt
     |   |   |   |- pic32mx7mmb/
     |   |   |   |   `- README.txt
     |   |   |   |- pic32mx-starterkit/
     |   |   |   |   `- README.txt
     |   |   |   |- sure-pic32mx/
     |   |   |   |   `- README.txt
     |   |   |   `- ubw32/
     |   |   |       `- README.txt
     |   |   `-pic32mz/
     |   |       |- flipnclick-pic32mz/
     |   |       |   `- README.txt
     |   |       `- pic32mz-starterkit/
     |   |           `- README.txt
     |   |- misoc/
     |   |   `- lm32/
     |   |       `- misoc/
     |   |           `- README.txt
     |   |- or1k/
     |   |   `- mor1kx/
     |   |       `- or1k/
     |   |           `- README.txt
     |   |- renesas/
     |   |   |- m16c/
     |   |   |   `- skp16c26/
     |   |   |       `- README.txt
     |   |   `-sh1/
     |   |       `- us7032evb1/
     |   |           `- README.txt
     |   |- risc-v/
     |   |- sim/
     |   |   `- sim/
     |   |       `- sim/
     |   |           |- include/README.txt
     |   |           `- README.txt
     |   |- x86/
     |   |   `- qemu/
     |   |       `- qemu-i486/
     |   |           `- README.txt
     |   |- xtensa/
     |   |   `- esp32/
     |   |       `- esp32-core/
     |   |           `- README.txt
     |   |- z16/
     |   |   `- z16f/
     |   |       `- z16f2800100zcog/
     |   |           |- configs/nsh/README.txt
     |   |           |- configs/ostest/README.txt
     |   |           |- configs/pashello/README.txt
     |   |           `- README.txt
     |   |- z80/
     |   |   |- ez80/
     |   |   |   |- ez80f910200kitg/
     |   |   |   |   |- configs/ostest/README.txt
     |   |   |   |   `- README.txt
     |   |   |   |- ez80f910200zco/
     |   |   |   |   |- configs/dhcpd/README.txt
     |   |   |   |   |- configs/httpd/README.txt
     |   |   |   |   |- configs/nettest/README.txt
     |   |   |   |   |- configs/nsh/README.txt
     |   |   |   |   |- configs/poll/README.txt
     |   |   |   |   `- README.txt
     |   |   |   |- makerlisp/
     |   |   |   |   |- configs/nsh_flash/README.txt
     |   |   |   |   |- configs/nsh_ram/README.txt
     |   |   |   |   |- configs/sdboot/README.txt
     |   |   |   |   `- README.txt
     |   |   |   `- z80x/
     |   |   |       |- configs/nsh_flash/README.txt
     |   |   |       |- configs/nsh_ram/README.txt
     |   |   |       |- configs/sdboot/README.txt
     |   |   |       `- README.txt
     |   |   |- z180/
     |   |   |   `- p112/
     |   |   |       `- README.txt
     |   |   |- z8/
     |   |   |   |- z8encore000zco/
     |   |   |   |   |- configs/ostest/README.txt
     |   |   |   |   `- README.txt
     |   |   |   `- z8f64200100kit/
     |   |   |       |- configs/ostest/README.txt
     |   |   |       `- README.txt
     |   |   `- z80/
     |   |       `- z80sim/
     |   |           `- README.txt
     |   `-README.txt
     |- drivers/
     |   |- eeprom/
     |   |   `- README.txt
     |   |- lcd/
     |   |   | README.txt
     |   |   `- pcf8574_lcd_backpack_readme.txt
     |   |- mtd/
     |   |   `- README.txt
     |   |- sensors/
     |   |   `- README.txt
     |   |- syslog/
     |   |   `- README.txt
     |   `- README.txt
     |- fs/
     |   |- binfs/
     |   |   `- README.txt
     |   |- cromfs/
     |   |   `- README.txt
     |   |- mmap/
     |   |   `- README.txt
     |   |- nxffs/
     |   |   `- README.txt
     |   |- smartfs/
     |   |   `- README.txt
     |   |- procfs/
     |   |   `- README.txt
     |   |- spiffs/
     |   |   `- README.md
     |   `- unionfs/
     |       `- README.txt
     |- graphics/
     |   `- README.txt
     |- libs/
     |   |- README.txt
     |   |- libc/
     |   |   |- zoneinfo
     |   |   |   `- README.txt
     |   |   `- README.txt
     |   |- libdsp/
     |   |   `- README.txt
     |   |- libnx/
     |   |   |- nxfongs
     |   |   |   `- README.txt
     |   |   `- README.txt
     |   |- libxx/
     |   `- README.txt
     |- mm/
     |   |- shm/
     |   |   `- README.txt
     |   `- README.txt
     |- net/
     |   |- sixlowpan
     |   |   `- README.txt
     |   `- README.txt
     |- pass1/
     |   `- README.txt
     |- syscall/
     |   `- README.txt
     `- tools/
         `- README.txt

Below is a guide to the available README files in the semi-optional apps/
source tree:

    apps/
     |- examples/
     |   |- bastest/README.txt
     |   |- json/README.txt
     |   |- pashello/README.txt
     |   `- README.txt
     |- gpsutils/
     |   `- minmea/README.txt
     |- graphics/
     |   |- tiff/README.txt
     |   `- traveler/tools/tcledit/README.txt
     |- interpreters/
     |   |- bas/
     |   |  `- README.txt
     |   |- ficl/
     |   |  `- README.txt
     |   `- README.txt
     |- modbus/
     |   `- README.txt
     |- netutils/
     |   |- discover/
     |   |  `- README.txt
     |   |- ftpc/
     |   |  `- README.txt
     |   |- json/
     |   |  `- README.txt
     |   |- telnetd/
     |   |  `- README.txt
     |   `- README.txt
     |- nshlib/
     |   `- README.txt
     |- NxWidgets/
     |   `- README.txt
     |- system/
     |   |- cdcacm/
     |   |  `- README.txt
     |   |- i2c/
     |   |  `- README.txt
     |   |- inifile/
     |   |  `- README.txt
     |   |- install/
     |   |  `- README.txt
     |   |- nsh/
     |   |  `- README.txt
     |   |- nxplayer/
     |   |  `- README.txt
     |   |- psmq/
     |   |  `- README.txt
     |   |- symtab/
     |   |   `- README.txt
     |   |- termcurses/
     |   |   `- README.txt
     |   |- usbmsc/
     |   |  `- README.txt
     |   `- zmodem/
     |      `- README.txt
     `- wireless
         |- bluetooth/
         |  `- btsak/
         |     `- README.txt
         `- ieee802154
            `- i8sak/
               `- README.txt

Additional README.txt files in the other, related repositories:

Use micro SD to SD adapter to insert your micro SD Card into built-in SD Card Reader.
Execute:

    lsblk

If `mmcblk0` is listed, then your microSD Card is being detected and you can proceed.
Copy the built image to microSD Card:

    dd if=/dev/zero of=/dev/mmcblk0 count=4 bs=1K
    dd if=nuttx.bin of=/dev/mmcblk0 seek=1 bs=1K
