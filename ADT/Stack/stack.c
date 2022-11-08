#include "stack.h"
#include "../Boolean/boolean.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
{
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
{
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean isOneElmtStack(Stack S)
{
    if (!IsEmptyStack(S))
    {
        simulator X;
        Pop(&S, &X);
        return IsEmptyStack(S);
    }
    return false;
}

boolean IsFullStack(Stack S)
{
    return (Top(S) == MaxEl - 1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, simulator X)
{
    Top(*S) += 1;
    InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, simulator *X)
{
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */