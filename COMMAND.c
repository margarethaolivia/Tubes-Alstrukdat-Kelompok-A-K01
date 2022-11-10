#include <stdio.h>
#include "ADT/Utility/utility.h"
#include "ADT/PrioQueue/prioqueue.h"
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/Stack/stack.h"
#include "ADT/Tree/tree.h"
#include "ADT/List_Resep/listresep.h"
#include "ADT/List_Makanan/listmakanan.h"

void INVERTORY(PQueue daftarInvertory)
{
    printf("List Makanan di Invertory\n(nama - waktu sisa kadaluwarsa)\n");
    int i;
    for (i = 0; i < lengthPQueue(daftarInvertory); i++)
    {
        char *namaMakanan = Nama(getElmtPQueue(daftarInvertory, i)).buffer;
        time kadaluwarsa = Expired(getElmtPQueue(daftarInvertory, i));
        printf("    %d. ", i + 1);
        printf(namaMakanan);
        printf(" -");
        printTimeHJM(kadaluwarsa);
        printf("\n");
    }
}

void pesan_(PQueue *bufferPesanan, Makanan makanan)
{
    enqueue(bufferPesanan, makanan);
}

int updateInvertory_(PQueue *bufferInvertory, PQueue *bufferNotifikasi)
{
    int jumlahKadaluwarsa = 0;

    ElTypePQueue makananKadaluwarsa;

    while ((timeToMin(Expired(Head(*bufferInvertory))) == 0) && lengthPQueue(*bufferInvertory) > 0)
    {
        dequeue(bufferInvertory, &makananKadaluwarsa);
        enqueue(bufferNotifikasi, makananKadaluwarsa);
        jumlahKadaluwarsa++;
    }

    return jumlahKadaluwarsa;
}

int updateDelivery_(PQueue *bufferInvertory, PQueue *bufferDelivery, PQueue *bufferNotifikasi)
{
    int jumlahDelivered = 0;

    ElTypePQueue makananDelivered;

    while (timeToMin(DelivTime(Head(*bufferDelivery))) == 0 && lengthPQueue(*bufferDelivery) > 0)
    {
        dequeue(bufferDelivery, &makananDelivered);
        enqueue(bufferInvertory, makananDelivered);
        enqueue(bufferNotifikasi, makananDelivered);
        jumlahDelivered++;
    }

    return jumlahDelivered;
}

void printNotifikasi_(PQueue *bufferNotifikasi, int jumlahKadaluwarsa, int jumlahDelivered)
{
    ElTypePQueue bufferMakanan;
    int i;
    for (i = 0; i < jumlahKadaluwarsa; i++)
    {
        dequeue(bufferNotifikasi, &bufferMakanan);
        printf("    %d. ", i + 1);
        printf(Nama(bufferMakanan).buffer);
        printf(" Kedaluwarsa.. : (\n");
    }
    for (i = jumlahKadaluwarsa; i < jumlahDelivered + jumlahKadaluwarsa; i++)
    {
        dequeue(bufferNotifikasi, &bufferMakanan);
        printf("    %d. ", i + 1);
        printf(Nama(bufferMakanan).buffer);
        printf(" sudah diterima oleh BNMO!\n");
    }
}

void UPDATE_INVERTORY_DELIVERY(PQueue *bufferInvertory, PQueue *bufferDelivery, PQueue *bufferNotifikasi)
{
    int i;
    for (i = 0; i < lengthPQueue(*bufferDelivery); i++)
    {
        ElTypePQueue *currentItem;
        currentItem = getElmtPQueueReff(bufferDelivery, i);

        DelivTime(*currentItem) = minToTime(timeToMin(DelivTime(*currentItem)) - 1);
    }

    for (i = 0; i < lengthPQueue(*bufferInvertory); i++)
    {
        ElTypePQueue *currentItem;
        currentItem = getElmtPQueueReff(bufferInvertory, i);

        Expired(*currentItem) = minToTime(timeToMin(Expired(*currentItem)) - 1);
    }

    int jumlahDelivered = updateDelivery_(bufferInvertory, bufferDelivery, bufferNotifikasi);
    int jumlahkadaluwarsa = updateInvertory_(bufferInvertory, bufferNotifikasi);

    printNotifikasi_(bufferNotifikasi, jumlahkadaluwarsa, jumlahDelivered);
}

