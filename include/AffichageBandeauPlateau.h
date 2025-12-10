/**
 * \file AffichageBandeauPlateau.h
 * 
 * \brief Fichier de définition des codes de retour de fonction pour l'appel
 * des différents modules du projet.
 * 
 */

#ifndef _AFFICHAGE_BANDEAU_ACTION_
#define _AFFICHAGE_BANDEAU_ACTION_


void afficherBandeauColon(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
void afficherBandeauArcher(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
void afficherBandeauGuerrier(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
void afficherBandeauBatisseur(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
void afficherBandeauVille(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
void afficherBandeauVille3(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
void afficherBandeauBase(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth);
#endif //_AFFICHAGE_BANDEAU_ACTION_ 