################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include TIMER_DRV/subdir.mk
-include SevenSegment/subdir.mk
-include LCD_DRV/subdir.mk
-include KPD_Drv/subdir.mk
-include DIO_DRV/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
safety_box.lss \

FLASH_IMAGE += \
safety_box.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: safety_box.elf secondary-outputs

# Tool invocations
safety_box.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,safety_box.map -mmcu=atmega32 -o "safety_box.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

safety_box.lss: safety_box.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S safety_box.elf  >"safety_box.lss"
	@echo 'Finished building: $@'
	@echo ' '

safety_box.hex: safety_box.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex safety_box.elf  "safety_box.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: safety_box.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 safety_box.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) safety_box.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
