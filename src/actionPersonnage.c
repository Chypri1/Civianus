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




void actionDeplacement(SDL_Renderer *renderer, int row, int col) {
    SDL_Event event;
    int bandeauActionEnCours = 1;

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    const int cols = 20;
    int caseWidth = windowWidth / cols;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0; // Quitter la partie et retourner au menu principal
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                // Calculer la case cliquée
                int clickedRow = mouseY / caseHeight;
                int clickedCol = mouseX / caseWidth;

                // Vérifier si le clic est dans une case adjacente
                if (clickedRow >= 0 && clickedRow < rows && clickedCol >= 0 && clickedCol < cols) {
                    int deltaRow = clickedRow - row -1;
                    int deltaCol = clickedCol - col;


                // TODO:  Ajouter vérification pour les limites de terrain et de troupes


                    // Utiliser des if else pour gérer les cases adjacentes
                    if (deltaRow == -1 && deltaCol == 0) { // Haut
                        printf("Déplacement vers le haut\n");
                        if(plateau[deltaRow][deltaCol][0] == 0){
                            int newRow = row - 1;
                            plateau[newRow][col][1] = plateau[row][col][1];
                            plateau[row][col][1] = 0;
                            bandeauActionEnCours = 0;
                        }
                    } else if (deltaRow == 1 && deltaCol == 0) { // Bas
                        printf("Déplacement vers le bas\n");
                        if(plateau[deltaRow][deltaCol][0] == 0){
                            int newRow = row + 1;
                            plateau[newRow][col][1] = plateau[row][col][1];
                            plateau[row][col][1] = 0;
                            bandeauActionEnCours = 0;
                        }
                    } else if (deltaRow == 0 && deltaCol == -1) { // Gauche
                        printf("Déplacement vers la gauche\n");
                        if(plateau[deltaRow][deltaCol][0] == 0){
                            int newCol = col - 1;
                            plateau[row][newCol][1] = plateau[row][col][1];
                            plateau[row][col][1] = 0;
                            bandeauActionEnCours = 0;
                        }
                    } else if (deltaRow == 0 && deltaCol == 1) { // Droite
                        printf("Déplacement vers la droite\n");
                        if(plateau[deltaRow][deltaCol][0] == 0){
                            int newCol = col + 1;
                            plateau[row][newCol][1] = plateau[row][col][1];
                            plateau[row][col][1] = 0;
                            bandeauActionEnCours = 0;
                        }
                    } else {
                        printf("Clic en dehors des cases adjacentes\n");
                        bandeauActionEnCours = 0;
                    }
                }
            }
        }
    }
    sauvegarderPlateau(plateau);
    printf("Fin du déplacement du personnage\n");
}


void actionAttaque(SDL_Renderer *renderer, int row, int col) {
    SDL_Event event;
    int bandeauActionEnCours = 1;

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    const int cols = 20;
    int caseWidth = windowWidth / cols;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe

    // Civilisation liste[4];
    // chargerCivilisation("sauvegarde_civilisation.txt", liste, 0);  // Charger la sauvegarde si elle existe

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0; // Quitter la partie et retourner au menu principal
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                // Calculer la case cliquée
                int clickedRow = mouseY / caseHeight;
                int clickedCol = mouseX / caseWidth;

                // Vérifier si le clic est dans une case adjacente
                if (clickedRow >= 0 && clickedRow < rows && clickedCol >= 0 && clickedCol < cols) {
                    int deltaRow = clickedRow - row -1;
                    int deltaCol = clickedCol - col;


                // TODO:  Ajouter vérification pour les limites de terrain et de troupes


                    // Utiliser des if else pour gérer les cases adjacentes
                    if (deltaRow == -1 && deltaCol == 0) { // Haut
                        printf("Attaque vers le haut\n");
                        if(plateau[deltaRow][deltaCol][1] == 5){
                            
                        } 
                        bandeauActionEnCours = 0;
                    } else if (deltaRow == 1 && deltaCol == 0) { // Bas
                        printf("Attaque vers le bas\n");
                        int newRow = row + 1;
                        plateau[newRow][col][1] = plateau[row][col][1];
                        plateau[row][col][1] = 0;
                        bandeauActionEnCours = 0;
                    } else if (deltaRow == 0 && deltaCol == -1) { // Gauche
                        printf("Attaque vers la gauche\n");
                        int newCol = col - 1;
                        plateau[row][newCol][1] = plateau[row][col][1];
                        plateau[row][col][1] = 0;
                        bandeauActionEnCours = 0;
                    } else if (deltaRow == 0 && deltaCol == 1) { // Droite
                        printf("Attaque vers la droite\n");
                        int newCol = col + 1;
                        plateau[row][newCol][1] = plateau[row][col][1];
                        plateau[row][col][1] = 0;
                        bandeauActionEnCours = 0;
                    } else {
                        printf("Clic en dehors des cases adjacentes\n");
                        bandeauActionEnCours = 0;
                    }
                }
            }
        }
    }
    sauvegarderPlateau(plateau);
    printf("Fin du déplacement du personnage\n");
}


