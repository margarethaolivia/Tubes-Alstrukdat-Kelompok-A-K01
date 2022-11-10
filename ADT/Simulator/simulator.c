#include "simulator.h"
#include <stdio.h>
#include "../Mesin_Kata/mesinkata.h"

void createSim(simulator *sim){
    (sim)->nama.buffer[0]='\0';
    // *sim->currentPos=NULL;
    PQueue q,q1;
    createPQueue(&q,100);
    createPQueue(&q1,100);
    sim->inventory=q;
    sim->delivery=q1;
    createTime(&sim->gtime,0,0,0);
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
                (sim)->currentPos.x=i-1;
                (sim)->currentPos.y=j-1;
            }
            
            j++;
        }
        i++;
    }
    
}

void moveKanan(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.x+1,(sim)->currentPos.y+2);
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        // ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        // ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+2)='S';
        (sim)->currentPos.y=(sim)->currentPos.y+1;
    }
    else{
        printf("ada rintangan\n");
    }
}
void moveKiri(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.x+1,(sim)->currentPos.y);
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        // ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        // ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x)='S';
        (sim)->currentPos.y=(sim)->currentPos.y-1;
    }
    else{
        printf("ada rintangan\n");
    }
}
void moveAtas(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.x,(sim)->currentPos.y+1);
    
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        // ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        // ELMT(*map,(sim)->currentPos.y,(sim)->currentPos.x+1)='S';
        (sim)->currentPos.x=(sim)->currentPos.x-1;
    }
    else{
        printf("ada rintangan\n");
    }
}

void moveBawah(simulator *sim, Matrix *map){
    char x=ELMT(*map,(sim)->currentPos.x+2,(sim)->currentPos.y+1);
    if ( x!='*' && x!='X' && x!='T' && x!='M' && x!='C' && x!='F' && x!='B' )
    {
        // ELMT(*map,(sim)->currentPos.y+1,(sim)->currentPos.x+1)=' ';
        // ELMT(*map,(sim)->currentPos.y+2,(sim)->currentPos.x+1)='S';
        (sim)->currentPos.x=(sim)->currentPos.x+1;
    }
    else{
        printf("ada rintangan\n");
    }
}

boolean isAdjacentTo(simulator sim, char object,Matrix map){
    boolean isAdjacent=false;
    int i=sim.currentPos.x;
    int j=sim.currentPos.y;
    while (i<sim.currentPos.x+3 && !isAdjacent)
    {
        j=sim.currentPos.y;
        while (j<sim.currentPos.y+3 && !isAdjacent)
        {
            if (ELMT(map,i,j)==object)
            {
                isAdjacent=true;
            }
            // printf("%c i%d j%d\n",ELMT(map,i,j),i,j);
            j++;
        }
        
        i++;
    }
    return isAdjacent;
}

void displayMapBasedOnCurrentPos(Matrix map, simulator sim){
    int i=0;
    int j=0;
    while (i<ROW_EFF(map))
    {
        j=0;
        while (j<COL_EFF(map))
        {
            if (i==sim.currentPos.x+1 && j==sim.currentPos.y+1)
            {
                printf("%c",'S');
            }
            else if (i!=sim.currentPos.x+1 || j!=sim.currentPos.y+1)
            {
                if (ELMT(map,i,j)!='S')
                {
                    printf("%c",ELMT(map,i,j));
                }
                else{
                    printf("%c",' ');
                }
            }
            
            
            if ((j==COL_EFF(map)-1))
            {
                /*if (i!=ROW_EFF(m)-1)
                {
                    printf("\n");
                }*/
                printf("\n");
            }
            else{
                printf(" ");
            }
            j++;
        }
        i++;
    }
}

// void displayInvent(simulator sim){
//     int l=lengthPQueue(sim.inventory);
//     int i=0;
//     while (i<l)
//     {
//         printMakanan(sim.inventory.queue[i]);
//         i++;
//     }
    
// }