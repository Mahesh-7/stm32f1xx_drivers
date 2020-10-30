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
 *  GPIOx base address
 */


#define GPIOA_BASEADDR			(APB2PERIPH_BASEADDR+0X0800U)				/*BASE ADDRESS OF GPIOA */
#define GPIOB_BASEADDR			(APB2PERIPH_BASEADDR+0X0C00U)				/*BASE ADDRESS OF GPIOB */
#define GPIOC_BASEADDR			(APB2PERIPH_BASEADDR+0X1000U)				/*BASE ADDRESS OF GPIOC */
#define GPIOD_BASEADDR			(APB2PERIPH_BASEADDR+0X1400U)				/*BASE ADDRESS OF GPIOD */
#define GPIOE_BASEADDR			(APB2PERIPH_BASEADDR+0X1800U)				/*BASE ADDRESS OF GPIOE */
#define GPIOF_BASEADDR			(APB2PERIPH_BASEADDR+0X1C00U)				/*BASE ADDRESS OF GPIOF */
#define GPIOG_BASEADDR			(APB2PERIPH_BASEADDR+0X2000U)				/*BASE ADDRESS OF GPIOG */
#define RCC_BASEADDR			(PERIPH_BASEADDR+0X21000U)					/*BASE ADDRESS OF RCC */
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
 * peripheral clk definition structure for RCC
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
 * peripheral definition macros
 */

#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)					/* macro def for gpioa peripheral addr */
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)					/* macro def for gpiob peripheral addr */
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)					/* macro def for gpioc peripheral addr */
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)					/* macro def for gpiod peripheral addr */
#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)						/* macro def for rcc peripheral addr */




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

#endif /* INC_STM32F103XX_H_ */
