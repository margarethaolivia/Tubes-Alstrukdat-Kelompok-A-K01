#include <stdio.h>
#include "../Time/time.h"
#include "makanan.h"
#include "../Boolean/boolean.h"

/* *** Konstruktor membentuk Makanan *** */
void createMakanan(Makanan *m, int id, Kata nama, time expired, char aksi, time delivTime)
{
    Id(*m) = id;
    Nama(*m) = nama;
    Expired(*m) = expired;
    Aksi(*m) = aksi;
    DelivTime(*m) = delivTime;
}
// membentuk sebuah Makanan dari komponen-komponennya

/* *** I/O Makanan *** */

// membaca komponen makanan
void readMakanan(Makanan *m)
{
}

// menuliskan makanan ke layar dengan format "nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time"
void printMakanan(Makanan m)
{
    // printNama(m);
    printf("%s ", Nama(m));
    printf("-");
    printTimeHJM(Expired(m));
    printf(" - ");
    printAksi(Aksi(m));
    printf(" -");
    printTimeHJM(DelivTime(m));
}

// mencetak nama makanan
// void printNama(Makanan m)
// {
//     int i;
//     for (i = 0; i < Nama(m).length; i++)
//     {
//         printf("%c", Nama(m).buffer[i]);
//     }
// }

void printAksi(char c)
{
    if (c == 'M')
    {
        printf("MIX");
    }
    else if (c == 'C')
    {
        printf("CHOP");
    }
    else if (c == 'F')
    {
        printf("FRY");
    }
    else if (c == 'B')
    {
        printf("BUY");
    }
}

// mencetak waktu dengan format .. hari .. jam .. menit
void printTimeHJM(time t)
{
    if (day(t) != 0)
    {
        printf(" %d hari", day(t));
    }

    if (hour(t) != 0)
    {
        printf(" %d jam", hour(t));
    }

    if (minute(t) != 0)
    {
        printf(" %d menit", minute(t));
    }

    if (day(t) == 0 && hour(t) == 0 && minute(t) == 0)
    {
        printf(" 0");
    }
}