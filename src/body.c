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
void initBody(Body* body, float* position, float* vitesse, float* acceleration, float* masse, float* rayon) {
    body->position = position;
    body->vitesse = vitesse;
    body->acceleration = acceleration;
    body->masse = masse;
    body->rayon = rayon;
}

/// <summary>
/// La fonction 'updateBody' met � jour l'acceleration, la vitesse et la position du corps en fonction de la force exerc� sur lui
/// </summary>
/// <param name="body">Corps mis � jour</param>
/// <param name="force"></param>
/// <param name="acceleration"></param>
void updateBody(Body* body) {
    // Mise à jour des vitesses en fonction de l'accélération
    for (int i = 0; i < DIMENSION; i++) {
        body->vitesse[i] += body->acceleration[i] * TIMESTEP;
    }

    // Mise à jour des positions en fonction des vitesses
    for (int i = 0; i < DIMENSION; i++) {
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
    free(body->rayon);
}


void initGalaxy(Galaxy* galaxy, int n, float* position){
    galaxy->bodies = (Body*)malloc(n * sizeof(Body));

    if(galaxy->bodies == NULL){
        printf("Erreur: echec de l'allocation mémoire\n");
        return;
    }

    galaxy->n = n;
    galaxy->position = position;

    for(int i = 0; i<n;i++){
        float* position = (float*)malloc(DIMENSION * sizeof(float));
        float* vitesse = (float*)malloc(DIMENSION * sizeof(float));
        float* acceleration = (float*)malloc(DIMENSION * sizeof(float));
        float* masse = (float*)malloc(sizeof(float));
        float* rayon = (float*)malloc(sizeof(float));

        if (position == NULL || vitesse == NULL || acceleration == NULL || masse == NULL || rayon == NULL) {
            printf("Erreur: echec de l'allocation mémoire\n");
            return;
        }

        for (int j = 0; j < DIMENSION; j++) {
            position[j] = ((float)(rand() % (int)(2 * (n - SPACE_LIMIT) * 500)) / n ) - SPACE_LIMIT + galaxy->position[j];
            vitesse[j] = (float)(rand() % 100) - 50;
            acceleration[j] = 0;
        }

        *masse = (float)(rand() % MAX_MASS) + 1;

        *rayon = sqrt(*masse) * 0.1;
        
        initBody(&galaxy->bodies[i], position, vitesse, acceleration, masse, rayon);
    }
}

void freeGalaxy(Galaxy* galaxy){
    for (int i = 0; i < galaxy->n; i++) {
        freeBody(&galaxy->bodies[i]);
    }

    free(galaxy->bodies);
    free(galaxy);
}