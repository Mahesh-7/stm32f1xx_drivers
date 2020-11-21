/*
 * stm32f103xx.h
 *
 *  Created on: Oct 19, 2020
 *      Author: user
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include <stdint.h>

#define __vo volatile


/*
 * base address of flash and SRAM memory
 */

#define FLASH_BASEADDR				0X80000000U							/*BASE ADDRESS OF FLASH MEMORY	*/
#define SRAM1_BASEADDR				0X20000000U							/*BASE ADDRESS OF SRAM1 MEMORY	*/
#define SRAM						SRAM1_BASEADDR						/*BASE ADDRESS OF SRAM MEMORY	*/
#define ROM_BASEADDR				0X1FFFE000U							/*BASE ADDRESS OF ROM MEMORY	*/

/*
 *  AHBx and APBx peripheral bus base address
 */


#define PERIPH_BASEADDR				0x40000000U							/*BASE ADDRESS OF PERIPHERAL      */
#define APB1PERIPH_BASEADDR			PERIPH_BASEADDR						/*BASE ADDRESS OF APB1 PERIPHERAL */
#define APB2PERIPH_BASEADDR			(PERIPH_BASEADDR+0X10000U)			/*BASE ADDRESS OF APB1 PERIPHERAL */
#define AHBPERIPH_BASEADDR			(PERIPH_BASEADDR+0X18000U)			/*BASE ADDRESS OF AHB PERIPHERAL  */

/*
 *  RCC,GPIOx,SPI base address
 */

#define RCC_BASEADDR			(PERIPH_BASEADDR+0X21000U)					/*BASE ADDRESS OF RCC */
#define GPIOA_BASEADDR			(APB2PERIPH_BASEADDR+0X0800U)				/*BASE ADDRESS OF GPIOA */
#define GPIOB_BASEADDR			(APB2PERIPH_BASEADDR+0X0C00U)				/*BASE ADDRESS OF GPIOB */
#define GPIOC_BASEADDR			(APB2PERIPH_BASEADDR+0X1000U)				/*BASE ADDRESS OF GPIOC */
#define GPIOD_BASEADDR			(APB2PERIPH_BASEADDR+0X1400U)				/*BASE ADDRESS OF GPIOD */
#define GPIOE_BASEADDR			(APB2PERIPH_BASEADDR+0X1800U)				/*BASE ADDRESS OF GPIOE */
#define GPIOF_BASEADDR			(APB2PERIPH_BASEADDR+0X1C00U)				/*BASE ADDRESS OF GPIOF */
#define GPIOG_BASEADDR			(APB2PERIPH_BASEADDR+0X2000U)				/*BASE ADDRESS OF GPIOG */
#define SPI_BASEADDR			(APB2PERIPH_BASEADDR+0X3000U)				/*BASE ADDRESS OF SPI */

//spi 0x4001 3000
/*
 * peripheral reg definition structure for RCC CLK Configuration
 */

typedef struct
{

	__vo uint32_t CR;       	 /* 	 Clock control register							address offset:0x000 */
	__vo uint32_t CFGR;			 /* 	 Clock configuration register 					address offset:0x004 */
	__vo uint32_t CIR;		 	 /* 	 Clock interrupt register  						address offset:0x008 */
	__vo uint32_t APB2RSTR;		 /* 	 APB2 peripheral reset register  				address offset:0x00c */
	__vo uint32_t APB1RSTR;		 /* 	 APB1 peripheral reset register					address offset:0x010 */
	__vo uint32_t AHBENR;		 /* 	 AHB Peripheral Clock enable register 			address offset:0x014 */
	__vo uint32_t APB2ENR;		 /* 	 APB2 peripheral clock enable register  		address offset:0x018 */
	__vo uint32_t APB1ENR;		 /* 	 APB1 peripheral clock enable register			address offset:0x01c */
	__vo uint32_t BDCR;			 /* 	 Backup domain control register 				address offset:0x020 */
	__vo uint32_t CSR;			 /* 	 Control/status register   						address offset:0x024 */
	__vo uint32_t AHBSTR;		 /* 	 AHB peripheral clock reset register  			address offset:0x028 */
	__vo uint32_t CFGR2;		 /* 	 Clock configuration register2  				address offset:0x02C */

}RCC_RegDef_t;



/*
 * peripheral reg definition structure for gpio
 */

