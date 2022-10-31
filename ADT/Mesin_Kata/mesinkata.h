/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../Boolean/boolean.h"
#include "../Mesin_Karakter/mesinkarakter.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char buffer[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int length;
} Kata;

void createKata(Kata* s,const char* string);
//membuat kata atau string;

/* State Mesin Word */
extern Kata currentKata;
extern char MARK;
boolean EndWord;

void ignoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startKata(const char* PATH,boolean rFile,char endOfKataMark1,char endOfKataMark2);
/* I.S. : currentChar sembarang
   F.S. : buffer kata terisi kata atau kosong*/
   //isi empty string saja jika hanya ingin MARK = \n, atau isi salah satu dengan MARK
   //yang diingingkan dan empty string untuk yg lainnya

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

void shutdownKata();
   //berhenti membaca IO terminal

void WordToInt(int *x);

void ADVNEWLINE1();
void ADVNEWLINE2();
void CopyWord1();
void CopyWord2();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

#endif