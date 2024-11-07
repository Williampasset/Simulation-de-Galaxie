#include "config.h"
#include "physics.h"
#include "display.h"


int main(int argc, int argv[]) {


	/// Initialisation des corps de la galaxie
	Body* bodies = (Body*)malloc(NUM_BODIES * sizeof(Body));

	for (int i = 0; i < NUM_BODIES; i++) {
		float* position = (float*)malloc(DIMENSION * sizeof(float));
		float* vitesse = (float*)malloc(DIMENSION * sizeof(float));
		float* acceleration = (float*)malloc(DIMENSION * sizeof(float));
		float* masse = (float*)malloc(sizeof(float));

		if (position == NULL || vitesse == NULL || acceleration == NULL || masse == NULL || bodies == NULL) {
			printf("Erreur: echec de l'allocation mémoire\n");
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

	/// Calcul des forces puis affichage de la galaxie avec les corps à jour
	for (int i = 0; i < STEPS; i++) {
		applyForces(bodies, NUM_BODIES);
		for (int j = 0; j < NUM_BODIES; j++) {
			updateBody(&bodies[j], bodies[j].acceleration, bodies[j].acceleration);
		}
		displayGrid(bodies, NUM_BODIES, GRID_WIDTH, GRID_HEIGHT, SPACE_LIMIT);
	}

	for (int i = 0; i < NUM_BODIES; i++) {
		freeBody(&bodies[i]);
	}
	free(bodies);


	return EXIT_SUCCESS;
}