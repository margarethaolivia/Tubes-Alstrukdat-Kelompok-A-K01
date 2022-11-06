#include <stdio.h>
#include <math.h>
#include "../Boolean/boolean.h"
#include "listmakanan.h"
#include "../Time/time.h"

void createListMakanan(listMakanan *l)
{
    for (int x = 0 ; x <CAPACITYSTATIC ; x++)
    {
        Id(MAKANAN(*l,x)) = MARKSTATIC;
    }
}

void insertMakanan(listMakanan *l, Makanan m)
{
    boolean found = false;
    int x = 0;

    while (x < lengthLlistMakanan(*l) && found == false )
    {
        if (Id(MAKANAN(*l,x)) == Id(m))
        {
            MAKANAN(*l,x) = m;
            found = true;
        }
        x += 1;
    }
    if (!found)
    {
        MAKANAN(*l, lengthLlistMakanan(*l)) = m;
    }
}

int lengthLlistMakanan(listMakanan l)
{
    int x = 0;
    while(Id(MAKANAN(l,x)) != MARKSTATIC && x < CAPACITYSTATIC)
    {
        x+=1;
    }
    return x;
}

void readMakananFile(listMakanan *lm, char* path)
{
    Makanan m;
    int i=0;
    int banyak_makanan=0;
    startKata(path,true,' ','\n');
    while (i<currentKata.length) //pembacaan jumlah banyaknya makanan 
    {
        banyak_makanan=banyak_makanan*10+ currentKata.buffer[i]%48;
        i++;
    }
    lm->listmakanlen=banyak_makanan;
    i=0;
    int j=0;
    int idx=0;;
    while (i<banyak_makanan) //proses pembacaan makanan sebanyak n (banyaknya makanan) kali
    {
        advKata(' ','\n');
        //mencari id dari makanan
        idx=0;
        j=0;
        while (j<currentKata.length)
        {
            idx=idx*10+currentKata.buffer[j]%48;
            j++;
        }
        m.id=idx;
        advKata('\0','\n');
        
        //mencari nama dari makanan
        m.nama = currentKata;
        advKata(' ','\n');


        //mencari waktu kadaluarsa dari makanan
        int hari,jam,menit;
        hari = 0;
        jam = 0;
        menit = 0;
        j=0;
        while(j<currentKata.length){
            hari=hari*10+currentKata.buffer[j]%48;
            j++;
        }
        // printf("hariexp S%s D%d\n",currentKata.buffer,hari);

        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            jam=jam*10+currentKata.buffer[j]%48;
            j++;
        }
        // printf("jamexp S%s D%d\n",currentKata.buffer,jam);
        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            menit=menit*10+currentKata.buffer[j]%48;
            j++;
        }
        // printf("menitexp S%s D%d\n",currentKata.buffer,menit);
        // printf("exp: %d %d %d\n",hari,menit,jam);
        time t;
        createTime(&t,hari,jam,menit);
        m.expired=t;
        advKata(' ','\n');
        
        //mencari waktu pengiriman dari makanan
        int hari2,jam2,menit2;
        hari2 = 0;
        jam2= 0;
        menit2 = 0;
        j=0;
        while(j<currentKata.length){
            hari2=hari2*10+currentKata.buffer[j]%48;
            j++;
        }
        // printf("harideliv S%s D%d\n",currentKata.buffer,hari2);

        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            jam2=jam2*10+currentKata.buffer[j]%48;
            j++;
        }
        // printf("jamdeliv S%s D%d\n",currentKata.buffer,jam2);
        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            menit2=menit2*10+currentKata.buffer[j]%48;
            j++;
        }
        // printf("menitdeliv S%s D%d\n",currentKata.buffer,menit2);
        // printf("DELIV: %d %d %d\n",hari2,menit2,jam2);
        time t2;
        createTime(&t2,hari2,jam2,menit2);
        m.delivTime=t2;
        advKata('\0','\n');

        //mencari aksi yang dapat dilakukan pada makanana
        m.aksi = currentKata.buffer[0];
        // advKata('\0','\n');

        lm->contents[i] = m;
        i++;
    }   
}

void displayListMakanan(listMakanan l){
    int i = 0;
    int len=l.listmakanlen;
    // printf("%d\n",len);
    while(i < len){
        printf("%d. ",i+1);
        printMakanan(MAKANAN(l,i));
        printf("\n");
        i++;
    }
}

boolean searchListMakananBasedOnID(listMakanan lm,int idx){
    boolean isFound=false;
    int i=0;
    int len=lm.listmakanlen;
    printf("%d\n",len);
    while (i<len)
    {
        if (lm.contents[i].id==idx)
        {
            isFound=true;
        }
        printf("%s\n",lm.contents[i].nama.buffer);
        i++;
    }
    return isFound;
}