################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include LCD16x2/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32_LCD_Libraries.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32_LCD_Libraries.list \

OBJCOPY_BIN += \
STM32_LCD_Libraries.bin \


# All Target
all: STM32_LCD_Libraries.elf secondary-outputs

# Tool invocations
STM32_LCD_Libraries.elf: $(OBJS) $(USER_OBJS) C:\Users\hvrsh\Documents\MY_FILES\STM32_Projects\GIT_PROJECTS\STM32_LCD16x2_interface\LinkerScript.ld
	arm-none-eabi-gcc -o "STM32_LCD_Libraries.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\hvrsh\Documents\MY_FILES\STM32_Projects\GIT_PROJECTS\STM32_LCD16x2_interface\LinkerScript.ld" --specs=nosys.specs -Wl,-Map="STM32_LCD_Libraries.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32_LCD_Libraries.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32_LCD_Libraries.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32_LCD_Libraries.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32_LCD_Libraries.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
