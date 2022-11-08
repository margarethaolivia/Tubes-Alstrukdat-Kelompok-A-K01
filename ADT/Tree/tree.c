#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tree createChild(ElTypeTree value){
    Tree a;
    a = (Tree)malloc(sizeof(Tree));
    ChildBase(a) = NULL;
    ChildCount(a) = 0;
    Mother(a) = value;
    return a;
}

Tree motherAddress(Tree* t, ElTypeTree mother){
    Tree result;
    result = NULL;
    if(*t!=NULL){
        if(Mother(*t) == mother){
            return *t;
        } else {
            
            Tree tempt;
            tempt = *t;
            if(ChildBase(tempt)!=NULL){
                int i = 0;
                while(i<ChildCount(tempt)&&result==NULL){
                    result = motherAddress(&(ChildBase(tempt))[i],mother);
                    i++;
                }
            }
        }
    }
    return result;
}

void createTree(Tree* t){
    *t = NULL;
}

void assignMotherEve(Tree* t, ElTypeTree mother){
    *t = createChild(mother);
}

void assignChildTo(Tree* t, ElTypeTree mother, Tree child){
    Tree motherData;
    motherData = motherAddress(t,mother);
    if(motherData==NULL){
        return;
    }

    if(Mother(motherData)==Mother(child)){
        destroyTree(motherData);
        *motherData = *child;
        return;
    }
    
    if(ChildBase(motherData)==NULL){
        ChildBase(motherData) = (Tree*)malloc(sizeof(Tree)*(ChildCount(motherData)+1));    
    } else {
        ChildBase(motherData) = (Tree*)realloc(ChildBase(motherData),sizeof(Tree)*(ChildCount(motherData)+1));
    }
    ChildBase(motherData)[ChildCount(motherData)] = child;
    ChildCount(motherData) = ChildCount(motherData) + 1;
}

int amountOfChildren(Tree t, ElTypeTree mother) {
    Tree motherData;
    motherData = motherAddress(&t,mother);
    return ChildCount(motherData);
}

ElTypeTree getNthChildOf(Tree t,ElTypeTree mother, int idx){

    Tree motherData;
    motherData = motherAddress(&t,mother);

    return Mother(ChildBase(motherData)[idx]);
}

void destroyTree(Tree* t){
    if(*t!=NULL){
        if(ChildBase(*t)==NULL){
            free(*t);
            return;
        } 
        int i = 0;
        while(i<ChildCount(*t)){
            destroyTree(&(ChildBase(*t)[i]));
            i++;
        }
        free(ChildBase(*t));
        free(*t);
    }
    *t = NULL;
}

void printTreeBody(Tree t){
    if(t!=NULL){
        int i;
        for(i=0;i<ChildCount(t);i++){
            printf("%d",Mother(ChildBase(t)[i]));
            if(i==ChildCount(t)-1){
                printf("\n");
            }
        }
        for(i=0;i<ChildCount(t);i++){
            printTreeBody(ChildBase(t)[i]);
        }
    }
}

void printTree(Tree t){
    printf("%d\n",Mother(t));
    printTreeBody(t);
}