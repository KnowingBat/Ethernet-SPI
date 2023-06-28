/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "iwdg.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "wiznet.h"
#include "w5500.h"
#include "socket.h"
#include "wizchip_conf.h"
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t mySocket;
	uint8_t memsize[2][8] = {{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}}; // 2 sockets of 2kb each
	wiz_NetInfo netInfo = {
			.ip = {192,168,1,100},
			.mac = {0xEA, 0x11, 0x22, 0x33, 0x44, 0xEA },
			.sn = {255,255,255,0},
			.gw = {192,168,1,1},
			.dns = {8,8,8,8},
			.dhcp = NETINFO_STATIC
	};

	uint8_t state = 0;
	uint8_t rxBuff[50];
	uint8_t txBuff[50];
	int32_t err_t;
	int32_t dataSize = 0;
	uint16_t port;
	size_t len;
	uint8_t serverStatus;
	intr_kind interrupt;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI2_Init();
  MX_IWDG_Init();
  /* USER CODE BEGIN 2 */
  // Pulse on reset pin
  HAL_GPIO_WritePin(RST_WIZCHIP_GPIO_Port, RST_WIZCHIP_Pin, GPIO_PIN_RESET);
  HAL_Delay(1); //wait 1 ms
  HAL_GPIO_WritePin(RST_WIZCHIP_GPIO_Port, RST_WIZCHIP_Pin, GPIO_PIN_SET);

  // Wizchip functions assignement
  reg_wizchip_cs_cbfunc(wizchip_select, wizchip_deselect);
  reg_wizchip_spi_cbfunc(wizchip_readByte, wizchip_writeByte);
  reg_wizchip_spiburst_cbfunc(wizchip_readBuff, wizchip_writeBuff);

  // Wizchip initialization
  if(ctlwizchip(CW_INIT_WIZCHIP, (void *) memsize) == -1){
  	// Error during initialization
  	printf("WIZCHIP init failed...\r\n");
  	while(1);
  }

  // No errors during initialization
  printf("WIZCHIP initialized...\r\n");

  if(ctlnetwork(CN_SET_NETINFO, (void *)&netInfo) == -1){
  	// Errors
  	while(1);
  }

  // Set interrupt mask for recv
  interrupt = IK_SOCK_1;
  if(ctlwizchip(CW_SET_INTRMASK, (void *)&interrupt) == -1){
  	// Errors
  	while(1);
  }

  HAL_IWDG_Refresh(&hiwdg);

  // Create a socket
  mySocket = socket(1, Sn_MR_TCP, 502, 0);
  if(mySocket != 1){
  	// Error in socket creation
  	while(1);
  }

  // Listen socket for connections
  err_t = listen(mySocket);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  	// Check for server status
  	serverStatus = getSn_SR(mySocket);

  	switch(state){
  	case 0: // Wait for client connections

  		if(serverStatus == SOCK_ESTABLISHED){
  			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
  			ctlnetwork(CN_GET_NETINFO, (void *) &netInfo);
  			port = getSn_PORT(mySocket);
  			display_netinfo(mySocket, &netInfo, port);
  			//send(mySocket, (uint8_t *)string, len);
  			state++;
  		}
  		break;
  	case 1: // Client has been connected
  		// Check for status
  		if(serverStatus == SOCK_CLOSE_WAIT){
  			// Reinit the connection
  			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
  			// Close the socket
  			close(mySocket);
  			state++;
  		}

  		// Check for incoming data
  		uint8_t intSocketRegister = getSn_IR(mySocket);
  		// Check for socket 1 RECV interrupt
  		if(intSocketRegister & (1<<2)){
  			// Interrupt occurred
  			dataSize = recv(mySocket, rxBuff, 50);

  			if(dataSize <= 0){
  				// Error
  				break;
  			}

  			memcpy(txBuff, rxBuff, dataSize);
  			if(send(mySocket, txBuff, dataSize) != dataSize){
  				// Something went wrong
  			  break;
  			}

  			// Clear interrupt register
  			intSocketRegister &= (1<<2);
  			setSn_IR(mySocket, intSocketRegister);
  		}

  		break;
  	case 2:
  		// Reinit the socket
  		mySocket = socket(1, Sn_MR_TCP, 502, 0);
  		if(mySocket != 1){
  		  // Error in socket creation
  		  while(1);
  		}

  		// Listen socket for connections
  		err_t = listen(mySocket);

  		state = 0;

  		break;
  	}

  	HAL_IWDG_Refresh(&hiwdg);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

