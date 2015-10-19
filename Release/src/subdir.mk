################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Carry\ Look-Ahead\ Calculator.c 

OBJS += \
./src/Carry\ Look-Ahead\ Calculator.o 

C_DEPS += \
./src/Carry\ Look-Ahead\ Calculator.d 


# Each subdirectory must supply rules for building sources it contributes
src/Carry\ Look-Ahead\ Calculator.o: ../src/Carry\ Look-Ahead\ Calculator.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Carry Look-Ahead Calculator.d" -MT"src/Carry\ Look-Ahead\ Calculator.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


