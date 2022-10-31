#include <stdio.h>
#include "utility.h"
#include "prioqueue.h"
#include "liststatik.h"

void INVERTORY(PQueue daftarInvertory){
    printf("List Makanan di Invertory\n(nama - waktu sisa kadaluwarsa)\n");
    int i;
    for(i=0;i<lengthPQueue(daftarInvertory);i++){
        char* namaMakanan = Nama(getElmtPQueue(daftarInvertory,i)).buffer;
        time kadaluwarsa = Expired(getElmtPQueue(daftarInvertory,i));
        printf("    %d. ",i+1);
        printf(namaMakanan);
        printf(" -");
        printTimeHJM(kadaluwarsa);
        printf("\n");
    }
}

void pesan_(PQueue* bufferPesanan, Makanan makanan){
    enqueue(bufferPesanan,makanan);
}

int updateInvertory_(PQueue* bufferInvertory, PQueue* bufferNotifikasi){
    int jumlahKadaluwarsa = 0;

    ElTypePQueue makananKadaluwarsa;

    while((timeToMin(Expired(Head(*bufferInvertory)))==0) && lengthPQueue(*bufferInvertory)>0){
        dequeue(bufferInvertory,&makananKadaluwarsa);
        enqueue(bufferNotifikasi,makananKadaluwarsa);
        jumlahKadaluwarsa++;
    }

    return jumlahKadaluwarsa;
}

int updateDelivery_(PQueue* bufferInvertory, PQueue* bufferDelivery, PQueue* bufferNotifikasi){
    int jumlahDelivered = 0;

    ElTypePQueue makananDelivered;

    while(timeToMin(DelivTime(Head(*bufferDelivery)))==0 && lengthPQueue(*bufferDelivery)>0){
        dequeue(bufferDelivery,&makananDelivered);
        enqueue(bufferInvertory,makananDelivered);
        enqueue(bufferNotifikasi,makananDelivered);
        jumlahDelivered++;
    }

    return jumlahDelivered;
}

void printNotifikasi_(PQueue* bufferNotifikasi, int jumlahKadaluwarsa, int jumlahDelivered){
    ElTypePQueue bufferMakanan;
    int i;
    for(i=0;i<jumlahKadaluwarsa;i++){
        dequeue(bufferNotifikasi,&bufferMakanan);
        printf("    %d. ",i+1);
        printf(Nama(bufferMakanan).buffer);
        printf(" Kedaluwarsa.. : (\n");
    }
    for(i=jumlahKadaluwarsa;i<jumlahDelivered+jumlahKadaluwarsa;i++){
        dequeue(bufferNotifikasi,&bufferMakanan);
        printf("    %d. ",i+1);
        printf(Nama(bufferMakanan).buffer);
        printf(" sudah diterima oleh BNMO!\n");
    }
}

void UPDATE_INVERTORY_DELIVERY(PQueue* bufferInvertory, PQueue* bufferDelivery, PQueue* bufferNotifikasi){
    int i;
    for(i=0;i<lengthPQueue(*bufferDelivery);i++){
        ElTypePQueue* currentItem;
        currentItem = getElmtPQueueReff(bufferDelivery,i);

        DelivTime(*currentItem) = minToTime(timeToMin(DelivTime(*currentItem)) - 1);
    }

    for(i=0;i<lengthPQueue(*bufferInvertory);i++){
        ElTypePQueue* currentItem;
        currentItem = getElmtPQueueReff(bufferInvertory,i);

        Expired(*currentItem) = minToTime(timeToMin(Expired(*currentItem)) - 1);
    }


    int jumlahDelivered = updateDelivery_(bufferInvertory,bufferDelivery,bufferNotifikasi);
    int jumlahkadaluwarsa = updateInvertory_(bufferInvertory,bufferNotifikasi);
    
    printNotifikasi_(bufferNotifikasi,jumlahkadaluwarsa,jumlahDelivered);

}

boolean fx(ElTypePQueue x, Kata a){
    return strcmp(Nama(x).buffer,a.buffer);
}

int main(){
    PQueue daftarInvertory;
    createPQueue(&daftarInvertory,7);
    Makanan man;
    time kadaluarsa;
    createTime(&kadaluarsa,0,0,1);
    Kata nama;
    createKata(&nama, "ASU GORENG");
    createMakanan(&man,1,nama,kadaluarsa,'n',kadaluarsa);

    enqueue(&daftarInvertory,man);

    Makanan man1;
    time kadaluarsa1;
    createTime(&kadaluarsa1,0,0,2);
    Kata nama1;
    createKata(&nama1, "ASU REBUS");
    createMakanan(&man1,4,nama1,kadaluarsa1,'f',kadaluarsa1);


    enqueue(&daftarInvertory,man1);
    enqueue(&daftarInvertory,man);
    enqueue(&daftarInvertory,man1);
    enqueue(&daftarInvertory,man1);
    enqueue(&daftarInvertory,man);

    PQueue daftarNotif;
    createPQueue(&daftarNotif,7);

    PQueue daftarDeliv;
    createPQueue(&daftarDeliv,7);

    enqueue(&daftarDeliv,man);
    enqueue(&daftarDeliv,man);
    enqueue(&daftarDeliv,man1);

    UPDATE_INVERTORY_DELIVERY(&daftarInvertory,&daftarDeliv,&daftarNotif);

    INVERTORY(daftarInvertory);

    UPDATE_INVERTORY_DELIVERY(&daftarInvertory,&daftarDeliv,&daftarNotif);

    INVERTORY(daftarInvertory);

}