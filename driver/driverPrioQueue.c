#include <stdio.h>
#include "../prioqueue.h"
#include "../utility.h"

//untuk menjalankan driver ini mohon ubah hal brkt:
// typedef int ElTypePQueue;
// typedef int CompareType;
// #define GetPrio(m) (m)


// boolean fx(ElTypePQueue x, Kata a){
//     return strcmp(Nama(x).buffer,a.buffer);
// }

boolean fx(ElTypePQueue x, int a){
    return x==a;
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
            int i;
            for(i=0;i<lengthPQueue(q);i++){
                ElTypePQueue* p = getElmtPQueueReff(&q,i);
                //Expired(*p) = minToTime(timeToMin(Expired(*p))-1);
                *p = *p - 1;
            }
        }

        int i;
        for(i=0;i<lengthPQueue(q);i++){
            printf("%d",getElmtPQueue(q,i));
        }
        printf("\n");

    }while(opsi!=5);
    destroyPQueue(&q);
}

int main(){
    p();
}
