#ifndef TREE_H
#define TREE_H


#include "../Boolean/boolean.h"
#include "../Makanan/makanan.h"

//typedef Makanan ElTypeTree;
typedef int ElTypeTree;

typedef struct Branch* Tree;

typedef struct Branch {
    Tree* childrenBase;
    ElTypeTree motherValue;
    int childAmount;
} branch;


#define ChildBase(m) (*m).childrenBase
#define ChildCount(m) (*m).childAmount
#define Mother(m) (*m).motherValue

void createTree(Tree* t);
void destroyTree(Tree* t);

Tree createChild(ElTypeTree value);

void assignMother(Tree* t, ElTypeTree mother);

Tree motherAddress(Tree* t, ElTypeTree mother);

int childrenAmountOf(Tree t, ElTypeTree mother);
ElTypeTree getNthChildOf(Tree t,ElTypeTree mother, int idx);

void assignChildTo(Tree* t, ElTypeTree mother, Tree child);


#endif