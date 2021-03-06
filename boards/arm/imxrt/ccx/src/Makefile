############################################################################
# boards/arm/imxrt/ccx/src/Makefile
#
#   Copyright (C) 2018 Gregory Nutt. All rights reserved.
#   Author: Gregory Nutt <gnutt@nuttx.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name NuttX nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

include $(TOPDIR)/Make.defs

ifeq ($(CONFIG_IMXRT_BOOT_COPYTORAM), y)
CSRCS = imxrt_boot.c imxrt_copytoram_boot.c
else
CSRCS = imxrt_boot.c imxrt_flexspi_nor_boot.c imxrt_flexspi_nor_flash.c
endif

ifeq ($(CONFIG_LIB_BOARDCTL),y)
CSRCS += imxrt_appinit.c imxrt_bringup.c
else ifeq ($(CONFIG_BOARD_LATE_INITIALIZE),y)
CSRCS += imxrt_bringup.c
endif

ifeq ($(CONFIG_IMXRT_ENET),y)
CSRCS += imxrt_ethernet.c
endif

ifeq ($(CONFIG_IMXRT_FLEXCAN),y)
CSRCS += imxrt_flexcan.c
endif

ifeq ($(CONFIG_SENSORS_INA260),y)
CSRCS += imxrt_ina260.c
endif

ifeq ($(CONFIG_IMXRT_LPSPI),y)
CSRCS += imxrt_spi.c
endif

ifeq ($(CONFIG_IMXRT_LPI2C),y)
CSRCS += imxrt_i2c.c
endif

ifeq ($(CONFIG_DEV_GPIO),y)
CSRCS += imxrt_gpio.c
endif

ifeq ($(CONFIG_IMXRT_USBOTG),y)
CSRCS += imxrt_usbhost.c
endif

include $(TOPDIR)/boards/Board.mk