boolean fx(ElTypePQueue x, Kata a)
{
    return strcmp(Nama(x).buffer, a.buffer);
}

void wait(time *current_time, int jam, int menit)
{
    int n = timeToMin(*current_time) + jam * 60 + menit;
    *current_time = minToTime(n);
}

// command CATALOG
void catalog(listMakanan lm)
{
    int i;
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
    for (i = 0; i < lengthLlistMakanan(lm); i++)
    {
        printf("%d. ", i + 1);
        printMakanan(MAKANAN(lm, i));
        printf("\n");
    }
}

void undo(Stack *stackSim, Stack *stackSimState, simulator *x, boolean *valid)
{
    if (isOneElmtStack(*stackSim))
    {
        printf("Undo gagal dilakukan (sudah berada di kondisi awal)\n");
        *valid = false;
    }
    else
    {
        Pop(stackSim, x);
        Push(stackSimState, *x);
        // *x = InfoTop(stackSim);
        printf("Berhasil melakukan undo\n");
        *valid = true;
    }
}

void redo(Stack *stackSim, Stack *stackSimState, simulator *x, boolean *valid)
{
    if (IsEmptyStack(*stackSimState))
    {
        printf("Redo gagal dilakukan (sudah berada di kondisi akhir)\n");
        *valid = false;
    }
    else
    {
        Pop(stackSimState, x);
        Push(stackSim, *x);
        printf("Berhasil melakukan redo\n");
        *valid = true;
    }
}

void READ_RESEP(const char *PATH, ListResep *l)
{
    startKata(PATH, true, '\n', "");
    int n = stoi(currentKata);
    int i;
    for (i = 0; i < n; i++)
    {
        int id, nchild;
        advKata(' ', '\n');
        id = stoi(currentKata);
        advKata(' ', '\n');
        nchild = stoi(currentKata);
        Tree t;
        createTree(&t);
        assignMotherEve(&t, id);
        int j;
        for (j = 0; j < nchild; j++)
        {
            int idChild;
            advKata(' ', '\n');
            idChild = stoi(currentKata);
            Tree childResep;
            boolean ada = false;
            int k = 0;
            while(!ada&&k<lengthListResep(*l)){
                if(Mother(getElmtListResep(*l,k))==idChild){
                    childResep = getElmtListResep(*l,k);
                    ada = true;
                }
                k++;
            }
            if(!ada){
                childResep = createChild(idChild);
            }
            assignChildTo(&t, id, childResep);
        }
        for(j=0;j<lengthListResep(*l);j++){
            assignChildTo(getElmtListResepReff(l,j),id,t);
        }
        insertLastListResep(l, t);
    }
}

void MIX(listMakanan lM, ListResep lR, PQueue* bufferInvertory){
    listMakanan lOpsi = searchListMakananBasedOnAksi(lM,'M');
    printf("=======================\n");
    printf("=         MIX         =\n");
    printf("=======================\n");
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    int i;
    for(i=0;i<lOpsi.listmakanlen;i++){
        printf("    %d. ",i+1);
        printf(Nama(lOpsi.contents[i]).buffer);
        printf("\n");
    }
    printf("\nKirim 0 utuk exit.\n\n");
    int opsi;
    do{
        printf("\nEnter Command: ");
        scanf("%d",&opsi);
        if(opsi<0||opsi>lOpsi.listmakanlen){
            printf("Mainnya hebat!.");
        }
        else if(opsi!=0){
            int requestId = Id(lOpsi.contents[opsi-1]);
            boolean doable = true;
            Makanan requestedMakanan = getElmakanid(lM,requestId);
            Tree resep;
            int j = 0;
            while(Mother(getElmtListResep(lR,j))!=requestId&&j<lengthListResep(lR)){
                j++;
            }
            int k;
            if(Mother(getElmtListResep(lR,j))==requestId){
                resep = getElmtListResep(lR,j);
                for(k=0;k<amountOfChildren(resep,requestId);k++){
                    int neededId = getNthChildOf(resep,requestId,k);
                    if(!isIdInQueue(*bufferInvertory,neededId)){
                        doable = false;
                    }
                }
                if(doable){
                    resep = getElmtListResep(lR,j);
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        removeIdFromQueue(bufferInvertory,neededId);
                    } 
                    enqueue(bufferInvertory,requestedMakanan);
                    printf("\n");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" selesai dibuat dan sudah masuk ke invertory!\n");
                } else {
                    printf("\nGagal membuat ");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        if(!isIdInQueue(*bufferInvertory,neededId)){
                            Makanan neededMakanan = getElmakanid(lM,neededId);
                            printf("%d ",i+1);
                            printf(Nama(neededMakanan).buffer);
                            printf("\n");
                        }
                    }
                }
            }
        }
    }while(opsi!=0);
}

