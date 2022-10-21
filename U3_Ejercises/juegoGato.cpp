/*
Autor: Luis Ernesto Anaya Tiscareño
Fecha: 20/10/22
Descripcion: Juego de gato
*/
#include <iostream>

using namespace std;
void construirTablero();
char obtenerJugada();
bool revisarJugadasPosibles(int, int);
bool revisarJugada(char);
void colocarJugada(char);
bool revisarGanador();

char tablero[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
string opciones = "abcdefghi";
int turnoJugador = 0;

int main() {
    char jugada;
    bool ganador = false;
    while (turnoJugador < 9 && ganador == false) {
        system("clear");
        construirTablero();
        jugada = obtenerJugada();
        revisarJugada(jugada) ? cout << "Jugada permitida"
                              : cout << "Jugada no permitida";
        cout << endl;
        if (revisarJugada(jugada)) {
            colocarJugada(jugada);
            ganador = revisarGanador();
            if (ganador) {
                system("clear");
                construirTablero();
                cout << "El ganador es el judador " << turnoJugador % 2 + 1
                     << endl;
            }
            turnoJugador++;
        }

        cout << endl;
    }
    return 0;
}

void construirTablero() {
    int x = 0, y = 0;
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 3; col++) {
            if (row < 5 && row % 2 == 1)
                cout << "___";
            else if (row < 5) {
                cout << " " << tablero[x][y] << " ";
                y++;
            } else
                cout << "   ";

            if (col < 2) cout << "|";
        }
        cout << endl;

        y = 0;
        if (row % 2 == 1) x++;
    }
}

char obtenerJugada() {
    int opcion = 0;
    bool posible;

    cout << "OPCIONES: " << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            posible = revisarJugadasPosibles(row, col);
            if (posible) {
                cout << opciones[opcion] << ": [" << row << "][" << col << "]"
                     << endl;
            }
            opcion++;
        }
    }
    char jugada;
    cout << "Selecciona tu jugada: ";
    cin >> jugada;
    return jugada;
}

bool revisarJugadasPosibles(int row, int col) {
    bool noOcupado;
    if (tablero[row][col] != ' ')
        noOcupado = false;
    else
        noOcupado = true;
    return noOcupado;
}

bool revisarJugada(char jugada) {
    bool jugadaPosible = false;
    if (jugada >= 'a' && jugada <= 'i') {
        if (jugada == 'a')
            jugadaPosible = revisarJugadasPosibles(0, 0);
        else if (jugada == 'b')
            jugadaPosible = revisarJugadasPosibles(0, 1);
        else if (jugada == 'c')
            jugadaPosible = revisarJugadasPosibles(0, 2);
        else if (jugada == 'd')
            jugadaPosible = revisarJugadasPosibles(1, 0);
        else if (jugada == 'e')
            jugadaPosible = revisarJugadasPosibles(1, 1);
        else if (jugada == 'f')
            jugadaPosible = revisarJugadasPosibles(1, 2);
        else if (jugada == 'g')
            jugadaPosible = revisarJugadasPosibles(2, 0);
        else if (jugada == 'h')
            jugadaPosible = revisarJugadasPosibles(2, 1);
        else if (jugada == 'i')
            jugadaPosible = revisarJugadasPosibles(2, 2);
    }

    return jugadaPosible;
}

void colocarJugada(char jugada) {
    char valor;
    if (turnoJugador % 2 == 1)
        valor = 'X';
    else
        valor = 'O';

    if (jugada == 'a')
        tablero[0][0] = valor;
    else if (jugada == 'b')
        tablero[0][1] = valor;
    else if (jugada == 'c')
        tablero[0][2] = valor;
    else if (jugada == 'd')
        tablero[1][0] = valor;
    else if (jugada == 'e')
        tablero[1][1] = valor;
    else if (jugada == 'f')
        tablero[1][2] = valor;
    else if (jugada == 'g')
        tablero[2][0] = valor;
    else if (jugada == 'h')
        tablero[2][1] = valor;
    else if (jugada == 'i')
        tablero[2][2] = valor;
}

bool revisarGanador() {
    bool existeGanador = false;
    if (tablero[0][0] != ' ' && tablero[0][1] == tablero[0][0] &&
        tablero[0][2] == tablero[0][0])
        existeGanador = true;
    return existeGanador;
}