#include <stdio.h>
#include "mesinkata.h"
#include "utility.h"
#include "simulator.h"
#include "matrix.h"
#include "point.h"


int main()
{
    // Splash Screen - Image
    printf("\n                     .:@:@@@@@@:.\n                    @=   . .     @@\n                     @@@..        @\n                      @..      @@@@\n                     @:.*@@@@-  @\n                     @@@=    #@@@\n                     @       ...@@\n                     @#     :...@\n                      @    ....@\n                       *@@@@@@   @@@@\n                           #@@@:...@.@@\n                          #@     .@....@\n                            @ #@@    ...@\n      @@ @@@@@@@@-.#@@@@@@@@ @       ....@\n      .@@     .@#@@@@..@.  @+@        ...@-\n        @        ..@         @        ....@.\n         @@@@@@@@@@          #@@@@@@@@@@@@#\n");

    // Splash Screen - Title
    printf("\n   ___          _   _            __      ___ _   _      ___ _  _ __  __  ___  \n  / __|___  ___| |_(_)_ _  __ _  \\ \\    / (_) |_| |_   | _ ) \\| |  \\/  |/ _ \\ \n | (__/ _ \\/ _ \\ / / | ' \\/ _` |  \\ \\/\\/ /| |  _| ' \\  | _ \\ .` | |\\/| | (_) |\n  \\___\\___/\\___/_\\_\\_|_||_\\__, |   \\_/\\_/ |_|\\__|_||_| |___/_|\\_|_|  |_|\\___/ \n                          |___/                                               \n");
    boolean isRun=false;
    simulator sim;
    Matrix map;
    
    startKata("",false,' ','\n');
    printf("%s\n",currentKata.buffer);
    if (strcmp(currentKata.buffer,"START"))
    {
        isRun=true;
        readMatrixFile(&map,"map.txt");
        map=matrixtoMap(map);
        createSim(&sim);
        initiatePoint(map,&sim);
        printf("selamat datang di bnmo\n");
        printf("masukkan nama:\n");
        startKata("",false,' ','\n');
        setNama(&sim,currentKata);
    }
    
    while (isRun)
    {
        printf("BNMO di posisi: ");
        printPoint(sim.currentPos);
        printf("\n");
        displayMatrix(map);
        printf("Enter command: \n");
        startKata("",false,' ','\n');
        printf("%s\n",currentKata.buffer);
        // printf("a\n");
        if (strcmp(currentKata.buffer,"EXIT"))
        {
            isRun=false;
            printf("END");
        }
        else if (strcmp(currentKata.buffer,"MOVE"))
        {
            advKata();
            printf("%s\n",currentKata.buffer);
            if (strcmp(currentKata.buffer,"EAST"))
            {
                moveKiri(&sim,&map);
            }
            else if (strcmp(currentKata.buffer,"WEST"))
            {
                moveKanan(&sim,&map);
            }
            else if (strcmp(currentKata.buffer,"NORTH"))
            {
                moveAtas(&sim,&map);
            }
            else if (strcmp(currentKata.buffer,"SOUTH"))
            {
                moveBawah(&sim,&map);
            }
        }
        
    }
    
    return 0;
}