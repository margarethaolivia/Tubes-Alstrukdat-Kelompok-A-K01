#include <stdio.h>
#include "mesinkata.h"
#include "utility.h"
#include "simulator.h"
#include "matrix.h"


int main()
{
    // Splash Screen - Image
    printf("\n                     .:@:@@@@@@:.\n                    @=   . .     @@\n                     @@@..        @\n                      @..      @@@@\n                     @:.*@@@@-  @\n                     @@@=    #@@@\n                     @       ...@@\n                     @#     :...@\n                      @    ....@\n                       *@@@@@@   @@@@\n                           #@@@:...@.@@\n                          #@     .@....@\n                            @ #@@    ...@\n      @@ @@@@@@@@-.#@@@@@@@@ @       ....@\n      .@@     .@#@@@@..@.  @+@        ...@-\n        @        ..@         @        ....@.\n         @@@@@@@@@@          #@@@@@@@@@@@@#\n");

    // Splash Screen - Title
    printf("\n   ___          _   _            __      ___ _   _      ___ _  _ __  __  ___  \n  / __|___  ___| |_(_)_ _  __ _  \\ \\    / (_) |_| |_   | _ ) \\| |  \\/  |/ _ \\ \n | (__/ _ \\/ _ \\ / / | ' \\/ _` |  \\ \\/\\/ /| |  _| ' \\  | _ \\ .` | |\\/| | (_) |\n  \\___\\___/\\___/_\\_\\_|_||_\\__, |   \\_/\\_/ |_|\\__|_||_| |___/_|\\_|_|  |_|\\___/ \n                          |___/                                               \n");
    boolean isRun=false;
    simulator sim;
    Matrix map;
    
    startKata("",false);
    if (strcmp(currentKata.buffer,"START"))
    {
        isRun=true;
        readMatrixFile(&map,"map.txt");
        map=matrixtoMap(map);
        createSim(&sim);
        initiatePoint(map,&sim);
        printf("selamat datang di bnmo\n");
        printf("masukkan nama:\n");
        startKata("",false);
        setNama(&sim,currentKata);
    }
    
    while (isRun)
    {
        displayNama(sim);
        startKata("",false);
        printf("a\n");
        if (strcmp(currentKata.buffer,"EXIT"))
        {
            isRun=false;
        }
    }
    
    return 0;
}