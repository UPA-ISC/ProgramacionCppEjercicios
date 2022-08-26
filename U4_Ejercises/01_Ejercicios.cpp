#include <stdio.h>
#include <stdlib.h>
#include "ArrayLib.h"

//using namespace std;

int main(int argc, char **args){
    
    int row = 2;
    int col = 2;
    float **mat = crearMatriz(row,col);
    float **nMat = crearMatriz(row,col);
    mat = datosMatriz(mat, row,col);

    mostrarMatriz(mat, row,col);

    nMat = multMatriz(mat, row, col, 2);
    mostrarMatriz(nMat, row,col);
    eliminarMatriz(mat, row);
    eliminarMatriz(nMat, row);

    return 0;
}