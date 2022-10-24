#include "time.h"
#include <stdio.h>


void createTime(time *t, int day, int hour, int minute){
    t->DD = day;
    t->HH = hour;
    t->MM = minute;
}

void advTime(time *t, int day, int hour, int minute){
    createTime(t,t->DD+day,t->HH+hour,t->MM+minute);
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
    return(day(t)<32 && day(t)>0 && hour(t)>=0 && hour(t) < 24  && minute(t) >= 0 && minute(t) < 60);
}