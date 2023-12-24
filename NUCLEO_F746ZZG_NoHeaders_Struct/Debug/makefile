################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := NUCLEO_F746ZG2_Struct
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
NUCLEO_F746ZG2_Struct.elf \

MAP_FILES += \
NUCLEO_F746ZG2_Struct.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NUCLEO_F746ZG2_Struct.list \


# All Target
all: main-build

# Main-build Target
main-build: NUCLEO_F746ZG2_Struct.elf secondary-outputs

# Tool invocations
NUCLEO_F746ZG2_Struct.elf NUCLEO_F746ZG2_Struct.map: $(OBJS) $(USER_OBJS) E:\workspace_1.14.0\NUCLEO_F746ZG2_Struct\STM32F746ZGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "NUCLEO_F746ZG2_Struct.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"E:\workspace_1.14.0\NUCLEO_F746ZG2_Struct\STM32F746ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NUCLEO_F746ZG2_Struct.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NUCLEO_F746ZG2_Struct.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NUCLEO_F746ZG2_Struct.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) NUCLEO_F746ZG2_Struct.elf NUCLEO_F746ZG2_Struct.list NUCLEO_F746ZG2_Struct.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
