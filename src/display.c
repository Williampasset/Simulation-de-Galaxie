//display.c

#include "display.h"



Color getBodyColor(BodyType type) {
    switch (type) {
        case ASTEROID:
            return BROWN;
        case PLANET:
            return GREEN;
        case STAR:
            return YELLOW;
        case BLACK_HOLE:
            return BLACK;
        default:
            return WHITE;
    }
}



void displayGrid(Body* bodies, int nbBodies, float spaceLimit, Color color) {
    ClearBackground(DARKBLUE);


    for (int i = 0; i < nbBodies; i++) {

        Vector3 bodyPosition = {
            bodies[i].position[0], // Coordonnée X
            bodies[i].position[1], // Coordonnée Y
            bodies[i].position[2]  // Coordonnée Z
        };
        
        // float speed = sqrt(pow(bodies[i].vitesse[0], 2) + pow(bodies[i].vitesse[1], 2) + pow(bodies[i].vitesse[2], 2));
        // Color bodyColor = (Color){255, (int)(speed * 25), 0, 255};
        Color bodyColor = getBodyColor(bodies[i].type);

        DrawSphere(bodyPosition, bodies[i].rayon, bodyColor);
    }
}

