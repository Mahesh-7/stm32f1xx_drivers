/*
 * uart_tx.c
 *
 *  Created on: Nov 28, 2020
 *      Author: user
 */


#include<stdio.h>
#include<string.h>

#include "stm32f103xx.h"

char msg[1024] = "UART Tx testing...\n\r";

USART_Handle_t usart1_handle;

void USART1_Init(void)
{
	usart1_handle.pUSARTx = USART1;
	usart1_handle.USART_Config.USART_Baud = USART_STD_BAUD_9600;
	usart1_handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	usart1_handle.USART_Config.USART_Mode = USART_MODE_ONLY_TX;
	usart1_handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	usart1_handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;
	usart1_handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	USART_Init(&usart1_handle);
}

void USART1_GPIOInit(void)
{
	GPIO_Handle_t usart_gpios;

	usart_gpios.pGPIOx = GPIOA;
	usart_gpios.GPIO_PinConfig.PinMode = GPIO_MODE_OUT_50mhz;
	usart_gpios.GPIO_PinConfig.PinType = ALTER_FUN_PP;

	//USART1 TX
	usart_gpios.GPIO_PinConfig.PinNumber  = GPIO_PIN_NO_9;
	GPIO_Init(&usart_gpios);

	usart_gpios.GPIO_PinConfig.PinMode = GPIO_MODE_IN;
	usart_gpios.GPIO_PinConfig.PinType = INPUT_FLOATING;

	//USART1 RX
	usart_gpios.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_10;
	GPIO_Init(&usart_gpios);


}

void GPIO_ButtonInit(void)
{
	GPIO_Handle_t GPIOBtn,GpioLed;

	//this is btn gpio configuration
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.PinType = INPUT_FLOATING;

	GPIO_Init(&GPIOBtn);

	//this is led gpio configuration
	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.PinMode = GPIO_MODE_OUT_50mhz;
	GpioLed.GPIO_PinConfig.PinType = GPIO_OP_TYPE_PP;


	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLed);

}

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}


int main(void)
{

	GPIO_ButtonInit();

	USART1_GPIOInit();

    USART1_Init();

    USART_PeripheralControl(USART1,ENABLE);

    USART_SendData(&usart1_handle,(uint8_t*)msg,strlen(msg));

    while(1)
    {
		//wait till button is pressed
    	//while( ! GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) );

		//to avoid button de-bouncing related issues 200ms of delay
		//delay();

    }

	return 0;
}

