#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/petite_fonction.h"
#include "../include/main.h"
#include "../include/AffichageBandeauPlateau.h"
#include "../include/plateau.h"
#include "../include/bandeauAction.h"

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauColon(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionPourColon(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauGuerrier(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionPourGuerrier(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauArcher(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionPourArcher(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauBatisseur(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionPourBatisseur(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauVille(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionPourVille(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauVille3(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionPourVille3(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}

// Exécute seulement quand on a besoin d'afficher le bandeau pour un colon
void afficherBandeauBase(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseHeight,int caseWidth) {
    // Ajouter le bandeau d'action pour le colon sur le rendu existant
    dessinerBandeauActionAvecImages(renderer, windowWidth, caseHeight);
    
    dessinerPlateau(renderer,windowWidth,windowHeight,caseWidth,caseHeight,0);
    // Mettre à jour l'écran pour inclure le nouveau bandeau
    SDL_RenderPresent(renderer);
}