#include "config.h"

/// <summary>
/// Structure représentant les corps (étoiles, planètes...) de notre galaxie
/// </summary>
typedef struct Bodies{
	float* position;
	float* vitesse;
	float* acceleration;
	float* masse;
	float* rayon;
}Body;

typedef struct Galaxy{
	Body* bodies;
	int n;
	float* position;
}Galaxy;


void initBody(Body* body, float* position, float* vitesse, float* acceleration, float* masse, float* rayon);
void updateBody(Body* body);
void freeBody(Body* body);

void initGalaxy(Galaxy* galaxy, int n, float* position);
void freeGalaxy(Galaxy* galaxy);

//Implémentation dans le fichier 'body.c'