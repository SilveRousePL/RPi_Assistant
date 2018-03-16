################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Buzzer.cpp \
../src/ExecutivePart.cpp \
../src/HD44780.cpp \
../src/RPi_Assistant.cpp 

OBJS += \
./src/Buzzer.o \
./src/ExecutivePart.o \
./src/HD44780.o \
./src/RPi_Assistant.o 

CPP_DEPS += \
./src/Buzzer.d \
./src/ExecutivePart.d \
./src/HD44780.d \
./src/RPi_Assistant.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++1y -I/home/darek/EclipseProjects/@RPi_Tools@/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