void FRY(listMakanan lM, ListResep lR, PQueue* bufferInvertory){
    listMakanan lOpsi = searchListMakananBasedOnAksi(lM,'F');
    printf("=======================\n");
    printf("=         FRY         =\n");
    printf("=======================\n");
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    int i;
    for(i=0;i<lOpsi.listmakanlen;i++){
        printf("    %d. ",i+1);
        printf(Nama(lOpsi.contents[i]).buffer);
        printf("\n");
    }
    printf("\nKirim 0 utuk exit.\n\n");
    int opsi;
    do{
        printf("\nEnter Command: ");
        scanf("%d",&opsi);
        if(opsi<0||opsi>lOpsi.listmakanlen){
            printf("Mainnya hebat!.");
        }
        else if(opsi!=0){
            int requestId = Id(lOpsi.contents[opsi-1]);
            boolean doable = true;
            Makanan requestedMakanan = getElmakanid(lM,requestId);
            Tree resep;
            int j = 0;
            while(Mother(getElmtListResep(lR,j))!=requestId&&j<lengthListResep(lR)){
                j++;
            }
            int k;
            if(Mother(getElmtListResep(lR,j))==requestId){
                resep = getElmtListResep(lR,j);
                for(k=0;k<amountOfChildren(resep,requestId);k++){
                    int neededId = getNthChildOf(resep,requestId,k);
                    if(!isIdInQueue(*bufferInvertory,neededId)){
                        doable = false;
                    }
                }
                if(doable){
                    resep = getElmtListResep(lR,j);
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        removeIdFromQueue(bufferInvertory,neededId);
                    } 
                    enqueue(bufferInvertory,requestedMakanan);
                    printf("\n");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" selesai dibuat dan sudah masuk ke invertory!\n");
                } else {
                    printf("\nGagal membuat ");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        if(!isIdInQueue(*bufferInvertory,neededId)){
                            Makanan neededMakanan = getElmakanid(lM,neededId);
                            printf("%d ",i+1);
                            printf(Nama(neededMakanan).buffer);
                            printf("\n");
                        }
                    }
                }
            }
        }
    }while(opsi!=0);
}

void BOIL(listMakanan lM, ListResep lR, PQueue* bufferInvertory){
    listMakanan lOpsi = searchListMakananBasedOnAksi(lM,'O');
    printf("=======================\n");
    printf("=        BOIL         =\n");
    printf("=======================\n");
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    int i;
    for(i=0;i<lOpsi.listmakanlen;i++){
        printf("    %d. ",i+1);
        printf(Nama(lOpsi.contents[i]).buffer);
        printf("\n");
    }
    printf("\nKirim 0 utuk exit.\n\n");
    int opsi;
    do{
        printf("\nEnter Command: ");
        scanf("%d",&opsi);
        if(opsi<0||opsi>lOpsi.listmakanlen){
            printf("Mainnya hebat!.");
        }
        else if(opsi!=0){
            int requestId = Id(lOpsi.contents[opsi-1]);
            boolean doable = true;
            Makanan requestedMakanan = getElmakanid(lM,requestId);
            Tree resep;
            int j = 0;
            while(Mother(getElmtListResep(lR,j))!=requestId&&j<lengthListResep(lR)){
                j++;
            }
            int k;
            if(Mother(getElmtListResep(lR,j))==requestId){
                resep = getElmtListResep(lR,j);
                for(k=0;k<amountOfChildren(resep,requestId);k++){
                    int neededId = getNthChildOf(resep,requestId,k);
                    if(!isIdInQueue(*bufferInvertory,neededId)){
                        doable = false;
                    }
                }
                if(doable){
                    resep = getElmtListResep(lR,j);
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        removeIdFromQueue(bufferInvertory,neededId);
                    } 
                    enqueue(bufferInvertory,requestedMakanan);
                    printf("\n");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" selesai dibuat dan sudah masuk ke invertory!\n");
                } else {
                    printf("\nGagal membuat ");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        if(!isIdInQueue(*bufferInvertory,neededId)){
                            Makanan neededMakanan = getElmakanid(lM,neededId);
                            printf("%d ",i+1);
                            printf(Nama(neededMakanan).buffer);
                            printf("\n");
                        }
                    }
                }
            }
        }
    }while(opsi!=0);
}

