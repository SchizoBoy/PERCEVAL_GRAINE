/* Ficher source contenant les fonctions générales concernant l'interface */

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "gestion_temps.h"

/* Initialisation du décor */
void init_background(){
  MLV_Image *background = MLV_load_image("./ressources/img/decor.png");

  /* On redimensionne l'image */
  MLV_resize_image_with_proportions(background, 500, 500);

  /* On pose le décor */
  MLV_draw_image(background, 0, 0);
  MLV_free_image(background);
}

/* Initialisation de perceval */
void init_perceval(){
  MLV_Image *perceval = MLV_load_image("./ressources/img/perceval.png");

  /* On redimensionne l'image */
  MLV_resize_image_with_proportions(perceval, 70, 70);

  /* On  pose perceval */
  MLV_draw_image(perceval, 50, 340);
  MLV_free_image(perceval);
}

/* Initialisation de la fenêtre */
void init_fenetre(){
  MLV_create_window("PERCEVAL", "PERCEVAL", 500, 500);
}

/* Permet d'afficher le timer */
void affiche_timer(MLV_Font *font, int sec){

  int h, m, s;
  h = sec/3600;
  sec -= h*3600;
  m = sec/60;
  sec -= m*60;
  s = sec;

  /* Affichage du temps */
  MLV_draw_text_with_font(
    100, 450,
    "Temps Restant : %02d",
    font, MLV_COLOR_WHITE, s
  );
}

/* Permet d'afficher le score */
void afficher_score(MLV_Font *font, int score){
  /* Affichage du score */
  MLV_draw_text_with_font(
    10, 410,
    "SCORE : %d",
    font, MLV_COLOR_WHITE, score
  );

  /* Message différent en fonction du score */

  if(score < 5){
    MLV_draw_text_with_font(
      240, 410,
      "Pas Miam...",
      font, MLV_COLOR_WHITE, score
    );
  }
  else if(score < 10){
    MLV_draw_text_with_font(
      260, 410,
      "Miam",
      font, MLV_COLOR_WHITE, score
    );
  }
  else if(score < 20){
    MLV_draw_text_with_font(
      240, 410,
      "MIAM MIAM",
      font, MLV_COLOR_WHITE, score
    );
  }
  else if(score < 40){
    MLV_draw_text_with_font(
      240, 410,
      "SUPER MIAM",
      font, MLV_COLOR_WHITE, score
    );
  }
  else if(score < 60){
    MLV_draw_text_with_font(
      240, 410,
      "GIGA MIAM",
      font, MLV_COLOR_WHITE, score
    );
  }
  else if(score >= 60){
    MLV_draw_text_with_font(
      220, 410,
      "ROI DU MIAM MIAM",
      font, MLV_COLOR_WHITE, score
    );
  }
}
