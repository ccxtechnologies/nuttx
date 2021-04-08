/****************************************************************************
 * boards/arm/imxrt/imxrt1064-evk/src/imxrt_ethernet.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/* Force verbose debug on in this file only to support unit-level testing. */

#ifdef CONFIG_NETDEV_PHY_DEBUG
#  undef  CONFIG_DEBUG_INFO
#  define CONFIG_DEBUG_INFO 1
#  undef  CONFIG_DEBUG_NET
#  define CONFIG_DEBUG_NET 1
#endif

#include <string.h>
#include <assert.h>
#include <errno.h>
#include <debug.h>

#include <nuttx/irq.h>
#include <nuttx/arch.h>

#include "imxrt_gpio.h"
#include "imxrt_enet.h"

#include "ccx.h"

#ifdef CONFIG_IMXRT_ENET

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define IMXRT_ENET1_DEVNAME "eth0"
#define IMXRT_ENET2_DEVNAME "eth1"

/* Debug ********************************************************************/

/* Extra, in-depth debug output that is only available if
 * CONFIG_NETDEV_PHY_DEBUG us defined.
 */

#ifdef CONFIG_NETDEV_PHY_DEBUG
#  define phyerr    _err
#  define phywarn   _warn
#  define phyinfo   _info
#else
#  define phyerr(x...)
#  define phywarn(x...)
#  define phyinfo(x...)
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function: imxrt_phy_boardinitialize
 *
 * Description:
 *   Some boards require specialized initialization of the PHY before it can
 *   be used.  This may include such things as configuring GPIOs, resetting
 *   the PHY, etc.
 *   If CONFIG_IMXRT_ENET_PHYINIT is defined in the configuration then the
 *   board specific logic must provide imxrt_phyinitialize();
 *   The i.MX RT Ethernet driver will call this function one time before it
 *   first uses the PHY.
 *
 * Input Parameters:
 *   intf - Always zero for now.
 *
 * Returned Value:
 *   OK on success; Negated errno on failure.
 *
 ****************************************************************************/

int imxrt_phy_boardinitialize(int intf)
{

  /* Configure the PHY reset pin.
   *
   * The #RST uses inverted logic.  The initial value of zero will put the
   * PHY into the reset state.
   */

  phyinfo("Configuring reset: %08x\n", GPIO_ENET_RST);
  imxrt_config_gpio(GPIO_ENET_RST);

  /* Take the PHY out of reset. */

  imxrt_gpio_write(GPIO_ENET_RST, true);
  return OK;
}

int arch_phy_irq(FAR const char *intf, xcpt_t handler, void *arg,
                 phy_enable_t *enable)
{
  DEBUGASSERT(intf);

  ninfo("%s: handler=%p\n", intf, handler);
  phyinfo("EMAC: devname=%s\n", intf == 1 ? IMXRT_ENET1_DEVNAME : IMXRT_ENET2_DEVNAME);

  if (handler == NULL)
    {
      return OK;
    }
  else
    {
      //throw error
      nerr("ERROR: Unsupported interface: %s\n", intf);
      return -EINVAL;
    }
}

#endif /* CONFIG_IMXRT_ENET */
