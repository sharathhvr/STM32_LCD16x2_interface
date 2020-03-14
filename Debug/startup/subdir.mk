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
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/LCD16x2/LCD_Includes" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/device" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/core" -x assembler-with-cpp --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

