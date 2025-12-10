#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structureCivilisation.h"


Civilisation** creerCivilisations(int nbJoueur) {
    Civilisation** civilisations = malloc(nbJoueur * sizeof(Civilisation*));
    if (!civilisations) {
        printf("Erreur d'allocation mémoire pour les civilisations.\n");
        return NULL;
    }

    for (int i = 0; i < nbJoueur; i++) {
        civilisations[i] = malloc(sizeof(Civilisation));
        if (!civilisations[i]) {
            printf("Erreur d'allocation mémoire pour la civilisation %d.\n", i + 1);
            continue;
        }

        // Initialisation des attributs de la civilisation
        snprintf(civilisations[i]->nom, sizeof(civilisations[i]->nom), "Civilisation %d", i + 1);
        civilisations[i]->productionTotale = 100 + i * 10;
        civilisations[i]->nourritureTotale = 200 + i * 20;
        civilisations[i]->sciencesTotales = 300 + i * 30;

        // Initialisation des villes (aucune par défaut)
        civilisations[i]->nbVilles = 0;
        civilisations[i]->villes = malloc(35 * sizeof(Ville*));

        // Initialisation des guerriers
        civilisations[i]->nbGuerriers = 2;
        civilisations[i]->guerriers = malloc(civilisations[i]->nbGuerriers * sizeof(Guerrier*));
        for (int j = 0; j < civilisations[i]->nbGuerriers; j++) {
            civilisations[i]->guerriers[j] = malloc(sizeof(Guerrier));
            snprintf(civilisations[i]->guerriers[j]->nom, sizeof(civilisations[i]->guerriers[j]->nom), "Guerrier %d", j + 1);
            civilisations[i]->guerriers[j]->pointsVie = 50 + j * 10;
            civilisations[i]->guerriers[j]->attaque = 15 + j * 5;
            civilisations[i]->guerriers[j]->posX = -1;
            civilisations[i]->guerriers[j]->posY = -1;
        }

        // Initialisation des archers
        civilisations[i]->nbArchers = 1;
        civilisations[i]->archers = malloc(civilisations[i]->nbArchers * sizeof(Archer*));
        for (int j = 0; j < civilisations[i]->nbArchers; j++) {
            civilisations[i]->archers[j] = malloc(sizeof(Archer));
            snprintf(civilisations[i]->archers[j]->nom, sizeof(civilisations[i]->archers[j]->nom), "Archer %d", j + 1);
            civilisations[i]->archers[j]->pointsVie = 40 + j * 10;
            civilisations[i]->archers[j]->attaque = 20 + j * 5;
            civilisations[i]->archers[j]->portee = 3 + j;
            civilisations[i]->archers[j]->posX = -1;
            civilisations[i]->archers[j]->posY = -1;
        }

        // Initialisation des colons
        civilisations[i]->nbColons = 1;
        civilisations[i]->colons = malloc(civilisations[i]->nbColons * sizeof(Colon*));
        for (int j = 0; j < civilisations[i]->nbColons; j++) {
            civilisations[i]->colons[j] = malloc(sizeof(Colon));
            snprintf(civilisations[i]->colons[j]->nom, sizeof(civilisations[i]->colons[j]->nom), "Colon %d", j + 1);
            civilisations[i]->colons[j]->pointsVie = 30;
            civilisations[i]->colons[j]->peutFonderVille = 1;
            civilisations[i]->colons[j]->posX = i;
            civilisations[i]->colons[j]->posY = 0;
        }

        // Initialisation des bâtisseurs
        civilisations[i]->nbBatisseurs = 0;
        civilisations[i]->batisseurs = malloc(civilisations[i]->nbBatisseurs * sizeof(Batisseur*));
    }

    return civilisations;
}


