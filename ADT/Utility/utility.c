#include "utility.h"
#include "../Mesin_Kata/mesinkata.h"

boolean strcmp(const char* s1, const char* s2){
    int i = 0;
    while(s1[i]!='\0'&&s1[i]==s2[i]){i++;}
                                                //comparasi string   
    return s1[i]==s2[i];
}

int stoi(Kata s){
    int buff = 0;int pow = 1;
    int i;
    for(i=s.length-1;i>=0;i--){
        buff += ((int)(s.buffer[i]-'0'))*pow;
        pow*=10;
    }
    return buff;
}

Kata concat(const char* s1, const char* s2){
    Kata s;
    char sBuffer[100];
    int i = 0;
    while(s1[i]!='\0'){
        sBuffer[i]=s1[i];
        i++;
    }
    int j = 0;
    while(s2[j]!='\0'){
        sBuffer[i]=s2[j];
        i++;
        j++;
    }
    sBuffer[i] = '\0';
    createKata(&s,sBuffer);

    return s;
}