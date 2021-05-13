/* Fichier header contenant les prototypes des fonctions concernant la */
/* gestion du temps durant le jeu */

#ifndef TEMPS_H_
#define TEMPS_H_

#include <time.h>

/* Définition du type montre */
typedef struct montre{
  int h;
  int m;
  int s;
}montre;

/* Fonction d'attente (en millisecondes) servant aux animations */
void wait_millisec(int n);

/* Fonction de conversion d'un type montre en secondes */
int compt_sec(montre timer);

/* Fonction de conversion des secondes en type montre */
montre seconds_to_montre(int seconds);

#endif
