#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
/**
* \file petite_fonction.h
* \author Tan Tony
* \version 2.6
* \brief Les fonctions prototypes de menu.c,petite_fonction.c et creer_partie.c
*/
void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t);
void SDL_ExitWithError(const char *message);
