#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../include/petite_fonction.h"
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/partie.h"


/**
* \file main.c
* \author Cyprien PENNACHI
* \version 2.3
* \brief La fonction principale,notre main à nous
*/

/**
* \fn int main(int argc, char **argv)
* \param argc Objet de type integer
* \param argv Pointeur sur un pointeur sur un objet de type char 
*/
int main(int argc, char ** argv){

  SDL_Window *fenetre=NULL;
  SDL_Renderer *renderer = NULL;
  Uint32 affich_fenetre=SDL_WINDOW_MAXIMIZED;

  e_code_main code = 1;


  if(SDL_Init(SDL_INIT_VIDEO) != 0)
  { //Lancement SDL
    SDL_ExitWithError("Initialisation SDL");
  }
  //Création de la fenêtre
  fenetre=SDL_CreateWindow("INFO PARTY",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,affich_fenetre);
  if (fenetre == NULL) {
    SDL_ExitWithError("La fenêtre n'a pas pu être créé");
  }
    // Création du renderer
  renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
      SDL_ExitWithError("Le renderer n'a pas pu être créé");
  }

  while(code != JEU_QUITTER){
        switch(code)
        {
            case M_PRINCIPAL : code = menu(renderer); break;
            case M_JEU : 
                code = nouvellePartie(renderer);
                break;
            case M_CHARGER : 
                code = chargerPartie(renderer); 
                break;
            // case M_OPTIONS : code = chargerMenu_Options(); break;
            // case M_CREDITS : code = afficherMenuCredits(); break;
            // case M_KEYMAP : code = chargerMenu_Options_keymap(); break;

            default : 
                printf("Erreur menu (code %i)\n", code);
                code = JEU_QUITTER;
        }
    }
  
  clean_ressources(fenetre,renderer,NULL);
  return 0;
}
