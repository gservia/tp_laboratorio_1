################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Employee.c \
../src/LinkedList.c \
../src/input_validation.c \
../src/main.c \
../src/menu.c \
../src/parser.c \
../src/utn.c 

OBJS += \
./src/Controller.o \
./src/Employee.o \
./src/LinkedList.o \
./src/input_validation.o \
./src/main.o \
./src/menu.o \
./src/parser.o \
./src/utn.o 

C_DEPS += \
./src/Controller.d \
./src/Employee.d \
./src/LinkedList.d \
./src/input_validation.d \
./src/main.d \
./src/menu.d \
./src/parser.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


