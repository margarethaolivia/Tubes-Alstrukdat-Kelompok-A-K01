/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../Boolean/boolean.h"
#define MARK '\n'

/* State Mesin */
extern char CC;
extern boolean EOP;

void START(const char* PATH,boolean rFile);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          EOP true => gagal baca file
          EOP false => berhasil baca file atau input dari IO terminal*/

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, EOP = false
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          Jika retval -1 maka EOP akan menyala (true) */

void QUIT();
//menghentikan mesin karakter secara manual

#endif