/* Fichier source contenant les fonctions associées aux mouvements des objets */
/* de jeu */

#include "objets.h"

/* Limites de mouvements des objets */
int LIMITE_GAUCHE = 0;
int LIMITE_DROITE = 440;
int LIMITE_HAUT = 20;
int LIMITE_BAS = 350;

/* Mouvements de perceval : */
/* Fonction animant un objet vers la gauche */
void mouvement_gauche(objet *obj){
  if(obj->x >= LIMITE_GAUCHE){
    obj->x -= 2;
  }
}

/* Fonction animant un objet vers la droite */
void mouvement_droite(objet *obj){
  if(obj->x <= LIMITE_DROITE){
    obj->x += 2;
  }
}

/* Mouvements de la graine : */
/* (Fonction jamais utilisée) */
/* Fonction animant un objet vers le haut */
void mouvement_haut(objet *obj){
  if(obj->y >= LIMITE_HAUT){
    obj->y -= 1;
  }
}

/* Fonction animant un objet vers le bas */
void mouvement_bas(objet *obj){
  if(obj->y <= LIMITE_BAS){
    obj->y += 1;
  }
}
