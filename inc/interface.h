/* Fichier header contenant les prototypes des fonction générales concernant */
/* l'interface */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <MLV/MLV_all.h>
#include "gestion_temps.h"

/* Initialisation du décor */
void init_background();

/* Initialisation de perceval */
void init_perceval();

/* Initialisation de la fenêtre */
void init_fenetre();

/* Permet d'afficher le score */
void afficher_score(MLV_Font *font, int score);

/* Permet d'afficher le timer */
void affiche_timer(MLV_Font *font, int sec);

#endif
