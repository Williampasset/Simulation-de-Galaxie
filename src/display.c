//display.c

#include "display.h"

void displayGrid(Body* bodies, int nbBodies, float spaceLimit, Color color) {
    ClearBackground(DARKBLUE);


    for (int i = 0; i < nbBodies; i++) {

        Vector3 bodyPosition = {
            bodies[i].position[0], // Coordonnée X
            bodies[i].position[1], // Coordonnée Y
            bodies[i].position[2]  // Coordonnée Z
        };
        
        // Dessin du corps en tant que sphère
        float speed = sqrt(pow(bodies[i].vitesse[0], 2) + pow(bodies[i].vitesse[1], 2) + pow(bodies[i].vitesse[2], 2));
        Color bodyColor = (Color){255, (int)(speed * 25), 0, 255};

        DrawSphere(bodyPosition, bodies[i].rayon, bodyColor);
    }
}

