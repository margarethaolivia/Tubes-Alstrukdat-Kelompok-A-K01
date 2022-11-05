#include <stdio.h>
#include "ADT/Mesin_Kata/mesinkata.h"
#include "ADT/Utility/utility.h"
#include "ADT/Simulator/simulator.h"
#include "ADT/Matrix/matrix.h"
#include "ADT/Point/point.h"
#include "ADT/List_Resep/listresep.h"
#include "ADT/List_Makanan/listmakanan.h"


int main()
{
    // Splash Screen - Image
    printf("\n                     .:@:@@@@@@:.\n                    @=   . .     @@\n                     @@@..        @\n                      @..      @@@@\n                     @:.*@@@@-  @\n                     @@@=    #@@@\n                     @       ...@@\n                     @#     :...@\n                      @    ....@\n                       *@@@@@@   @@@@\n                           #@@@:...@.@@\n                          #@     .@....@\n                            @ #@@    ...@\n      @@ @@@@@@@@-.#@@@@@@@@ @       ....@\n      .@@     .@#@@@@..@.  @+@        ...@-\n        @        ..@         @        ....@.\n         @@@@@@@@@@          #@@@@@@@@@@@@#\n");

    // Splash Screen - Title
    printf("\n   ___          _   _            __      ___ _   _      ___ _  _ __  __  ___  \n  / __|___  ___| |_(_)_ _  __ _  \\ \\    / (_) |_| |_   | _ ) \\| |  \\/  |/ _ \\ \n | (__/ _ \\/ _ \\ / / | ' \\/ _` |  \\ \\/\\/ /| |  _| ' \\  | _ \\ .` | |\\/| | (_) |\n  \\___\\___/\\___/_\\_\\_|_||_\\__, |   \\_/\\_/ |_|\\__|_||_| |___/_|\\_|_|  |_|\\___/ \n                          |___/                                               \n");
    boolean isRun=false;
    simulator sim;
    Matrix map;
    ListResep listresep;
    listMakanan listmakanan;
    
    
    startKata("",false,'\0','\n');
    printf("%s\n",currentKata.buffer);
    if (strcmp(currentKata.buffer,"START"))
    {
        isRun=true;
        readMatrixFile(&map,"Config/map.txt");
        map=matrixtoMap(map);
        createSim(&sim);
        initiatePoint(map,&sim);
        createListResep(&listresep);
        createListMakanan(&listmakanan);
        printf("selamat datang di bnmo\n");
        printf("masukkan nama:\n");
        startKata("",false,'\0','\n');
        setNama(&sim,currentKata);
    }
    
    while (isRun)
    {
        printf("BNMO di posisi: ");
        printPoint(sim.currentPos);
        printf("\n");
        displayMapBasedOnCurrentPos(map,sim);
        printf("Enter command: \n");
        advKata('\0','\n');
        // printf("%s\n",currentKata.buffer);
        // printf("a\n");
        if (strcmp(currentKata.buffer,"EXIT"))
        {
            isRun=false;
            printf("END");
        }
        else if (strcmp(currentKata.buffer,"MOVE WEST"))
        {
            moveKiri(&sim,&map);
        }
        else if(strcmp(currentKata.buffer,"MOVE EAST")){
            moveKanan(&sim,&map);
        }
        else if(strcmp(currentKata.buffer,"MOVE NORTH")){
            moveAtas(&sim,&map);
        }
        else if(strcmp(currentKata.buffer,"MOVE SOUTH")){
            moveBawah(&sim,&map);
        }
        else if(strcmp(currentKata.buffer,"INVENTORY")){
            
        }
        
    }
    
    return 0;
}