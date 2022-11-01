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
    if(Mother(*t) == mother){
        return *t;
    } else {
        Tree tempt;
        tempt = *t;
        int i = 0;
        while(i<ChildCount(tempt)&&result==NULL){
            result = motherAddress(&(ChildBase(tempt))[i],mother);
            i++;
        }
    }
    return result;
}

void createTree(Tree* t){
    *t = NULL;
}

void assignMother(Tree* t, ElTypeTree mother){
    *t = createChild(mother);
}

void assignChildTo(Tree* t, ElTypeTree mother, Tree child){
    Tree motherData;
    motherData = motherAddress(t,mother);
    
    if(ChildBase(motherData)==NULL){
        ChildBase(motherData) = (Tree*)malloc(sizeof(Tree)*(ChildCount(motherData)+1));    
    } else {
        ChildBase(motherData) = (Tree*)realloc(ChildBase(motherData),sizeof(Tree)*(ChildCount(motherData)+1));
    }
    ChildBase(motherData)[ChildCount(motherData)] = child;
    ChildCount(motherData) = ChildCount(motherData) + 1;
}