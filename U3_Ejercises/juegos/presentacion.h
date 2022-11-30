
#include <unistd.h>
#include <iostream>

using namespace std;
//Texto para banner
string banner[5][1] = {{":::::: ::  ::::   ::::::    ::     ::::   ::::::  ::::  ::::::"},
                       {"  ::   :: ::        ::    ::  ::  ::        ::   ::  :: ::    "},
                       {"  ::   :: ::        ::    ::  ::  ::        ::   ::  :: ::::::"},
                       {"  ::   :: ::        ::   :::::::: ::        ::   ::  :: ::    "},
                       {"  ::   ::  ::::     ::   ::    ::  ::::     ::    ::::  ::::::"}};

 //Se guarda en global el tamaño de la matriz a mover
 int tamRenglon = 5; 
 int tamColumna = 1;
 //Velocidad de desplazamiento
 int retardo = 50000;


void gotoxy(int x, int y) { cout << "\033[" << y << ";" << x << "f"; }


void mostrarLinea(int xO, int yO, int longitud){
    /*
    xO posición en x inicial
    yO posición en y inicial
    longitud, tamaño de la linea
    */
    gotoxy(xO, yO);
    for (int row = 0; row < longitud; row++)
        cout << "="; //Caracter para dibujar la línea
    
}

void mostrarBanner(int xO, int yO) {
    /*
        xO posición inicial de columnas
        yO posición inicial de renglones
        mov cantidad de desplazamiento
    */
    int x = xO, y = yO;

    for (int row = 0; row < tamRenglon; row++) {
        x = xO;  // Se inicializa la columna con offset
        for (int col = 0; col < tamColumna; col++) {
            gotoxy(x, y);
            cout << " \033[1;33m" << banner[row][col] << "\033[0m ";
            cout.flush();  // Limpiar la cadena
            x++;           // Se incrementa la columna
        }
        y++;  // Se incrementa el renglon
    }
    // Se deja el cursor en posición inicial
    cout << endl;
}

void animarBanner(int xO, int yO, int movimientos) {
    /*
        xO posición inicial de columnas
        yO posición inicial de renglones
        movimientos cantidad de desplazamiento
    */
    int x = xO, y = yO;
    for (int mov = 0; mov < movimientos; mov++) {
        mostrarBanner(x, y);
        x = xO + mov;
        usleep(retardo);
        //Si llegamos al final de movimientos, no se limpia pantalla
        if (movimientos-mov !=1) system("clear");
    }
    //Se deja el cursor en posición inicial
    cout << endl;
}

void parpadearBanner(int xO, int yO, int parpadeos, int tiempo){
    /*
        xO posicion inicial en x
        yO posicion inicial en y
        parpadeos cantidad de parpadeos desdeados
        tiempo es el retardo de cada parpadeo
    */
    for (int parpadeo = 0; parpadeo < parpadeos; parpadeo++)
    {
        mostrarBanner(xO, yO);
        usleep(tiempo);
        if (parpadeos-parpadeo!=1) {
            system("clear");
            usleep(tiempo);
            }
    }
    
}

