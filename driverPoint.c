#include "point.h"
#include <stdio.h>
int main(){
    point p;
    createPoint(&p,0,2);
    printPoint(p);
    move(&p,2,2);
    printPoint(p);
    if(isPointValid(p)){
        printf("ok\n");
    }
    else{
        printf("not ok\n");
    }
    move(&p,-20,-20);
    printPoint(p);
    if(isPointValid(p)){
        printf("ok\n");
    }
    else{
        printf("not ok\n");
    }    
    return 0;
}