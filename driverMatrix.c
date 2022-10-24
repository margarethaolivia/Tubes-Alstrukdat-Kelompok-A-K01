#include "matrix.c"

int main(int argc, char const *argv[])
{
    Matrix m;
    Matrix map;
    readMatrix(&m,10,10);
    map=matrixtoMap(m);
    displayMap(map);
    return 0;
}
