#ifndef DWT_DELAY_H
#define DWT_DELAY_H

#include "stm32f1xx_hal.h"

uint32_t DWT_Scale = (HAL_RCC_GetHCLKFreq() / 1000000); // Do this ONCE
#define DWT_Fudge 1 // Likely mostly unnecessary, tuning value to account for call and computation overhead

__STATIC_INLINE void DWT_Delay_us(uint32_t microseconds)
{
	uint32_t clk_cycle_start = DWT->CYCCNT;
	uint32_t ticks = (microseconds * DWT_Scale) - DWT_Fudge; /* Go to number of cycles for system */
	while ((DWT->CYCCNT - clk_cycle_start) < ticks); /* Delay till end */
}

#endif //DWT_DELAY_H
