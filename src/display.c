//display.c

#include "display.h"

/// <summary>
/// 
/// </summary>
/// <param name="bodies"></param>
/// <param name="nbBodies"></param>
/// <param name="gridWidth"></param>
/// <param name="gridHeight"></param>
/// <param name="spaceLimit"></param>
void displayGrid(Body* bodies, int nbBodies, int gridWidth, int gridHeight, float spaceLimit, Color color) {
    int cellWidth = gridWidth / GRID_WIDTH;
    int cellHeight = gridHeight / GRID_HEIGHT;
    float twoSpaceLimit = 2.0f * spaceLimit;

    ClearBackground(DARKBLUE);

    // Placement des corps
    for (int i = 0; i < nbBodies; i++) {

        float normalizedX = (bodies[i].position[0] + spaceLimit) / (twoSpaceLimit);
        float normalizedY = (bodies[i].position[1] + spaceLimit) / (twoSpaceLimit);

        // Conversion en indices de la grille.
        int x = (int)(normalizedX * GRID_WIDTH);
        int y = (int)(normalizedY * GRID_HEIGHT);

        // Position centrale dans la cellule.
        int cellX = x * cellWidth;
        int cellY = y * cellHeight;


        // Dessin du corps.
        // float speed = sqrt(pow(bodies[i].vitesse[0], 2) + pow(bodies[i].vitesse[1], 2));
        // Color bodyColor = (Color){255, (int)(speed * 25) % 255, 0, 255};
        DrawCircle(cellX, cellY, *bodies[i].rayon, color);
    }
}
