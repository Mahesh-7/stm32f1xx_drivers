/*
 * hello_world.c
 *
 *  Created on: Oct 31, 2020
 *      Author: user
 */


/*
 * main.c
 *
 *  Created on: Oct 19, 2020
 *      Author: user
 */


#include "stm32f103xx.h"
#include <stdio.h>

#include "FreeRTOS.h"

#include "task.h"



extern void initialise_monitor_handles(void);

TaskHandle_t xTaskHandle1=0;
TaskHandle_t xTaskHandle2=0;

void vTask1_Handler(void * param);
void vTask2_Handler(void * param);

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

	initialise_monitor_handles(); //openocd semihosting enable only for debugging ,for normal test command this line

	xTaskCreate(vTask1_Handler,"task1",configMINIMAL_STACK_SIZE,0,2,&xTaskHandle1);

	xTaskCreate(vTask2_Handler,"task2",configMINIMAL_STACK_SIZE,0,2,&xTaskHandle2);

	//vTaskStartScheduler();

	for(;;);

	return 0;
}

void vTask1_Handler(void * param)
{
	//while(1);
	printf("task1 running\n");
}

void vTask2_Handler(void * param)
{
	//while(1);
	printf("task2 running\n");
}

