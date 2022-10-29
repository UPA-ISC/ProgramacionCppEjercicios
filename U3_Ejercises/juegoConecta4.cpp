#include <iostream>

using namespace std;
string jugadorPC = "PC";
string jugadorHumano = "HUMANO";

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
char tableroPrueba[10][10];
int turnoJugador = 0;

void construirTablero();
bool hacerJugada(int);
bool hacerJugadaPrueba(int, string);
bool revisarGanador(int, string);
bool revisarHorizontal(int,int,char, string);
bool revisarVertical(int,int,char, string);
bool revisarDiagonalPositiva(int,int,char,string);
bool revisarDiagonalNegativa(int,int,char,string);
int seleccionarColumnaCorrecta();
void crearTableroPrueba();
int obtenerRenglonVacio(int, string);
int existeColumnaGanadora(string);


int main(){
    int jugada;
    bool jugadaCorrecta = false;
    bool esGanador = false;
    int jugadaPC;
    construirTablero();
    while (turnoJugador < 100 && esGanador == false) {
        do {
            if (turnoJugador % 2 == 0) {
                // Jugador 1
                cout << "Haz tu jugada seleccionando la columna: ";
                cin >> jugada;
                jugadaCorrecta = hacerJugada(jugada);
                if (jugadaCorrecta == true) esGanador = revisarGanador(jugada, jugadorHumano);
            } else {
                //Jugador 2
                jugadaPC = seleccionarColumnaCorrecta();
                jugadaCorrecta = hacerJugada(jugadaPC);
                if (jugadaCorrecta == true) esGanador = revisarGanador(jugadaPC, jugadorHumano);
            }
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
        if (tablero[row][col] == ' ') {
            tablero[row][col] = valor;
            lugarDisponible = true;
            break;
        }
    } 
    if(lugarDisponible== false)
        cout << "Columna llena" << endl; 
    return lugarDisponible;
}

bool hacerJugadaPrueba(int col, string jugador){
    char valor = 'x';
    valor = (jugador == jugadorHumano)?'x':'o';
    bool lugarDisponible = false;
    for (int row = 9; row >= 0; row--)
    {
        if (tableroPrueba[row][col] == ' ') {
            tableroPrueba[row][col] = valor;
            lugarDisponible = true;
            break;
        }
    } 
    if(lugarDisponible== false)
        cout << "Columna llena" << endl; 
    return lugarDisponible;
}

bool revisarGanador(int col, string jugador){
    int renglon, row;
    int contador = 0;
    char ultimaJugada;
    int columna = col;
    bool esGanador = false;

    for (row = 9; row >= 0; row--)
    {
        if (jugador == jugadorHumano){
            if (tablero[row][col] == ' ')
                break;
        }else if (jugador == jugadorPC)
            if (tableroPrueba[row][col] == ' ')
                break;
    }

    //Obtengo el renglon y la ficha de la ultima jugada
    renglon = (row == 9)?row:row+1;
    if(jugador == jugadorHumano)
        ultimaJugada = tablero[renglon][col];
    else
        ultimaJugada = tableroPrueba[renglon][col];

    if (revisarHorizontal(renglon, col, ultimaJugada, jugador) == true)
        esGanador = true;
    else if (revisarVertical(renglon, col, ultimaJugada, jugador) == true)
        esGanador = true;
    else if (revisarDiagonalPositiva(renglon, col, ultimaJugada, jugador) == true)
        esGanador = true;
    else if (revisarDiagonalNegativa(renglon, col, ultimaJugada, jugador) == true)
        esGanador = true;
    else 
        esGanador = false;

    return esGanador;
}

bool revisarHorizontal(int row, int col, char ultimaJugada, string jugador) {
    int contador = 0;
    int columna = col;
    char esGanador = false;
    if (jugador == jugadorHumano) {
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
    }else{
         // Hacia la derecha
        while (tableroPrueba[row][columna] == ultimaJugada && columna < 10) {
            contador++;
            columna++;
        }
        // Hacia la izquierda
        columna = col;
        while (tableroPrueba[row][columna] == ultimaJugada && columna >= 0) {
            contador++;
            columna--;
        }

    }

    if (contador > 4) esGanador = true;

    return esGanador;
}

bool revisarVertical(int row, int col, char ultimaJugada, string jugador) {
    int contador = 0;
    int renglon = row;
    char esGanador = false;

    // Hacia la abajo
    if (jugador == jugadorHumano) {
        while (tablero[renglon][col] == ultimaJugada && renglon < 10) {
            contador++;
            renglon++;
        }
    } else {
        while (tableroPrueba[renglon][col] == ultimaJugada && renglon < 10) {
            contador++;
            renglon++;
        }
    }

    if (contador >= 4) esGanador = true;

    return esGanador;
}

bool revisarDiagonalPositiva(int row, int col, char ultimaJugada, string jugador) {
    int contador = 0;
    int columna = col;
    int renglon = row;
    char esGanador = false;
    if (jugador == jugadorHumano) {
        // Hacia arriba
        while (tablero[renglon][columna] == ultimaJugada && columna < 10 &&
               renglon >= 0) {
            contador++;
            columna++;
            renglon--;
        }
        // Hacia abajo
        columna = col;
        renglon = row;
        while (tablero[renglon][columna] == ultimaJugada && renglon < 10 &&
               columna >= 0) {
            contador++;
            columna--;
            renglon++;
        }
    }else{
        // Hacia arriba
        while (tableroPrueba[renglon][columna] == ultimaJugada && columna < 10 &&
               renglon >= 0) {
            contador++;
            columna++;
            renglon--;
        }
        // Hacia abajo
        columna = col;
        renglon = row;
        while (tableroPrueba[renglon][columna] == ultimaJugada && renglon < 10 &&
               columna >= 0) {
            contador++;
            columna--;
            renglon++;
        }

    }

    if (contador > 4) esGanador = true;

    return esGanador;
}

bool revisarDiagonalNegativa(int row,int col,char ultimaJugada, string jugador){
   int contador = 0;
    int columna = col;
    int renglon = row;
    char esGanador = false;
    if (jugador == jugadorHumano) {  // Hacia arriba
        while (tablero[renglon][columna] == ultimaJugada && columna >= 0 &&
               renglon >= 0) {
            contador++;
            columna--;
            renglon--;
        }
        // Hacia abajo
        columna = col;
        renglon = row;
        while (tablero[renglon][columna] == ultimaJugada && renglon < 10 &&
               columna < 10) {
            contador++;
            columna++;
            renglon++;
        }
    } else {
        while (tableroPrueba[renglon][columna] == ultimaJugada &&
               columna >= 0 && renglon >= 0) {
            contador++;
            columna--;
            renglon--;
        }
        // Hacia abajo
        columna = col;
        renglon = row;
        while (tableroPrueba[renglon][columna] == ultimaJugada &&
               renglon < 10 && columna < 10) {
            contador++;
            columna++;
            renglon++;
        }
    }
    if (contador > 4) esGanador = true;
    return esGanador; 
}

void crearTableroPrueba(){
    for (int row = 0; row < 10; row++)
        for (int col = 0; col < 10; col++)
            tableroPrueba[row][col] = tablero[row][col];    
}

int obtenerRenglonVacio(int col, string jugador){

    for (int row = 9; row >= 0; row--)
    {
        if (jugador == jugadorPC){
            if (tableroPrueba[row][col] == ' ')
                return row;
        }else if (jugador == jugadorHumano)
            if (tablero[row][col] == ' ')
                return row;
    }
    
    //retorna negativo si la columna esta llena
    return -1;
}

int seleccionarColumnaCorrecta(){
    bool esGanador = false;
    int col;
    srand(time(0));
    //Revisar si se puede ganar
    col = existeColumnaGanadora(jugadorPC);
    if (col != -1){
        cout << "Columna ganadora" << endl;
        return col;
    }
    col = existeColumnaGanadora(jugadorHumano);
    if (col != -1){
        cout << "Tapo la jugada del oponente"<<endl;
        return col;
    }

        return 1 + rand() % 9;;
}

int existeColumnaGanadora(string jugador){
    bool esGanador = false;
    int col;
    int renglonVacio;

    string jugadorARevisar = jugador;

    //crearTableroPrueba();
        
     for (col = 0; col < 10; col++)
     {
        crearTableroPrueba();
        renglonVacio = obtenerRenglonVacio(col,jugadorARevisar);
        if (renglonVacio != -1){
            if(hacerJugadaPrueba(col, jugadorARevisar)==true)
                esGanador = revisarGanador(col,jugadorPC);
        }
        if (esGanador == true) break;
     }
    
    if (esGanador == true) 
        return col;
    else 
        return -1;
}

