#include <stdio.h>
#include "utility.h"
#include "prioqueue.h"

void INVERTORY(PQueue q){
    printf("List Makanan di Invertory\n(nama - waktu sisa kadaluwarsa)\n");
    int i;
    for(i=0;i<lengthPQueue(q);i++){
        char* namaMakanan = Nama(getElmtPQueue(q,i)).buffer;
        time kadaluwarsa = Expired(getElmtPQueue(q,i));
        printf("    %d. ",i+1);
        printf(namaMakanan);
        printf(" -");
        printTimeHJM(kadaluwarsa);
        printf("\n");
    }
}

// int main(){
//     PQueue q;
//     createPQueue(&q,4);
//     Makanan man;
//     time kadaluarsa;
//     createTime(&kadaluarsa,3,2,1);
//     Kata nama;
//     createKata(&nama, "ASU GORENG");
//     createMakanan(&man,1,nama,kadaluarsa,'n',kadaluarsa);

//     enqueue(&q,man);

//     Makanan man1;
//     time kadaluarsa1;
//     createTime(&kadaluarsa1,2,21,13);
//     Kata nama1;
//     createKata(&nama1, "ASU REBUS");
//     createMakanan(&man1,4,nama1,kadaluarsa1,'f',kadaluarsa1);

    
//     createMakanan(&man,1,nama,kadaluarsa1,'j',kadaluarsa);

//     enqueue(&q,man1);
//     enqueue(&q,man);

//     INVERTORY(q);

// }