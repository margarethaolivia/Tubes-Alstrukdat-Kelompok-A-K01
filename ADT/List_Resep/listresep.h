#include "../Tree/tree.h"
#include <stdio.h>

typedef struct {
    Tree container[50];
    int len;
} ListResep;

void createListResep(ListResep* l);

void insertLastListResep(ListResep* l, Tree t);

Tree getElmtListResep(ListResep l, int idx);

int lengthListResep(ListResep l);

Tree* getElmtListResepReff(ListResep* l, int idx);
