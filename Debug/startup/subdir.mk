################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_LCD_Libraries/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_LCD_Libraries/inc" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_LCD_Libraries/CMSIS/device" -I"C:/Users/hvrsh/OneDrive/Desktop/FreeRTOS Workspace/STM32_LCD_Libraries/CMSIS/core" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


