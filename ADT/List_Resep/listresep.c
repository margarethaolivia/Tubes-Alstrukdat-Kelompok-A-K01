#include "listresep.h"

void createListResep(ListResep* l){
    l->len=0;
}

void insertLastListResep(ListResep* l, Tree t){
    l->container[l->len] = t;
    l->len = l->len + 1;
}

Tree getElmtListResep(ListResep l, int idx){
    return l.container[idx];
}

int lengthListResep(ListResep l){
    return l.len;
}