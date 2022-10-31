#ifndef TREE_H
#define TREE_H


#include "../Boolean/boolean.h"
#include "../Makanan/makanan.h"

typedef struct node *tree;

typedef struct {
    tree *TabTree;
    int Size;
}ListOfTree;

typedef struct node {
    int value;
    ListOfTree content[];
} node;



#define r(t) ((t)->right)
#define left(t) ((t)->left)
#define value(t) ((t)->value)

tree newTree(int value, int size);
void freeTree(tree t);
void printTree(tree t);
int treeSize(tree t);
int treeHeight(tree t);
int treeSum(tree t);
int treeMax(tree t);
int treeMin(tree t);
int treeDepth(tree t, int value);
int treeCount(tree t, int value);
int treeCountLeaves(tree t);
int treeCountNodes(tree t);
int treeCountFullNodes(tree t);
int treeCountHalfNodes(tree t);
int treeCountOddNodes(tree t);
int treeCountEvenNodes(tree t);
int treeCountPositiveNodes(tree t);
int treeCountNegativeNodes(tree t);
int treeCountZeroNodes(tree t);
int treeCountNonZeroNodes(tree t);
int treeCountNonPositiveNodes(tree t);
int treeCountNonNegativeNodes(tree t);
int treeCountNonOddNodes(tree t);
int treeCountNonEvenNodes(tree t);
int treeCountNonFullNodes(tree t);
int treeCountNonHalfNodes(tree t);
int treeCountNonLeaves(tree t);
int treeCountNonNodes(tree t);
int treeCountNonPositiveLeaves(tree t);
int treeCountNonNegativeLeaves(tree t);
int treeCountNonOddLeaves(tree t);
int treeCountNonEvenLeaves(tree t);
int treeCountNonFullLeaves(tree t);
int treeCountNonHalfLeaves(tree t);
int treeCountNonPositiveNodes(tree t);
int treeCountNonNegativeNodes(tree t);
int treeCountNonOddNodes(tree t);
int treeCountNonEvenNodes(tree t);





#endif