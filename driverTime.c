#include "time.h"
#include <stdio.h>

int main(){
    time t;
    createTime(&t, 0, 0, 0);
    printTime(t);
    nextMin(&t);
    nextMin(&t);
    printTime(t);
    if(isTimeValid(t)){
        printf("ok\n");
    }
    else{
        printf("not ok\n");
    }
    prevMin(&t);
    prevMin(&t);
    prevMin(&t);
    prevMin(&t);
    prevMin(&t);
    prevMin(&t);
    prevMin(&t);
    prevMin(&t);
    printTime(t);
    if(isTimeValid(t)){
        printf("ok\n");
    }
    else{
        printf("not ok\n");
    }   
}