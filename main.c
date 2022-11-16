#include <stdio.h>
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/Utility/utility.h"
#include "ADT/Simulator/simulator.h"
#include "ADT/Matrix/matrix.h"
#include "ADT/Point/point.h"
// #include "ADT/List_Resep/listresep.h"
#include "ADT/List_Makanan/listmakanan.h"
#include "ADT/Stack/stack.h"
#include "COMMAND.c"
#include "ADT/Time/time.h"

int main()
{
    // Splash Screen - Image
    printf("\n                     .:@:@@@@@@:.\n                    @=   . .     @@\n                     @@@..        @\n                      @..      @@@@\n                     @:.*@@@@-  @\n                     @@@=    #@@@\n                     @       ...@@\n                     @#     :...@\n                      @    ....@\n                       *@@@@@@   @@@@\n                           #@@@:...@.@@\n                          #@     .@....@\n                            @ #@@    ...@\n      @@ @@@@@@@@-.#@@@@@@@@ @       ....@\n      .@@     .@#@@@@..@.  @+@        ...@-\n        @        ..@         @        ....@.\n         @@@@@@@@@@          #@@@@@@@@@@@@#\n");

    // Splash Screen - Title
    printf("\n   ___          _   _            __      ___ _   _      ___ _  _ __  __  ___  \n  / __|___  ___| |_(_)_ _  __ _  \\ \\    / (_) |_| |_   | _ ) \\| |  \\/  |/ _ \\ \n | (__/ _ \\/ _ \\ / / | ' \\/ _` |  \\ \\/\\/ /| |  _| ' \\  | _ \\ .` | |\\/| | (_) |\n  \\___\\___/\\___/_\\_\\_|_||_\\__, |   \\_/\\_/ |_|\\__|_||_| |___/_|\\_|_|  |_|\\___/ \n                          |___/                                               \n");
    boolean isRun = false;
    boolean valid;
    int countNotif;
    simulator dump;
    simulator sim;
    Matrix map;
    ListResep listresep;
    listMakanan listmakanan;
    Stack undoStack, stackSimState;
    PQueue o;
    createPQueue(&o, 3);
    // time gTime;

    startKata("", false, '\0', '\n');
    // printf("%s\n", currentKata.buffer);
    if (strcmp(currentKata.buffer, "START"))
    {
        isRun = true;
        createListResep(&listresep);
        createListMakanan(&listmakanan);
        readMatrixFile(&map, "Config/map.txt");
        READ_RESEP("Config/resep.txt", &listresep);
        readMakananFile(&listmakanan, "Config/makanan.txt");
        map = matrixtoMap(map);
        // createTime(&gTime, 0, 0, 0);
        createSim(&sim);
        initiatePoint(map, &sim);
        CreateEmpty(&undoStack);
        CreateEmpty(&stackSimState);
        printf("\nSELAMAT DATANG DI 'COOKING WITH BNMO'\n");
        printf("Masukkan nama: ");
        startKata("", false, '\0', '\n');
        setNama(&sim, currentKata);
        simulator x = copySim(sim);
        //Push(&undoStack, x);
        printf("\n");
    }

    while (isRun)
    {
        countNotif = 0;
        printf("BNMO di posisi: ");
        printPoint(sim.currentPos);
        printf("Waktu: ");
        printTime(sim.gtime);
        printf("\n");

        displayMapBasedOnCurrentPos(map, sim);
        printf("Enter Command: ");
        startKata("", false, ' ', '\n');
        // printf("%s\n",currentKata.buffer);
        printf("\n");
        if (strcmp(currentKata.buffer, "EXIT"))
        {
            isRun = false;
            printf("END");
        }
        else if (strcmp(currentKata.buffer, "MOVE"))
        {
            while (!IsEmptyStack(stackSimState))
            {
                Pop(&stackSimState, &dump);
            }
            advKata(' ', '\n');
            if (strcmp(currentKata.buffer, "WEST"))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                moveKiri(&sim, &map);
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else if (strcmp(currentKata.buffer, "EAST"))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                moveKanan(&sim, &map);
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else if (strcmp(currentKata.buffer, "NORTH"))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                moveAtas(&sim, &map);
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else if (strcmp(currentKata.buffer, "SOUTH"))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                moveBawah(&sim, &map);
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else
            {
                printf("Command tidak dikenal\n");
            }
        }
        else if (strcmp(currentKata.buffer, "INVENTORY"))
        {
            INVERTORY(sim.inventory);
        }
        else if (strcmp(currentKata.buffer, "DELIVERY"))
        {
            DELIVERY(sim.delivery);
        }
        else if (strcmp(currentKata.buffer, "BUY"))
        {
            if (isAdjacentTo(sim, 'T', map))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                while (!IsEmptyStack(stackSimState))
                {
                    Pop(&stackSimState, &dump);
                }
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                BUY(listmakanan, &(sim.delivery));
                nextMin(&sim.gtime);
            }
            else
            {
                printf("BNMO tidak berada di area telepon!\n");
            }
        }
        else if (strcmp(currentKata.buffer, "MIX"))
        {
            if (isAdjacentTo(sim, 'M', map))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                while (!IsEmptyStack(stackSimState))
                {
                    Pop(&stackSimState, &dump);
                }
                MIX(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else
            {
                printf("BNMO tidak berada di area mix!\n");
            }
        }
        else if (strcmp(currentKata.buffer, "CHOP"))
        {
            if (isAdjacentTo(sim, 'C', map))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                while (!IsEmptyStack(stackSimState))
                {
                    Pop(&stackSimState, &dump);
                }
                CHOP(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else
            {
                printf("BNMO tidak berada di area chop!\n");
            }
        }
        else if (strcmp(currentKata.buffer, "FRY"))
        {
            if (isAdjacentTo(sim, 'F', map))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                while (!IsEmptyStack(stackSimState))
                {
                    Pop(&stackSimState, &dump);
                }
                FRY(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else
            {
                printf("BNMO tidak berada di area fry!\n");
            }
        }
        else if (strcmp(currentKata.buffer, "BOIL"))
        {
            if (isAdjacentTo(sim, 'B', map))
            {
                simulator x = copySim(sim);
                Push(&undoStack, x);
                while (!IsEmptyStack(stackSimState))
                {
                    Pop(&stackSimState, &dump);
                }
                BOIL(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
            else
            {
                printf("BNMO tidak berada di area boil!\n");
            }
        }
        else if (strcmp(currentKata.buffer, "COOKBOOK"))
        {
            COOKBOOK(listresep, listmakanan);
        }
        else if (strcmp(currentKata.buffer, "UNDO"))
        {
            undo(&undoStack, &stackSimState, &sim, &valid);
            if (!valid)
            {
                //sim = InfoTop(undoStack);
            }
            //UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
        }
        else if (strcmp(currentKata.buffer, "REDO"))
        {
            redo(&undoStack, &stackSimState, &sim, &valid);
            //UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
        }
        else if (strcmp(currentKata.buffer, "CATALOG"))
        {
            catalog(listmakanan);
            nextMin(&sim.gtime);
        }
        else if (strcmp(currentKata.buffer, "WAIT"))
        {
            simulator x = copySim(sim);
            Push(&undoStack, x);
            advKata(' ', '\n');
            int jam = stoi(currentKata);
            advKata(' ', '\n');
            int mnt = stoi(currentKata);

            wait(&sim.gtime, jam, mnt);

            int i;
            for (i = 0; i < jam * 60 + mnt; i++)
            {
                if (countNotif == 0)
                {
                    printf("Notifikasi: \n");
                    countNotif += 1;
                }
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
            }
        }
        else
        {
            printf("Command tidak dikenal\n");
        }
    }

    return 0;
}