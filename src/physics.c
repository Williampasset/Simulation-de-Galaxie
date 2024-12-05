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

    if(distance == 0){
        return;
    }

    distance = sqrt(distance);

    for (int i = 0; i < DIMENSION; i++) {
        direction[i] /= distance;
    }

    force = (G * a->masse * b->masse) / (distance * distance);

    for (int i = 0; i < DIMENSION; i++) {
        float acceleration_contribution = force * direction[i];
        a->acceleration[i] += acceleration_contribution / a->masse;
        b->acceleration[i] -= acceleration_contribution / b->masse;
    }

}



/// <summary>
/// La fonction 'applyForces' fait appel � la fonction 'computeGravitationalForce' pour calculer l'ensemble des forces qui s'appliquent
/// sur l'ensemble des corps de la galaxie
/// </summary>
/// <param name="bodies">Tableau des corps dont on veut calculer les diff�rentes forces</param>
/// <param name="n">Nombres de corps existant</param>
void applyForces(Body* bodies, int* n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; j++) {

            if (checkCollision(&bodies[i], &bodies[j])) {

                Body mergedBody;
                mergeBodies(&bodies[i], &bodies[j], &mergedBody);

                bodies[i] = mergedBody;

                bodies[j] = bodies[*n - 1];
                (*n)--;

                j = i;
                continue;
            }

            // Calcul des forces gravitationnelles
            computeGravitationalForce(&bodies[i], &bodies[j]);
        }
    }
}


/// <summary>
/// Vérifie si deux corps sont en collision.
/// </summary>
/// <param name="a">Premier corps</param>
/// <param name="b">Second corps</param>
/// <returns>1 si collision, 0 sinon</returns>
int checkCollision(Body* a, Body* b) {
    float distanceSquared = 0.0f;

    for (int i = 0; i < DIMENSION; i++) {
        float diff = b->position[i] - a->position[i];
        distanceSquared += diff * diff;
    }

    float radiusSum = a->rayon + b->rayon;

    return distanceSquared <= (radiusSum * radiusSum);
}

/// <summary>
/// Fusionne deux corps en un seul.
/// </summary>
/// <param name="a">Premier corps</param>
/// <param name="b">Second corps</param>
/// <param name="result">Corps résultant de la fusion</param>
void mergeBodies(Body* a, Body* b, Body* result) {
    float totalMass = a->masse + b->masse;

    // Position : centre de masse
    for (int i = 0; i < DIMENSION; i++) {
        result->position[i] = (a->position[i] * a->masse + b->position[i] * b->masse) / totalMass;
    }

    // Vitesse : conservation de l'élan
    for (int i = 0; i < DIMENSION; i++) {
        result->vitesse[i] = (a->vitesse[i] * a->masse + b->vitesse[i] * b->masse) / totalMass;
    }

    // Masse et rayon
    result->masse = totalMass;
    result->rayon = sqrt(result->masse) * 0.01f;

    // Accélération (optionnel, souvent réinitialisée après fusion)
    for (int i = 0; i < DIMENSION; i++) {
        result->acceleration[i] = 0.0f;
    }
}



