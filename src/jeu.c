/* Fichier source contenant les fonctions concernant le deroulement du jeu */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "interface.h"
#include "objets.h"
#include "mouvement.h"
#include "touche.h"
#include "gestion_temps.h"
#include "menu.h"

/* Fonction contenant la partie principale du jeu */
void jeu(){
  objet perceval;       /* Perceval */
  objet *graines;       /* Tableau des graines */
  MLV_Image *p_gauche;  /* Image gauche de perceval */
  MLV_Image *p_droite;  /* Image droite de perceval */
  MLV_Font *font;       /* Police d'écriture */
  montre debut, act;
  int i, nb_graine = 0, act_graine = 0, new_graine = 0, score = 0;


  /* ########################    Initialisation    ######################## */

  srand(time(NULL));    /* Initialisation du random */

  init_fenetre();       /* Initialisation de la fenêtre */
  init_background();    /* Initialisation du décor */

  /* Initialisation de l'horloge de départ */
  MLV_get_date(&debut.s, &debut.m, &debut.h, NULL, NULL, NULL, NULL);

  /* Création du tableau de graine */
  graines = (objet *)malloc(5 * sizeof(objet));

  /* Initialisation de la police d'écriture */
  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 30);
  /* Réglage de l'image gauche de perceval */
  p_gauche = MLV_load_image("./ressources/img/perceval_gauche.png");
  MLV_resize_image_with_proportions(p_gauche, 70, 70);
  /* Réglage de l'image droite de perceval */
  p_droite = MLV_load_image("./ressources/img/perceval_droite.png");
  MLV_resize_image_with_proportions(p_droite, 70, 70);
  /* Création de l'objet perceval */
  perceval = creer_objet("./ressources/img/perceval_droite.png",
                80, 80, 50, 335
              );
  /* Création de l'objet graine[0] */
  graines[0] = creer_objet("./ressources/img/seed.png", 40, 40, rand()%460, 10);
  nb_graine++;
  new_graine++;
  affiche_objet(perceval);
  affiche_objet(graines[0]);


  /* ########################    BOUCLE DE JEU    ######################## */

  while(30+(compt_sec(debut)-compt_sec(act)) != 0){
    wait_millisec(10000000);        /* On attend (animation) */

    MLV_clear_window(MLV_COLOR_BLACK);

    /* actualisation de l'horloge actuelle*/
    MLV_get_date(&act.s, &act.m, &act.h, NULL, NULL, NULL, NULL);

    init_background();

    if(est_presse_gauche()){        /* Perceval bouge à gauche */
      perceval.img = p_gauche;      /* Perceval change de sens */
      mouvement_gauche(&perceval);  /* Perceval bouge */
    }
    else if(est_presse_droite()){   /* Perceval bouge à droite */
      perceval.img = p_droite;      /* Perceval change de sens */
      mouvement_droite(&perceval);  /* Perceval bouge */
    }
    for(i = 0; i < nb_graine; i++){
      mouvement_bas(&graines[i]);   /* Les graine descendent */
    }

    /* Nouvelle graine */
    if(graines[act_graine].y == 100){

      if(nb_graine != 5){          /* 10 graines maximum dans le tableau */
        nb_graine++;
      }
      else{                         /* Une graine en écrase une autre */
        detruire_objet(&graines[new_graine]);
      }
      act_graine = new_graine;      /* On change le pointeur */
      /* On place la nouvelle graine */
      graines[new_graine] = creer_objet("./ressources/img/seed.png",
                              40, 40, rand()%460, 10
                            );

      /* L'emplacement de la nouvelle graine change */
      new_graine = (new_graine+1) % 5;
    }

    /* Vérification du contact */
    for(i = 0; i < nb_graine; i++){
      if(est_en_contact(perceval, graines[i])){
        graines[i].x = 550;
        graines[i].y = 550;
        score++;
      }
    }

    /* Affichage des graines */
    for(i = 0; i < nb_graine; i++){
      affiche_objet(graines[i]);
    }

    /* Affichage du timer */
    affiche_timer(font, 30+(compt_sec(debut)-compt_sec(act)));
    affiche_objet(perceval);          /* Affichage de perceval */
    afficher_score(font, score);      /* Affichage du score */
    MLV_actualise_window();           /* Actualisation de la fenêtre */
  }

  /* FIN DU JEU */
  init_background();
  MLV_draw_text_with_font(
    80, 250,
    "Bravo, votre score : %d",
    font, MLV_COLOR_WHITE, score
  );
  MLV_actualise_window();
  MLV_wait_mouse(NULL, NULL);
  MLV_free_window();
  menu();
}
