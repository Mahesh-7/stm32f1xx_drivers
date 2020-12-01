/*
 * i2c_master_tx.c
 *
 *  Created on: Nov 23, 2020
 *      Author: user
 */


#include "stm32f103xx.h"
#include<stdio.h>
#include<string.h>



#define MY_ADDR 0x61;

#define SLAVE_ADDR  0xA0

void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}

void delay1(void)
{
	unsigned int i,j;

	for (i=0; i<1000; i++)
	{
		for (j=0; j<100; j++);  //5000
	}
}

I2C_Handle_t I2C1Handle;

//some data
uint8_t some_data[] = "We are testing I2C master Tx\n";
/*
 * PB6-> SCL
 * PB7 -> SDA
 */

void I2C1_GPIOInits(void)
{
	GPIO_Handle_t I2CPins;

	I2CPins.pGPIOx = GPIOB;
	I2CPins.GPIO_PinConfig.PinMode = GPIO_MODE_OUT_50mhz;
	I2CPins.GPIO_PinConfig.PinType = ALTER_FUN_OD;

	//scl
	I2CPins.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_6;
	GPIO_Init(&I2CPins);


	//sda
	I2CPins.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_7;
	GPIO_Init(&I2CPins);


}

void I2C1_Inits(void)
{
	I2C1Handle.pI2Cx = I2C1;
	I2C1Handle.I2C_Config.I2C_AckControl = I2C_ACK_ENABLE;
	I2C1Handle.I2C_Config.I2C_DeviceAddress = MY_ADDR;
	I2C1Handle.I2C_Config.I2C_FMDutyCycle = I2C_FM_DUTY_2;
	I2C1Handle.I2C_Config.I2C_SCLSpeed = I2C_SCL_SPEED_SM;
	I2C_Init(&I2C1Handle);

}

void GPIO_ButtonInit(void)
{
#if 0
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
	GpioLed.GPIO_PinConfig.PinMode =  GPIO_MODE_OUT_50mhz;
	GpioLed.GPIO_PinConfig.PinType = GPIO_OP_TYPE_PP ;


	GPIO_Init(&GpioLed);
#endif
}


void i2c_gpio_init(void)
{
	//i2c and port clk enable
	RCC->APB1ENR &= 0x00000000;
	RCC->APB2ENR &= 0x00000000;

	RCC->APB1ENR |= (1<<21); //enable i2c clk
	RCC->APB2ENR |= (1<<3);  //enable portb clk
	//RCC->APB2ENR |=(1<<0);  //alternate function clk enable

	GPIOB->CRL &=0x00000000;

	//scl
	GPIOB->CRL |= (3<<24);  //pb6-output
	GPIOB->CRL |= (3<<26);  //pb6-alterante open drain

	//sda
	GPIOB->CRL |= (3<<28);  //pb7-output
	GPIOB->CRL |= (3<<30);  //pb7-alterante open drain

}



void i2c_init(void)
{
	//i2c master mode
	I2C1->CR1 &=0x0000;
	I2C1->CR2 &=0x0000;

	I2C1->CR1 |= (1<<10);  //ack enable

	I2C1->CR2 |= 8<<0;  //freq :8mhz

	I2C1->CCR =0x28;  //100khz

	I2C1->TRISE &=0x0000;
	I2C1->TRISE |=9;  //scal rise time config

	I2C1->CR1 |= (1<<0); //i2c peripheral enable
}

int main(void)
{

	i2c_gpio_init();

	//GPIO_ButtonInit();

	//i2c pin inits
	//I2C1_GPIOInits();

	//i2c peripheral configuration
	//I2C1_Inits();

	i2c_init();

	//enable the i2c peripheral
	//I2C_PeripheralControl(I2C1,ENABLE);

	I2C_MasterSendData(&I2C1Handle,some_data,strlen((char*)some_data),SLAVE_ADDR,I2C_ENABLE_SR);

	while(1)
	{
		//wait till button is pressed
		//while( ! GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0) );
		//GPIO_ToggleOutputPin(GPIOC,GPIO_PIN_NO_13);
		//to avoid button de-bouncing related issues 200ms of delay
		//delay();

		//send some data to the slave

	}

}
