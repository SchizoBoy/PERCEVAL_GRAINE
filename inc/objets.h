/* Fichier header contenant les prototypes des fonctions générales concernant */
/* les objets de jeu */

#ifndef OBJETS_H
#define OBJETS_H

#include <MLV/MLV_all.h>

/* Définition de la structure contenant un objet de jeu */
typedef struct objet{
  int x;            /* Coordonnée x */
  int y;            /* Coordonnée y */
  int size;         /* Taille de l'objet */
  MLV_Image *img;   /* Image représentant l'objet */
}objet;

/* Fonction de création d'objet */
objet creer_objet(char *nom_img, int size_x, int size_y, int px, int py);

/* Fonction d'affichage d'un objet */
void affiche_objet(objet obj);

/* Renvoie 1 si les objets sont en contact, 0 sinon*/
int est_en_contact(objet obj1, objet obj2);

/* Fonction permettant de detruire un objet */
void detruire_objet(objet *obj);

#endif
