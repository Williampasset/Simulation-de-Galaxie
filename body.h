#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define DIMENSION 3

/// <summary>
/// Structure représentant les objets de notre galaxie
/// </summary>
typedef struct Objet {
	float* position;
	float* vitesse; 
	float* acceleration;
	float* masse;
}Objet;

typedef struct Galaxie {
	Objet* Items;
	int* size;

};
