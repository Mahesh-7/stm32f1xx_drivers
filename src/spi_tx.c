/*
 * spi_tx.c
 *
 *  Created on: Nov 2, 2020
 *      Author: user
 */



#include<string.h>

#include "stm32f103xx.h"

/*
 *
 * PB14 --> SPI2_MISO
 * PB15 --> SPI2_MOSI
 * PB13 -> SPI2_SCLK
 * PB12 --> SPI2_NSS

 */
/*
 *
 * PA4 --> SPI1_NSS
 * PA5 -->SPI1_SCLK
 * PA6 ->  SPI1_MISO
 * PA7 --> SPI1_MOSI

 */

void SPI1_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig.PinMode =GPIO_MODE_OUT_50mhz;
	SPIPins.GPIO_PinConfig.PinType = ALTER_FUN_PP;


	//SCLK
	SPIPins.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_5;
	GPIO_Init(&SPIPins);

	//MOSI
	SPIPins.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_7;
	GPIO_Init(&SPIPins);

	//MISO
	//SPIPins.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_6;
	//GPIO_Init(&SPIPins);


	//NSS
	//SPIPins.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_4;
	//GPIO_Init(&SPIPins);


}

void SPI1_Inits(void)
{

	SPI_Handle_t SPI1handle;

	SPI1handle.pSPIx = SPI1;
	SPI1handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI1handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI1handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;//generates sclk of 1MHz
	SPI1handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI1handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI1handle.SPIConfig.SPI_SSM = SPI_SSM_EN; //software slave management enabled for NSS pin

	SPI_Init(&SPI1handle);
}

int main(void)
{

#if 1
	char user_data[] = "Hello world";

	//this function is used to initialize the GPIO pins to behave as SPI2 pins
	SPI1_GPIOInits();

	//This function is used to initialize the SPI2 peripheral parameters
	SPI1_Inits();

	//this makes NSS signal internally high and avoids MODF error
	SPI_SSIConfig(SPI1,ENABLE);

	//enable the SPI peripheral
	SPI_PeripheralControl(SPI1,ENABLE);

	//to send data
	SPI_SendData(SPI1,(uint8_t*)user_data,strlen(user_data));

	//lets confirm SPI is not busy
	while( SPI_GetFlagStatus(SPI1,SPI_BUSY_FLAG) );

	//Disable the SPI2 peripheral
	SPI_PeripheralControl(SPI1,DISABLE);

	while(1);

#endif

	return 0;

}


