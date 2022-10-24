#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "boolean.h"
#include "point.h"
#include "matrix.h"

typedef struct 
{
    // prioQueue invent[100];
    point currentPos;
    char nama[100];

} simulator;
#define nama(simulator) simulator.nama

void createSim(simulator *sim);
void setNama(simulator *sim);

void displayNama(simulator sim);

void initiatePoint(Matrix map, simulator *sim);



#endif