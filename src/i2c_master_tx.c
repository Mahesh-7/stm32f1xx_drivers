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


#if 1

	GPIO_PeriClockControl(GPIOB, ENABLE);//portb clk enable
	I2C_PeriClockControl(I2C1,ENABLE); //i2c clk enable

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



#endif


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


int main(void)
{

	//GPIO_ButtonInit();

	//i2c pin inits
	I2C1_GPIOInits();

	//i2c peripheral configuration
	I2C1_Inits();

	//enable the i2c peripheral
	I2C_PeripheralControl(I2C1,ENABLE);

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
