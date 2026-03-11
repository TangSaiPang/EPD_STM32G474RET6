#ifndef __BSP_BUTTON_H
#define __BSP_BUTTON_H

#include "stm32g4xx.h"

#define B1_GPIO_Port  GPIOC
#define B1_Pin        GPIO_PIN_13

void BUTTON_GPIO_Init(void);

#endif
