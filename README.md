# TP ActionneurAutomatique

## Objectifs du TP
Le but de ce TP filé est de réaliser la commande asservie d'un moteur à courant continu, par l'intermédiaire d'un shell et d'un hacheur à commande complémentaire décalée. Le software est executé sur une carte Nucleo (microcontrôleur STM32G474RET6).
Pour ce faire, plusieurs réalisations intermédiaires sont à implémenter:
* Écriture d'un shell, acceptant quelques commandes basiques pour le contrôle du moteur à venir (start, stop, speed xxx, etc...)
* Branchement et activation logicielle des broches utilisées de la carte Nucléo (UART pour communiquer les ordres via le shell, PWMs pour le contrôle des 4 transistors du hacheur, GPIOs, etc...)
* Codage des fonctions appelables par le shell pour l'allumage et l'éteignage du moteur, et la sélection d'une vitesse à atteindre par celui-ci.
* Réalisation de l'asservissement, via capteurs et boucle de traitements logiciels sur l'intensité électrique consommée et la vitesse de rotation du rotor.
* (Documentation du tout avec l'outil Doxygen)

## Avancements
* Le shell est codé et implémente les fonctions basique *help*, *pinout*, *start* et *stop*, où :
 * *help* renvoit le nom des trois autre commandes disponibles, ainsi que leur utilité
 * *pinout* renvoit la liste des broches du microcontrôleur utilisées, ainsi que leur rôle/assignation
 * *start*, qui ne fait rien pour le moment
 * *stop*, qui ne fait rien pour le moment
* Les broches concernées sont activées et assignées aux bons protocoles
* Fonctions de commandes codées : NON
* Aasservissement réalisé : NON