void actionColon(SDL_Renderer *renderer, int row, int col, Civilisation *civilisation) {
    SDL_Event event;
    int bandeauActionEnCours = 1;

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);

    // Vérifier que la position contient un colon
    if (plateau[row][col][1] != 1) {
        printf("Erreur : Pas de colon à la position (%d, %d).\n", row, col);
        return;
    }

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;

                if (mouseY < caseHeight) {
                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    printf("Index du bandeau cliqué : %d\n", bandeauCaseIndex);

                    if (bandeauCaseIndex == 2) {
                        printf("Retour à la partie depuis la case 1 du bandeau\n");
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 3) {
                        plateau[row][col][2] = 1;
                        plateau[row][col][1] = 0;
                        sauvegarderPlateau(plateau);

                        // Ajouter une ville à la civilisation
                        if (civilisation->nbVilles < 35) {

                            Ville * nouvelleVille = malloc(sizeof(Ville));
                            // {
                            //     .posX = col,
                            //     .posY = row,
                            //     .population = 1,
                            //     .nourriture = 1,
                            //     .production = 1,
                            //     .sciences = 1,
                            // };

                            // snprintf(nouvelleVille.nom, sizeof(nouvelleVille.nom), "Ville %d", civilisation->nbVilles + 1);

                            Ville* temp = realloc(civilisation->villes, (civilisation->nbVilles + 1) * sizeof(Ville));
                            if (temp == NULL) {
                                printf("Erreur de mémoire lors de l'ajout de la nouvelle ville.\n");
                            } else {
                                civilisation->villes = temp;
                                civilisation->villes = &nouvelleVille;
                                civilisation->nbVilles++;
                                printf("Ville ajoutée à la civilisation. Total villes : %d\n", civilisation->nbVilles);
                            }
                        } else {
                            printf("Erreur : Nombre maximum de villes atteint pour cette civilisation.\n");
                        }

                        sauvegarderCivilisations(&civilisation, 1);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 4) {
                        actionDeplacement(renderer, row, col);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 9) {
                        printf("Fin de tour depuis la case 9 du bandeau\n");
                    }
                }
            }
        }
    }
    printf("Fin du bandeau d'action du colon \n");
}


void actionGuerrier(SDL_Renderer *renderer, int row, int col){
    SDL_Event event;
    int bandeauActionEnCours = 1;

     int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
             if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0; // Quitter la partie et retourner au menu principal
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseY < caseHeight) { // Clic dans le bandeau d'action

                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    // Gérer le clic sur une des 10 cases du bandeau
                    printf("Clic sur le bandeau, case %d\n", bandeauCaseIndex);
                    if (bandeauCaseIndex == 2) {
                        printf("Retour à la partie depuis la case 1 du bandeau\n");
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 3) {
                        plateau[row][col][2] = 1; // création ville1
                        plateau[row][col][1] = 0; // suppression colon
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 4) {
                        actionDeplacement(renderer,row,col);
                        bandeauActionEnCours = 0;
                        // fonction d'attente pour le déplacement du colon
                        
                    }
                    if (bandeauCaseIndex == 5) {
                        actionAttaque(renderer,row,col);
                        bandeauActionEnCours = 0;
                        // fonction d'attente pour le déplacement du colon
                        
                    }
                    if (bandeauCaseIndex == 9) {
                        // Si la case 0 est cliquée, quitter le jeu et retourner au menu principal
                        printf("Fin de tour depuis la case 9 du bandeau\n");
                    }
                }
            }
        }
    }
    printf("Fin du bandeau d'action du colon \n");
}



