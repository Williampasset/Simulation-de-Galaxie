// physics.h
#pragma once
#ifndef PHYSICS_H
#define PHYSICS_H

#include "body.h"

void computeGravitationalForce(Body *a, Body *b); 
void applyForces(Body* bodies, int n);

#endif // PHYSICS_H