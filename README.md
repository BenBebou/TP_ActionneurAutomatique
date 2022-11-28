# TP - Actionneurs et automatique appliquée

## Notre groupe
* RUIZ Guilhem
* HERBELIN Benjamin
* LENOIR Adrien

## Objectifs du TP
Le but de ce TP filé est de réaliser la commande asservie d'un moteur à courant continu, par l'intermédiaire d'un shell et d'un hacheur à commande complémentaire décalée. Le software est executé sur une carte Nucleo (microcontrôleur STM32G474RET6).
Pour ce faire, plusieurs réalisations intermédiaires sont à implémenter:

* Écriture d'un shell, acceptant quelques commandes basiques pour le contrôle du moteur à venir (start, stop, speed xxx, etc...)
* Branchement et activation logicielle des broches utilisées de la carte Nucléo (UART pour communiquer les ordres via le shell, PWMs pour le contrôle des 4 transistors du hacheur, GPIOs, etc...)
* Codage des fonctions appelables par le shell pour l'allumage et l'éteignage du moteur, et la sélection d'une vitesse à atteindre par celui-ci.
* Réalisation de l'asservissement, via capteurs et boucle de traitements logiciels sur l'intensité électrique consommée et la vitesse de rotation du rotor.
* (Documentation du tout avec l'outil Doxygen)


## En séance 

### Le Shell

### PWM complémentaire décalée - STM32

Les temps morts : 

Nous souhaitons un dead-time de 2us avec une résolution à 10 bits. Pour obtenir ce résultat, il faut réaliser quelques calculs préliminaires. Une résolution à 10 bits signifie que nous avons un ARR avec une valeur de 1024.

$F_{clk} = 164MHz \Rightarrow  T_{clk} = 6{,}1ns$
$DT = 2 \mu s$

Grâce à la documentation qui nous est donné dans le cours, nous pouvons déterminer le Dead Time : 

<p align="center">
![Capture d’écran 2022-11-28 à 20 03 24](https://user-images.githubusercontent.com/13495977/204360288-8f8b9956-45b2-4e01-a9e8-d4154b585226.png)
 Figure 1 : Formule pour obtenir le Dead Time
</p>

On sait que : 

$DTG[4:0] = \frac{DT\cdot f}{8} -32 \Leftrightarrow DTG[4:0] = 2\cdot10^{-6}\frac{164\cdot10^6}{8} - 32$
$DTG[4:0] = 9 \Rightarrow 0 1001$

Et : 
$DTG[7:5] = 110$

$DTG[7:5] = 110$
Donc : 
$DTG = 1100 1001 = 201$

Pour obtenir un temps mort de $2\mu s$, il faut un DTG de 201.

<p align="center">
![temps mort ch1 ch1n(pa8_pa11)](https://user-images.githubusercontent.com/13495977/204361393-34d0c83a-00fe-4929-b742-cae07658b2f0.png)
 Figure 2 : Capture du temps mort
</p>

Sur l’oscilloscope, nous obtenons bien $2\mus$ de temps mort. Nos calculs sont donc corrects.

PWM :

Nous souhaitons créer une PWM complémentaire décalée pour contrôler notre hacheur et par conséquent notre moteur. Nous souhaitons que les transistors H1 et H4 soient fermés pendant que les transistors H2 et H3 sont ouverts. Pour reproduire ce pattern, il nous faut donc deux channels avec des PWM complémentaires. ![image](https://user-images.githubusercontent.com/13495977/204362103-4f35a3fb-a84c-40f0-ad00-a71d7de2ef75.png)


<p align="center">
![image](https://user-images.githubusercontent.com/13495977/204362103-4f35a3fb-a84c-40f0-ad00-a71d7de2ef75.png)
 Figure 3 : Hacheurs 4 quadrants
</p>

Voici comment sont configurés nos channels sur CubeIDE : 

<p align="center">
![image](https://user-images.githubusercontent.com/13495977/204362252-9e97d016-3a70-4e0e-9d4f-19d24a32d19c.png)
 Figure 4 : Configuration des channels 1 et 2 du timer 1
</p>



## Avancements

* Le shell est codé et implémente les fonctions basique *help*, *pinout*, *start* et *stop*, où :
  * *help* renvoit le nom des trois autre commandes disponibles, ainsi que leur utilité
  * *pinout* renvoit la liste des broches du microcontrôleur utilisées, ainsi que leur rôle/assignation
  * *start*, qui ne fait rien pour le moment
  * *stop*, qui ne fait rien pour le moment
* Les broches concernées sont activées et assignées aux bons protocoles
* Fonctions de commandes codées : NON
* Asservissement réalisé : NON
