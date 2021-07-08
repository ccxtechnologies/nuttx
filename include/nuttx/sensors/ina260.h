/****************************************************************************
 * include/nuttx/sensors/ina260.h
 * Character driver for the INA260 Power Sensor
 *
 *   Copyright (C) 2017 Giorgio Groß. All rights reserved.
 *   Author: Giorgio Groß <giorgio.gross@robodev.eu>
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

#ifndef __INCLUDE_NUTTX_SENSORS_INA260_H
#define __INCLUDE_NUTTX_SENSORS_INA260_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/sensors/ioctl.h>

#if defined(CONFIG_I2C) && defined(CONFIG_SENSORS_INA260)

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* INA260 Register Definitions ***********************************************/

#define INA260_REG_CONFIG            0  /* See below */
#define INA260_REG_CURRENT           1
#define INA260_REG_BUS_VOLTAGE       2  /* Bus votlage in 1.25 mV units */
#define INA260_REG_POWER             3  /* Requires prior calibration */
#define INA260_REG_MASK_ENABLE       6  /* Sets Alert pin function */
#define INA260_REG_ALERT_LIMIT       7  /* Sets Alert pin limits */

/* INA260 Config Register bits */

/* Averaging mode */

#define INA260_CONFIG_AVG_SHIFT      9
#define INA260_CONFIG_AVG_MASK       (7 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_1          (0 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_4          (1 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_16         (2 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_64         (3 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_128        (4 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_256        (5 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_512        (6 << INA260_CONFIG_AVG_SHIFT)
#define INA260_CONFIG_AVG_1024       (7 << INA260_CONFIG_AVG_SHIFT)

/* Bus voltage conversion time */

#define INA260_CONFIG_VBUSCT_SHIFT   6
#define INA260_CONFIG_VBUSCT_MASK    (7 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_140US   (0 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_204US   (1 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_332US   (2 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_588US   (3 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_1100US  (4 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_2116US  (5 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_4156US  (6 << INA260_CONFIG_VBUSCT_SHIFT)
#define INA260_CONFIG_VBUSCT_8244US  (7 << INA260_CONFIG_VBUSCT_SHIFT)

/* Shunt voltage conversion time */

#define INA260_CONFIG_ISHCT_SHIFT    3
#define INA260_CONFIG_ISHCT_MASK    (7 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_140US   (0 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_204US   (1 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_332US   (2 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_588US   (3 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_1100US  (4 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_2116US  (5 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_4156US  (6 << INA260_CONFIG_ISHCT_SHIFT)
#define INA260_CONFIG_ISHCT_8244US  (7 << INA260_CONFIG_ISHCT_SHIFT)

/* Operating mode */

#define INA260_CONFIG_MODE_SHIFT   0
#define INA260_CONFIG_MODE_MASK    (7 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_PWRDOWN (0 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_STRIG   (1 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_BTRIG   (2 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_SBTRIG  (3 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_SCONT   (5 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_BCONT   (6 << INA260_CONFIG_MODE_SHIFT)
#define INA260_CONFIG_MODE_SBCONT  (7 << INA260_CONFIG_MODE_SHIFT)

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct i2c_master_s;

struct ina260_s
{
  uint32_t voltage;  /* FS range: 40.96V; LSB: 1.25mV; Device max: 36V. */
  int32_t  current;  /* [microampere] max 2.1 kA - sensor is bidirectional */
  uint32_t power;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: ina260_register
 *
 * Description:
 *   Register the INA260 character device as 'devpath'
 *
 * Input Parameters:
 *   devpath - The full path to the driver to register. E.g., "/dev/pwrmntr0"
 *   i2c - An instance of the I2C interface to use to communicate with INA260
 *   addr - The I2C address of the INA260.
 *   shuntval - resistor value in microohms
 *   config - a combination of the constants defined earlier in this file.
 *
 * Returned Value:
 *   Zero (OK) on success; a negated errno value on failure.
 *
 ****************************************************************************/

int ina260_register(FAR const char *devpath, FAR struct i2c_master_s *i2c,
                    uint8_t addr, uint16_t config);

#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif /* CONFIG_I2C && CONFIG_SENSORS_INA260 */
#endif /* __INCLUDE_NUTTX_SENSORS_INA260_H */
