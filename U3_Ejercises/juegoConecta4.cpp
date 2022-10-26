#include <iostream>

using namespace std;

char tablero[10][10] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
int turnoJugador = 0;

void construirTablero();
bool hacerJugada(int);
bool revisarGanador(int);
bool revisarHorizontal(int,int,char);
bool revisarVertical(int,int,char);
bool revisarDiagonalPositiva(int,int,char);
bool revisarDiagonalNegativa(int,int,char);

int main(){
    int jugada;
    bool jugadaCorrecta = false;
    bool esGanador = false;
   
    while (turnoJugador < 100 && esGanador == false) {
        do {
            cout << "Haz tu jugada seleccionando la columna: ";
            cin >> jugada;
            jugadaCorrecta = hacerJugada(jugada);
            if (jugadaCorrecta == true) esGanador = revisarGanador(jugada);
            
        } while (jugadaCorrecta == false);
        
        turnoJugador++;
        system("clear");
        construirTablero();

        if (esGanador == true)
            cout << "GANADOR" << endl;
        else
            cout << "SIGUE JUGANDO" << endl;
    }
    return 0;
}

void construirTablero(){
    int x = 0, y = 0;
    for (int row = 0; row < 12; row++)
    {
        for (int col = 0; col < 21; col++)
        {
            if (row < 10 && col % 2 == 1) {
                if (tablero[x][y] == 'x')
                    cout << "\033[1;34m" << tablero[x][y] << "\033[0m";
                else if (tablero[x][y] == 'o')
                    cout << "\033[1;31m" << tablero[x][y] << "\033[0m";
                else if (tablero[x][y] == ' ')
                    cout << tablero[x][y];
                y++;
            } else if (row < 10 && col % 2 == 0)
                cout << "|";
            else if (row == 10)
                cout << "-";
            else if (row == 11 && col == 0)
                cout << "|";
            else if (row == 11 && col < 11)
                cout << col-1 << "|";
        }
        cout << endl;
        y = 0;
        x++;
        
    }
    
}

bool hacerJugada(int col){
    char valor = 'x';
    valor = (turnoJugador%2 ==0)?'x':'o';
    bool lugarDisponible = false;
    for (int row = 9; row >= 0; row--)
    {
        if (tablero[row][col] == ' ')
        {
            tablero[row][col] = valor;
            lugarDisponible = true;
            break;
        }  
    } 
    if(lugarDisponible== false)
        cout << "Columna llena" << endl; 
    return lugarDisponible;
}

bool revisarGanador(int col){
    int renglon, row;
    int contador = 0;
    char ultimaJugada;
    int columna = col;
    bool esGanador = false;

    for (row = 9; row >= 0; row--)
    {
        if (tablero[row][col] == ' ')
            break;
    }

    //Obtengo el renglon y la ficha de la ultima jugada
    renglon = (row == 9)?row:row+1;
    ultimaJugada = tablero[renglon][col];
    if (revisarHorizontal(renglon, col, ultimaJugada) == true)
        esGanador = true;
    else if (revisarVertical(renglon, col, ultimaJugada) == true)
        esGanador = true;
    else if (revisarDiagonalPositiva(renglon, col, ultimaJugada) == true)
        esGanador = true;
    else if (revisarDiagonalNegativa(renglon, col, ultimaJugada) == true)
        esGanador = true;
    else 
        esGanador = false;

    return esGanador;
}

bool revisarHorizontal(int row, int col, char ultimaJugada) {
    int contador = 0;
    int columna = col;
    char esGanador = false;

    // Hacia la derecha
    while (tablero[row][columna] == ultimaJugada && columna < 10) {
        contador++;
        columna++;
    }
    // Hacia la izquierda
    columna = col;
    while (tablero[row][columna] == ultimaJugada && columna >= 0) {
        contador++;
        columna--;
    }

    if (contador > 4) esGanador = true;

    return esGanador;
}

bool revisarVertical(int row, int col, char ultimaJugada) {
    int contador = 0;
    int renglon = row;
    char esGanador = false;

    // Hacia la abajo
    while (tablero[renglon][col] == ultimaJugada && renglon < 10) {
        contador++;
        renglon++;
    }

    if (contador >= 4) esGanador = true;

    return esGanador;
}

bool revisarDiagonalPositiva(int row, int col, char ultimaJugada) {
    int contador = 0;
    int columna = col;
    int renglon = row;
    char esGanador = false;

    // Hacia arriba
    while (tablero[renglon][columna] == ultimaJugada && columna < 10 && renglon >= 0) {
        contador++;
        columna++;
        renglon--;
    }
    // Hacia abajo
    columna = col;
    renglon = row;
    while (tablero[renglon][columna] == ultimaJugada && renglon < 10 && columna >= 0) {
        contador++;
        columna--;
        renglon++;
    }

    if (contador > 4) esGanador = true;

    return esGanador;
}

bool revisarDiagonalNegativa(int row,int col,char ultimaJugada){
   int contador = 0;
    int columna = col;
    int renglon = row;
    char esGanador = false;

    // Hacia arriba
    while (tablero[renglon][columna] == ultimaJugada && columna >= 0 && renglon >= 0) {
        contador++;
        columna--;
        renglon--;
    }
    // Hacia abajo
    columna = col;
    renglon = row;
    while (tablero[renglon][columna] == ultimaJugada && renglon < 10 && columna < 10) {
        contador++;
        columna++;
        renglon++;
    }

    if (contador > 4) esGanador = true;

    return esGanador; 
}