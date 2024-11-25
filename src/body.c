//body.c

#include "body.h"

/// <summary>
/// La fonction 'initBody' initialise un corps dans une galaxie avec ses conditions initiales
/// </summary>
/// <param name="body">Corps sur lequel on va initialiser les valeurs</param>
/// <param name="position">Position initiale du corps</param>
/// <param name="vitesse">Vitesse initiale du corps</param>
/// <param name="acceleration">Acceleration initiale du corps</param>
/// <param name="masse">Masse du corps</param>
void initBody(Body* body, float* position, float* vitesse, float* acceleration, float* masse) {
    body->position = position;
    body->vitesse = vitesse;
    body->acceleration = acceleration;
    body->masse = masse;
}

/// <summary>
/// La fonction 'updateBody' met � jour l'acceleration, la vitesse et la position du corps en fonction de la force exerc� sur lui
/// </summary>
/// <param name="body">Corps mis � jour</param>
/// <param name="force"></param>
/// <param name="acceleration"></param>
void updateBody(Body* body, float* force, float* acceleration) {
    for (int i = 0; i < DIMENSION; i++) {
        acceleration[i] = force[i] / *body->masse;
        body->vitesse[i] += acceleration[i] * TIMESTEP;
        body->position[i] += body->vitesse[i] * TIMESTEP;
    }
}

/// <summary>
/// La fonction 'freeBody' permet de lib�rer la m�moire allouer � un corps
/// </summary>
/// <param name="body">Corps dont on veut lib�rer la m�moire</param>
void freeBody(Body* body) {
    free(body->position);
    free(body->vitesse);
    free(body->acceleration);
    free(body->masse);
}