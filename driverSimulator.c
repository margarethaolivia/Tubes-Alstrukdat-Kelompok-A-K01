#include "simulator.c"

int main(int argc, char const *argv[])
{
    simulator sim;
    Matrix map;
    setNama(&sim);
    displayNama(sim);
    initiatePoint(map,sim);
    return 0;
}
