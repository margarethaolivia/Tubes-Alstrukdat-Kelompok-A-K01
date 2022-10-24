#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct
{
    int x;
    int y;
} point;

#define x(point) (point).x
#define y(point) (point).y

void createPoint(point *p, int x, int y); // Membuat point baru
int getX(point p); // Mengembalikan nilai x pada point
int getY(point p); // Mengembalikan nilai y pada point
boolean isPointValid(point p); // Memastikan apakah point valid/tidak
void move(point *p, int x, int y); // Menggeser nilai pada point sebesar x dan y
void printPoint(point p); // Mencetak point ke layar dalam bentuk (x,y)


#endif