Civilisation** chargerCivilisations(int* nbJoueur) {
    FILE *fichier = fopen("sauvegarde_civilisation.txt", "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier de chargement");
        return NULL;
    }

    // Lecture du nombre djoueurs
    fscanf(fichier, "%d\n", nbJoueur);
    Civilisation **civilisations = malloc(*nbJoueur * sizeof(Civilisation*));

    for (int i = 0; i < *nbJoueur; i++) {
        Civilisation *civ = malloc(sizeof(Civilisation));
        fscanf(fichier, "%s %d %d %d\n", civ->nom, &civ->productionTotale, &civ->nourritureTotale, &civ->sciencesTotales);

        // Chargement des villes
        fscanf(fichier, "%d\n", &civ->nbVilles);
        civ->villes = malloc(civ->nbVilles * sizeof(Ville*));
        for (int j = 0; j < civ->nbVilles; j++) {
            Ville *ville = malloc(sizeof(Ville));
            fscanf(fichier, "%s %d %d %d %d %d %d\n", ville->nom, &ville->population, &ville->posX, &ville->posY,
                   &ville->production, &ville->nourriture, &ville->sciences);
            civ->villes[j] = ville;
        }

        // Chargement des guerriers
        fscanf(fichier, "%d\n", &civ->nbGuerriers);
        civ->guerriers = malloc(civ->nbGuerriers * sizeof(Guerrier*));
        for (int j = 0; j < civ->nbGuerriers; j++) {
            Guerrier *guerrier = malloc(sizeof(Guerrier));
            fscanf(fichier, "%s %d %d %d %d\n", guerrier->nom, &guerrier->pointsVie, &guerrier->attaque,
                   &guerrier->posX, &guerrier->posY);
            civ->guerriers[j] = guerrier;
        }

        // Chargement des archers
        fscanf(fichier, "%d\n", &civ->nbArchers);
        civ->archers = malloc(civ->nbArchers * sizeof(Archer*));
        for (int j = 0; j < civ->nbArchers; j++) {
            Archer *archer = malloc(sizeof(Archer));
            fscanf(fichier, "%s %d %d %d %d %d\n", archer->nom, &archer->pointsVie, &archer->attaque, &archer->portee,
                   &archer->posX, &archer->posY);
            civ->archers[j] = archer;
        }

        // Chargement des colons
        fscanf(fichier, "%d\n", &civ->nbColons);
        civ->colons = malloc(civ->nbColons * sizeof(Colon*));
        for (int j = 0; j < civ->nbColons; j++) {
            Colon *colon = malloc(sizeof(Colon));
            fscanf(fichier, "%s %d %d %d %d\n", colon->nom, &colon->posX, &colon->posY, &colon->pointsVie,
                   &colon->peutFonderVille);
            civ->colons[j] = colon;
        }

        // Chargement des bâtisseurs
        fscanf(fichier, "%d\n", &civ->nbBatisseurs);
        civ->batisseurs = malloc(civ->nbBatisseurs * sizeof(Batisseur*));
        for (int j = 0; j < civ->nbBatisseurs; j++) {
            Batisseur *batisseur = malloc(sizeof(Batisseur));
            fscanf(fichier, "%s %d %d %d %d\n", batisseur->nom, &batisseur->pointsVie, &batisseur->chargesRestantes,
                   &batisseur->posX, &batisseur->posY);
            civ->batisseurs[j] = batisseur;
        }

        civilisations[i] = civ;
    }

    fclose(fichier);
    return civilisations;
}


void sauvegarderCivilisations(Civilisation **civilisations, int nbJoueur) {
    FILE *fichier = fopen("sauvegarde_civilisation.txt", "w");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
        return;
    }

    fprintf(fichier, "%d\n", nbJoueur); // Sauvegarde du nombre de joueurs

    for (int i = 0; i < nbJoueur; i++) {
        Civilisation *civ = civilisations[i];
        fprintf(fichier, "%s %d %d %d\n", civ->nom, civ->productionTotale, civ->nourritureTotale, civ->sciencesTotales);

        // Sauvegarde des villes
        fprintf(fichier, "%d\n", civ->nbVilles);
        for (int j = 0; j < civ->nbVilles; j++) {
            Ville *ville = &civ->villes[j];
            fprintf(fichier, "%s %d %d %d %d %d %d\n", ville->nom, ville->population, ville->posX, ville->posY,
                    ville->production, ville->nourriture, ville->sciences);
        }

        // Sauvegarde des guerriers
        fprintf(fichier, "%d\n", civ->nbGuerriers);
        for (int j = 0; j < civ->nbGuerriers; j++) {
            Guerrier *guerrier = &civ->guerriers[j];
            fprintf(fichier, "%s %d %d %d %d\n", guerrier->nom, guerrier->pointsVie, guerrier->attaque,
                    guerrier->posX, guerrier->posY);
        }

        // Sauvegarde des archers
        fprintf(fichier, "%d\n", civ->nbArchers);
        for (int j = 0; j < civ->nbArchers; j++) {
            Archer *archer = &civ->archers[j];
            fprintf(fichier, "%s %d %d %d %d %d\n", archer->nom, archer->pointsVie, archer->attaque, archer->portee,
                    archer->posX, archer->posY);
        }

        // Sauvegarde des colons
        fprintf(fichier, "%d\n", civ->nbColons);
        for (int j = 0; j < civ->nbColons; j++) {
            Colon *colon = &civ->colons[j];
            fprintf(fichier, "%s %d %d %d %d\n", colon->nom, colon->posX, colon->posY, colon->pointsVie,
                    colon->peutFonderVille);
        }

        // Sauvegarde des bâtisseurs
        fprintf(fichier, "%d\n", civ->nbBatisseurs);
        for (int j = 0; j < civ->nbBatisseurs; j++) {
            Batisseur *batisseur = &civ->batisseurs[j];
            fprintf(fichier, "%s %d %d %d %d\n", batisseur->nom, batisseur->pointsVie, batisseur->chargesRestantes,
                    batisseur->posX, batisseur->posY);
        }
    }

    fclose(fichier);
}
