/*
 * Copyright (c) 2018 qianfan Zhao
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/pinmux.h>
#include <sys/sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* pin assignments for NUCLEO-F207ZG board */
static const struct pin_config pinconf[] = {
#if DT_NODE_HAS_STATUS(DT_NODELABEL(mac), okay) && CONFIG_NET_L2_ETHERNET
	{STM32_PIN_PC1, STM32F2_PINMUX_FUNC_PC1_ETH},
	{STM32_PIN_PC4, STM32F2_PINMUX_FUNC_PC4_ETH},
	{STM32_PIN_PC5, STM32F2_PINMUX_FUNC_PC5_ETH},

	{STM32_PIN_PA1, STM32F2_PINMUX_FUNC_PA1_ETH},
	{STM32_PIN_PA2, STM32F2_PINMUX_FUNC_PA2_ETH},
	{STM32_PIN_PA7, STM32F2_PINMUX_FUNC_PA7_ETH},

	{STM32_PIN_PG11, STM32F2_PINMUX_FUNC_PG11_ETH},
	{STM32_PIN_PG13, STM32F2_PINMUX_FUNC_PG13_ETH},
	{STM32_PIN_PB13, STM32F2_PINMUX_FUNC_PB13_ETH},
#endif
#ifdef CONFIG_USB_DC_STM32
	{STM32_PIN_PA11, STM32F2_PINMUX_FUNC_PA11_OTG_FS_DM},
	{STM32_PIN_PA12, STM32F2_PINMUX_FUNC_PA12_OTG_FS_DP},
#endif	/* CONFIG_USB_DC_STM32 */
};

static int pinmux_stm32_init(const struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
		CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
