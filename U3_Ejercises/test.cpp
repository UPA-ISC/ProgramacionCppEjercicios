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


int main(){
    int numeros[100];
   /* gotoxy(10,10);
    cout << "Hola";
    gotoxy(0,3);
    cout << "Regreso" << endl;*/
    float matriz[4][4] ={8.2};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
        
    }
    


    getchar();
    //cargarVector(numeros, 5);
    //calcularFuncion(numeros, )
    //imprimirVector(numeros, 10);

    return 0;
}