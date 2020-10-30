/*
 * main.c
 *
 *  Created on: Oct 19, 2020
 *      Author: user
 */


#include "stm32f103xx.h"
#include <stdio.h>

void delay(void)
{
	unsigned int i,j;

	for (i=0; i<1000; i++)
	{
		for (j=0; j<100; j++);  //5000
	}
}

int main()
{


	GPIO_Handle_t led;

	led.pGPIOx = GPIOC;
	led.GPIO_PinConfig.PinNumber=GPIO_PIN_NO_13 ;
	led.GPIO_PinConfig.PinMode=GPIO_MODE_OUT_10mhz;
	led.GPIO_PinConfig.pinType=GPIO_OP_TYPE_PP;

	GPIO_Init(&led);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOC,GPIO_PIN_NO_13);

		delay();
	}

	return 0;
}

