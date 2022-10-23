#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

extern boolean EOP;
extern char CC;

extern Kata currentKata;

void p(){
    int opsi;
    do{
        printf("1.IO terminal\n2.FILE\n3.exit\n");
        scanf(" %d",&opsi);
        if(opsi==1){
            printf("ketik '.' untuk exit\n");
            START("",false);
            while(CC!='.'){
                printf("%c",CC);
                ADV();
            }
            printf("\n");
        } else if(opsi == 2) {
            printf("tulis nama file\n");
            startKata("",false);
            QUIT();
            START(currentKata.buffer,true);
            while(!EOP){
                printf("%c",CC);
                ADV();
            }
            printf("\n");
        }
    } while(opsi!=3);
}

int main(){
    p();
}