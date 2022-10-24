#include <stdio.h>
#include "time.h"
#include "makanan.h"
#include "boolean.h"

/* *** Konstruktor membentuk Makanan *** */
void createMakanan(Makanan *m, int id, Kata nama, time expired, Kata aksi, time delivTime)
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
    printf("%s -", Nama(m));
    printTimeHJM(Expired(m));
    printf(" - %s -", Aksi(m));
    printTimeHJM(DelivTime(m));
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
        printf(" %d jam", day(t));
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