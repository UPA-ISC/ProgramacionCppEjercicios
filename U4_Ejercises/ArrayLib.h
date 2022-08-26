#ifndef __ARRAYLIB
#define __ARRAYLIB

#include <stdio.h>
//Para el uso de new y delete
#include <stdlib.h>
#include <iostream>
using namespace std;

float **crearMatriz(int row, int col){
    float **matriz;
    matriz = new float*[row];
    for (int renglon = 0; renglon <row; renglon++){
        matriz[renglon] = new float[col];
    }
    
    
    return matriz;
}
float **datosMatriz(float **matriz,int row, int col ){
    for (int renglon =0; renglon<row; renglon++){
        for (int columna =0; columna<col; columna++){
            cout << "[" << renglon <<"]["<< columna << "]: ";
            cin >> *(*(matriz+renglon)+columna);
        }
    }
    return matriz;
}

void **mostrarMatriz(float **matriz, int row, int col){
   for (int renglon = 0; renglon<row; renglon++){
        for(int columna = 0; columna< col; columna++){
            cout << *(*(matriz+renglon)+columna) << "\t";
        }
        cout << "\n";
    }
}

void eliminarMatriz(float **matriz, int row){
    for(int renglon =0; renglon < row; renglon++){
        delete[] matriz[renglon];
    }
    delete[] matriz;
}

float **multMatriz(float **matriz,int row, int col, float escala){
    float **nMatriz = crearMatriz(row,col);
    for (int renglon = 0; renglon<row; renglon++){
        for(int columna = 0; columna< col; columna++){
            *(*(nMatriz+renglon)+columna) = matriz[renglon][columna]*escala;
        }
    }
    return nMatriz;
}

#endif