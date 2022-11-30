/*
Autor:
Fecha:
Descripcion:
*/
#include <unistd.h>
#include <iostream>

using namespace std;

string banner[4][1] = {{":::::: ::  ::::  ::::::    ::  "},
                         {"  ::   :: ::       ::    ::  ::"},
                         {"  ::   :: ::       ::   ::::::::"},
                         {"  ::   ::  ::::    ::   ::    ::"}};


 //Se guarda en global el tamaño de la matriz a mover
 int tamRenglon = 4; 
 int tamColumna = 1;
 //Velocidad de desplazamiento
 int retardo = 50000;


void gotoxy(int x, int y) { cout << "\033[" << y << ";" << x << "f"; }
//Prototipo de función banner
void mostrarBanner(int, int, int);
void mostrarLinea(int,int,int);

int main() {
    
    mostrarBanner(4,10,30);
    mostrarLinea(20,8,50);
    mostrarLinea(20,15,50);

    //Este codigo es otro ejemplo de corrimientos para un solo renglon
    /*
    for (int x = 1; x < 50; x++) {
        gotoxy(x, 3);
        system("clear");
        //cout << "\u1F30F Hola \u1F30F";
        cout << "ᗧ•••" << endl;
        gotoxy(x, 4);
        cout << "Hola";
        cout.flush(); //Limpiar la cadena
        usleep(retardo);
    }
    for (int x = 50; x > 1; x--) {
        gotoxy(x, 3);
        system("clear");
        cout << "•••ᗤ";
        cout.flush(); //Limpiar la cadena
        usleep(retardo);
    }*/

    //Esperar la tecla enter para terminar el programa
    getchar();
    return 0;
}

void mostrarBanner(int xO, int yO, int movimientos) {
    /*
        xO posición inicial de columnas
        yO posición inicial de renglones
        movimientos cantidad de desplazamiento
    */
    int x = xO, y = yO;
    for (int mov = 0; mov < movimientos; mov++) {
        for (int row = 0; row < tamRenglon; row++) {
            x = xO+mov; //Se inicializa la columna con offset
            for (int col = 0; col < tamColumna; col++) {
                gotoxy(x, y);
                cout << banner[row][col];
                cout.flush(); //Limpiar la cadena
                x++; // Se incrementa la columna
            }
            y++; // Se incrementa el renglon
        }
        usleep(retardo);
        //Si llegamos al final de movimientos, no se limpia pantalla
        if (movimientos-mov !=1) system("clear");

        //Reiniciando el renglon
        y = yO;
    }
    //Se deja el cursor en posición inicial
    cout << endl;
}

void mostrarLinea(int xO, int yO, int longitud){
    gotoxy(xO, yO);
    for (int row = 0; row < longitud; row++)
        cout << ".";
    
}