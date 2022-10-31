/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H

#include "../Boolean/boolean.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../PrioQueue/prioqueue.h"
#include "../Time/time.h"

#define IDX_UNDEF -1

typedef struct
{
    Makanan *content;        
    int capacity;
    int nEff;
    int lastIdx;
} listMakanan; 

/*----Selektor----*/
#define LASTIDX(l) (l).lastIdx
#define MAKANAN(l, i) (l).content[i]
#define CAPACITY(l) (l).capacity
#define CONTENT(l) (l).content

    //void readMakanan(); (jadinya digabung sama createMakanan)
    //Baca file makanan, buat listMakanan pake createListMakanan, manggil fungsi createMakanan buat bikin semua
    //makanan yang ada di file terus masukin ke listMakanan lewat addMakanan
    //I.S:
    //sembarang
    //F.S:
    //terbentuk listMakanan l dengan isi semua makanan sesuai bacaan dari file

void createListMakanan(listMakanan *l, int size);
    //Buat listMakanan kosong, sizenya baca dari file, lastIdx awal IDX_UNDEF
    //I.S:
    //sembarang, size dari baca file
    //F.S:
    //terbentuk listMakanan l kosong dengan ukuran size

void createMakanan(listMakanan *l);
//Baca file dari makanan, masukin ke variabel, trs bikin variabel makanan.
    //Buat makanan baru, isinya id, nama, waktu kedaluwarsa, lokasi aksi, waktu pengiriman
    //Masukin makanan yang baru dibikin ke listMakanan
    //I.S:
    //sembarang
    //F.S:
    //terbentuk listMakanan l dengan isi semua makanan sesuai bacaan dari file



#endif