void CHOP(listMakanan lM, ListResep lR, PQueue* bufferInvertory){
    listMakanan lOpsi = searchListMakananBasedOnAksi(lM,'C');
    printf("=======================\n");
    printf("=         CHOP        =\n");
    printf("=======================\n");
    printf("List Bahan Makanan yang Bisa Dibuat:\n");
    int i;
    for(i=0;i<lOpsi.listmakanlen;i++){
        printf("    %d. ",i+1);
        printf(Nama(lOpsi.contents[i]).buffer);
        printf("\n");
    }
    printf("\nKirim 0 utuk exit.\n\n");
    int opsi;
    do{
        printf("\nEnter Command: ");
        scanf("%d",&opsi);
        if(opsi<0||opsi>lOpsi.listmakanlen){
            printf("Mainnya hebat!.");
        }
        else if(opsi!=0){
            int requestId = Id(lOpsi.contents[opsi-1]);
            boolean doable = true;
            Makanan requestedMakanan = getElmakanid(lM,requestId);
            Tree resep;
            int j = 0;
            while(Mother(getElmtListResep(lR,j))!=requestId&&j<lengthListResep(lR)){
                j++;
            }
            int k;
            if(Mother(getElmtListResep(lR,j))==requestId){
                resep = getElmtListResep(lR,j);
                for(k=0;k<amountOfChildren(resep,requestId);k++){
                    int neededId = getNthChildOf(resep,requestId,k);
                    if(!isIdInQueue(*bufferInvertory,neededId)){
                        doable = false;
                    }
                }
                if(doable){
                    resep = getElmtListResep(lR,j);
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        removeIdFromQueue(bufferInvertory,neededId);
                    } 
                    enqueue(bufferInvertory,requestedMakanan);
                    printf("\n");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" selesai dibuat dan sudah masuk ke invertory!\n");
                } else {
                    printf("\nGagal membuat ");
                    printf(Nama(requestedMakanan).buffer);
                    printf(" karena kamu tidak memiliki bahan berikut:\n");
                    for(k=0;k<amountOfChildren(resep,requestId);k++){
                        int neededId = getNthChildOf(resep,requestId,k);
                        if(!isIdInQueue(*bufferInvertory,neededId)){
                            Makanan neededMakanan = getElmakanid(lM,neededId);
                            printf("%d ",i+1);
                            printf(Nama(neededMakanan).buffer);
                            printf("\n");
                        }
                    }
                }
            }
        }
    }while(opsi!=0);
}

void BUY(listMakanan lM, PQueue* bufferDelivery){
    listMakanan lOpsi = searchListMakananBasedOnAksi(lM,'B');
    printf("=======================\n");
    printf("=         BUY         =\n");
    printf("=======================\n");
    printf("List Bahan Makanan yang Bisa Dibeli:\n");
    int i;
    for(i=0;i<lOpsi.listmakanlen;i++){
        printf("    %d. ",i+1);
        printf(Nama(lOpsi.contents[i]).buffer);
        printf(" (");
        // printTime(lOpsi.contents[i].delivTime);
        if (lOpsi.contents[i].delivTime.DD>0)
        {
            printf(" %d hari ",lOpsi.contents[i].delivTime.DD);
        }
        if (lOpsi.contents[i].delivTime.HH>0)
        {
            printf(" %d jam ",lOpsi.contents[i].delivTime.HH);
        }
        if (lOpsi.contents[i].delivTime.MM>0)
        {
            printf(" %d menit ",lOpsi.contents[i].delivTime.MM);
        }
        printf(")");
        printf("\n");
    }
    printf("\nKirim 0 utuk exit.\n\n");
    int opsi=-1;
    while (opsi!=0)
    {
        startKata("",false,' ','\n');
        opsi =stoi(currentKata);
        if(opsi<0||opsi>lOpsi.listmakanlen){
            printf("Mainnya hebat!.");
        }
        else{
            enqueue(&*bufferDelivery,lOpsi.contents[opsi-1]);
            printf("berhasil membeli ");
            printf(lOpsi.contents[opsi-1].nama.buffer);
            printf("\n");
        }
    }
}

