/*
Autor: 
Fecha: 
Descripcion: 
*/
#include <iostream>
#include <math.h>
#include<stdio.h>

using namespace std;
float calcularFuncion(float x){
    return pow(x,2) + 3*x + 8;
}

 
//gotoxy() function definition
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);   
}
 

void cargarVector(int v[], int tamano){
    for (int elemento = 0; elemento < tamano; elemento++)
    {
        cout << "Dame el valor " << elemento << ": ";
        cin >> v[elemento];
    }
}
void imprimirVector(int v[], int tamano){
    for (int elemento = 0; elemento < tamano; elemento++)
    {
        cout << v[elemento] << " ";
    }
    cout << endl;  
}

void cargarVectorChar(char v[], int tamano){
    for (int elemento = 0; elemento < tamano; elemento++)
    {
        cout << "Dame el valor " << elemento << ": ";
        cin >> v[elemento];
    }
}
void imprimirVectorChar(char v[], int tamano){
    for (int elemento = 0; elemento < tamano; elemento++)
    {
        cout << v[elemento] << " ";
    }
    cout << endl;  
}


int main(){
    int numeros[100] = {0};
    char c[6];
    cargarVector(numeros,6);
    imprimirVector(numeros,6);

    cargarVectorChar(c,6);
    imprimirVectorChar(c,6);
    cout << endl; 
    getchar();


    return 0;
}




