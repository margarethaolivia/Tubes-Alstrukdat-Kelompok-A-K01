#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../Boolean/boolean.h"
#include "../Point/point.h"
#include "../Matrix/matrix.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../PrioQueue/prioqueue.h"

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
void displayMapBasedOnCurrentPos(Matrix map, simulator sim);

#endif