#include <stdio.h>
#include <math.h>
#include "liststatik.h"
#include "../Boolean/boolean.h"
#include "listmakanan.h"

void createListMakanan(listMakanan *l, int size)
    {
        CAPACITY(*l) = size;
        CONTENT(*l) = (Makanan *) malloc(size * sizeof(Makanan));
        LASTIDX(*l) = IDX_UNDEF;
    }

void createMakanan(listMakanan *l)
    {
        startKata("../../Config/makanan.txt");
        int size;
        WordToInt(&size);
        CAPACITY(*l) = size;
        createListMakanan(l, size);
        for(int i = 0; i < size; i++){
            ADVNEWLINE1();
            int id;
            WordToInt(&id);
            Id(MAKANAN(*l, i)) = id;
            ADVNEWLINE2();
            Nama(MAKANAN(*l, i)) = currentKata;
            ADVNEWLINE1();
            time expired;
            BacaTIME(&expired);
            Expired(MAKANAN(*l, i)) = expired;
            ADVNEWLINE1();
            time delivTime;
            BacaTIME(&delivTime);
            DelivTime(MAKANAN(*l, i)) = delivTime;
            ADVNEWLINE1();
            Aksi(MAKANAN(*l, i)) = currentKata;
        }
    }