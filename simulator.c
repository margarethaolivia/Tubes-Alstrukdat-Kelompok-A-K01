#include "simulator.h"
#include <stdio.h>
#include "mesinkata.h"

void createSim(simulator *sim){
    (sim)->nama.buffer[0]='\0';
    // *sim->currentPos=NULL;
    PQueue q;
    createPQueue(&q,1);
    (sim)->inventory=q;
    
}

void setNama(simulator *sim,Kata currentKata){
    // startKata("",false);
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

void moveKanan(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+2);
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+2)='S';
        (sim)->currentPos.x=(sim)->currentPos.x+1;
    }
    else{
        printf("ada rintangan\n");
    }
}
void moveKiri(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x);
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x)='S';
        (sim)->currentPos.x=(sim)->currentPos.x-1;
    }
    else{
        printf("ada rintangan\n");
    }
}
void moveAtas(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.y,(sim)->currentPos.x+1);
    
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        ELMT(*map,(sim)->currentPos.y,(sim)->currentPos.x+1)='S';
        (sim)->currentPos.y=(sim)->currentPos.y-1;
    }
    else{
        printf("ada rintangan\n");
    }
}

void moveBawah(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.y+2,(sim)->currentPos.x+1);
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        ELMT(*map,(sim)->currentPos.y+2,(sim)->currentPos.x+1)='S';
        (sim)->currentPos.y=(sim)->currentPos.y+1;
    }
    else{
        printf("ada rintangan\n");
    }
}

boolean isAdjacentTo(simulator sim, char object,Matrix map){
    boolean isAdjacent=false;
    int i=sim.currentPos.y;
    int j=sim.currentPos.x;
    while (i<sim.currentPos.y+3 && !isAdjacent)
    {
        j=sim.currentPos.x;
        while (j<sim.currentPos.x+3 && !isAdjacent)
        {
            if (ELMT(map,i,j)==object)
            {
                isAdjacent=true;
            }
            j++;
        }
        
        i++;
    }
    return isAdjacent;
}

void displayInvent(simulator sim){
    int l=lengthPQueue(sim.inventory);
    int i=0;
    while (i<l)
    {
        printMakanan(sim.inventory.queue[i]);
        i++;
    }
    
}