//physics.c

#include "physics.h"

/// <summary>
/// La fonction 'computeGravitationalForce' calcule la force qui s'applique entre 2 corps
/// </summary>
/// <param name="a">Premier corps</param>
/// <param name="b">Second corps</param>
void computeGravitationalForce(Body *a, Body *b){
    float distance = 0;
    float force = 0;
    float direction[DIMENSION];

    for (int i = 0; i < DIMENSION; i++) {
        direction[i] = b->position[i] - a->position[i];
        distance += direction[i] * direction[i];
    }


    distance = sqrt(distance);

    if(distance < 10){
        distance = 10;
    }

    for (int i = 0; i < DIMENSION; i++) {
        direction[i] /= distance;
    }

    force = (G * *a->masse * *b->masse) / (distance * distance);


    for (int i = 0; i < DIMENSION; i++) {
        float acceleration_contribution = force * direction[i] / distance;
        if(*a->acceleration > 1000 || *b->acceleration > 1000){
            a->acceleration[i] = 0;
            b->acceleration[i] = 0;
        }
        a->acceleration[i] += acceleration_contribution / *a->masse;
        b->acceleration[i] -= acceleration_contribution / *b->masse;
    }

}



/// <summary>
/// La fonction 'applyForces' fait appel � la fonction 'computeGravitationalForce' pour calculer l'ensemble des forces qui s'appliquent
/// sur l'ensemble des corps de la galaxie
/// </summary>
/// <param name="bodies">Tableau des corps dont on veut calculer les diff�rentes forces</param>
/// <param name="n">Nombres de corps existant</param>
void applyForces(Body* bodies, int* n){
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; j++) {
            computeGravitationalForce((bodies + i), (bodies + j));
        }
    }
}

void checkCollision(Body* a, Body* b){
    float distance = 0;
    for (int i = 0; i < DIMENSION; i++) {
        distance += (b->position[i] - a->position[i]) * (b->position[i] - a->position[i]);
    }

    distance = sqrt(distance);

    if(distance < *a->rayon + *b->rayon){
        float newMasse = *a->masse + *b->masse;
        for (int i = 0; i < DIMENSION; i++) {
            a->position[i] = (a->position[i] * *a->masse + b->position[i] * *b->masse) / newMasse;
            a->vitesse[i] = (a->vitesse[i] * *a->masse + b->vitesse[i] * *b->masse) / newMasse;
        }

        *a->masse = newMasse;
        *a->rayon = sqrt(newMasse) * 0.1;
        *b->masse = 0;
        *b->rayon = 0;
    }
}