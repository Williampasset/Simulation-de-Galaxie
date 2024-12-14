//config.h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#ifndef CONFIG_H
#define CONFIG_H

#define G 6.64730e-11 // Constante gravitationnelle (modifier par convenance)
#define NUM_BODIES 500
#define TIMESTEP 0.01
#define GRID_WIDTH 1080
#define GRID_HEIGHT 720
#define SPACE_LIMIT 300
#define DIMENSION 3
// #define MAX_MASS 1000000000
#define GALAXY_NUMBER 1
#define PI 3.14159265358979323846
#define EPSILON 1e-2 // Valeur minimale pour la distance entre 2 corps (pour éviter des accelerations infinies)

#endif // !CONFIG_H
