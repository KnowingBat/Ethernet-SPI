################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTFormat.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTPacket.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.c \
../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.c 

OBJS += \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTFormat.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTPacket.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.o \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.o 

C_DEPS += \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTFormat.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTPacket.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.d \
./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/%.o: ../Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/%.c Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/David/STM32CubeIDE/workspace_1.8.0/Ethernet-SPI/ioLibrary_Driver-master/ioLibrary_Driver-master" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Ethernet-2f-Internet-2f-MQTT-2f-MQTTPacket-2f-src

clean-Drivers-2f-Ethernet-2f-Internet-2f-MQTT-2f-MQTTPacket-2f-src:
	-$(RM) ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTFormat.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTFormat.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTPacket.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTPacket.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.o ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.d ./Drivers/Ethernet/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.o

.PHONY: clean-Drivers-2f-Ethernet-2f-Internet-2f-MQTT-2f-MQTTPacket-2f-src

