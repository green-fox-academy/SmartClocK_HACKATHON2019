#ifndef MAIN_H
#define MAIN_H

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include <string.h>


UART_HandleTypeDef huart6;
UART_HandleTypeDef huart1;
GPIO_InitTypeDef bluetooth_config;
I2C_HandleTypeDef hi2c1;
GPIO_InitTypeDef i2c_pin_config;





#endif /* MAIN_H */
