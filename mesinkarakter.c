/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mesinkarakter.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE *pita;
static int retval;

void START(const char* PATH,boolean rFile)
{
       EOP=false;
       if(rFile){
              pita = fopen(PATH, "r");                       //buka file dan handle gagal buka file
              if(pita == NULL){
                     printf("Gagal membaca file.\n");
                     EOP = true;
              }
       } else {
              pita = stdin;             //jika mesin karakter baca dari terminal
       }
       if(!EOP){ADV();} //mencegah segmentblabla fault
}

void ADV()
{
       retval = fscanf(pita, "%c", &CC); //CC <- karakter pada pita
       EOP = retval==-1; //retval -1 = file yang dibaca sudah mencapai akhir.
       if (EOP)
       {
              fclose(pita); //free?
       }
}

void QUIT()
{
       EOP=true;            //menghentikan mesin karakter secara manual, misalnya
       //fclose(pita);        // saat command EXIT
}
