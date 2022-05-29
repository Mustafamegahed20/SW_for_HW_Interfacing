################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/7_seg.c \
../drivers/src/gpio.c 

OBJS += \
./drivers/src/7_seg.o \
./drivers/src/gpio.o 

C_DEPS += \
./drivers/src/7_seg.d \
./drivers/src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o: ../drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"E:/embded/Tasks/task7/StdPeriph_Driver/inc" -I"E:/embded/Tasks/task7/drivers/include" -I"E:/embded/Tasks/task7/inc" -I"E:/embded/Tasks/task7/CMSIS/device" -I"E:/embded/Tasks/task7/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


