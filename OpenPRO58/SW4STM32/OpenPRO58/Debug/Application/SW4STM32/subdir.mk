################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
E:/REPO_PRIV/PRO58/HAL_version/src/OpenPRO58/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s 

OBJS += \
./Application/SW4STM32/startup_stm32f103xb.o 


# Each subdirectory must supply rules for building sources it contributes
Application/SW4STM32/startup_stm32f103xb.o: E:/REPO_PRIV/PRO58/HAL_version/src/OpenPRO58/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f103xb.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


