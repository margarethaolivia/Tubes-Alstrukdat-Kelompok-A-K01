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