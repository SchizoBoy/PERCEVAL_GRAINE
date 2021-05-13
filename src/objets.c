/* Fichier source contenant les fonctions générales concernant les objets de */
/* jeu */

#include <MLV/MLV_all.h>
#include "objets.h"

/* Fonction de création d'objet */
objet creer_objet(char *nom_img, int size_x, int size_y, int px, int py){
  MLV_Image *obj_img = MLV_load_image(nom_img);
  objet obj;

  if(size_x != 0 && size_y != 0){
    MLV_resize_image_with_proportions(obj_img, size_x, size_y);
  }
  obj.img = obj_img;
  obj.size = size_x;
  obj.x = px;
  obj.y = py;

  return obj;
}

/* Fonction d'affichage d'un objet */
void affiche_objet(objet obj){
  MLV_draw_image(obj.img, obj.x, obj.y);
  MLV_actualise_window();
}

/* Renvoie 1 si les objets sont en contact, 0 sinon*/
int est_en_contact(objet obj1, objet obj2){
  if(10 <= obj2.x-obj1.x && obj2.x-obj1.x <= 30){
    if(0 <= obj2.y-obj1.y && obj2.y-obj1.y <= 30){
      return 1;
    }
  }
  return 0;
}

/* Fonction permettant de detruire un objet */
void detruire_objet(objet *obj){
  MLV_free_image(obj->img);
}
