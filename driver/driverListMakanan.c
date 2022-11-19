#include <stdio.h>
#include "../ADT/List_Makanan/listmakanan.h"

int main(int argc, char const *argv[])
{
    listMakanan lm;
    createListMakanan(&lm);
    readMakananFile(&lm,"../Config/makanan.txt");
    displayListMakanan(lm);
    return 0;
}
