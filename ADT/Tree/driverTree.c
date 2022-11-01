#include "tree.h"
#include <stdio.h>

int main(){
    Tree t;
    createTree(&t);
    assignMother(&t,3);
    assignChildTo(&t,3,createChild(4));
    assignChildTo(&t,4,createChild(6));
    assignChildTo(&t,3,createChild(7));
    t = motherAddress(&t,8);
    if(t == NULL){printf("o");}
    printf("%d",Mother(t));
}