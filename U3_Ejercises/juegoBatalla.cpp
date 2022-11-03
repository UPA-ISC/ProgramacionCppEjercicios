/*
Autor: Luis Ernesto Anaya Tiscareño
Fecha: 21/10/22
Descripcion: Juego de batalla naval
*/
#include <stdio.h>

#include <iostream>

using namespace std;
char tablero[10][10] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
char tableroPC[10][10] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
int turnoJugador = 1;
int puntosJugador, puntosMaquina;
// construirTablero(0: jugador, 1: maquina)
void construirTablero(int);

// pedirBarcos(0: por usuario, 1: aleatorio; 0: jugador, 1: maquina)
void pedirBarcos(int, int);
bool revisarColocacion(int, int, int, int);
void colocarBarcos(int, int, int, int, int);
void hacerTiro(int, int, int);

// gotoxy() function definition
void gotoxy(int x, int y) { printf("%c[%d;%df", 0x1B, y, x); }

int main() {
    int valorX, valorY;
    int puntosGanador = 21;

    srand(time(0));

    // poner barcos aleatorios para usuario
    pedirBarcos(1, 0);

    // poner barcos aleatorios para maquina
    pedirBarcos(1, 1);
    
    //Limpio pantalla
    system("clear");

    cout << "TABLERO JUGADOR" << endl;
    construirTablero(0);
    cout << endl;

    //TODO: Imprimir el tablero de tiradas del jugador sin mostrar los barcos de la maquina
    cout << "TABLERO MAQUINA" << endl;
    construirTablero(1);

    while (turnoJugador < 100 && puntosJugador < puntosGanador &&
           puntosMaquina < puntosGanador) {
        if (turnoJugador % 2 == 1) {
            cout << "Haz tu tiro: ";
            cin >> valorX >> valorY;
            hacerTiro(valorX, valorY, 1);
        } else
            hacerTiro(1 + rand() % 10, 1 + rand() % 10, 0);
        system("clear");
        cout << "TABLERO JUGADOR" << endl;
        construirTablero(0);
        cout << endl;
        cout << "TABLERO MAQUINA" << endl;
        construirTablero(1);

        if (puntosJugador == puntosGanador)
            cout << "HAS GANADO" << endl;
        else if (puntosMaquina == puntosGanador)
            cout << "HAS PERDIDO" << endl;
        else
            cout << "SIGUE JUGANDO" << endl;
        turnoJugador++;
    }
    return 0;
}

void construirTablero(int jugador) {
    int x = 0, y = 0;
    for (int row = 0; row < 22; row++) {
        for (int col = 0; col < 11; col++) {
            if (row == 0 && col > 0)
                (col > 9) ? cout << " " << col << ""
                          : cout << " " << col << " ";
            else if (row % 2 == 0 && col == 0 && row > 1)
                (row / 2 > 9) ? cout << " " << row / 2 << ""
                              : cout << " " << row / 2 << " ";
            else if (row < 22 && row % 2 == 1)
                cout << "___";
            else if (row < 21 && col > 0 && row > 1) {
                if (jugador == 0) {
                    if (tablero[x][y] == 'b')
                        cout << " \033[1;37m" << tablero[x][y] << "\033[0m ";
                    else if (tablero[x][y] == 'x')
                        cout << " \033[1;31m" << tablero[x][y] << "\033[0m ";
                    else if (tablero[x][y] == 'o')
                        cout << " \033[1;34m" << tablero[x][y] << "\033[0m ";
                    else
                        cout << "   ";
                    y++;
                } else {
                    if (tableroPC[x][y] == 'b')
                        cout << " \033[1;37m" << tableroPC[x][y] << "\033[0m ";
                    else if (tableroPC[x][y] == 'x')
                        cout << " \033[1;31m" << tableroPC[x][y] << "\033[0m ";
                    else if (tableroPC[x][y] == 'o')
                        cout << " \033[1;34m" << tableroPC[x][y] << "\033[0m ";
                    else
                        cout << "   ";
                    y++;
                }
            } else
                cout << "   ";
            if (col < 11) cout << "|";
        }
        cout << endl;
        y = 0;
        if (row % 2 == 1 && row > 1) x++;
    }
}

