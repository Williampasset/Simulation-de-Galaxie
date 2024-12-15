# DM - Simulation de Galaxie

## Table des matières
- [Description](#description)
- [Fonctionnalités](#fonctionnalités)
- [Utilisation](#utilisation)
- [Structure du devoir](#structuredudevoir)
- [Améliorations potentielles](#améliorationspotentielles)
- [Améliorations personnelles](#améliorationspersonnelles)

## Description

Ce devoir est une simulation de galaxie en 3D, implémenté en C avec la bibliothèque **Raylib** pour l'affichage. L'objectif de ce devoir est de modéliser le comportement de corps célestes en utilisant des lois physiques telle que les lois de la gravitation.
Les corps (astéroïdes, planètes, étoiles, trous noirs) interagissent entre eux via des forces gravitationnelles.

## Fonctionnalités
- ### Simulation physique:
  - Calcul des forces gravitationnelles entre les corps.
  - Types de corps : astéroïdes, planètes, étoiles, trous noirs.
  - Génération optimiser suivant une loi normale
- ### Exploration interactive:
  - Contrôles de la caméra (translation, zoom).
  - Visualisation de la simulation en temps réel.
- ### Affichage 3D:
  - Utilisation de la bibliothèque **Raylib** pour représenter les corps et leurs interactions dans un environnement spatial.
- ### Paramètres configurables:
  - Possibilités de rentrer le nombre de corps de la galaxie ainsi que la taille de l'espace où ceci sont générés en ligne de commande

## Compilation
- **Compiler C** (GCC...)
- **Raylib** (à installer via leur site internet(#https://www.raylib.com/))

### 1. Clonez le dépôt
```bash
**git clone** `<URL_DU_DEPOT>`
```
### 2. Compilez le projet
```bash
gcc main.c physics.c body.c display.c -o galaxie.exe -lraylib -lm -lopengl32 -lgdi32 -lwinmm
```

### 3. Exécutez le programme
```bash
./galaxie
```

## Utilisation

### Contrôles
- **Démarrer la simulation**: Appuyez sur entrée
- **Explorer la galaxie**:
  - Translation de la caméra: Flèches directionnelles (Haut, bas, droite, gauche)
  - Monter/Descendre: **P** et **M**
  - Zoom: Molette de la souris
 
## Structure du devoir: {#structuredudevoir}
- **main.c**: Point d'entrée du programme, gestion de la boucle principale et des entrées utilisateur.
- **config.h**: Définition des constantes du projet tel que la constante gravitationnelle, la taille de l'écran, le nombre de corps par défaut...
- **display.c**: Gestion de l'affichage des différents corps
- **body.c**: Gestion de la génération des corps, de la galaxie et des conditions initiales
- **physics.c**: Gestion de la physique complète de la galaxie avec le calcul des forces, positions, vitesses et accèlerations
- **display.h**: Définition des prototypes pour l'affichage
- **body.h**: Définition des différentes structures et prototypes pour les corps
- **physics.h**: Définition des prototypes pour la physique

## Améliorations potentielles: {#améliorationspotentielles}
- Ajout des collisions entre les corps (précédemment implémenté mais des problèmes sont survenus suite à l'ajout des types de corps)
- Optimisation des calculs pour un très grand nombre de corps
- Ajout des threads pour une simulation plus fluide et des calculs en parallèles (conflit entre raylib et windows.h, possible sous une VM linux)
- Possibilité de faire intéragir plusieurs galaxies entre elles
- Améliorer l'affichage
- Ajout d'un fichier makefile, meson ou Cmake pour facilité la compilation

## Améliorations personnelles: {#améliorationspersonnelles}
Ce devoir m'a permis d'être plus à l'aise avec le langage C que ce soit dans la gestion de la mémoire, la structuration des différents fichiers et les différentes notions vues en cours. Malgrè une simulation imparfaite, je suis tout de même fier du rendu de ce devoir.

## Auteur
- **William Passet**
- **william.passet@student.junia.com**

