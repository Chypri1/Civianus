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

// Fonction pour sauvegarder le plateau dans un fichier texte
void sauvegarderPlateau(int plateau[19][20][3]) {
    FILE *fichier = fopen("sauvegarde_plateau.txt", "w");
    if (!fichier) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 20; j++) {
            fprintf(fichier, "%d %d %d ", plateau[i][j][0], plateau[i][j][1], plateau[i][j][2]); // Écrit l'index de la texture de chaque case
        }
        fprintf(fichier, "\n"); // Retour à la ligne pour chaque nouvelle ligne du plateau
    }

    fclose(fichier);
    printf("Plateau sauvegardé avec succès.\n");
}


// Fonction pour sauvegarder l'état du plateau dans un fichier texte
void créationPlateau() {
    // Définir la taille du plateau
    const int rows = 19;
    const int cols = 20;

    // Ouvrir le fichier en mode écriture
    FILE *fichier = fopen("sauvegarde_plateau.txt", "w");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }
    int colon_place = 0;
    // Sauvegarder l'état du plateau dans le fichier
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Choisir un terrain aléatoire (0 = herbe, 1 = eau, 2 = montagne)
            int randValue = rand() % 100;
            int terrainType = 0;
            int personnage = 0;
            int batiment = 0;
            if (randValue < 70) {
                if (colon_place == 1)
                {
                    terrainType = 0;  
                    personnage = (randValue < 15 ? 5:0); // ajout de barbare
                }
                else{
                    terrainType = 0;  
                    personnage = (randValue < 15 ? 5:0); // ajout de barbare
                    if(randValue > 45){
                        personnage = 1; // ajout de barbare
                        colon_place = 1;
                    } 
                }
            } else if (randValue < 85) {
                terrainType = 1;  // eau
            } else {
                terrainType = 2;  // montagne
            }

            // Sauvegarder le type de terrain dans le fichier
            fprintf(fichier, "%d %d %d ", terrainType, personnage, batiment);
        }
        fprintf(fichier, "\n");  // Passer à la ligne suivante pour chaque rangée
    }


    // Fermer le fichier
    fclose(fichier);
    printf("Sauvegarde du plateau effectuée dans %s.\n", "sauvegarde_plateau.txt");
}



// Fonction pour charger l'état du plateau depuis un fichier texte
void chargerPlateau(const char *nomFichier, int plateau[19][20][3], int nouvellePartie) {
    if(nouvellePartie){
        créationPlateau();
    }
    FILE *fichier = fopen(nomFichier, "r");
    // Lire les données du fichier et remplir le tableau plateau
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 20; j++) {
            fscanf(fichier, "%d %d %d ", &plateau[i][j][0], &plateau[i][j][1], &plateau[i][j][2]);
        } 
    }
    fclose(fichier);
    printf("Plateau chargé depuis %s.\n", nomFichier);
}




