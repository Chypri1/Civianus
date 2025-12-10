/**
 * \file bandeauAction.h
 * 
 * \brief Fichier de définition des codes de retour de fonction pour l'appel
 * des différents modules du projet.
 * 
 */

#ifndef _BANDEAU_ACTION_
#define _BANDEAU_ACTION_


void dessinerBandeauActionAvecImages(SDL_Renderer *renderer, int windowWidth, int caseHeight);
void dessinerBandeauActionPourColon(SDL_Renderer *renderer, int windowWidth, int caseHeight);
void dessinerBandeauActionPourArcher(SDL_Renderer *renderer, int windowWidth, int caseHeight);
void dessinerBandeauActionPourGuerrier(SDL_Renderer *renderer, int windowWidth, int caseHeight);
void dessinerBandeauActionPourBatisseur(SDL_Renderer *renderer, int windowWidth, int caseHeight);
void dessinerBandeauActionPourVille(SDL_Renderer *renderer, int windowWidth, int caseHeight);
void dessinerBandeauActionPourVille3(SDL_Renderer *renderer, int windowWidth, int caseHeight);


#endif //_BANDEAU_ACTION_ 