void actionBatisseur(SDL_Renderer *renderer, int row, int col){
    SDL_Event event;
    int bandeauActionEnCours = 1;

     int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
             if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0; // Quitter la partie et retourner au menu principal
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseY < caseHeight) { // Clic dans le bandeau d'action

                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    // Gérer le clic sur une des 10 cases du bandeau
                    printf("Clic sur le bandeau, case %d\n", bandeauCaseIndex);
                    if (bandeauCaseIndex == 2) {
                        printf("Retour à la partie depuis la case 1 du bandeau\n");
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 4) {
                        actionDeplacement(renderer,row,col);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 5) {
                        plateau[row][col][2] = 5; // création ferme
                        plateau[row][col][1] = 0; // suppression batisseur
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 6) {
                        plateau[row][col][2] = 4; // création biblio
                        plateau[row][col][1] = 0; // suppression batisseur
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 9) {
                        // Si la case 0 est cliquée, quitter le jeu et retourner au menu principal
                        printf("Fin de tour depuis la case 9 du bandeau\n");
                    }
                }
            }
        }
    }
    printf("Fin du bandeau d'action du colon \n");
}

void actionVille1(SDL_Renderer *renderer, int row, int col){
    SDL_Event event;
    int bandeauActionEnCours = 1;

     int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
             if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0; // Quitter la partie et retourner au menu principal
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseY < caseHeight) { // Clic dans le bandeau d'action

                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    // Gérer le clic sur une des 10 cases du bandeau
                    printf("Clic sur le bandeau, case %d\n", bandeauCaseIndex);
                    if (bandeauCaseIndex == 2) {
                        printf("Retour à la partie depuis la case 1 du bandeau\n");
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 4) {
                        plateau[row][col][1] = 4; // création batisseur
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 5) {
                        plateau[row][col][1] = 1; // création colon
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 6) {
                        plateau[row][col][2] = 2; // création guerrier
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 7) {
                        plateau[row][col][1] = 3; // création archer
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 8) {
                        plateau[row][col][2] += 1 ; // amélioration ville
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 9) {
                        printf("Fin de tour depuis la case 9 du bandeau\n");
                    }
                }
            }
        }
    }
    printf("Fin du bandeau d'action du colon \n");
}




void actionVille3(SDL_Renderer *renderer, int row, int col){
    SDL_Event event;
    int bandeauActionEnCours = 1;

     int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    const int rows = 19;
    int caseHeight = windowHeight / (rows + 1);

    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, 0);  // Charger la sauvegarde si elle existe

    while (bandeauActionEnCours) {
        while (SDL_PollEvent(&event)) {
             if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                bandeauActionEnCours = 0; // Quitter la partie et retourner au menu principal
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;
                if (mouseY < caseHeight) { // Clic dans le bandeau d'action

                    int bandeauCaseWidth = windowWidth / 10;
                    int bandeauCaseIndex = mouseX / bandeauCaseWidth;

                    // Gérer le clic sur une des 10 cases du bandeau
                    printf("Clic sur le bandeau, case %d\n", bandeauCaseIndex);
                    if (bandeauCaseIndex == 2) {
                        printf("Retour à la partie depuis la case 1 du bandeau\n");
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 4) {
                        plateau[row][col][1] = 4; // création batisseur
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 5) {
                        plateau[row][col][1] = 1; // création colon
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;
                    }
                    if (bandeauCaseIndex == 6) {
                        plateau[row][col][2] = 2; // création guerrier
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 7) {
                        plateau[row][col][1] = 3; // création archer
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 8) {
                        plateau[row][col][2] += 1 ; // amélioration ville
                        sauvegarderPlateau(plateau);
                        bandeauActionEnCours = 0;                        
                    }
                    if (bandeauCaseIndex == 9) {
                        printf("Fin de tour depuis la case 9 du bandeau\n");
                    }
                }
            }
        }
    }
    printf("Fin du bandeau d'action du colon \n");
}