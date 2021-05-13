/* Fichier source contenant les fonctions concernant la gestion du temps */
/* durant le jeu */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "gestion_temps.h"

/* Fonction d'attente (en millisecondes) servant aux animations */
void wait_millisec(int n){
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = 1000000*n;
  nanosleep(&t,&t);
}

/* Fonction de conversion d'un type montre en secondes */
int compt_sec(montre timer){
  return (timer.h*3600 + timer.m * 60 + timer.s);
}

/* Fonction de conversion des secondes en type montre */
montre seconds_to_montre(int seconds){
  montre timer;
  timer.h = seconds/3600;
  timer.m = (seconds-timer.h*3600)/60;
  timer.s = (seconds-timer.h*3600-timer.m*60);

  return timer;
}
