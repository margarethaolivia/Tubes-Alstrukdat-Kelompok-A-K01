#include "simulator.h"
#include <stdio.h>
#include "mesinkata.h"

void createSim(simulator *sim){
    *sim->nama=NULL;
    // *sim->currentPos=NULL;
}

void setNama(simulator *sim){
    startKata(*sim->nama,false);
}

void displayNama(simulator sim){
    int i=0;
    while (sim.nama[i]!=NULL)
    {
        printf(sim.nama[i]);
        i++;
    }
    printf("\n");
    
}