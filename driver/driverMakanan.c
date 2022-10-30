#include <stdio.h>
#include "../makanan.h"
#include "../mesinkata.h"
#include "../mesinkarakter.h"

extern boolean EOP;
extern Kata currentKata;

int main()
{
    Makanan m;
    time exp, deliv;
    Kata nama[CAPACITY];
    char aksi;
    int len, i;

    startKata("", false, ' ', '\n');

    len = 0;
    i = 0;
    while (CC != '\n')
    {
        nama[i] = currentKata;
        i += 1;
        len += 1;
        advKata();
    }
    nama[i] = currentKata;
    len += 1;

    aksi = 'B';

    createTime(&exp, 0, 0, 5);
    createTime(&deliv, 0, 0, 12);

    createMakanan(&m, 0, nama, len, exp, aksi, deliv);
    printMakanan(m);
    return 0;
}