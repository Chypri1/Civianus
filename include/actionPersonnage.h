/**
 * \file ACTION_PERSONNAGE.h
 * 
 * \brief Fichier de définition des codes de retour de fonction pour l'appel
 * des différents modules du projet.
 * 
 */

#ifndef _ACTION_PERSONNAGE_
#define _ACTION_PERSONNAGE_

#include "../include/structureCivilisation.h"

void actionDeplacement(SDL_Renderer *renderer, int row, int col);
void actionColon(SDL_Renderer *renderer, int row, int col, Civilisation *civilisation);
void actionGuerrier(SDL_Renderer *renderer, int row, int col);
void actionBatisseur(SDL_Renderer *renderer, int row, int col);
void actionVille1(SDL_Renderer *renderer, int row, int col);
void actionVille3(SDL_Renderer *renderer, int row, int col);



#endif //_ACTION_PERSONNAGE_