#include "timer.h"

void MX_TIMER_init(void) {

	__HAL_RCC_TIM1_CLK_ENABLE()
	;
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	__HAL_RCC_TIM3_CLK_ENABLE()
	;
	__HAL_RCC_TIM4_CLK_ENABLE()
	;

	HH10D_PWM.Instance = TIM2;
	HH10D_PWM.Init.Period = 3333;
	HH10D_PWM.Init.Prescaler = 32400;
	HH10D_PWM.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HH10D_PWM.Init.CounterMode = TIM_COUNTERMODE_UP;

	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

	HAL_TIM_Base_Init(&HH10D_PWM);

	TEMP_AND_RH.Instance = TIM3;
	TEMP_AND_RH.Init.Period = 13332;
	TEMP_AND_RH.Init.Prescaler = 32400 - 1;
	TEMP_AND_RH.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TEMP_AND_RH.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_NVIC_SetPriority(TIM3_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
	HAL_TIM_Base_Init(&TEMP_AND_RH);

	DATE_AND_TIME.Instance = TIM4;
	DATE_AND_TIME.Init.Period = 3333;
	DATE_AND_TIME.Init.Prescaler = 32400 - 1;
	DATE_AND_TIME.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	DATE_AND_TIME.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_NVIC_SetPriority(TIM4_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
	HAL_TIM_Base_Init(&DATE_AND_TIME);

}
