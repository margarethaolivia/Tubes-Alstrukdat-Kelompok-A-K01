#include <stdio.h>
#include "mesinkata.h"

Kata currentKata;

extern char CC;
extern boolean EOP;

void ignoreBlanks(){
    while((CC==' '||CC=='\n')&&!EOP){
        ADV();  //ignor bleng
    }
}

void salinKata(){
    while(CC!=' '&&CC!='\n'&&!EOP){
        currentKata.buffer[currentKata.length] = CC;
        currentKata.length++;       //salin char ke buffer
        ADV();
    }
    currentKata.buffer[currentKata.length] = '\0';  //add \0 untuk mempermudah komparasi
}

void startKata(const char* PATH,boolean rFile){
    currentKata.buffer[0]='\0';
    currentKata.length = 0;

    START(PATH, rFile);     //mulai menyalin kata
    advKata();
}

void advKata(){
    currentKata.buffer[0]='\0';
    currentKata.length = 0;
    if(!EOP){
        ignoreBlanks();     //adv kata
        salinKata();
    }
}

void shutdown(){
    QUIT();
    advKata();
}