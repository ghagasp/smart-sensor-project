################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Mainxx.lss \

FLASH_IMAGE += \
Mainxx.hex \

EEPROM_IMAGE += \
Mainxx.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Mainxx.elf secondary-outputs

# Tool invocations
Mainxx.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Mainxx.map -mmcu=atmega328 -o "Mainxx.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Mainxx.lss: Mainxx.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Mainxx.elf  >"Mainxx.lss"
	@echo 'Finished building: $@'
	@echo ' '

Mainxx.hex: Mainxx.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Mainxx.elf  "Mainxx.hex"
	@echo 'Finished building: $@'
	@echo ' '

Mainxx.eep: Mainxx.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Mainxx.elf  "Mainxx.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Mainxx.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t Mainxx.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Mainxx.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
