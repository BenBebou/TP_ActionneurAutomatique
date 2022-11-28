/**
 * \file fonctions_shell.h
 * \brief Header du fichier contenant les fonctions appelées par main.c
 * \author RUIZ Guilhem, HERBELIN Benjamin, LENOIR Adrien
 * \version 2
 * \date Dernière modification : 28 Novembre 2022
 *
 * Fichier header de fonctions_shell.c, qui contient toutes les fonctions pouvant être appelées dans le shell
 *
 */

#ifndef INC_FONCTIONS_SHELL_H_
#define INC_FONCTIONS_SHELL_H_

#define MOTEUR_ON 1
#define MOTEUR_OFF 0

#include "main.h"

void help(void);
void pinout(void);
int start(void);
int stop(void);
int alpha(int rapport_cyclique_initial, int rapport_cyclique);

#endif /* INC_FONCTIONS_SHELL_H_ */
