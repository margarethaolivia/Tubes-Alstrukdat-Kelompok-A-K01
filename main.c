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
    Stack undoStack;
    
    startKata("",false,'\0','\n');
    printf("%s\n",currentKata.buffer);
    if (strcmp(currentKata.buffer,"START"))
    {
        isRun=true;
        readMatrixFile(&map,"Config/map.txt");
        READ_RESEP("Config/resep.txt",&listresep);
        map=matrixtoMap(map);
        createSim(&sim);
        initiatePoint(map,&sim);
        createListResep(&listresep);
        createListMakanan(&listmakanan);
        CreateEmpty(&undoStack);
        printf("selamat datang di bnmo\n");
        printf("masukkan nama:\n");
        startKata("",false,'\0','\n');
        setNama(&sim,currentKata);
        Push(&undoStack,sim);
        printTree(getElmtListResep(listresep, 1));
    }
    
    while (isRun)
    {
        printf("BNMO di posisi: ");
        printPoint(sim.currentPos);
        printf("\n");
        displayMapBasedOnCurrentPos(map,sim);
        printf("Enter command: \n");
        startKata("",false,'\0','\n');
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
            Push(&undoStack,sim);
        }
        else if(strcmp(currentKata.buffer,"MOVE EAST")){
            moveKanan(&sim,&map);
            Push(&undoStack,sim);
        }
        else if(strcmp(currentKata.buffer,"MOVE NORTH")){
            moveAtas(&sim,&map);
            Push(&undoStack,sim);
        }
        else if(strcmp(currentKata.buffer,"MOVE SOUTH")){
            moveBawah(&sim,&map);
            Push(&undoStack,sim);
        }
        else if(strcmp(currentKata.buffer,"INVENTORY")){
            
        }
        else if (strcmp(currentKata.buffer,"UNDO"))
        {
            if (IsEmptyStack(undoStack))
            {
                printf("undah mentok\n");
            }
            else{
                Pop(&undoStack,&sim);
                printf("pop\n");
                printPoint(sim.currentPos);
            }
            
        }
        
    }
    
    return 0;
}