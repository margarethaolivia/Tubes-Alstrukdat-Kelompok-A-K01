#include "utility.h"

boolean strcmp(const char* s1, const char* s2){
    int i = 0;
    while(s1[i]!='\0'&&s1[i]==s2[i]){i++;}
                                                //comparasi string   
    return s1[i]==s2[i];
}