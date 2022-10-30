#include "../matrix.c"

int main(int argc, char const *argv[])
{
    Matrix m;
    Matrix map;
    readMatrixFile(&m,"map.txt");
    displayMatrix(m);
    map=matrixtoMap(m);
    displayMap(map);
    return 0;
}
