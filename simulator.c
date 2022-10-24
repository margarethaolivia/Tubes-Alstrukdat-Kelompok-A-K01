#include "simulator.h"
#include <stdio.h>
#include "mesinkata.h"

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

void initiatePoint(Matrix map, simulator *sim){
    int i=0;
    int j=0;
    while (i<ROW_EFF(map))
    {
        j=0;
        while (j<COL_EFF(map))
        {
            if (ELMT(map,i,j)=='S')
            {
                (sim)->currentPos.x=j-1;
                (sim)->currentPos.y=i-1;
            }
            
            j++;
        }
        i++;
    }
    
}