void DELIVERY(PQueue bufferDelivery){
    int i=0;
    int len=lengthPQueue(bufferDelivery);
    printf("List makanan di perjalanan\n");
    printf("(nama - waktu sisa pengantaran)\n");
    if (len==0)
    {
        printf("Tidak ada makanan yang sedang diantar\n");
    }
    else{
        while (i<len)
        {
            printf(bufferDelivery.queue[i].nama.buffer);
            printf(" - ");
            if (bufferDelivery.queue[i].delivTime.DD>0)
            {
                printf("%d hari ",bufferDelivery.queue[i].delivTime.DD);
            }
            if (bufferDelivery.queue[i].delivTime.HH>0)
            {
                printf("%d jam ",bufferDelivery.queue[i].delivTime.HH);
            }
            if (bufferDelivery.queue[i].delivTime.MM>0)
            {
                printf("%d menit ",bufferDelivery.queue[i].delivTime.MM);
            }
            printf("\n");
            i++;
        }
    }
}


// int main()
// {

//     // --- TESTING COMMAND CATALOG ---
//     // Makanan m;
//     // time exp, deliv;
//     // Kata nama;
//     // char aksi;
//     // int len, i;

//     // listMakanan lm;
//     // createListMakanan(&lm);

//     // createKata(&nama, "Ayam Goreng");
//     // aksi = 'F';
//     // createTime(&exp, 0, 0, 5);
//     // createTime(&deliv, 0, 0, 12);
//     // createMakanan(&m, 0, nama, exp, aksi, deliv);
//     // insertMakanan(&lm, m);

//     // createKata(&nama, "Bawang");
//     // aksi = 'C';
//     // createTime(&exp, 0, 0, 7);
//     // createTime(&deliv, 0, 0, 3);
//     // createMakanan(&m, 1, nama, exp, aksi, deliv);
//     // insertMakanan(&lm, m);

//     // catalog(lm);
//     // --- END TESTING COMMAND CATALOG ---

//     //     PQueue daftarInvertory;
//     //     createPQueue(&daftarInvertory, 7);
//     //     Makanan man;
//     //     time kadaluarsa;
//     //     createTime(&kadaluarsa, 0, 0, 1);
//     //     Kata nama;
//     //     createKata(&nama, "ASU GORENG");
//     //     createMakanan(&man, 1, nama, kadaluarsa, 'n', kadaluarsa);

//     //     enqueue(&daftarInvertory, man);

//     //     Makanan man1;
//     //     time kadaluarsa1;
//     //     createTime(&kadaluarsa1, 0, 0, 2);
//     //     Kata nama1;
//     //     createKata(&nama1, "ASU REBUS");
//     //     createMakanan(&man1, 4, nama1, kadaluarsa1, 'f', kadaluarsa1);

//     //     PQueue daftarNotif;
//     //     createPQueue(&daftarNotif, 7);

//     //     PQueue daftarDeliv;
//     //     createPQueue(&daftarDeliv, 7);

//     //     enqueue(&daftarDeliv, man);
//     //     enqueue(&daftarDeliv, man);
//     //     enqueue(&daftarDeliv, man1);

//     //     UPDATE_INVERTORY_DELIVERY(&daftarInvertory, &daftarDeliv, &daftarNotif);

//     //     INVERTORY(daftarInvertory);

//     //     UPDATE_INVERTORY_DELIVERY(&daftarInvertory, &daftarDeliv, &daftarNotif);

//     //     INVERTORY(daftarInvertory);

//     ListResep l;
//     createListResep(&l);

//     READ_RESEP("tes.txt", &l);
//     //printTree(getElmtListResep(l, 3));
//     // printf("%d",lengthListResep(l));
//     listMakanan listmakanan;
//     readMakananFile(&listmakanan, "Config/makanan.txt");
//     PQueue t;
//     createPQueue(&t,10);
//     int i;
//     for(i=0;i<listmakanan.listmakanlen;i++){
//         enqueue(&t,listmakanan.contents[i]);
//     }
//     MIX(listmakanan,l,&t);
//     FRY(listmakanan,l,&t);
//     CHOP(listmakanan,l,&t);
//     BOIL(listmakanan,l,&t);

// }