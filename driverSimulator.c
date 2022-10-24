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
    return 0;
}
