#include "bsp_led.h"

void LED_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : LED1_Pin */
    GPIO_InitStruct.Pin = LED1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

}

void LED_Flash(void)
{
	LED1_ON();
	HAL_Delay(500);
	LED1_OFF();
	HAL_Delay(500);
}
