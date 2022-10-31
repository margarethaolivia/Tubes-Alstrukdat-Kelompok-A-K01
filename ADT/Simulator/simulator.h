#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "boolean.h"
#include "point.h"
#include "matrix.h"
#include "mesinkata.h"
#include "prioqueue.h"

typedef struct 
{
    PQueue inventory;
    point currentPos;
    Kata nama;

} simulator;
#define nama(simulator) simulator.nama

void createSim(simulator *sim);
void setNama(simulator *sim,Kata currentKata);

void displayNama(simulator sim);

void initiatePoint(Matrix map, simulator *sim);

void moveKanan(simulator *sim, Matrix *map);
void moveKiri(simulator *sim, Matrix *map);
void moveAtas(simulator *sim, Matrix *map);
void moveBawah(simulator *sim, Matrix *map);
boolean isAdjacentTo(simulator sim, char object,Matrix map);
void displayInvent(simulator sim);

#endif