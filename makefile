# Inclure Makefile.compilation pour gérer les dépendances en fonction du système
include Makefile.compilation

# Paramètres pour SDL
SDL = -I include -lSDL2main -lSDL2 -lSDL2_image $(LDFLAGS)

BIN = bin/main
OBJ = obj/menu.o obj/petite_fonction.o obj/partie.o obj/plateau.o obj/bandeauAction.o obj/AffichageBandeauPlateau.o obj/actionPersonnage.o obj/structureCivilisation.o obj/main.o 

# Raccourcis pour la compilation
CFLAGS = -Wall
CCLNK = gcc
CCOBJ = gcc -c
LIBMATH = -lm

# Compilation des exécutables principaux
all: $(BIN)

bin/main: $(OBJ)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(OBJ) -o bin/main $(SDL)

# Compilation des fichiers objets
obj/main.o: src/main.c include/main.h include/petite_fonction.h include/menu.h include/partie.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/main.c -o obj/main.o $(SDL)

obj/petite_fonction.o: src/petite_fonction.c include/petite_fonction.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/petite_fonction.c -o obj/petite_fonction.o $(SDL)

obj/menu.o: src/menu.c include/petite_fonction.h include/main.h include/menu.h 
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/menu.c -o obj/menu.o $(SDL)

obj/partie.o: src/partie.c include/petite_fonction.h include/main.h include/partie.h include/plateau.h include/actionPersonnage.h include/structureCivilisation.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/partie.c -o obj/partie.o $(SDL)

obj/plateau.o: src/plateau.c include/plateau.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/plateau.c -o obj/plateau.o $(SDL)

obj/bandeauAction.o: src/bandeauAction.c include/bandeauAction.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/bandeauAction.c -o obj/bandeauAction.o $(SDL)

obj/AffichageBandeauPlateau.o: src/AffichageBandeauPlateau.c include/AffichageBandeauPlateau.h include/bandeauAction.h include/plateau.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/AffichageBandeauPlateau.c -o obj/AffichageBandeauPlateau.o $(SDL)

obj/actionPersonnage.o: src/actionPersonnage.c include/actionPersonnage.h include/bandeauAction.h include/plateau.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/actionPersonnage.c -o obj/actionPersonnage.o $(SDL)

obj/structureCivilisation.o: src/structureCivilisation.c include/structureCivilisation.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/structureCivilisation.c -o obj/structureCivilisation.o $(SDL)

# Commandes de nettoyage
clean:
	- rm obj/*.o
	- rm bin/main
	@echo "Nettoyage terminé."

# Commandes pour exécuter les programmes
main:
	./bin/main
