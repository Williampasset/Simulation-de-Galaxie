#include "body.h"


/// @brief Génère un nombre aléatoire suivant une loi normale
/// @param mean
/// @param stddev
/// @return float
float gaussianRandom(float mean, float stddev) {
    float u1 = (float)rand() / RAND_MAX;
    float u2 = (float)rand() / RAND_MAX;
    float z0 = sqrt(-2.0f * log(u1)) * cos(2.0f * PI * u2);
    return z0 * stddev + mean;
}


/// @brief Initialise un corps avec les paramètres donnés
/// @param body 
/// @param position 
/// @param vitesse 
/// @param acceleration 
/// @param masse 
/// @param rayon 
void initBody(Body* body, float* position, float* vitesse, float* acceleration, float* masse, float* rayon) {
    for (int i = 0; i < DIMENSION; i++) {
        body->position[i] = position[i];
        body->vitesse[i] = vitesse[i];
        body->acceleration[i] = acceleration[i];
    }
    body->masse = *masse;
    body->rayon = *rayon;
}


/// @brief Met à jour la position et la vitesse d'un corps
/// @param body 
void updateBody(Body* body) {
    for (int i = 0; i < DIMENSION; i++) {
        body->vitesse[i] += body->acceleration[i] * TIMESTEP;
        body->position[i] += body->vitesse[i] * TIMESTEP;
    }
}


/// @brief Initialise une galaxie avec un nombre de corps donné
/// @param galaxy 
/// @param n 
/// @param centre 
void initGalaxy(Galaxy* galaxy, int n, float* centre) {
    galaxy->bodies = (Body*)malloc(n * sizeof(Body));
    if (galaxy->bodies == NULL) {
        printf("Erreur: échec de l'allocation mémoire\n");
        return;
    }

    galaxy->n = n;

    for (int j = 0; j < DIMENSION; j++) {
        galaxy->centre[j] = centre[j];
    }

    for (int i = 0; i < n; i++) {
        float position[DIMENSION];
        float vitesse[DIMENSION];
        float acceleration[DIMENSION] = {0.0f};
        float masse;
        float rayon;

        for (int j = 0; j < DIMENSION; j++) {
            position[j] = gaussianRandom(centre[j], SPACE_LIMIT / 3.0f);
            vitesse[j] = gaussianRandom(0.0f, 50.0f);
        }

        masse = (float)(rand() % MAX_MASS) + 1.0f;
        rayon = sqrt(masse) * 0.1f;

        initBody(&galaxy->bodies[i], position, vitesse, acceleration, &masse, &rayon);
    }
}


/// @brief Libère la mémoire allouée pour les corps de la galaxie
/// @param galaxy 
void freeGalaxy(Galaxy* galaxy) {
    if (galaxy->bodies != NULL) {
        free(galaxy->bodies);
    }
    galaxy->n = 0;
}
