################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Ethernet/Application/multicast/multicast.c 

OBJS += \
./Drivers/Ethernet/Application/multicast/multicast.o 

C_DEPS += \
./Drivers/Ethernet/Application/multicast/multicast.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Ethernet/Application/multicast/%.o: ../Drivers/Ethernet/Application/multicast/%.c Drivers/Ethernet/Application/multicast/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/David/STM32CubeIDE/workspace_1.8.0/Ethernet-SPI/ioLibrary_Driver-master/ioLibrary_Driver-master" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Ethernet-2f-Application-2f-multicast

clean-Drivers-2f-Ethernet-2f-Application-2f-multicast:
	-$(RM) ./Drivers/Ethernet/Application/multicast/multicast.d ./Drivers/Ethernet/Application/multicast/multicast.o

.PHONY: clean-Drivers-2f-Ethernet-2f-Application-2f-multicast

