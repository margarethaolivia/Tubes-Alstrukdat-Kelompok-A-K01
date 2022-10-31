#include <stdio.h>
#include <math.h>
#include "liststatik.h"
#include "../Boolean/boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l) 
{
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
  // KAMUS
    int i;

  // ALGORITMA
    for (i=0; i<CAPACITY; i++)
    {
        ELMT(*l,i) = MARK;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) 
{
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
    int i, length = 0;

    for (i=0; i<CAPACITY; i++)
    {
        if (ELMT(l,i) != MARK)
            length += 1;
    }
    return length;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) 
{
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return ELMT(l,0);
}

IdxType getLastIdx(ListStatik l) 
{
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return ELMT(l,(listLength(l)-1));
}


/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) 
{
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
    if (i >= CAPACITY || i < 0)
    {
        return false;
    }

    return true;
}

boolean isIdxEff(ListStatik l, IdxType i) 
{
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
    if (isIdxValid(l,i)) 
    {
        if (ELMT(l,i) == MARK)
        {
            return false;
        }
        return true;
    }
    return false;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    if (ELMT(l,0) == MARK)
        return true;
  
    return false;
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l) {
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    if (ELMT(l,CAPACITY-1) == MARK)
        return false;
  
    return true;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
    int n;

    do {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY);
  
    CreateListStatik(l);
    if (n != 0) {
        int i, input;
        for (i=0; i<n; i++) {
            do {
                scanf("%d", &input);
            } while (input <= 0);
            ELMT(*l,i) = input;
        }
    }  
}

void printList(ListStatik l) {
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
    int i;
  
    printf("[");
    if (ELMT(l,0) == MARK) {
        printf("]");
        return;
    }
    printf("%d",ELMT(l,0));
    for (i=1; i<CAPACITY; i++) {
        if (ELMT(l,i) == MARK)
            break;
        printf(",%d",ELMT(l,i));
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    int i;
    ListStatik l3;
    CreateListStatik(&l3);
    
    if (plus) {
        for(i=0; i<listLength(l1); i++) {
        ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
        }
        return l3;
    }

    for (i=0; i<listLength(l1); i++) {
        ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
    if (listLength(l1) == listLength(l2)) {
        int i;
        for (i=0; i<listLength(l2); i++) {
        if (ELMT(l1,i) != ELMT(l2,i))
            return false;
        }
        return true;
    }
    return false;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
    int i;
    for (i=0; i<CAPACITY; i++) {
        if (ELMT(l,i) == val)
            return i;
        if (ELMT(l,i) == MARK)
            return IDX_UNDEF;
    }
    return IDX_UNDEF;
}


/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
    int i;

    *max = ELMT(l,0);
    *min = ELMT(l,0);

    for (i=1; i<CAPACITY; i++) {
        if (ELMT(l,i) == MARK)
        return;
        if (ELMT(l,i) > *max)
        *max = ELMT(l,i);
        if (ELMT(l,i) < *min)
        *min = ELMT(l,i);
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
    int i; 
    for (i = listLength(*l)-1; i >= 0 ; i--) {
        (ELMT(*l,i) = ELMT(*l, i-1));
    }
    ELMT(*l,i-1) = val;
    return;
}


void insertAt(ListStatik *l, ElType val, IdxType idx) {
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
    int i; 
    for (i = listLength(*l)-1; i >= idx ; i--) {
        (ELMT(*l,i) = ELMT(*l, i-1));
    }
    ELMT(*l,i-1) = val;
    return;
}

void insertLast(ListStatik *l, ElType val) {
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    for (int i = 0; i < CAPACITY; i++) {
        if (ELMT(*l,i) == MARK) {
            ELMT(*l,i) = val;
            return;
        }
    }
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val) {
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
    int i; 
    for (i = listLength(*l)-1; i<0; i++) {
        (ELMT(*l,i) = ELMT(*l, i+1));
        return;
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
    int i; 
    for (i = listLength(*l)-1; i<idx-1; i++) {
        (ELMT(*l,i) = ELMT(*l, i+1));
        return;
    }
}

void deleteLast(ListStatik *l, ElType *val) {
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
    for (int i = 0; i<CAPACITY; i++) {
        if (ELMT(*l,i) == MARK) {
            *val = ELMT(*l,i-1);
            ELMT(*l,i-1) = MARK;
            return;
        }
    }
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    int i,j,swap_idx,len;
    ElType temp;

    len = listLength(*l);
    if (asc) {
        for (i=0; i<len; i++) {
        swap_idx = i;
        for (j=i+1; j<len; j++) {
            if (ELMT(*l,j) < ELMT(*l,swap_idx))
            swap_idx = j;
        }
        temp = ELMT(*l,swap_idx);
        ELMT(*l,swap_idx) = ELMT(*l,i);
        ELMT(*l,i) = temp;
        }
        return;
    }

    for (i=0; i<len; i++) {
        swap_idx = i;
        for (j=i+1; j<len; j++) {
        if (ELMT(*l,j) > ELMT(*l,swap_idx))
            swap_idx = j;
        }
        temp = ELMT(*l,swap_idx);
        ELMT(*l,swap_idx) = ELMT(*l,i);
        ELMT(*l,i) = temp;
    }
}