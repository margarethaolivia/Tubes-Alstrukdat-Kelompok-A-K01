#include <stdio.h>
#include "mesinkata.h"
#include "utility.h"

extern char CC;
extern boolean EOP;

extern Kata currentKata;
Kata otherKata;

void p(){
    int opsi;
    do{
        printf("1.IO terminal\n2.FILE\n3.exit\n");
        scanf(" %d",&opsi);
        if(opsi==1){
            printf("ketik \"EXIT\" untuk berhenti.\n");
            startKata("",false);
            while(currentKata.length!=0){
                printf(currentKata.buffer);
                printf("\n");
                if(strcmp(currentKata.buffer,"EXIT")){
                    QUIT();
                }
                advKata();
            }
        }
        if(opsi==2){
            printf("tulis nama file\n");
            startKata("",false);
            otherKata = currentKata;
            QUIT();
            startKata(otherKata.buffer,true);
            while(currentKata.length!=0){
                printf(currentKata.buffer);
                advKata();
                if(strcmp(currentKata.buffer,"EXIT")){
                    QUIT();
                }
            }
        }
    }while(opsi!=3);
}

int main(){
    p();
}