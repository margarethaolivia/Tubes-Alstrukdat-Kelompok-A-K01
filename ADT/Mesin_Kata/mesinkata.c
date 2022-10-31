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










void WordToInt(int *x){
    int cc=1;
    *x=0;
    int len = currentKata.length-1;
    for(int i=len;i>=0;i--){
        *x = *x + (int)(currentKata.buffer[i]-48)*cc;
        cc*=10;
    }
}

void ADVNEWLINE1(){
    Kata EMPTY = {"", 0};
    currentKata = EMPTY;
    if(CC == MARK){
        EndWord = false;
        ADV();
        CopyWord1();
    }
}

void ADVNEWLINE2(){
    Kata EMPTY = {"", 0};
    currentKata = EMPTY;
    if(CC == MARK){
        EndWord = false;
        ADV();
        CopyWord2();
    }
}

void CopyWord1(){
    int i=0;
    while ((CC!=MARK && CC!= BLANK && i<NMax)){
        currentKata.buffer[i] = CC;
        ADV();
        i++;
    }
    currentKata.length = i;   
}

void CopyWord2(){
    int i=0;
    while ((CC!=MARK && i<NMax)){
        currentKata.buffer[i] = CC;
        ADV();
        i++;
    }
    currentKata.length = i;   
}

void ADVWORD1(){
    ignoreBlanks();
    if(CC==MARK){
        EndWord = true;
    }
    else{
        CopyWord1();
        ignoreBlanks();
    }
}

void ADVWORD2(){
    if(CC==MARK){
        EndWord = true;
    }
    else{
        CopyWord2();
        ignoreBlanks();
    }
}
