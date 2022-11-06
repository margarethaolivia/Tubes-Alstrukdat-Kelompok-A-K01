#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H

#include "../Boolean/boolean.h"
#include "../Mesin_Kata/mesinkata.h"
#include "../Makanan/makanan.h"
#include "../Time/time.h"

#define IDX_UNDEF -1
#define CAPACITYSTATIC 100
#define MARKSTATIC -69

// typedef struct
// {
//     int id;         /* id makanan   */
//     Kata nama;      /* nama makanan */
//     time expired;   /* waktu kadaluwarsa */
//     char aksi;      /* aksi */
//     time delivTime; /* lama pengiriman */
// } Makanan;

/* *** Notasi Akses: Selektor Makanan *** */
#define Id(m) (m).id
#define Nama(m) (m).nama
#define Expired(m) (m).expired
#define Aksi(m) (m).aksi
#define DelivTime(m) (m).delivTime

typedef struct
{
    Makanan contents[CAPACITYSTATIC];
} listMakanan; 


/*----Selektor----*/
#define MAKANAN(l, i) (l).contents[(i)]


void createListMakanan(listMakanan *l);


void insertMakanan(listMakanan *l, Makanan m);

int lengthLlistMakanan(listMakanan l);

void readMakananFile(listMakanan *lm, Kata path);

void displayListMakanan(listMakanan l);

#endif
