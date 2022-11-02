#include "tree.h"
#include <stdio.h>

int main(){
    Tree t;
    createTree(&t);
    assignMotherEve(&t,3);
    assignChildTo(&t,3,createChild(4));
    assignChildTo(&t,4,createChild(6));
    assignChildTo(&t,3,createChild(7));
    printf("%d",Mother(t));
    Tree p = motherAddress(&t,4);
    destroyTree(&t);
    int i;
    // for(i=0;i<ChildCount(t);i++){
    //     printf("%d",getNthChildOf(t,3,i));
    // }
    if(p==NULL){printf("p");}
}