/* Fichier source contenant les fonctions concernant le menu */

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "jeu.h"

/* Fonction d'affichage du menu */
void menu(){
  MLV_Font *font;
  int choisi = 0, x, y;

  /* Création de la fenêtre */
  MLV_create_window("MENU PERCEVAL", "MENU PERCEVAL", 400, 600);

  /* Initialisation de la police */
  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 60);

  MLV_draw_text_with_font(
    70, 70,
    "PERCEVAL",
    font, MLV_COLOR_WHITE
  );

  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 40);

  MLV_draw_text_with_font(
    110, 220,
    "1 Joueur",
    font, MLV_COLOR_WHITE
  );

  MLV_draw_text_with_font(
    110, 380,
    "2 Joueur",
    font, MLV_COLOR_WHITE
  );

  MLV_actualise_window();

  while(!choisi){
    MLV_get_mouse_position(&x, &y);

    /* Le joueur passe au dessus de la zone */
    if(110 <= x && x <= 290 && 220 <= y && y <= 260){
      MLV_draw_text_with_font(
        110, 220,
        "1 Joueur",
        font, MLV_COLOR_RED
      );
      /* Il clique dont son choix est le premier */
      if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED){
        choisi = 1;
      }
    }
    /* Sinon on redessine la phrase en blanc */
    else{
      MLV_draw_text_with_font(
        110, 220,
        "1 Joueur",
        font, MLV_COLOR_WHITE
      );
    }

    /* Le joueur passe au dessus de la zone */
    if(110 <= x && x <= 290 && 380 <= y && y <= 420){
      MLV_draw_text_with_font(
        110, 380,
        "2 Joueur",
        font, MLV_COLOR_RED
      );
      /* Il clique dont son choix est le second */
      if(MLV_get_mouse_button_state(MLV_BUTTON_LEFT) == MLV_PRESSED){
        choisi = 2;
      }
    }
    /* Sinon on redessine la phrase en blanc */
    else{
      MLV_draw_text_with_font(
        110, 380,
        "2 Joueur",
        font, MLV_COLOR_WHITE
      );
    }
    MLV_actualise_window();
  }

  MLV_free_font(font);
  MLV_free_window();
  jeu();
}
