################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Ethernet/Internet/TFTP/netutil.c \
../Drivers/Ethernet/Internet/TFTP/tftp.c 

OBJS += \
./Drivers/Ethernet/Internet/TFTP/netutil.o \
./Drivers/Ethernet/Internet/TFTP/tftp.o 

C_DEPS += \
./Drivers/Ethernet/Internet/TFTP/netutil.d \
./Drivers/Ethernet/Internet/TFTP/tftp.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Ethernet/Internet/TFTP/%.o: ../Drivers/Ethernet/Internet/TFTP/%.c Drivers/Ethernet/Internet/TFTP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/David/STM32CubeIDE/workspace_1.8.0/Ethernet-SPI/ioLibrary_Driver-master/ioLibrary_Driver-master" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Ethernet-2f-Internet-2f-TFTP

clean-Drivers-2f-Ethernet-2f-Internet-2f-TFTP:
	-$(RM) ./Drivers/Ethernet/Internet/TFTP/netutil.d ./Drivers/Ethernet/Internet/TFTP/netutil.o ./Drivers/Ethernet/Internet/TFTP/tftp.d ./Drivers/Ethernet/Internet/TFTP/tftp.o

.PHONY: clean-Drivers-2f-Ethernet-2f-Internet-2f-TFTP

