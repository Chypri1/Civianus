#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../include/petite_fonction.h"
#include "../include/main.h"

e_code_main menu(SDL_Renderer *renderer) {
    SDL_Event event;
    int menuRunning = 1;
    e_code_main code = M_PRINCIPAL;

    // Charger la texture pour l'image de fond
    SDL_Texture *backgroundTexture = IMG_LoadTexture(renderer, "src/img/background.jpg");
    if (!backgroundTexture) {
        printf("Erreur lors du chargement de l'image de fond : %s\n", SDL_GetError());
        return JEU_QUITTER;
    }

    // Charger les textures pour chaque bouton
    SDL_Texture *btnJouer = IMG_LoadTexture(renderer, "src/img/bouton/restart.png");
    SDL_Texture *btnCharger = IMG_LoadTexture(renderer, "src/img/bouton/continuer.png");
    SDL_Texture *btnOptions = IMG_LoadTexture(renderer, "src/img/check.png");
    SDL_Texture *btnQuitter = IMG_LoadTexture(renderer, "src/img/bouton/quit.png");

    if (!btnJouer || !btnCharger || !btnOptions || !btnQuitter) {
        printf("Erreur lors du chargement des images de boutons : %s\n", SDL_GetError());
        SDL_DestroyTexture(backgroundTexture);
        return JEU_QUITTER;
    }

    // Définir les positions des boutons dans la fenêtre
    SDL_Rect optionJouer = {200, 200, 200, 50};
    SDL_Rect optionCharger = {200, 300, 200, 50};
    SDL_Rect optionOptions = {200, 400, 200, 50};
    SDL_Rect optionQuitter = {200, 500, 200, 50};

    // Définir le rectangle pour le fond (plein écran)
    SDL_Rect backgroundRect = {0, 0, 800, 600}; // Changez les dimensions si nécessaire

    while (menuRunning) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                code = JEU_QUITTER;
                menuRunning = 0;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;

                if (SDL_PointInRect(&(SDL_Point){x, y}, &optionJouer)) {
                    code = M_JEU;
                    menuRunning = 0;
                } else if (SDL_PointInRect(&(SDL_Point){x, y}, &optionCharger)) {
                    code = M_CHARGER;
                    menuRunning = 0;
                // } else if (SDL_PointInRect(&(SDL_Point){x, y}, &optionOptions)) {
                //     code = M_OPTIONS;
                //     menuRunning = 0;
                } else if (SDL_PointInRect(&(SDL_Point){x, y}, &optionQuitter)) {
                    code = JEU_QUITTER;
                    menuRunning = 0;
                }
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Afficher l'image de fond
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);

        // Afficher chaque bouton avec son image
        SDL_RenderCopy(renderer, btnJouer, NULL, &optionJouer);
        SDL_RenderCopy(renderer, btnCharger, NULL, &optionCharger);
        SDL_RenderCopy(renderer, btnOptions, NULL, &optionOptions);
        SDL_RenderCopy(renderer, btnQuitter, NULL, &optionQuitter);

        // Mettre à jour le rendu
        SDL_RenderPresent(renderer);
    }

    // Libérer les textures des boutons et de l'image de fond avant de quitter
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(btnJouer);
    SDL_DestroyTexture(btnCharger);
    SDL_DestroyTexture(btnOptions);
    SDL_DestroyTexture(btnQuitter);

    return code;
}
