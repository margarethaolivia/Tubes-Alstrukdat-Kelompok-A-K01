#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "boolean.h"
#include "point.c"
#include "matrix.c"

typedef struct 
{
    // prioQueue invent[100];
    point currentPos;
    char* nama;

} simulator;

void createSim(simulator *sim);
void setNama(simulator *sim);

void displayNama(simulator sim);

void initiatePoint(Matrix map, simulator *sim);



#endif