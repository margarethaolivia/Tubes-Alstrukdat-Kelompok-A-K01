
#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"
// #include "simulator.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; 
typedef char ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; 
   int colEff; 
} Matrix;



void createMatrix(int nRows, int nCols, Matrix *m);


/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]


boolean isMatrixIdxValid(int i, int j);



IdxType getLastIdxRow(Matrix m);

IdxType getLastIdxCol(Matrix m);
boolean isIdxEff(Matrix m, IdxType i, IdxType j);


void copyMatrix(Matrix mIn, Matrix *mOut);

void readMatrix(Matrix *m, int nRow, int nCol);
void displayMatrix(Matrix m);



boolean isMatrixEqual(Matrix m1, Matrix m2);

boolean isMatrixSizeEqual(Matrix m1, Matrix m2);

int countElmt(Matrix m);

boolean isSquare(Matrix m);
boolean isSymmetric(Matrix m);

void displayMap(Matrix m);

Matrix matrixtoMap(Matrix m);
// void moveSim(simulator sim, Matrix map,char command);
// boolean adjacentCheck(simulator sim, Matrix map,char thing);
// boolean checkWASD(simulator sim, Matrix map,char direction);
#endif