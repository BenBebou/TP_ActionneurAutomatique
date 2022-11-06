/**
 * \file fonctions_shell.c
 * \brief Fichier contenant les fonctions appelées par main.c
 * \author RUIZ Guilhem, HERBELIN Benjamin, LENOIR Adrien
 * \version 1
 * \date 28 Octobre 2022
 *
 * Fichier contenant toutes les fonctions pouvant être appelées dans le shell
 *
 */


void help(){
	/**
	 * \fn void help (void)
	 * \brief La fonction d'aide du shell, elle sert à lister les différentes fonctions disponibles
	 * \param void
	 * \return void
	 */
	sprintf(uartTxBuffer, "Liste fonctions disponiles :\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "(help)\r\npinout\r\nstart\r\nstop\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
}

void pinout(){
	/**
	 * \fn void pinout (void)
	 * \brief Renvoie le détail des broches connectées/initialisées et de leur fonction
	 * \param void
	 * \return void
	 */
	sprintf(uartTxBuffer, "PA2 : USART2_TX\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA3 : USART2_RX\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA5 : LED\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA8 : TIM1_CH1\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA9 : TIM1_CH2\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA11 : TIM1_CH1N\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA12 : TIM1_CH2N\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA13 : T_SWDIO\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PA14 : T_SWCLK\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PC3 : ISO_RESET\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PC13 : BUTTON\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PC14 : RCC_OSC32_IN\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PC15 : RCC_OSC32_OUT\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PF0 : RCC_OSC_IN\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "PF1 : RCC_OSC_OUT\r\n");
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);

	// Affichage du pinout dans le prompt :

	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x20, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x31, 0x31, 0x20);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x31);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x31, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x78, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x78);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
	sprintf(uartTxBuffer, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\r\n", 0x20, 0x31, 0x78, 0x31, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x20);
	HAL_UART_Transmit(&huart2, uartTxBuffer, 32, HAL_MAX_DELAY);
}

int start(){
	/**
	 * \fn int start (void)
	 * \brief Allume l'étage de puissance du moteur
	 * \param void
	 * \return void
	 */
	// RIEN POUR LE MOMENT
	return 0;
}

int stop(){
	/**
	 * \fn int stop (void)
	 * \brief Eteint l'étage de puissance du moteur
	 * \param void
	 * \return void
	 */
	// RIEN POUR LE MOMENT
	return 0;
}
