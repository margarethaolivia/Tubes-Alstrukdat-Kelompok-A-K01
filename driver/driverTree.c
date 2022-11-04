#include "../ADT/Tree/tree.h"
#include <stdio.h>

void p(Tree* t){
    int i;
    for(i=0;i<2;i++){
        assignChildTo(t,3,createChild(i));    
    }
}

int main(){
    Tree t;
    createTree(&t);
    assignMotherEve(&t,3);
    assignChildTo(&t,3,createChild(4));
    assignChildTo(&t,4,createChild(6));
    p(&t);
    assignChildTo(&t,3,createChild(7));
    assignChildTo(&t,7,createChild(8));
    assignChildTo(&t,7,createChild(10));
    printTree(t);
    Tree p = motherAddress(&t,4);
    destroyTree(&p);
    printTree(t);
    // for(i=0;i<ChildCount(t);i++){
    //     printf("%d",getNthChildOf(t,3,i));
    // }
    if(p==NULL){printf("p");}
}