/****************************************************************************
 * boards/arm/imxrt/ccx/src/ccx.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Authors: Gregory Nutt <gnutt@nuttx.org>
 *            David Sidrane <david_s5@nscdg.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __BOARDS_ARM_IMXRT_CCX_SRC_CCX_H
#define __BOARDS_ARM_IMXRT_CCX_SRC_CCX_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include <arch/irq.h>
#include <nuttx/irq.h>

#include "imxrt_gpio.h"
#include "imxrt_iomuxc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* LPSPI1 CS:  GPIO_EMC_30 */

#define IOMUX_LPSPI1_CS (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                         IOMUX_SPEED_MEDIUM | IOMUX_PULL_DOWN_100K | \
                         _IOMUX_PULL_ENABLE)
#define GPIO_LPSPI1_CS  (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                         GPIO_PORT4 | GPIO_PIN30 | IOMUX_LPSPI1_CS)

/* ADC_RESET1: B11 GPIO_B1_01 */

#define IOMUX_ADC_RESET1 (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                          IOMUX_SPEED_MEDIUM | IOMUX_PULL_DOWN_100K | \
                           _IOMUX_PULL_ENABLE)
#define GPIO_ADC_RESET1 (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                         GPIO_PORT2 | GPIO_PIN17 | IOMUX_ADC_RESET1)

/* ADC_RESET2: N4 GPIO_SD_B1_09 */

#define IOMUX_ADC_RESET2 (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                          IOMUX_SPEED_MEDIUM | IOMUX_PULL_DOWN_100K | \
                           _IOMUX_PULL_ENABLE)
#define GPIO_ADC_RESET2 (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                         GPIO_PORT3 | GPIO_PIN9 | IOMUX_ADC_RESET2)
/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public data
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Name: imxrt_bringup
 *
 * Description:
 *   Bring up board features
 *
 ****************************************************************************/

#if defined(CONFIG_LIB_BOARDCTL) || defined(CONFIG_BOARD_LATE_INITIALIZE)
int imxrt_bringup(void);
#endif

/****************************************************************************
 * Name: imxrt_spidev_initialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the ccx board.
 *
 ****************************************************************************/

void imxrt_spidev_initialize(void);

/****************************************************************************
 * Name: imxrt_i2c_setup
 *
 * Description:
 *  Setup I2C device
 *
 ****************************************************************************/

#ifdef CONFIG_IMXRT_LPI2C
void imxrt_i2c_setup(void);
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_ARM_IMXRT_CCX_SRC_CCX_H */
