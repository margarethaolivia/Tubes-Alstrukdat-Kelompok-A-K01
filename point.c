#include "point.h"
#include "stdio.h"

void createPoint(point *p, int x, int y){
    p->x = x;
    p->y = y;
}

int getX(point p){ // Mengembalikan nilai x pada point
    return x(p);
}
int getY(point p){ // Mengembalikan nilai y pada point
    return y(p);
}

boolean isPointValid(point p){ // Memastikan apakah point valid/tidak
    return (x(p) >= 0 && y(p) >= 0);
}

void move(point *p, int a, int b){ // Menggeser nilai pada point sebesar x dan y
    createPoint(p,p->x+a,p->y+b);
}

void printPoint(point p){
    printf("(%d,%d)\n",x(p),y(p));
}