void pedirBarcos(int aleatorio, int jugador) {
    int posX, posY, direccion;
    int newX, newY;
    bool barcoCorrecto = false;
    int cantidadBarcos[4] = {2, 3, 3, 1};
    srand(time(0));
    for (int barco = 1; barco <= 4; barco++) {
        do {
            if (aleatorio == 0) {
                cout << "Dame la posición origen del barco " << barco << ": ";
                cin >> posX >> posY;

                cout << "Dame la dirección del barco " << barco << ": ";
                cin >> direccion;
            } else {
                posX = 1 + rand() % 10;
                posY = 1 + rand() % 10;

                direccion = 1 + rand() % 4;
            }
            barcoCorrecto = revisarColocacion(posX, posY, direccion, barco);
            if (barcoCorrecto) {
                if (aleatorio == 0) {
                    system("clear");
                    construirTablero(0);
                    cout << endl;
                }
                colocarBarcos(posX, posY, direccion, barco, jugador);
                cantidadBarcos[barco - 1]--;
            } else
                (aleatorio == 0)
                    ? cout << "NO ES POSIBLE COLOCAR EL BARCO" << endl
                    : cout << "";
        } while (barcoCorrecto == false || cantidadBarcos[barco - 1] > 0);
    }
}

bool revisarColocacion(int x, int y, int dir, int longitud) {
    int newX, newY;
    bool esPosible = false;
    for (int espacio = 0; espacio < longitud; espacio++) {
        newX = x - 1;
        newY = y - 1;
        if (dir == 1)
            newY += espacio;
        else if (dir == 2)
            newX += espacio;
        else if (dir == 3)
            newY -= espacio;
        else if (dir == 4)
            newX -= espacio;
        if (newX < 0 || newX > 9 || newY < 0 || newY > 9 ||
            tablero[newX][newY] != ' ') {
            esPosible = false;
            break;
        } else
            esPosible = true;
    }
    return esPosible;
}

void colocarBarcos(int posX, int posY, int direccion, int longitud,
                   int jugador) {
    int newX, newY;

    for (int espacio = 0; espacio < longitud; espacio++) {
        newX = posX - 1;
        newY = posY - 1;
        if (direccion == 1)
            newY += espacio;
        else if (direccion == 2)
            newX += espacio;
        else if (direccion == 3)
            newY -= espacio;
        else if (direccion == 4)
            newX -= espacio;
        if (jugador == 0)
            tablero[newX][newY] = 'b';
        else
            tableroPC[newX][newY] = 'b';
    }
}

void hacerTiro(int vX, int vY, int jugador) {
    int x = vX - 1;
    int y = vY - 1;

    if (jugador == 0) {
        if (tablero[x][y] == 'b') {
            tablero[x][y] = 'x';
            puntosMaquina++;
        } else if (tablero[x][y] == ' ')
            tablero[x][y] = 'o';
        else if (tablero[x][y] == 'x')
            tablero[x][y] = 'x';
        else if (tablero[x][y] == 'o')
            tablero[x][y] = 'o';
        else
            cout << "Jugada existente" << endl;
    } else {
        if (tableroPC[x][y] == 'b') {
            puntosJugador++;
            tableroPC[x][y] = 'x';
        } else if (tableroPC[x][y] == ' ')
            tableroPC[x][y] = 'o';
        else if (tableroPC[x][y] == 'x')
            tableroPC[x][y] = 'x';
        else if (tableroPC[x][y] == 'o')
            tableroPC[x][y] = 'o';
        else
            cout << "Jugada existente" << endl;
    }
}