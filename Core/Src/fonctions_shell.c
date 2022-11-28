/**
 * \file fonctions_shell.c
 * \brief Fichier contenant les fonctions appelées par main.c
 * \author RUIZ Guilhem, HERBELIN Benjamin, LENOIR Adrien
 * \version 3
 * \date Dernière modification : 28 Novembre 2022
 *
 * Fichier contenant toutes les fonctions pouvant être appelées dans le shell
 *
 */

#include <stdio.h>
#include "fonctions_shell.h"
#include "tim.h"

#define UART_TX_BUFFER_SIZE 64

int EtatMoteur;

extern UART_HandleTypeDef huart2;
extern uint8_t uartTxBuffer[UART_TX_BUFFER_SIZE];

void help(){
	/**
	 * \fn void help (void)
	 * \brief La fonction d'aide du shell, elle sert à lister les différentes fonctions disponibles
	 * \param void
	 * \return void
	 */
	sprintf((char*)uartTxBuffer, "Liste fonctions disponiles :\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "(help)\r\npinout\r\nstart\r\nstop\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
}

void pinout(){
	/**
	 * \fn void pinout (void)
	 * \brief Renvoie le détail des broches connectées/initialisées et de leur fonction
	 * \param void
	 * \return void
	 */
	sprintf((char*)uartTxBuffer, "PA2 : USART2_TX\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA3 : USART2_RX\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA5 : LED\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA8 : TIM1_CH1\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA9 : TIM1_CH2\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA11 : TIM1_CH1N\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA12 : TIM1_CH2N\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA13 : T_SWDIO\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PA14 : T_SWCLK\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PC3 : ISO_RESET\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PC13 : BUTTON\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PC14 : RCC_OSC32_IN\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PC15 : RCC_OSC32_OUT\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PF0 : RCC_OSC_IN\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "PF1 : RCC_OSC_OUT\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);

	// Affichage du pinout dans le prompt :

	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x20, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x31, 0x31, 0x20);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf((char*)uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x20, 0x31, 0x78, 0x31, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x20);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
}

int start(){
	/**
	 * \fn int start (void)
	 * \brief Allume l'étage de puissance du moteur
	 * \param void
	 * \return int
	 *
	 * Commande le démarage du moteur via la "séquence d'allumage"
	 */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);

	EtatMoteur = MOTEUR_ON;

	return 0;
}

int stop(){
	/**
	 * \fn int stop (void)
	 * \brief Eteint l'étage de puissance du moteur (ne fait rien pour le moment)
	 * \param void
	 * \return int
	 */
	//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
	//TIM_Cmd(TIM1, DISABLE);
	EtatMoteur = MOTEUR_OFF;

	return 0;
}

int alpha(int alphaInit, int alphaFin) {
	/**
	 * \fn int alpha(int alphaInit, int alphaFin)
	 * \brief La fonction permet de changer le rapport cyclique progressivement
	 * \param int alphaInit, int alphaFin
	 * \return int
	 *
	 * Cette fonction permet de faire varier le rapport cyclique (donné par alphaXxx/1024) de "alphaInit" à "alphaFin",
	 * à une cadence d'environs 10 % (soit 100 cycles) par seconde (chaque cycle mesure de 10 ms+).
	 */
	int alphaActu = 0;
	if (alphaInit <= alphaFin) {
		alphaActu = alphaInit;
		while (alphaActu <= alphaFin) {
			TIM1->CCR1=alphaActu;
			TIM1->CCR2=(1024-alphaActu);
			HAL_UART_Transmit(&huart2, alphaActu, sizeof(alphaActu), HAL_MAX_DELAY);
			alphaActu++;
			HAL_Delay(10);
		}

	}
	else if(alphaFin < alphaInit) {
		alphaActu = alphaFin;
		while (alphaActu >= alphaFin) {
			TIM1->CCR1=alphaActu;
			TIM1->CCR2=(1024-alphaActu);
			HAL_UART_Transmit(&huart2, alphaActu, sizeof(alphaActu), HAL_MAX_DELAY);
			alphaActu--;
			HAL_Delay(100);
		}
	}
	return alphaActu;
}
