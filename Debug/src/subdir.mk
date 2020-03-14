################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.o: ../src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -c -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/LCD16x2/LCD_Includes" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/device" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/core" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/syscalls.o: ../src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -c -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/LCD16x2/LCD_Includes" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/device" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/core" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
src/system_stm32f4xx.o: ../src/system_stm32f4xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -c -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/StdPeriph_Driver/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/LCD16x2/LCD_Includes" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/inc" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/device" -I"C:/Users/hvrsh/Documents/MY_FILES/STM32_Projects/GIT_PROJECTS/STM32_LCD16x2_interface/CMSIS/core" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