/// Fonction pour dessiner le plateau
void dessinerPlateau(SDL_Renderer *renderer, int windowWidth, int windowHeight, int caseWidth, int caseHeight, int nouvellePartie) {
    // Charger plusieurs images et les stocker dans un tableau de textures
    const int nbTextures = 3;
    SDL_Texture *textures[nbTextures];
    textures[0] = IMG_LoadTexture(renderer, "src/img/tuileFond/herbe.png");
    textures[1] = IMG_LoadTexture(renderer, "src/img/tuileFond/eau.png");
    textures[2] = IMG_LoadTexture(renderer, "src/img/tuileFond/montagne.png");

   // Vérification des erreurs de chargement
    for (int i = 0; i < nbTextures; i++) {
        if (!textures[i]) {
            printf("Erreur de chargement de l'image %d : %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées et quitter
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(textures[j]);
            }
            return;
        }
    }

    const int nbTexturesPersonnages = 5;
    SDL_Texture *texturesPersonnages[nbTexturesPersonnages];
    texturesPersonnages[0] = IMG_LoadTexture(renderer, "src/img/personnage/colon.png");
    texturesPersonnages[1] = IMG_LoadTexture(renderer, "src/img/personnage/guerrier.png");
    texturesPersonnages[2] = IMG_LoadTexture(renderer, "src/img/personnage/archer.png");
    texturesPersonnages[3] = IMG_LoadTexture(renderer, "src/img/personnage/batisseur.png");
    texturesPersonnages[4] = IMG_LoadTexture(renderer, "src/img/personnage/barbare.png");
    // Vérification des erreurs de chargement
    for (int i = 0; i < nbTexturesPersonnages; i++) {
        if (!texturesPersonnages[i]) {
            printf("Erreur de chargement de l'image %d : %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées et quitter
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(texturesPersonnages[j]);
            }
            return;
        }
    }

    const int nbTexturesBatiment = 5;

    SDL_Texture *texturesBatiment[nbTexturesBatiment];
    texturesBatiment[0] = IMG_LoadTexture(renderer, "src/img/tuileBatiment/ville1.png");
    texturesBatiment[1] = IMG_LoadTexture(renderer, "src/img/tuileBatiment/ville2.png");
    texturesBatiment[2] = IMG_LoadTexture(renderer, "src/img/tuileBatiment/ville3.png");
    texturesBatiment[3] = IMG_LoadTexture(renderer, "src/img/tuileBatiment/biblio.png");
    texturesBatiment[4] = IMG_LoadTexture(renderer, "src/img/tuileBatiment/ferme.png");

    // Vérification des erreurs de chargement
    for (int i = 0; i < nbTexturesBatiment; i++) {
        if (!texturesBatiment[i]) {
            printf("Erreur de chargement de l'image %d : %s\n", i, SDL_GetError());
            // Libérer les textures déjà chargées et quitter
            for (int j = 0; j < i; j++) {
                SDL_DestroyTexture(texturesBatiment[j]);
            }
            return;
        }
    }

    const int rows = 19;  // 19 lignes pour le plateau
    const int cols = 20;

    // Plateau 2D pour stocker les types de terrain
    int plateau[19][20][3];
    chargerPlateau("sauvegarde_plateau.txt", plateau, nouvellePartie);  // Charger la sauvegarde si elle existe

    // Dessiner le plateau avec les images chargées ou avec des images aléatoires si pas de sauvegarde
    for (int i = 1; i <= rows; i++) { // Commencer à 1 pour laisser place au bandeau
        for (int j = 0; j < cols; j++) {
            SDL_Rect caseRect = { j * caseWidth, i * caseHeight, caseWidth, caseHeight };
            int terrainType = plateau[i - 1][j][0]; // Utiliser la sauvegarde ou une valeur par défaut
            int personnage = plateau[i - 1][j][1];
            int batiment = plateau[i - 1][j][2];
            // Dessiner la texture correspondant au type de terrain
             if(batiment != 0){
                SDL_RenderCopy(renderer, texturesBatiment[batiment - 1], NULL, &caseRect);
            }
            else if(personnage != 0){
                SDL_RenderCopy(renderer, textures[terrainType], NULL, &caseRect);
                SDL_RenderCopy(renderer, texturesPersonnages[personnage - 1], NULL, &caseRect);
            }
            else{
                SDL_RenderCopy(renderer, textures[terrainType], NULL, &caseRect);
            }
        }
    }

    // Libérer toutes les textures à la fin
    for (int i = 0; i < nbTextures; i++) {
        SDL_DestroyTexture(textures[i]);
    }

     // Libérer toutes les texturesBatiment à la fin
    for (int i = 0; i < nbTexturesBatiment; i++) {
        SDL_DestroyTexture(texturesBatiment[i]);
    }

    // Libérer toutes les texturesBatiment à la fin
    for (int i = 0; i < nbTexturesPersonnages; i++) {
        SDL_DestroyTexture(texturesPersonnages[i]);
    }
}


// Fonction principale qui appelle les deux autres fonctions
void initPlateau(SDL_Renderer *renderer, int nouvellePartie) {
    // Initialisation de la génération de nombres aléatoires
    srand((unsigned int)time(NULL));

    // Obtenir la taille de la fenêtre
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    // Définir la taille des cases pour le plateau
    const int rows = 19;  // 19 lignes pour le plateau, 1 ligne pour le bandeau
    const int cols = 20;
    int caseWidth = windowWidth / cols;
    int caseHeight = windowHeight / (rows + 1); // Inclure le bandeau

    // Effacer l'écran et définir la couleur du fond
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Couleur de fond (noir)
    SDL_RenderClear(renderer);

    // Dessiner le bandeau d'action avec des images
    dessinerBandeauActionAvecImages(renderer, windowWidth, caseHeight);
    // dessinerBandeauAction(renderer, windowWidth, caseHeight);

    // Dessiner le plateau avec les cases de terrain (herbe, eau, montagne)
    dessinerPlateau(renderer, windowWidth, windowHeight, caseWidth, caseHeight, nouvellePartie);

    // Mettre à jour l'écran
    SDL_RenderPresent(renderer);
}

