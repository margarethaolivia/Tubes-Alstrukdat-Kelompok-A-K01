#include <stdio.h>
#include "mesinkata.h"

Kata currentKata;

extern char CC;
extern boolean EOP;

char MARK1;
char MARK2;

void createKata(Kata* s,const char* string){
    int len = 0;
    while(string[len]!='\0'){
        s->buffer[len] = string[len];
        len++;
    }
    s->buffer[len] = '\0';
    s->length = len;
}

void ignoreBlanks(){
    while((CC==MARK1||CC==MARK2)&&!EOP){
        ADV();  //ignor bleng
    }
}

void salinKata(){
    while(CC!=MARK1&&CC!=MARK2&&!EOP){
        currentKata.buffer[currentKata.length] = CC;
        currentKata.length++;       //salin char ke buffer
        ADV();
    }
    currentKata.buffer[currentKata.length] = '\0';  //add \0 untuk mempermudah komparasi
}

void startKata(const char* PATH,boolean rFile,char endOfKataMark1,char endOfKataMark2){
    currentKata.buffer[0]='\0';
    currentKata.length = -1;

    MARK1 = endOfKataMark1;
    MARK2 = endOfKataMark2;

    if(endOfKataMark2=='\0'&&endOfKataMark1=='\0'){MARK2 = '\n';MARK1 = '\n';}
    else if(endOfKataMark2=='\0'||endOfKataMark1=='\0'){
        if(endOfKataMark1=='\0'){MARK1 = MARK2;}
        else if(endOfKataMark2=='\0'){MARK2 = MARK1;}
    }

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

void shutdownKata(){
    QUIT();
    advKata();
}

