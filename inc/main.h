#ifndef MAIN_H
#define MAIN_H

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include <string.h>
#include "i2c.h"
#include "usart.h"
#include "timer.h"
#include "gpio.h"
#include "lcd_driver.h"



UART_HandleTypeDef huart6;
UART_HandleTypeDef huart1;
GPIO_InitTypeDef bluetooth_config;
I2C_HandleTypeDef hi2c1;
GPIO_InitTypeDef i2c_pin_config;
TIM_HandleTypeDef HH10D_PWM;
TIM_ClockConfigTypeDef sClockSourceConfig;
TIM_MasterConfigTypeDef sMasterConfig;
TIM_HandleTypeDef TEMP_AND_RH;
TIM_HandleTypeDef DATE_AND_TIME;




#endif /* MAIN_H */
