#include "simulator.h"
#include <stdio.h>
#include "mesinkata.c"

void createSim(simulator *sim){
    *sim->nama='\0';
    // *sim->currentPos=NULL;
}

void setNama(simulator *sim){
    startKata(*sim->nama,false);
}

void displayNama(simulator sim){
    int i=0;
    while (sim.nama[i]!='\0' || sim.nama[i]!='\n')
    {
        printf("%c",sim.nama[i]);
        i++;
    }
    printf("\n");
    
}