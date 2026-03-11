#include "bsp_button.h"
#include "bsp_led.h"
//#include "usart.h"
#include "tim.h"

void BUTTON_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*Configure GPIO pin : B1_Pin */
    GPIO_InitStruct.Pin = B1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

    /* EXTI interrupt init*/
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == B1_Pin)
	{
//		HAL_UART_Transmit(&huart3, (uint8_t *)"z", 1, 100);
//		LED1_TOGGLE();
//		HAL_TIM_Base_Stop_IT(&htim6);
//		HAL_TIM_PWM_Stop_IT(&htim8, TIM_CHANNEL_1);
//		HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
		LED1_TOGGLE();
	}
}