typedef struct
{

	__vo uint32_t CRL;        /* 	 Port configuration register low				address offset:0x00 */
	__vo uint32_t CRH;		 /* 	 Port configuration register high 				address offset:0x04 */
	__vo uint32_t IDR;		 /* 	 Port input data register 						address offset:0x08 */
	__vo uint32_t ODR;		 /* 	 Port output data register 						address offset:0x0c */

}GPIO_RegDef_t;




/*
 * peripheral reg definition structure for SPI
 */

typedef struct
{

	__vo uint32_t CR1;       	 /* 	 SPI control register 1							address offset:0x00 */
	__vo uint32_t CR2;			 /* 	 SPI control register 2  						address offset:0x04 */
	__vo uint32_t SR;		 	 /* 	 SPI status register  							address offset:0x08 */
	__vo uint32_t DR;			 /* 	 SPI data register  							address offset:0x0c */
	__vo uint32_t CRCPR;		 /* 	 SPI CRC polynomial register					address offset:0x10 */
	__vo uint32_t RXCRCR;		 /* 	 SPI RX CRC register 							address offset:0x14 */
	__vo uint32_t TXCRCR;		 /* 	 SPI TX CRC register  							address offset:0x18 */
	__vo uint32_t I2SCFGR;		 /* 	 SPI_I2S configuration register					address offset:0x1c */
	__vo uint32_t I2SPR;		 /* 	 SPI_I2S prescaler register 					address offset:0x20 */

}SPI_RegDef_t;




/*
 * peripheral definition macros
 */

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)						/* macro def for rcc peripheral addr */
#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)					/* macro def for gpioa peripheral addr */
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)					/* macro def for gpiob peripheral addr */
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)					/* macro def for gpioc peripheral addr */
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)					/* macro def for gpiod peripheral addr */
#define SPI 				((SPI_RegDef_t*)SPI_BASEADDR)						/* macro def for SPI peripheral addr */



/*
 * clock disable macro for gpio peripheral
 */


#define GPIOA_PCLK_DI()		(RCC->APB2ENR &= ~(1<<2))
#define GPIOB_PCLK_DI()		(RCC->APB2ENR &= ~(1<<3))
#define GPIOC_PCLK_DI()		(RCC->APB2ENR &= ~(1<<4))
#define GPIOD_PCLK_DI()		(RCC->APB2ENR &= ~(1<<5))


/*
 * clock enable macro for gpio peripheral
 */


#define GPIOA_PCLK_EN()		(RCC->APB2ENR |= (1<<2))
#define GPIOB_PCLK_EN()		(RCC->APB2ENR |= (1<<3))
#define GPIOC_PCLK_EN()		(RCC->APB2ENR |= (1<<4))
#define GPIOD_PCLK_EN()		(RCC->APB2ENR |= (1<<5))

/*
 * Clock Enable Macros for SPIx peripheralsbu
 */
#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))


/******************************************************************************************
 *Bit position definitions of SPI peripheral
 ******************************************************************************************/
/*
 * Bit position definitions SPI_CR1
 */
#define SPI_CR1_CPHA     				 0
#define SPI_CR1_CPOL      				 1
#define SPI_CR1_MSTR     				 2
#define SPI_CR1_BR   					 3
#define SPI_CR1_SPE     				 6
#define SPI_CR1_LSBFIRST   			 	 7
#define SPI_CR1_SSI     				 8
#define SPI_CR1_SSM      				 9
#define SPI_CR1_RXONLY      		 	10
#define SPI_CR1_DFF     			 	11
#define SPI_CR1_CRCNEXT   			 	12
#define SPI_CR1_CRCEN   			 	13
#define SPI_CR1_BIDIOE     			 	14
#define SPI_CR1_BIDIMODE      			15

/*
 * Bit position definitions SPI_CR2
 */
#define SPI_CR2_RXDMAEN		 			0
#define SPI_CR2_TXDMAEN				 	1
#define SPI_CR2_SSOE				 	2
#define SPI_CR2_ERRIE					5
#define SPI_CR2_RXNEIE				 	6
#define SPI_CR2_TXEIE					7


/*
 * Bit position definitions SPI_SR
 */
#define SPI_SR_RXNE						0
#define SPI_SR_TXE				 		1
#define SPI_SR_CHSIDE				 	2
#define SPI_SR_UDR					 	3
#define SPI_SR_CRCERR				 	4
#define SPI_SR_MODF					 	5
#define SPI_SR_OVR					 	6
#define SPI_SR_BSY					 	7



//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET          RESET
#define FLAG_SET 			SET


#include "stm32f103xx_gpio_driver.h"
#include "stm32f103xx_spi_driver.h"

#endif /* INC_STM32F103XX_H_ */
