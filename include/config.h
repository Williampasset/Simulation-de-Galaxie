//config.h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#ifndef CONFIG_H
#define CONFIG_H

#define G 6.64730e-11 // Constante gravitationnelle (modifier par convenance)
#define NUM_BODIES 500 // Nombre de corps
#define TIMESTEP 0.01 // Pas de temps
#define GRID_WIDTH 1080 // Largeur de la fenêtre
#define GRID_HEIGHT 720 // Hauteur de la fenêtre
#define SPACE_LIMIT 200 // Limite de l'espace pour la génération des corps
#define DIMENSION 3 // Nombre de dimensions
#define GALAXY_NUMBER 1 // Nombre de galaxies
#define PI 3.14159265358979323846 // Valeur de PI (approximative)
#define EPSILON 1e-2 // Valeur minimale pour la distance entre 2 corps (pour éviter des accelerations infinies)

#endif // CONFIG_H