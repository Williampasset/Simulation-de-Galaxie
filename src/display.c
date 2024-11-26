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
void displayGrid(Body* bodies, int nbBodies, int gridWidth, int gridHeight, float spaceLimit) {
    int cellWidth = gridWidth / GRID_WIDTH;
    int cellHeight = gridHeight / GRID_HEIGHT;

    ClearBackground(DARKBLUE);

    // Placement des corps
    for (int i = 0; i < nbBodies; i++) {

        float normalizedX = (bodies[i].position[0] + spaceLimit) / (2.0f * spaceLimit);
        float normalizedY = (bodies[i].position[1] + spaceLimit) / (2.0f * spaceLimit);

        if (normalizedX < 0.0f || normalizedX > 1.0f || normalizedY < 0.0f || normalizedY > 1.0f) {
            printf("Corps %d hors limites : Position (%f, %f)\n", i, bodies[i].position[0], bodies[i].position[1]);
            continue;
        }

        // Conversion en indices de la grille.
        int x = (int)(normalizedX * GRID_WIDTH);
        int y = (int)(normalizedY * GRID_HEIGHT);

        if (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT) {
            // Position centrale dans la cellule.
            int cellX = x * cellWidth + cellWidth / 2;
            int cellY = y * cellHeight + cellHeight / 2;

            // Taille du corps proportionnelle à la racine carrée de la masse pour éviter des tailles trop grandes.
            float radius = sqrt(*bodies[i].masse) * 0.1;

            // Contrainte de taille minimale et maximale pour éviter des corps trop petits ou trop grands.
            // if (radius < 2.0f) radius = 2.0f; // Taille minimale.
            // if (radius > cellWidth / 2) radius = cellWidth / 2; // Taille maximale relative à la cellule.

            // Dessin du corps.
            DrawCircle(cellX, cellY, radius, RAYWHITE);
            printf("Rayon du corps: %f \n", radius);
            printf("Masse du corps: %f \n", *bodies[i].masse);
        } else {
            printf("Corps %d hors de la grille : x=%d, y=%d\n", i, x, y);
        }
    }
}
