//display.c

#include "include/display.h"

/// <summary>
/// 
/// </summary>
/// <param name="bodies"></param>
/// <param name="nbBodies"></param>
/// <param name="gridWidth"></param>
/// <param name="gridHeight"></param>
/// <param name="spaceLimit"></param>
void displayGrid(Body* bodies, int nbBodies, int gridWidth, int gridHeight, float spaceLimit) {

    /// Initialisation de la grille d'affichage
    char** grid = (char**)malloc(gridHeight * sizeof(char*));

    for (int i = 0; i < gridHeight; i++) {
        grid[i] = (char*)malloc(gridWidth * sizeof(char));

        for (int j = 0; j < gridWidth; j++) {
            grid[i][j] = ' ';
        }
    }

    /// Placement des corps dans la grille (repr�sentant notre galaxie)
    for (int i = 0; i < nbBodies; i++) {
        int x = (int)((bodies[i].position[0] + spaceLimit) / (2 * spaceLimit) * gridWidth);
        int y = (int)((bodies[i].position[1] + spaceLimit) / (2 * spaceLimit) * gridHeight);

        if (x >= 0 && x < gridWidth && y >= 0 && y < gridHeight) {
            grid[y][x] = '*';
        }
    }

    /// Affichage de la limite haute de la grille
    for (int i = 0; i < gridWidth + 2; i++) {
        printf("-");
    }

    printf("\n");

    /// Affichage de la grille
    for (int i = 0; i < gridHeight; i++) {
        printf("|");

        for (int j = 0; j < gridWidth; j++) {
            printf("%c", grid[i][j]);
        }

        printf("|\n");
    }

    /// Affichage de la limite basse de la grille
    for (int i = 0; i < gridWidth + 2; i++) {
        printf("-");
    }

    printf("\n");

    for (int i = 0; i < gridHeight; i++) {
        free(grid[i]);
    }

    free(grid);
}

void sleep(float time){
    clock_t start_time = clock();

    clock_t wait_time = (clock_t)(time * CLOCKS_PER_SEC);

    while (clock() - start_time < wait_time);
}