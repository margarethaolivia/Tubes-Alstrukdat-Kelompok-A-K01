/* File: makanan.h */
/* *** Definisi ABSTRACT DATA TYPE MAKANAN *** */

#ifndef MAKANAN_H
#define MAKANAN_H

#include "../Boolean/boolean.h"
#include "../Time/time.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../PrioQueue/prioqueue.h"

typedef struct
{
    int id;         /* id makanan   */
    Kata nama;      /* nama makanan */
    time expired;   /* waktu kadaluwarsa */
    char aksi;      /* aksi */
    time delivTime; /* lama pengiriman */
} Makanan;


/* *** Notasi Akses: Selektor Makanan *** */
#define Id(m) (m).id
#define Nama(m) (m).nama
#define Expired(m) (m).expired
#define Aksi(m) (m).aksi
#define DelivTime(m) (m).delivTime

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

/* *** Konstruktor membentuk Makanan *** */
void createMakanan(Makanan *m, int id, Kata nama, time expired, char aksi, time delivTime);
// membentuk sebuah Makanan dari komponen-komponennya

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