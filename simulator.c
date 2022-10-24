#include "simulator.h"
#include <stdio.h>
#include "mesinkata.c"

void createSim(simulator *sim){
    (sim)->nama.buffer[0]='\0';
    // *sim->currentPos=NULL;
}

void setNama(simulator *sim){
    startKata("",false);
    (sim)->nama=currentKata;
}

void displayNama(simulator sim){
    int i=0;
    while (i<sim.nama.length)
    {
        printf("%c",sim.nama.buffer[i]);
        i++;
    }
    printf("\n");
    
}