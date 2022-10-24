#include "simulator.c"

int main(int argc, char const *argv[])
{
    simulator sim;
    Matrix map;
    setNama(&sim);
    displayNama(sim);
    readMatrixFile(&map,"map.txt");
    map=matrixtoMap(map);
    displayMatrix(map);
    initiatePoint(map,&sim);
    printPoint(sim.currentPos);
    printf("kanan");
    moveKanan(&sim,&map);
    displayMatrix(map);
    printf("kiri");
    moveKiri(&sim,&map);
    displayMatrix(map);
    printf("bawah");
    moveBawah(&sim,&map);
    displayMatrix(map);
    printf("atas\n");
    moveAtas(&sim,&map);
    displayMatrix(map);
    printPoint(sim.currentPos);
    return 0;
}
