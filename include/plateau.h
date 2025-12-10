/**
 * \file plateau.h
 * 
 * \brief Fichier de définition des codes de retour de fonction pour l'appel
 * des différents modules du projet.
 * 
 */

#ifndef _PLATEAU_
#define _PLATEAU_


void initPlateau(SDL_Renderer *renderer, int nouvellePartie);
void sauvegarderPlateau(int plateau[19][20][3]);
void chargerPlateau(const char *nomFichier, int plateau[19][20][3], int nouvellePartie);
void dessinerPlateau(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseWidth, int caseHeight, int nouvellePartie);
#endif //_PARTIE_