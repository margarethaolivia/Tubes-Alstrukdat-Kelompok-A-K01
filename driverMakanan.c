#include <stdio.h>
#include "makanan.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

extern boolean EOP;
extern Kata currentKata;

int main()
{
    Makanan m;
    time exp, deliv;
    Kata nama;
    char aksi;

    // const char *PATH = "tes.txt";
    // startKata(PATH, true);

    startKata("", false);
    nama = currentKata;
    advKata();
    aksi = 'B';

    createTime(&exp, 0, 0, 5);
    createTime(&deliv, 0, 0, 12);

    createMakanan(&m, 0, nama, exp, aksi, deliv);
    printMakanan(m);
    return 0;
}