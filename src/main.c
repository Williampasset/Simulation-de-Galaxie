#include "config.h"
#include "physics.h"
#include "display.h"

int main() {

    /// Initialisation des corps de la galaxie
	Body* bodies = (Body*)malloc(NUM_BODIES * sizeof(Body));

	for (int i = 0; i < NUM_BODIES; i++) {
		float* position = (float*)malloc(DIMENSION * sizeof(float));
		float* vitesse = (float*)malloc(DIMENSION * sizeof(float));
		float* acceleration = (float*)malloc(DIMENSION * sizeof(float));
		float* masse = (float*)malloc(sizeof(float));

		if (position == NULL || vitesse == NULL || acceleration == NULL || masse == NULL || bodies == NULL) {
			printf("Erreur: echec de l'allocation m�moire\n");
			return EXIT_FAILURE;
		}

		for (int j = 0; j < DIMENSION; j++) {
			position[j] = (float)(rand() % (int)(2 * SPACE_LIMIT * 100)) / 100 - SPACE_LIMIT;
			vitesse[j] = (float)(rand() % 100) - 50;
			acceleration[j] = 0;
		}

		*masse = (float)(rand() % 1000) + 1;
		initBody(&bodies[i], position, vitesse, acceleration, masse);
	}

    // Initialisation de la fenêtre raylib
    InitWindow(GRID_WIDTH, GRID_HEIGHT, "Galaxie");

    SetTargetFPS(60);

    Image logo = LoadImage("logo.png");

    SetWindowIcon(logo);

    // Texture2D texture = LoadTextureFromImage(logo);

    UnloadImage(logo);

    // ClearBackground(DARKBLUE);

    while (!WindowShouldClose()) {

        for (int i = 0; i < NUM_BODIES; i++) {
            for (int j = 0; j < DIMENSION; j++) {
                bodies[i].acceleration[j] = 0;
            }
        }

        applyForces(bodies, NUM_BODIES);

        for (int i = 0; i < NUM_BODIES; i++) {
            updateBody(&bodies[i], bodies[i].acceleration, bodies[i].acceleration);
        }

        BeginDrawing();
        displayGrid(bodies, NUM_BODIES, GRID_WIDTH, GRID_HEIGHT, SPACE_LIMIT);
        EndDrawing();
    }

    // UnloadTexture(texture);
    CloseWindow();

    for (int i = 0; i < NUM_BODIES; i++) {
	    freeBody(&bodies[i]);
	}

	free(bodies);

    return 0;
}
