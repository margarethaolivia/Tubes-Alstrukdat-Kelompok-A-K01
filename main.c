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
        Push(&undoStack, x);
        printf("\n");
    }

    while (isRun)
    {
        // printf("Notifikasi: \n");
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
            advKata(' ', '\n');
            if (strcmp(currentKata.buffer, "WEST"))
            {
                moveKiri(&sim, &map);
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
            }
            else if (strcmp(currentKata.buffer, "EAST"))
            {
                moveKanan(&sim, &map);
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
            }
            else if (strcmp(currentKata.buffer, "NORTH"))
            {
                moveAtas(&sim, &map);
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
            }
            else if (strcmp(currentKata.buffer, "SOUTH"))
            {
                moveBawah(&sim, &map);
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
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
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                BUY(listmakanan, &(sim.delivery));
                nextMin(&sim.gtime);
                simulator x = copySim(sim);
                Push(&undoStack, x);
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
                MIX(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
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
                CHOP(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
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
                FRY(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
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
                BOIL(listmakanan, listresep, &(sim.inventory));
                nextMin(&sim.gtime);
                UPDATE_INVERTORY_DELIVERY(&(sim.inventory), &(sim.delivery), &o);
                simulator x = copySim(sim);
                Push(&undoStack, x);
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
            if (valid)
            {
                sim = InfoTop(undoStack);
                // prevMin(&sim.gtime);
            }
        }
        else if (strcmp(currentKata.buffer, "REDO"))
        {
            redo(&undoStack, &stackSimState, &sim, &valid);
            if (valid)
            {
                // nextMin(&sim.gtime);
            }
        }
        else if (strcmp(currentKata.buffer, "CATALOG"))
        {
            catalog(listmakanan);
            nextMin(&sim.gtime);
        }
        else if (strcmp(currentKata.buffer, "WAIT"))
        {
            advKata(' ', '\n');
            int jam = stoi(currentKata);
            advKata(' ', '\n');
            int mnt = stoi(currentKata);

            wait(&sim.gtime, jam, mnt);
            simulator x = copySim(sim);
            Push(&undoStack, x);

            int i;
            for (i = 0; i < jam * 60 + mnt; i++)
            {
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