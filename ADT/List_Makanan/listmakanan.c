#include <stdio.h>
#include <math.h>
#include "../Boolean/boolean.h"
#include "listmakanan.h"

void createListMakanan(listMakanan *l)
{
    for (int x = 0 ; x <CAPACITYSTATIC ; x++)
    {
        Id(MAKANAN(*l,x)) = MARKSTATIC;
    }
}

void insertMakanan(listMakanan *l, Makanan m)
{
    boolean found = false;
    int x = 0;

    while (x < lengthLlistMakanan(*l) && found == false )
    {
        if (Id(MAKANAN(*l,x)) == Id(m))
        {
            MAKANAN(*l,x) = m;
            found = true;
        }
        x += 1;
    }
    if (!found)
    {
        MAKANAN(*l, lengthLlistMakanan(*l)) = m;
    }
}

int lengthLlistMakanan(listMakanan l)
{
    int x = 0;
    while(Id(MAKANAN(l,x)) != MARKSTATIC && x < CAPACITYSTATIC)
    {
        x+=1;
    }
    return x;
}
