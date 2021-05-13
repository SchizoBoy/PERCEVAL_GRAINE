/* Fichier source contenant les fonctions concernant les touches de jeu */

#include <MLV/MLV_all.h>

/* Fonction renvoyant 1 si la fleche de gauche est pressée, 0 sinon */
int est_presse_gauche(){
  return (MLV_get_keyboard_state(MLV_KEYBOARD_LEFT) == MLV_PRESSED);
}

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_droite(){
  return (MLV_get_keyboard_state(MLV_KEYBOARD_RIGHT) == MLV_PRESSED);
}
