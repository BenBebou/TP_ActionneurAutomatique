
/* USER CODE BEGIN Header */

/**
 * \file main.c
 * \brief Shell pour la commande d'un hacheur.
 * \author RUIZ Guilhem, HERBELIN Benjamin, LENOIR Adrien
 * \version 3
 * \date Dernière modification : 28 Novembre 2022
 *
 * Shell de commande pour l'alimentation d'un moteur via un hacheur à commande complétaire décalée
 *
 */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//////////
#include "fonctions_shell.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define UART_TX_BUFFER_SIZE 64
#define UART_RX_BUFFER_SIZE 1
#define CMD_BUFFER_SIZE 64
#define MAX_ARGS 9
// LF = line feed, saut de ligne
#define ASCII_LF 0x0A
// CR = carriage return, retour chariot
#define ASCII_CR 0x0D
// DEL = delete
#define ASCII_DEL 0x7F

// About PWMs
#define PERIODE (TIM1->ARR) + 1 //sinon mettre 1024

#define MAX_SPEED 922

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
const uint8_t prompt[]="user@Nucleo-STM32G431>>";
const uint8_t started[]=
		"\r\n*-----------------------------*"
		"\r\n| Welcome on Nucleo-STM32G431 |"
		"\r\n*-----------------------------*"
		"\r\n";
const uint8_t newline[]="\r\n";
////

const uint8_t helpMSG[]="Appel de la fonction d'aide\r\n";
const uint8_t pinoutMSG[]="Pinout de la carte Nucleo :\r\n";
const uint8_t powerOn[]="Power ON\r\n";
const uint8_t powerOff[]="Power OFF\r\n";

////
const uint8_t cmdNotFound[]="Command not found\r\n";
uint32_t uartRxReceived;
uint8_t uartRxBuffer[UART_RX_BUFFER_SIZE];
uint8_t uartTxBuffer[UART_TX_BUFFER_SIZE];

// About PWMs
//float alpha = 0.6;
//uint8_t periode = 1024;

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
	char	 	cmdBuffer[CMD_BUFFER_SIZE];
	int 		idx_cmd = 0;
	char* 		argv[MAX_ARGS];
	int		 	argc = 0;
	char*		token;
	int 		newCmdReady = 0;

	//le rapport cyclique est initialement à 60%
	int rapport_cyclique = 614;
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
	MX_TIM1_Init();
	/* USER CODE BEGIN 2 */
	memset(argv,NULL,MAX_ARGS*sizeof(char*));
	memset(cmdBuffer,NULL,CMD_BUFFER_SIZE*sizeof(char));
	memset(uartRxBuffer,NULL,UART_RX_BUFFER_SIZE*sizeof(char));
	memset(uartTxBuffer,NULL,UART_TX_BUFFER_SIZE*sizeof(char));

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);

	// Equivalences:
	// CH1 : PA8 : T1 : Signal Jaune
	// CH2 : PA9 : T4 : Signal Vert (En symbiose avec T1, a décaler de T/2)
	// CH1N : PA11 : T2 (Opposition à T1 sinon court-circuit) : Signal Bleu
	// CH2N : PA12 : T3 (Opposition à T4 sinon court-circuit) : Signal Magenta

	// Affichage d'accueil du prompt
	HAL_UART_Receive_IT(&huart2, uartRxBuffer, UART_RX_BUFFER_SIZE);
	HAL_Delay(10);
	HAL_UART_Transmit(&huart2, started, sizeof(started), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, prompt, sizeof(prompt), HAL_MAX_DELAY);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		// uartRxReceived is set to 1 when a new character is received on uart 1
		if(uartRxReceived){
			switch(uartRxBuffer[0]){
			// Nouvelle ligne, instruction à traiter
			case ASCII_CR: // Enter pressed
				HAL_UART_Transmit(&huart2, newline, sizeof(newline), HAL_MAX_DELAY);
				cmdBuffer[idx_cmd] = '\0';
				idx_cmd++;
				argc = 0;
				token = strtok(cmdBuffer, " ");
				while(token!=NULL){
					argv[argc] = token;
					argc++;
					token = strtok(NULL, " ");
				}

				idx_cmd = 0;
				newCmdReady = 1;
				break;
				// Suppression du dernier caractère
			case ASCII_DEL:
				cmdBuffer[idx_cmd] = '\0';
				idx_cmd--;
				HAL_UART_Transmit(&huart2, uartRxBuffer, UART_RX_BUFFER_SIZE, HAL_MAX_DELAY);
				break;
				// Nouveau caractère
			default:
				cmdBuffer[idx_cmd] = uartRxBuffer[0];
				idx_cmd++;
				HAL_UART_Transmit(&huart2, uartRxBuffer, UART_RX_BUFFER_SIZE, HAL_MAX_DELAY);
			}
			uartRxReceived = 0;
		}

		if(newCmdReady){ ////////////////////////////////////////////////////

			if(strcmp(argv[0],"help")==0){
				HAL_UART_Transmit(&huart2, helpMSG, 32, HAL_MAX_DELAY);
				help();
			}
			else if(strcmp(argv[0], "pinout")==0)
			{
				HAL_UART_Transmit(&huart2, pinoutMSG, 32, HAL_MAX_DELAY);
				pinout();
			}
			else if(strcmp(argv[0], "start")==0)
			{
				HAL_UART_Transmit(&huart2, powerOn, 32, HAL_MAX_DELAY);
				start();
			}
			else if(strcmp(argv[0], "stop")==0)
			{
				HAL_UART_Transmit(&huart2, powerOff, 32, HAL_MAX_DELAY);
				// Appel de la fonction "stop"
				stop();
			}
			else if((argv[0][0] == 's') && (argv[0][1] == 'p') && (argv[0][2] == 'e') && (argv[0][3] == 'e') && (argv[0][4] == 'd') && (argv[0][5] == '='))
			{
				//on s'attend à recevoir un commmande de la forme speed = xxxx (où xxxx est un nombre compris entre 0 et 1024)
				int value = 0;

				for(int i = 1; i < 5; i++)
				{
					value+= ((int)pow(10, (4-i))) * atoi(argv[0][5+i]);
				}
				if(value > MAX_SPEED){
					value = MAX_SPEED;
					printf("Valeur maximale attendue : 1024");
				}

				// Envoi du rapport cyclique alpha tel que alpha = value/PERIODE
				alpha(rapport_cyclique, value);
				rapport_cyclique = value;
			}
			else{ // La commande n'est pas reconnue
				HAL_UART_Transmit(&huart2, cmdNotFound, sizeof(cmdNotFound), HAL_MAX_DELAY);
			}

			////////
			HAL_UART_Transmit(&huart2, prompt, sizeof(prompt), HAL_MAX_DELAY);
			newCmdReady = 0;
			////////
		}
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
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
	HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV4;
	RCC_OscInitStruct.PLL.PLLN = 85;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
	RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback (UART_HandleTypeDef * huart){
	uartRxReceived = 1;
	HAL_UART_Receive_IT(&huart2, uartRxBuffer, UART_RX_BUFFER_SIZE);
}
/* USER CODE END 4 */

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM6 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/* USER CODE BEGIN Callback 0 */

	/* USER CODE END Callback 0 */
	if (htim->Instance == TIM6) {
		HAL_IncTick();
	}
	/* USER CODE BEGIN Callback 1 */

	/* USER CODE END Callback 1 */
}

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
