#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree newTree(int value, int size) {
    int val, childsize;
    tree t;
    
    tree T = (tree) malloc(sizeof(node));
    value(T) = value;
    T.ListOfTree = (tree*) malloc (size*sizeof(tree));
    for (int i = 0; i < size; i++) {
        scanf("%d", &val);
        searchTree(&t, val);
        T.ListOfTree[i] = t;
    }
    return T;
}

void printTree(tree T) {
    if (T != NULL) {
        printf("%d ", value(T));
        for (int i = 0; i < T.ListOfTree.size; i++){
            printTree(T.ListOfTree[i]);
        }
    }
}
