################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Application.c 

OBJS += \
./APP/Application.o 

C_DEPS += \
./APP/Application.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\Utilities" -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\MCAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\HAL" -I"E:\Embedded projects and exprience\Shell Car Project\MCU2\APP" -Wall -g2 -gstabs -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


