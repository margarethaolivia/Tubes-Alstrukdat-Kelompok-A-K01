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
    int banyak_makanan=0;;
    startKata(path,true,' ','\n');
    while (i<currentKata.length) //pembacaan jumlah banyaknya makanan 
    {
        banyak_makanan=banyak_makanan*10+ currentKata.buffer[i]%48;
        i++;
    }
    i=0;
    int j=0;
    advKata();
    while (i<banyak_makanan) //proses pembacaan makanan sebanyak n (banyaknya makanan) kali
    {
        //mencari id dari makanan
        m.id=0;
        while (j<currentKata.length)
        {
            m.id=m.id*10+currentKata.buffer[j]%48;
            j++;
        }
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
            hari=hari*10+currentKata%48;
            j++
        }
        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            jam=jam*10+currentKata%48;
            j++;
        }
        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            menit=menit*10+currentKata%48;
            j++;
        }
        time t;
        createTime(&t,hari,jam,menit);
        m.expired=t;
        advKata();
        
        //mencari waktu pengiriman dari makanan
        int hari2,jam2,menit2;
        hari2 = 0;
        jam2= 0;
        menit2 = 0;
        j=0;
        while(j<currentKata.length){
            hari2=hari2*10+currentKata%48;
            j++
        }
        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            jam2=jam2*10+currentKata%48;
            j++;
        }
        advKata(' ','\n');
        j=0;
        while(j<currentKata.length){
            menit2=menit2*10+currentKata%48;
            j++;
        }
        createTime(&t2,hari2,jam2,menit2);
        m.delivTime=t2;
        advKata();

        //mencari aksi yang dapat dilakukan pada makanana
        m.aksi = currentKata;
        advKata('\0','\n');

        *lm->contents[i] = m;

        i++;
    }   
}

void displayListMakanan(listMakanan l){
    int i = 0;
    while(i < lengthLlistMakanan(l)){
        printf("%d. ",i+1);
        printMakanan(MAKANAN(l,i));
        printf("\n");
    }
}