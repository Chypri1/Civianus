#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../include/petite_fonction.h"
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/plateau.h"
#include "../include/bandeauAction.h"
#include "../include/AffichageBandeauPlateau.h"
#include "../include/actionPersonnage.h"
#include "../include/structureCivilisation.h"


e_code_main nouvellePartie(SDL_Renderer *renderer) {
    SDL_Event event;
    int partieEnCours = 1;

    // Initialiser le plateau
    initPlateau(renderer, 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);

    // Gestion des civilisations
    int nbJoueurs = 1;
    Civilisation** civilisations = creerCivilisations(nbJoueurs);
    sauvegarderCivilisations(civilisations,nbJoueurs);
    
    Civilisation** civilisationsBis = chargerCivilisations(&nbJoueurs);
    
    if(civilisations == civilisationsBis){
        printf("chargement et création fonctionne correctement\n");
    }
    else{
        printf("chargement et création ne fonctionne pas correctement\n");
    }

    // Obtenir la taille de la fenêtre
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    const int cols = 20;
    int caseWidth = windowWidth / cols;
    int caseHeight = windowHeight / (rows + 1);

    // Boucle principale
    while (partieEnCours) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                partieEnCours = 0;
                break;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                partieEnCours = 0;
                break;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (mouseY < caseHeight) {
                    // Gestion des clics sur le bandeau
                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    if (bandeauCaseIndex == 0) {
                        partieEnCours = 0;
                        break;
                    } else if (bandeauCaseIndex == 1) {
                        sauvegarderPlateau(plateau); // Sauvegarder le plateau
                        sauvegarderCivilisations(civilisations, nbJoueurs); // Sauvegarder les civilisations
                    }
                } else {
                    // Gestion des clics sur le plateau
                    int row = (mouseY - caseHeight) / caseHeight;
                    int col = mouseX / caseWidth;

                    if (row >= 0 && row < rows && col >= 0 && col < cols) {
                        printf("Clic sur le plateau, case (%d, %d)\n", row, col);

                         switch(plateau[row][col][2]){
                            case 1:
                                // bandeauAction pour les ville1
                                afficherBandeauVille(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionVille1(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 2:
                                // bandeauAction pour les ville2
                                afficherBandeauVille(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionVille1(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 3:
                                // bandeauAction pour les ville3
                                afficherBandeauVille3(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionVille3(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            default:
                                // bandeauAction pas modifié
                                break;
                        }
                         // Gérer le clic sur le plateau
                        switch(plateau[row][col][1]){
                            case 1:
                                // bandeauAction pour les colons
                                afficherBandeauColon(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionColon(renderer,row,col, civilisations[1]);

                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 2:
                                // bandeauAction pour les guerriers
                                afficherBandeauGuerrier(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionGuerrier(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 3:
                                // bandeauAction pour les archers
                                afficherBandeauArcher(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                //actionColon(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                civilisations = chargerCivilisations(&nbJoueurs);
                                break;
                            case 4:
                                // bandeauAction pour les batisseurs
                                afficherBandeauBatisseur(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionBatisseur(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            default:
                                // bandeauAction pas modifié
                                break;
                        }
                    }
                }
            }
        }
    }

    // Libérer la mémoire des civilisations
    for (int i = 0; i < nbJoueurs; i++) {
        if (civilisations[i]) {
            free(civilisations[i]->guerriers);
            free(civilisations[i]->archers);
            free(civilisations[i]->colons);
            free(civilisations[i]->batisseurs);
            free(civilisations[i]);
        }
    }
    free(civilisations);

    return M_PRINCIPAL;
}

e_code_main chargerPartie(SDL_Renderer *renderer) {
    SDL_Event event;
    int partieEnCours = 1;

    // Initialiser le plateau
    initPlateau(renderer, 0);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);

    // Gestion des civilisations
    // int nbJoueurs = 1;
    // Civilisation** civilisations = creerCivilisations(nbJoueurs);
    // sauvegarderCivilisations(civilisations,nbJoueurs);

    int nbJoueurs = 1;
    Civilisation** civilisations = chargerCivilisations(&nbJoueurs);

    // Obtenir la taille de la fenêtre
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    const int cols = 20;
    int caseWidth = windowWidth / cols;
    int caseHeight = windowHeight / (rows + 1);

    // Boucle principale
    while (partieEnCours) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                partieEnCours = 0;
                break;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                partieEnCours = 0;
                break;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (mouseY < caseHeight) {
                    // Gestion des clics sur le bandeau
                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    if (bandeauCaseIndex == 0) {
                        partieEnCours = 0;
                        break;
                    } else if (bandeauCaseIndex == 1) {
                        sauvegarderPlateau(plateau); // Sauvegarder le plateau
                        sauvegarderCivilisations(civilisations, nbJoueurs); // Sauvegarder les civilisations
                    }
                } else {
                    // Gestion des clics sur le plateau
                    int row = (mouseY - caseHeight) / caseHeight;
                    int col = mouseX / caseWidth;

                    if (row >= 0 && row < rows && col >= 0 && col < cols) {
                        printf("Clic sur le plateau, case (%d, %d)\n", row, col);

                         switch(plateau[row][col][2]){
                            case 1:
                                // bandeauAction pour les ville1
                                afficherBandeauVille(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionVille1(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 2:
                                // bandeauAction pour les ville2
                                afficherBandeauVille(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionVille1(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 3:
                                // bandeauAction pour les ville3
                                afficherBandeauVille3(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionVille3(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            default:
                                // bandeauAction pas modifié
                                break;
                        }
                         // Gérer le clic sur le plateau
                        switch(plateau[row][col][1]){
                            case 1:
                                // bandeauAction pour les colons
                                afficherBandeauColon(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionColon(renderer,row,col, civilisations[1]);

                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 2:
                                // bandeauAction pour les guerriers
                                afficherBandeauGuerrier(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionGuerrier(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 3:
                                // bandeauAction pour les archers
                                afficherBandeauArcher(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                //actionColon(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            case 4:
                                // bandeauAction pour les batisseurs
                                afficherBandeauBatisseur(renderer, windowWidth,windowHeight, caseWidth, caseHeight);
                                actionBatisseur(renderer,row,col);
                                afficherBandeauBase( renderer,  windowWidth,  windowHeight,  caseHeight, caseWidth);
                                chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe
                                break;
                            default:
                                // bandeauAction pas modifié
                                break;
                        }
                    }
                }
            }
        }
    }

    // Libérer la mémoire des civilisations
    for (int i = 0; i < nbJoueurs; i++) {
        if (civilisations[i]) {
            free(civilisations[i]->guerriers);
            free(civilisations[i]->archers);
            free(civilisations[i]->colons);
            free(civilisations[i]->batisseurs);
            free(civilisations[i]);
        }
    }
    free(civilisations);

    return M_PRINCIPAL;
}

