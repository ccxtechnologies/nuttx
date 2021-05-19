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

/* i.MX RT 1064-CCX GPIO Pin Definitions ************************************/

/* LEDs
*
* Only RED and BLUE LEDs can be controlled by software
* RED: GPIO_SD_B1_07
* BLUE: GPIO_SD_B1_08
*/
#define GPIO_LED_RED        (GPIO_OUTPUT | IOMUX_LED_DEFAULT | \
                         GPIO_OUTPUT_ZERO | GPIO_PORT3 | GPIO_PIN7)  /* SD_B1_07 */

#define GPIO_LED_BLUE        (GPIO_OUTPUT | IOMUX_LED_DEFAULT | \
                         GPIO_OUTPUT_ZERO | GPIO_PORT3 | GPIO_PIN8)  /* SD_B1_08 */


/* Discretes
*
*
*
*/
#define BOARD_NGPIOIN   4 /* Amount of GPIO Input pins */
#define BOARD_NGPIOOUT  7 /* Amount of GPIO Output pins (CAN3_EN_A/B + LED_RED/BLUE) */

#define GPIO_GP_INPUT1  (GPIO_INPUT | IOMUX_SW_DEFAULT | \
                         GPIO_PORT4 | GPIO_PIN16)   /* EMC_16 */
#define GPIO_GP_INPUT2  (GPIO_INPUT | IOMUX_SW_DEFAULT | \
                         GPIO_PORT4 | GPIO_PIN15)   /* EMC_15 */
#define GPIO_GP_INPUT3  (GPIO_INPUT | IOMUX_SW_DEFAULT | \
                         GPIO_PORT4 | GPIO_PIN23)   /* EMC_23 */
#define GPIO_GP_INPUT4  (GPIO_INPUT | IOMUX_SW_DEFAULT | \
                         GPIO_PORT4 | GPIO_PIN24)   /* EMC_24 */

#define GPIO_RESET_OUTPUT1  (GPIO_OUTPUT | GPIO_OUTPUT_ZERO | \
                             IOMUX_SW_DEFAULT | GPIO_PORT3 |GPIO_PIN26) /* EMC_40 */
#define GPIO_RESET_OUTPUT2  (GPIO_OUTPUT | GPIO_OUTPUT_ZERO | \
                             IOMUX_SW_DEFAULT | GPIO_PORT3 |GPIO_PIN27) /* EMC_41 */
#define GPIO_SOFTWARE_RST_N (GPIO_OUTPUT | GPIO_OUTPUT_ZERO | \
                             IOMUX_SW_DEFAULT | GPIO_PORT3 |GPIO_PIN26) /* EMC_40 */

/* Ethernet */
/* Ethernet Reset:  GPIO_B1_00
 *
 * The #RST uses inverted logic.  The initial value of zero will put the
 * PHY into the reset state.
 */

#define GPIO_ENET_RST   (GPIO_OUTPUT | GPIO_OUTPUT_ZERO | \
                         GPIO_PORT2 | GPIO_PIN16 | IOMUX_ENET_RST_DEFAULT) /* B1_00 */


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

/* FlexCAN3 A_EN: GPIO_SD_B1_03 */

#define IOMUX_FLEXCAN3_A_EN (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                         IOMUX_SPEED_MEDIUM | IOMUX_PULL_DOWN_100K | \
                         _IOMUX_PULL_ENABLE)
#define GPIO_FLEXCAN3_A_EN  (GPIO_OUTPUT | GPIO_OUTPUT_ZERO | \
                         GPIO_PORT3 | GPIO_PIN3 | IOMUX_FLEXCAN3_A_EN)

/* FlexCAN3 B_EN: GPIO_SD_B1_03 */

#define IOMUX_FLEXCAN3_B_EN (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                         IOMUX_SPEED_MEDIUM | IOMUX_PULL_DOWN_100K | \
                         _IOMUX_PULL_ENABLE)
#define GPIO_FLEXCAN3_B_EN  (GPIO_OUTPUT | GPIO_OUTPUT_ZERO | \
                         GPIO_PORT3 | GPIO_PIN6 | IOMUX_FLEXCAN3_B_EN)

/* USB OTG ID Pin： GPIO_AD_B0_01 */

#define GPIO_USBOTG_ID  (GPIO_USB_OTG1_ID_2 | IOMUX_USBOTG_ID_DEFAULT)      /* AD_B0_01 */

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

/****************************************************************************
 * Name: imxrt_usbhost_initialize
 *
 * Description:
 *   Initialize USB host drivers
 *
 ****************************************************************************/

#if defined(CONFIG_IMXRT_USBOTG) || defined(CONFIG_USBHOST)
int imxrt_usbhost_initialize(void);
#endif

/****************************************************************************
 * Name: imxrt_can_setup
 *
 * Description:
 *  Setup FlexCAN device
 *
 ****************************************************************************/

#if defined(CONFIG_IMXRT_FLEXCAN) && defined(CONFIG_NETDEV_LATEINIT)
int imxrt_can_setup(void);
#endif

/****************************************************************************
 * Name: imxrt_gpio_initialize
 *
 * Description:
 *   Initialize GPIO drivers for use with /apps/examples/gpio
 *
 ****************************************************************************/

#ifdef CONFIG_DEV_GPIO
int imxrt_gpio_initialize(void);
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_ARM_IMXRT_CCX_SRC_CCX_H */
