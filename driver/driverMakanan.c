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
    Kata nama;
    char aksi;
    int len, i;

    printf("Masukkan nama makanan : ");
    startKata("", false, '\0', '\n');
    createKata(&nama, currentKata.buffer);

    aksi = 'B';

    createTime(&exp, 0, 0, 5);
    createTime(&deliv, 0, 0, 12);

    createMakanan(&m, 0, nama, exp, aksi, deliv);

    printMakanan(m);
    return 0;
}