#pragma once
#include "physics.h"
#include <time.h>
#include "raylib.h"


void displayGrid(Body* bodies, int nbBodies, float spaceLimit, Color color);
Color getBodyColor(BodyType type);