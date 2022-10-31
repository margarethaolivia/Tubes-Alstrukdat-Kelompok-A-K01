#ifndef TIME_H
#define TIME_H

#include "../Boolean/boolean.h"

typedef struct{
    int DD;
    int HH;
    int MM;
} time;

#define day(time) time.DD
#define hour(time) time.HH
#define minute(time) time.MM

void createTime(time *t, int day, int hour, int minute); // Menginisiasi waktu
void advTime(time *t, int day, int hour, int minute); // Mengubah value dari waktu, kasih tanda (-) di day, hour, sama minute kalo mau ngurangin
void nextMin(time *t); // Menjalankan waktu sebanyak 1 menit
void prevMin(time *t); // Mengurangi waktu sebanyak 1 menit
void printTime(time t); // Mencetak waktu pada layar
boolean isTimeValid(time t); // Mengecek apakah waktu tersebut bernilai valid atau tidak
int timeToMin(time t); // Mengubah time menjadi menit 
time minToTime(int min); // Mengubah menit menjadi time
#endif