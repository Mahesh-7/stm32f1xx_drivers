################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

C_SRCS += \
../startup/sysmem.c 

OBJS += \
./startup/startup_stm32.o \
./startup/sysmem.o 

C_DEPS += \
./startup/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -I"C:/Users/user.user-PC/Desktop/cubemx_code/ecllipse/stm32f1x_drivers/drivers/inc" -I"C:/Users/user.user-PC/Desktop/cubemx_code/ecllipse/stm32f1x_drivers/Free_RTOS_Config" -I"C:/Users/user.user-PC/Desktop/cubemx_code/ecllipse/stm32f1x_drivers/Free_RTOS/Source/include" -I"C:/Users/user.user-PC/Desktop/cubemx_code/ecllipse/stm32f1x_drivers/Free_RTOS/Source/portable/GCC/ARM_CM3" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


