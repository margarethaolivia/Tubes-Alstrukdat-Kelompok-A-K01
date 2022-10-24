
#include <stdio.h>
#include "matrix.h"

Matrix kofaktor(Matrix m, int p, int q);
float AvgRow(Matrix M, IdxType i);
float AvgCol(Matrix M, IdxType j);
void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min);
int CountNumRow(Matrix M, IdxType i, ElType X);
void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min);
int CountNumCol(Matrix M, IdxType j, ElType X);
void RotateMat(Matrix *m);
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROW_EFF(*m)=nRows;
    COL_EFF(*m)=nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
{
    return ((i<ROW_CAP) && (j<COL_CAP) && (i>=0) && (j>=0));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return ((i<ROW_EFF(m)) && (j<COL_EFF(m)) && (i>=0) && (j>=0));
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
/* Melakukan assignment mOut <- mIn */
{
    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
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
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
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


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
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
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
{
    return (ROW_EFF(m1)==ROW_EFF(m2) && COL_EFF(m1)==COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return ROW_EFF(m)*COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
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