#include "time.h"
#include "../Mesin_Kata/mesinkata.h"
#include <stdio.h>


void createTime(time *t, int day, int hour, int minute){
    t->DD = day;
    t->HH = hour;
    t->MM = minute;
}

void advTime(time *t, int day, int hour, int minute){
    int n = timeToMin(*t) + day*1440 + hour*60 + minute;
    *t = minToTime(n);
}

void nextMin(time *t){  
    advTime(t,t->DD,t->HH,1);
}
void prevMin(time *t){
    advTime(t,t->DD,t->HH,-1);
}
void printTime(time t){
    printf("%d.%d\n",hour(t),minute(t));
}
boolean isTimeValid(time t){
    return(day(t)>=0 && hour(t)>=0 && hour(t) < 24  && minute(t) >= 0 && minute(t) < 60);
    // Jumlah hari diasumsikan tidak memiliki batas dan dimulai dari hari ke-0
}
int timeToMin(time t){
    return(1440*day(t) + 60*hour(t) + minute(t));
}
time minToTime(int min){
    time T;
    createTime(&T,min/24/60,min/60%24,min%60);
    return T;
}
