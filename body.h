#include "config.h"


/// <summary>
/// Structure représentant les corps (étoiles, planètes...) de notre galaxie
/// </summary>
typedef struct Bodies{
	float* position;
	float* vitesse;
	float* acceleration;
	float* masse;
}Body;


void initBody(Body* body, float* position, float* vitesse, float* acceleration, float* masse);
void updateBody(Body* body, float* force, float* acceleration);
void freeBody(Body* body);

//Implémentation dans le fichier 'body.c'
