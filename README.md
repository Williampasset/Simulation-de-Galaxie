# DM - Simulation de Galaxie

## Table des matières
- [Description](#description)
- [Fonctionnalités](#fonctionnalités)
- [Démarches](#démarches)
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
  - Génération optimiser suivant une loi normale pour une simulation plus réaliste
- ### Exploration interactive:
  - Contrôles de la caméra (translation, zoom).
  - Visualisation de la simulation en temps réel.
- ### Affichage 3D:
  - Utilisation de la bibliothèque **Raylib** pour représenter les corps et leurs interactions dans un environnement spatial.
- ### Paramètres configurables:
  - Possibilités de rentrer le nombre de corps de la galaxie ainsi que la taille de l'espace où ceci sont générés en ligne de commande

## Démarches
La première étape de ce devoir était de réaliser une simple simulation d'une galaxie en 2D. Il y avait donc une structure de corps et une structure de galaxie. Chaque corps était généré avec une masse aléatoire entre une valeur minimale et maximale sans distinction de type (planètes, trous noirs, étoiles, astéroïdes). Pour rendre la simulation plus visuel, j'ai fais le choix de donner à chaque corps une couleur en fonction de leur vitesse ce qui m'a permis de voir les possibles problèmes de calcul et les intéractions entre chacun. J'avais donc une simulation en 2D avec des corps qui se déplaçaient toujours dans la même direction et avec la même vitesse initiale.
Le principal problème que j'ai rencontré lors du développement a été la génération de corps réalistes qui pouvaient s'afficher facilement. En effet, les premiers corps que je générais avaient une masse entre 10 tonne et 100 tonne, ce qui donnait des intéractions trop faibles pour pouvoir être observer.
La seconde étape était de savoir comment améliorer mon programme qui rentrait déjà dans les consignes du devoir. J'ai donc opté pour une simulation 3D qui n'a pas été si complexe à mettre en place car il fallait juste ajouter la gestion d'une 3ème composante.
J'ai fais le choix de rester sur un simple tableau car je ne pensais pas rentrer dans un nombre de corps trop élevés, j'aurais pu cependant utiliser tout de même une liste chaînée pour ma galaxie, ce qui m'aurait permis de faire une simulation plus fluide.
Pour ce devoir, je n'ai pas grandement utiliser d'IA, seulement pour de la documentation notamment pour la génération de la galaxie suivant la loi normale. 

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
 
## Structure du devoir:
- **main.c**: Point d'entrée du programme, gestion de la boucle principale et des entrées utilisateur.
- **config.h**: Définition des constantes du projet tel que la constante gravitationnelle, la taille de l'écran, le nombre de corps par défaut...
- **display.c**: Gestion de l'affichage des différents corps
- **body.c**: Gestion de la génération des corps, de la galaxie et des conditions initiales
- **physics.c**: Gestion de la physique complète de la galaxie avec le calcul des forces, positions, vitesses et accèlerations
- **display.h**: Définition des prototypes pour l'affichage
- **body.h**: Définition des différentes structures et prototypes pour les corps
- **physics.h**: Définition des prototypes pour la physique

## Améliorations potentielles:
- Ajout des collisions entre les corps (précédemment implémenté mais des problèmes sont survenus suite à l'ajout des types de corps)
- Optimisation des calculs pour un très grand nombre de corps
- Ajout des threads pour une simulation plus fluide et des calculs en parallèles (conflit entre raylib et windows.h, possible sous une VM linux)
- Possibilité de faire intéragir plusieurs galaxies entre elles
- Améliorer l'affichage
- Ajout d'un fichier makefile, meson ou Cmake pour facilité la compilation

## Améliorations personnelles:
Ce devoir m'a permis d'être plus à l'aise avec le langage C que ce soit dans la gestion de la mémoire, la structuration des différents fichiers et les différentes notions vues en cours. Malgrè une simulation imparfaite, je suis tout de même fier du rendu de ce devoir.

## Auteur
- **William Passet**
- **william.passet@student.junia.com**

