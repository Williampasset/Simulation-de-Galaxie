//physics.c

#include "include/physics.h"

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
    force = (G * *a->masse * *b->masse) / (distance * distance);

    for (int i = 0; i < DIMENSION; i++) {
        a->acceleration[i] += (force * direction[i]) / distance / *a->masse;
        b->acceleration[i] -= (force * direction[i]) / distance / *b->masse;
    }
}

/// <summary>
/// La fonction 'applyForces' fait appel � la fonction 'computeGravitationalForce' pour calculer l'ensemble des forces qui s'appliquent
/// sur l'ensemble des corps de la galaxie
/// </summary>
/// <param name="bodies">Tableau des corps dont on veut calculer les diff�rentes forces</param>
/// <param name="n">Nombres de corps existant</param>
void applyForces(Body* bodies, int n){
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            computeGravitationalForce((bodies + i), (bodies + j));
        }
    }
}