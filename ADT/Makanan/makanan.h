/* File: makanan.h */
/* *** Definisi ABSTRACT DATA TYPE MAKANAN *** */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../Boolean/boolean.h"
#include "../Time/time.c"
#include "../Time/time.h"

typedef struct
{
    int id;         /* id makanan   */
    Kata nama;      /* nama makanan */
    time expired;   /* waktu kadaluwarsa */
    char aksi;      /* aksi */
    time delivTime; /* lama pengiriman */
} Makanan;

typedef struct
{
    Makanan *content; // Nanti pake listdinamis, masih bingung
    int capacity;
    int nEff;
    int lastIdx;
} listMakanan;

/* *** Notasi Akses: Selektor Makanan *** */
#define Id(m) (m).id
#define Nama(m) (m).nama
#define Expired(m) (m).expired
#define Aksi(m) (m).aksi
#define DelivTime(m) (m).delivTime

#define LASTIDX(l) (l).lastIdx
#define MAKANAN(l, i) (l).content[i]

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

void createListMakanan(listMakanan *l, int size);
// Buat listMakanan kosong, sizenya baca dari file, lastIdx awal IDX_UNDEF
// I.S:
// sembarang, size dari baca file
// F.S:
// terbentuk listMakanan l kosong dengan ukuran size

/* *** Konstruktor membentuk Makanan *** */
void createMakanan(Makanan *m, int id, Kata nama, time expired, char aksi, time delivTime);
// membentuk sebuah Makanan dari komponen-komponennya

void addMakanan(Makanan *m, listMakanan *l);
// Masukin makanan ke listMakanan
// I.S:
// Makanan m dan listMakanan l terdefinisi
// F.S:
// m dimasukan ke l

/* *** I/O Makanan *** */

void readMakanan(Makanan *m);
// membaca komponen makanan dari file

void printMakanan(Makanan m);
// menuliskan makanan ke layar dengan format "nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time"

void printNama(Makanan m);
// mencetak nama makanan

void printAksi(char c);
// mencetak aksi

void printTimeHJM(time t);
// mencetak waktu dengan format .. hari .. jam .. menit

#endif