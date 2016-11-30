/** @addtogroup rcc_defines
 *
 * @author @htmlonly &copy; @endhtmlonly 2013
 * Frantisek Burian <BuFran@seznam.cz>
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2013 Frantisek Burian <BuFran@seznam.cz>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/* THIS FILE SHOULD NOT BE INCLUDED DIRECTLY, BUT ONLY VIA RCC.H
 * The order of header inclusion is important. rcc.h defines the device
 * specific enumerations before including this header file.
 */

/** @cond */
#ifdef LIBOPENCM3_RCC_H
/** @endcond */

#ifndef LIBOPENCM3_RCC_COMMON_ALL_H
#define LIBOPENCM3_RCC_COMMON_ALL_H

/**@{*/

BEGIN_DECLS

void rcc_peripheral_enable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_disable_clock(volatile uint32_t *reg, uint32_t en);
void rcc_peripheral_reset(volatile uint32_t *reg, uint32_t reset);
void rcc_peripheral_clear_reset(volatile uint32_t *reg, uint32_t clear_reset);

/** @brief Enable Peripheral Clock in running mode.
 *
 * Enable the clock on particular peripheral.
 *
 * @param[in] clken rcc_periph_clken Peripheral RCC
 *
 * For available constants, see #rcc_periph_clken (RCC_UART1 for example)
 */
static inline
void rcc_periph_clock_enable(enum rcc_periph_clken clken)
{
	_RCC_REG(clken) |= _RCC_BIT(clken);
}

/** @brief Disable Peripheral Clock in running mode.
 * Disable the clock on particular peripheral.
 *
 * @param[in] clken rcc_periph_clken Peripheral RCC
 *
 * For available constants, see #rcc_periph_clken (RCC_UART1 for example)
 */
static inline
void rcc_periph_clock_disable(enum rcc_periph_clken clken)
{
	_RCC_REG(clken) &= ~_RCC_BIT(clken);
}

void rcc_periph_reset_pulse(enum rcc_periph_rst rst);
void rcc_periph_reset_hold(enum rcc_periph_rst rst);
void rcc_periph_reset_release(enum rcc_periph_rst rst);

void rcc_set_mco(uint32_t mcosrc);

/**
 * Is the given oscillator ready?
 * @param osc Oscillator ID
 * @return true if the hardware indicates the oscillator is ready.
 */
bool rcc_is_osc_ready(enum rcc_osc osc);

/**
 * Wait for Oscillator Ready.
 * Block until the hardware indicates that the Oscillator is ready.
 * @param osc Oscillator ID
 */
void rcc_wait_for_osc_ready(enum rcc_osc osc);

END_DECLS
/**@}*/

#endif
/** @cond */
#else
#warning "rcc_common_all.h should not be included explicitly, only via rcc.h"
#endif
/** @endcond */

