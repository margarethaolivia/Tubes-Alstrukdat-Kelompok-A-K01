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