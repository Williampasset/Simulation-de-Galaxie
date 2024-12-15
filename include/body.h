#include "config.h"


///TODO: Ajouter les types de corps possible (étoile, planète, astéroïde...)
///Enum ci-dessous:
typedef enum { STAR, PLANET, BLACK_HOLE, ASTEROID } BodyType;

/// <summary>
/// Structure représentant les corps (étoiles, planètes...) de notre galaxie
/// </summary>
typedef struct Body {
    float position[DIMENSION];
    float vitesse[DIMENSION];
    float acceleration[DIMENSION];
    float masse;
    float rayon;
    BodyType type;
} Body;


typedef struct Galaxy{
	Body* bodies;
	int n;
	float centre[DIMENSION];
}Galaxy;

float gaussianRandom(float mean, float stddev);

void initBody(Body* body, float* position, float* vitesse, float* acceleration, float* masse, float* rayon);
void updateBody(Body* body);

void initGalaxy(Galaxy* galaxy, int n, float* position, float spaceLimit);
void freeGalaxy(Galaxy* galaxy);

//Implémentation dans le fichier 'body.c'