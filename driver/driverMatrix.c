#include "../ADT/Matrix/matrix.h"

int main(int argc, char const *argv[])
{
    Matrix m;
    Matrix map;
    readMatrixFile(&m,"../Config/map.txt");
    displayMatrix(m);
    map=matrixtoMap(m);
    displayMap(map);
    return 0;
}
