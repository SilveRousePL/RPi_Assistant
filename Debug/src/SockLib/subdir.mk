################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SockLib/CSCommonPart.cpp \
../src/SockLib/Client.cpp \
../src/SockLib/NetSock.cpp \
../src/SockLib/Server.cpp 

OBJS += \
./src/SockLib/CSCommonPart.o \
./src/SockLib/Client.o \
./src/SockLib/NetSock.o \
./src/SockLib/Server.o 

CPP_DEPS += \
./src/SockLib/CSCommonPart.d \
./src/SockLib/Client.d \
./src/SockLib/NetSock.d \
./src/SockLib/Server.d 


# Each subdirectory must supply rules for building sources it contributes
src/SockLib/%.o: ../src/SockLib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-gnueabihf-g++ -std=c++1y -I/home/darek/EclipseProjects/@RPi_Tools@/arm-bcm2708/arm-rpi-4.9.3-linux-gnueabihf/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


