/**
 * Copyright (c) 2021 Joel Spadin
 *
 * SPDX-License-Identifier: MIT
 */

#include <kernel.h>
#include <init.h>
#include <hal/nrf_power.h>

static int board_numble_init(const struct device *dev)
{
    ARG_UNUSED(dev);

    const uint32_t key = irq_lock();

    // Enable DC/DC regulator for REG0 stage.
    // Default REGOUT0 is 1.8V, so no need to change that.
    nrf_power_dcdcen_vddh_set(NRF_POWER, true);

    irq_unlock(key);

    return 0;
}

SYS_INIT(board_numble_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
