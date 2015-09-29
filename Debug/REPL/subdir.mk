################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../REPL/echo.o \
../REPL/redirect.o 

C_SRCS += \
../REPL/echo.c \
../REPL/execute.c \
../REPL/parse.c \
../REPL/prompt.c \
../REPL/read.c \
../REPL/redirect.c \
../REPL/setup.c 

OBJS += \
./REPL/echo.o \
./REPL/execute.o \
./REPL/parse.o \
./REPL/prompt.o \
./REPL/read.o \
./REPL/redirect.o \
./REPL/setup.o 

C_DEPS += \
./REPL/echo.d \
./REPL/execute.d \
./REPL/parse.d \
./REPL/prompt.d \
./REPL/read.d \
./REPL/redirect.d \
./REPL/setup.d 


# Each subdirectory must supply rules for building sources it contributes
REPL/%.o: ../REPL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -D_XOPEN_SOURCE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


