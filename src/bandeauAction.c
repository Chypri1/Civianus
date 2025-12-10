#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

#include "../include/bandeauAction.h"
// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionAvecImages(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.png");  // bouton save
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 1; i < bandeauCols-1; i++) {
        bandeauTextures[i] = IMG_LoadTexture(renderer, "src/img/check.png");

        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}

// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionPourColon(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/check.png");
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.jpg");  // bouton save
    bandeauTextures[2] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");  // bouton retour
    bandeauTextures[3] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_ville1.png");  // bouton construction ville
    bandeauTextures[4] = IMG_LoadTexture(renderer, "src/img/allemagne.png");  // bouton déplacement
    bandeauTextures[5] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[6] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[7] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[8] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 0; i < bandeauCols; i++) {
        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}


// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionPourGuerrier(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/check.png");
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.jpg");  // bouton save
    bandeauTextures[2] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");  // bouton retour
    bandeauTextures[3] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[4] = IMG_LoadTexture(renderer, "src/img/allemagne.png");  // bouton déplacement
    bandeauTextures[5] = IMG_LoadTexture(renderer, "src/img/pierre.png");  // bouton attaque
    bandeauTextures[6] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[7] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[8] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 0; i < bandeauCols; i++) {
        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}


// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionPourArcher(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/check.png");
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.jpg");  // bouton save
    bandeauTextures[2] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");  // bouton retour
    bandeauTextures[3] = IMG_LoadTexture(renderer, "src/img/check.png.png");  // bouton vide
    bandeauTextures[4] = IMG_LoadTexture(renderer, "src/img/allemagne.png");  // bouton déplacement
    bandeauTextures[5] = IMG_LoadTexture(renderer, "src/img/pierre.png");  // bouton attaque
    bandeauTextures[6] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[7] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[8] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 0; i < bandeauCols; i++) {
        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}


// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionPourBatisseur(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/check.png");
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.jpg");  // bouton save
    bandeauTextures[2] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");  // bouton retour
    bandeauTextures[3] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[4] = IMG_LoadTexture(renderer, "src/img/allemagne.png");  // bouton déplacement
    bandeauTextures[5] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_ferme.png");  // bouton construction ferme
    bandeauTextures[6] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_biblio.png");  // bouton construction biblio
    bandeauTextures[7] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[8] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 0; i < bandeauCols; i++) {
        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}


// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionPourVille(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/check.png"); // bouton vide
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.jpg");  // bouton save
    bandeauTextures[2] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");  // bouton retour
    bandeauTextures[3] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[4] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_batisseur.png");  // bouton lancement batisseur
    bandeauTextures[5] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_colon.png");  // bouton lancement colon
    bandeauTextures[6] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_guerrier.png");  // bouton lancement guerrier
    bandeauTextures[7] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_archer.png");  // bouton lancement archer
    bandeauTextures[8] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_ville1.png");  // bouton amélioration ville 
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 0; i < bandeauCols; i++) {
        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}

// Fonction pour dessiner le bandeau d'action avec des images
void dessinerBandeauActionPourVille3(SDL_Renderer *renderer, int windowWidth, int caseHeight) {
    
    int bandeauCols = 10; // Le bandeau a 10 cases
    int bandeauCaseWidth = windowWidth / bandeauCols;
    int bandeauY = 0;

    // Charger les images pour le bandeau
    SDL_Texture *bandeauTextures[bandeauCols];
    bandeauTextures[0] = IMG_LoadTexture(renderer, "src/img/check.png"); // bouton vide
    bandeauTextures[1] = IMG_LoadTexture(renderer, "src/img/background.jpg");  // bouton save
    bandeauTextures[2] = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");  // bouton retour
    bandeauTextures[3] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide
    bandeauTextures[4] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_archer.png");  // bouton lancement batisseur
    bandeauTextures[5] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_colon.png");  // bouton lancement colon
    bandeauTextures[6] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_guerrier.png");  // bouton lancement guerrier
    bandeauTextures[7] = IMG_LoadTexture(renderer, "src/img/bouton/bouton_batisseur.png");  // bouton lancement archer
    bandeauTextures[8] = IMG_LoadTexture(renderer, "src/img/check.png");  // bouton vide car plus d'amélioration possible
    bandeauTextures[9] = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png"); // bouton continuer

    for (int i = 0; i < bandeauCols; i++) {
        if (!bandeauTextures[i]) {
            printf("Erreur de chargement de l'image %d pour le bandeau: %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(bandeauTextures[j]);
            }
            return;
        }
    }

    // Dessiner chaque case du bandeau avec l'image correspondante
    for (int i = 0; i < bandeauCols; i++) {
        SDL_Rect bandeauCaseRect = { i * bandeauCaseWidth, bandeauY, bandeauCaseWidth, caseHeight };
        SDL_RenderCopy(renderer, bandeauTextures[i], NULL, &bandeauCaseRect);

        // Optionnel : Dessiner une bordure autour de chaque case
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Bordure blanche
        SDL_RenderDrawRect(renderer, &bandeauCaseRect);
    }

    // Libérer les textures du bandeau
    for (int i = 0; i < bandeauCols; i++) {
        SDL_DestroyTexture(bandeauTextures[i]);
    }
}

