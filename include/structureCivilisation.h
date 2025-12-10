/**
 * \file plateau.h
 * 
 * \brief Fichier de définition des codes de retour de fonction pour l'appel
 * des différents modules du projet.
 * 
 */

#ifndef _CIVILISATION_
#define _CIVILISATION_


// Structure pour une ville
typedef struct {
    char nom[50];
    int population;
    int posX;
    int posY;
    int production; // Valeur de production de la ville
    int nourriture; // Valeur de nourriture produite par la ville
    int sciences;   // Valeur de sciences produite par la ville
} Ville;

// Structure pour un guerrier
typedef struct {
    char nom[50];
    int pointsVie; // Points de vie du guerrier
    int attaque;   // Points d'attaque du guerrier
    int posX;
    int posY;
} Guerrier;

// Structure pour un archer
typedef struct {
    char nom[50];
    int pointsVie; // Points de vie de l'archer
    int attaque;   // Points d'attaque de l'archer
    int portee;    // Portée de tir de l'archer
    int posX;
    int posY;
} Archer;

// Structure pour un colon
typedef struct {
    char nom[50];
    int posX;
    int posY;
    int pointsVie; // Points de vie du colon
    int peutFonderVille; // Booléen (1 ou 0) indiquant s'il peut fonder une ville
} Colon;

// Structure pour un bâtisseur
typedef struct {
    char nom[50];
    int pointsVie; // Points de vie du bâtisseur
    int chargesRestantes; // Nombre de charges de construction restantes
    int posX;
    int posY;
} Batisseur;

// Structure principale pour une civilisation
typedef struct {
    char nom[50];
    int productionTotale; // Production totale de la civilisation
    int nourritureTotale; // Nourriture totale de la civilisation
    int sciencesTotales;  // Sciences totales de la civilisation

    Ville** villes;       // Liste des villes
    int nbVilles;        // Nombre de villes

    Guerrier** guerriers; // Liste des guerriers
    int nbGuerriers;     // Nombre de guerriers

    Archer** archers;     // Liste des archers
    int nbArchers;       // Nombre d'archers

    Colon** colons;       // Liste des colons
    int nbColons;        // Nombre de colons

    Batisseur** batisseurs; // Liste des bâtisseurs
    int nbBatisseurs;      // Nombre de bâtisseurs
} Civilisation;



Civilisation** creerCivilisations(int nbJoueur);
void sauvegarderCivilisations(Civilisation **civilisations, int nbJoueur);
Civilisation** chargerCivilisations(int* nbJoueur);
#endif // _CIVILISATION_