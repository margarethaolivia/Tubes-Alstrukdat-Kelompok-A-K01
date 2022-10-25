/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakter.h"

#define NMax 50

typedef struct
{
   char buffer[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int length;
} Kata;

/* State Mesin Word */
extern Kata currentKata;

void ignoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startKata(const char* PATH,boolean rFile);
/* I.S. : currentChar sembarang
   F.S. : buffer kata terisi kata atau kosong*/

void advKata();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, 
          buffer kata mungkin kosong
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void salinKata();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          buffer kata mungkin kosong
          */

void shutdown();
   //berhenti membaca IO terminal

#endif