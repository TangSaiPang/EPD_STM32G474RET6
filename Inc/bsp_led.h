#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32g4xx.h"

#define LED1_GPIO_Port  GPIOA
#define LED1_Pin        GPIO_PIN_5

#define LED1_ON()       HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED1_OFF()      HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
#define LED1_TOGGLE()   HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)

void LED_GPIO_Init(void);
void LED_Flash(void);

#endif
