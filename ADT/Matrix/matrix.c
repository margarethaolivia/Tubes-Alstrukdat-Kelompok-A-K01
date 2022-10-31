
#include <stdio.h>
#include "matrix.h"
// #include "mesinkarakter.h"
#include "../Mesin_Kata/mesinkata.h"


void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m)=nRows;
    COL_EFF(*m)=nCols;
}

boolean isMatrixIdxValid(int i, int j)
{
    return ((i<ROW_CAP) && (j<COL_CAP) && (i>=0) && (j>=0));
}

IdxType getLastIdxRow(Matrix m)
{
    return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m)
{
    return COL_EFF(m)-1;
}

boolean isIdxEffMatrix(Matrix m, IdxType i, IdxType j)
{
    return ((i<ROW_EFF(m)) && (j<COL_EFF(m)) && (i>=0) && (j>=0));
}

void copyMatrix(Matrix mIn, Matrix *mOut)
{
    *mOut = mIn;
}

void readMatrix(Matrix *m, int nRow, int nCol)
{
    int i=0;
    int j=0;
    createMatrix(nRow,nCol,m);
    while (i<nRow)
    {
        j=0;
        while (j<nCol)
        {
            scanf("%c",&ELMT(*m,i,j));
            j++;
        }
        i++;
    }
    
}

void displayMatrix(Matrix m)
{
    int i=0;
    int j=0;
    while (i<ROW_EFF(m))
    {
        j=0;
        while (j<COL_EFF(m))
        {
            printf("%c",ELMT(m,i,j));
            if ((j==COL_EFF(m)-1))
            {
                /*if (i!=ROW_EFF(m)-1)
                {
                    printf("\n");
                }*/
                printf("\n");
            }
            else{
                printf(" ");
            }
            j++;
        }
        i++;
    }
}


boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    int i=0;
    int j=0;
    boolean eq=true;
    if ((getLastIdxRow(m1)!=getLastIdxRow(m2)) || (getLastIdxCol(m1)!=getLastIdxCol(m1))){
        eq=false;
    }
    else{
        while (i<ROW_EFF(m1) && (eq==true))
        {
            j=0;
            while (j<COL_EFF(m1))
            {
                if (ELMT(m1,i,j)!=ELMT(m2,i,j))
                {
                    eq=false;
                }
                
                j++;
            }
            i++;
        }
    }
    return eq;
}



boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return (ROW_EFF(m1)==ROW_EFF(m2) && COL_EFF(m1)==COL_EFF(m2));
}

int countElmt(Matrix m)
{
    return ROW_EFF(m)*COL_EFF(m);
}

boolean isSquare(Matrix m)
{
    return ROW_EFF(m)==COL_EFF(m);
}


void displayMap(Matrix m){
    int i=0;
    int j=0;
    while (i<ROW_EFF(m))
    {
        j=0;
        while (j<COL_EFF(m))
        {
            printf("%c",ELMT(m,i,j));
            if ((j==COL_EFF(m)-1))
            {
                /*if (i!=ROW_EFF(m)-1)
                {
                    printf("\n");
                }*/
                printf("\n");
            }
            // else
            // {
            //     printf(" ");
            // }
            
            j++;
        }
        i++;
    }
}

Matrix matrixtoMap(Matrix m){
    Matrix map;
    createMatrix(ROW_EFF(m)+2,COL_EFF(m)+2,&map);
    int i=0;
    int j=0;
    while (i<ROW_EFF(map))
    {
        j=0;
        while (j<COL_EFF(map))
        {
            if (i==0 || i==ROW_EFF(map)-1 || j==0 || j==COL_EFF(map)-1)
            {
                ELMT(map,i,j)='*';
            }
            else{
                if (ELMT(m,i-1,j-1)=='#')
                {
                    ELMT(map,i,j)=' ';
                }
                else{
                    ELMT(map,i,j)=ELMT(m,i-1,j-1);
                }
            }
            j++;
        }
        i++;
    }
    return map;
}
void readMatrixFile(Matrix *m, char* path){
    int i=0;
    int j=0;
    startKata(path,true,' ','\n');
    int k=0;
    int row=0;
    while (k<currentKata.length)
    {
        row=row*10+ currentKata.buffer[k]%48;
        k++;
    }
    
    advKata();
    k=0;
    int col=0;
    while (k<currentKata.length)
    {
        col=col*10+ currentKata.buffer[k]%48;
        k++;
    }
    ADV();
    createMatrix(row,col,m);
    while (i<row)
    {
        j=0;
        while (j<col)
        {
            if (CC!='\n' && CC!='\0')
            {
                ELMT(*m,i,j)=CC;
            }
            
            
            ADV();
            j++;
        }
        ADV();
        i++;
    }
    
}
// void moveSim(simulator sim,Matrix map,char command){
    
// }

// boolean adjacentCheck(simulator sim, Matrix map,char thing){
//     boolean isadjacent=false;
//     int i=-1;
//     int j=-1;
//     char x;
//     while (i<2)
//     {
//         j=0;
//         while (j<2)
//         {
//             x=ELMT(map,sim.currentPos.y+i,sim.currentPos.x+j);
//             if (x==thing)
//             {
//                 isadjacent=true;
//             }
            
//             j++;
//         }
        
//         i++;
//     }
//     return isadjacent;
// }

// boolean checkWASD(simulator sim, Matrix map,char direction){
//     boolean isadjacent=false;
//     currentPosX=sim.currentPos.x;
//     currentPosY=sim.currentPos.y;
//     if (direction=='E')
//     {
//         char x=ELMT(map,currentPosY,currentPosX+1);
//         if (x=='B'||x=='C'||x=='F'||x=='T'||x=='M'||x=='X'||x=='*')
//         {
//             isadjacent=true;
//         }
        
//     }
//     else if (direction=='S')
//     {
//         char x=ELMT(map,currentPosY+1,currentPosX);
//         if (x=='B'||x=='C'||x=='F'||x=='T'||x=='M'||x=='X'||x=='*')
//         {
//             isadjacent=true;
//         }
        
//     }
//     else if (direction=='W')
//     {
//         char x=ELMT(map,currentPosY,currentPosX-1);
//         if (x=='B'||x=='C'||x=='F'||x=='T'||x=='M'||x=='X'||x=='*')
//         {
//             isadjacent=true;
//         }
        
//     }
//     else if (direction=='N')
//     {
//         char x=ELMT(map,currentPosY-1,currentPosX);
//         if (x=='B'||x=='C'||x=='F'||x=='T'||x=='M'||x=='X'||x=='*')
//         {
//             isadjacent=true;
//         }
        
//     }
//     return isadjacent;
// }