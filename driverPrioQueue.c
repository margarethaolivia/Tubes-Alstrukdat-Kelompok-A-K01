#include <stdio.h>
#include "prioqueue.h"

//untuk menjalankan driver ini mohon ubah hal brkt:
// typedef int ElTypePQueue;
// typedef int CompareType;
// #define GetPrio(m) (m)


boolean fx(ElTypePQueue x, int a){
    return x == a;
}


void p(){

    PQueue q;
    createPQueue(&q,3);
    int opsi;
    do{
        printf("1.enqueue\n2.dequeue\n3.remove\n4.halt\n5.exit\n");
        scanf("%d",&opsi);
        if(opsi==1){
            ElTypePQueue input;
            scanf("%d",&input);
            enqueue(&q,input);
        }
        if(opsi==2){
            ElTypePQueue output;
            dequeue(&q,&output);
            printf("%d\n",output);
        }
        if(opsi==3){
            ElTypePQueue input;
            scanf("%d",&input);

            removeFromQueue(&q,fx,input);
        }
        if(opsi==4){
            updateElmtPriority(&q,-1);
        }

        int i;
        for(i=0;i<length(q);i++){
            printf("%d",getElmt(q,i));
        }
        printf("\n");

    }while(opsi!=5);
    destroy(&q);
}

int main(){
    p();
}
