#include "config.h"
#include "physics.h"
#include "display.h"


// int main(int argc, char** argv) {


// 	/// Initialisation des corps de la galaxie
// 	Body* bodies = (Body*)malloc(NUM_BODIES * sizeof(Body));

// 	for (int i = 0; i < NUM_BODIES; i++) {
// 		float* position = (float*)malloc(DIMENSION * sizeof(float));
// 		float* vitesse = (float*)malloc(DIMENSION * sizeof(float));
// 		float* acceleration = (float*)malloc(DIMENSION * sizeof(float));
// 		float* masse = (float*)malloc(sizeof(float));

// 		if (position == NULL || vitesse == NULL || acceleration == NULL || masse == NULL || bodies == NULL) {
// 			printf("Erreur: echec de l'allocation m�moire\n");
// 			return EXIT_FAILURE;
// 		}

// 		for (int j = 0; j < DIMENSION; j++) {
// 			position[j] = (float)(rand() % (int)(2 * SPACE_LIMIT * 100)) / 100 - SPACE_LIMIT;
// 			vitesse[j] = (float)(rand() % 100) - 50;
// 			acceleration[j] = 0;
// 		}

// 		*masse = (float)(rand() % 1000) + 1;
// 		initBody(&bodies[i], position, vitesse, acceleration, masse);
// 	}


// 	/// Calcul des forces puis affichage de la galaxie avec les corps � jour
// 	for (int i = 0; i < STEPS; i++) {
// 		applyForces(bodies, NUM_BODIES);
// 		for (int j = 0; j < NUM_BODIES; j++) {
// 			updateBody(&bodies[j], bodies[j].acceleration, bodies[j].acceleration);
// 		}
// 		displayGrid(bodies, NUM_BODIES, GRID_WIDTH, GRID_HEIGHT, SPACE_LIMIT);

// 		sleep(STEP_TIME);
// 		printf("\033[H");
// 		printf("\033[2J");
// 	}

// 	for (int i = 0; i < NUM_BODIES; i++) {
// 		freeBody(&bodies[i]);
// 	}
// 	free(bodies);
// 	return EXIT_SUCCESS;
// }

#include "raylib.h"

int main() {
    InitWindow(GRID_WIDTH, GRID_HEIGHT, "Galaxie");

    SetTargetFPS(60);

    Image logo = LoadImage("logo.png");

    SetWindowIcon(logo);

    Texture2D texture = LoadTextureFromImage(logo);

    UnloadImage(logo);


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawTexture(texture, GRID_WIDTH / 2 - texture.width / 2, GRID_HEIGHT / 3 - texture.height / 2, WHITE);
        DrawText("Play ", 190, 200, 20, YELLOW);
        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
