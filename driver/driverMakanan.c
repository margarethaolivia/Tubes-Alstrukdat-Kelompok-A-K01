#include <stdio.h>
#include "../ADT/Makanan/makanan.h"
#include "../ADT/Mesin_Kata/mesinkata.h"
#include "../ADT/Mesin_Karakter/mesinkarakter.h"

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