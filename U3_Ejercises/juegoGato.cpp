/*
Autor: Luis Ernesto Anaya Tiscareño
Fecha: 20/10/22
Descripcion: Juego de gato
*/
#include <iostream>

using namespace std;

const string MAQUINA = "PC";
const string HUMANO = "HUMANO";
const string TABLERO_REAL = "HUMANO";
const string TABLERO_MAQUINA = "PC";

void gotoxy(int x, int y) {
    // Coloca el cursor en la posicion (x,y)
    cout << "\033[" << y << ";" << x << "f";
}

void construirTablero(int, int);
char obtenerJugada(string);
bool revisarJugadasPosibles(int, int, string);
bool revisarJugada(int, string);
void colocarJugada(int, string, string);
bool revisarGanador(string);
void jugarGato(string);
int obtenerMejorJugada();
void crearTableroPrueba();
int existeCasillaGanadora(string);
void colocarMensaje(int);
void darBienvenida();

char tablero[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char tableroPrueba[3][3];
int turnoJugador = 0;

int main() {
    string tipoContrincante;
    int seleccion;

    darBienvenida();
    do {
        cout << "Selecciona si jugarás contra la máquina o un humano: " << endl;
        cout << "1) Máquina" << endl;
        cout << "2) Humano" << endl;
        cout << "Tu selección es: ";
        cin >> seleccion;

        if (seleccion == 1)
            tipoContrincante = MAQUINA;
        else if (seleccion == 2)
            tipoContrincante = HUMANO;
        else
            cout << "Selección incorrecta, intenta nuevamente" << endl;

    } while (seleccion != 1 && seleccion != 2);
    system("clear");
    jugarGato(tipoContrincante);
    return 0;
}

void jugarGato(string contrincante) {
    int jugada;
    bool ganador = false;
    bool jugadaCorrecta;
    string jugador;
    string jugadorGanador = "No_ganador";

    construirTablero(6, 2);
    while (turnoJugador < 9 && ganador == false) {
        if (turnoJugador % 2 == 0)
            jugador = HUMANO;
        else {
            jugador = (contrincante == HUMANO) ? HUMANO : MAQUINA;
        }

        jugada = obtenerJugada(jugador);
        //Reviso la jugada en tablero real
        jugadaCorrecta = revisarJugada(jugada, TABLERO_REAL);
       
        if (jugadaCorrecta == true) {
            colocarJugada(jugada, HUMANO, TABLERO_REAL);
            ganador = revisarGanador(HUMANO);
            system("clear");
            construirTablero(6, 2);
            if (ganador) {
                colocarMensaje(turnoJugador % 2 + 1);
            }
            turnoJugador++;
        }
    }
    if (ganador == false) colocarMensaje(3);
}

void construirTablero(int xD, int yD) {
    int x = 0, y = 0;
    for (int row = 0; row < 6; row++) {
        gotoxy(xD, yD++);
        for (int col = 0; col < 3; col++) {
            if (row < 5 && row % 2 == 1)
                cout << "___";
            else if (row < 5) {
                if (tablero[x][y] == 'X')
                    cout << " \033[1;31m" << tablero[x][y] << "\033[0m ";
                else if (tablero[x][y] == 'O')
                    cout << " \033[1;34m" << tablero[x][y] << "\033[0m ";
                else
                    cout << " \033[0;37m" << tablero[x][y] << "\033[0m ";
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

char obtenerJugada(string jugador) {
    int opcion = 0;
    bool posible;

    int jugada;
    if (jugador == HUMANO) {
        cout << "Selecciona tu jugada: ";
        cin >> jugada;
    } else if (jugador == MAQUINA) {
        jugada = obtenerMejorJugada();
    } else
        cout << "ERROR";
    return jugada;
}

bool revisarJugadasPosibles(int row, int col, string jugador) {
    bool noOcupado;
    if (jugador == HUMANO) {
        if (tablero[row][col] != 'X' && tablero[row][col] != 'O')
            noOcupado = true;
        else
            noOcupado = false;
    } else if (jugador == MAQUINA) {
        if (tableroPrueba[row][col] != 'X' && tableroPrueba[row][col] != 'O')
            noOcupado = true;
        else
            noOcupado = false;
    }
    return noOcupado;
}

bool revisarJugada(int jugada, string jugador) {
    bool jugadaPosible = false;
    if (jugada >= 1 && jugada <= 9) {
        if (jugada == 1)
            jugadaPosible = revisarJugadasPosibles(0, 0, jugador);
        else if (jugada == 2)
            jugadaPosible = revisarJugadasPosibles(0, 1, jugador);
        else if (jugada == 3)
            jugadaPosible = revisarJugadasPosibles(0, 2, jugador);
        else if (jugada == 4)
            jugadaPosible = revisarJugadasPosibles(1, 0, jugador);
        else if (jugada == 5)
            jugadaPosible = revisarJugadasPosibles(1, 1, jugador);
        else if (jugada == 6)
            jugadaPosible = revisarJugadasPosibles(1, 2, jugador);
        else if (jugada == 7)
            jugadaPosible = revisarJugadasPosibles(2, 0, jugador);
        else if (jugada == 8)
            jugadaPosible = revisarJugadasPosibles(2, 1, jugador);
        else if (jugada == 9)
            jugadaPosible = revisarJugadasPosibles(2, 2, jugador);
    }

    return jugadaPosible;
}

void colocarJugada(int jugada, string jugador, string tipoFicha) {
    char valor;
    int renglon, columna;
    if (jugador == HUMANO) {
        if (turnoJugador % 2 == 0)
            valor = 'X';  // Jugador 1
        else
            valor = 'O';  // Jugador 2
    } else {
        if (tipoFicha == HUMANO)
            valor = 'X';  // Jugador Humano
        else
            valor = 'O';  // Jugador Maquina
    }

    if (jugada == 1) {
        renglon = 0;
        columna = 0;
    } else if (jugada == 2) {
        renglon = 0;
        columna = 1;
    } else if (jugada == 3) {
        renglon = 0;
        columna = 2;
    } else if (jugada == 4) {
        renglon = 1;
        columna = 0;
    } else if (jugada == 5) {
        renglon = 1;
        columna = 1;
    } else if (jugada == 6) {
        renglon = 1;
        columna = 2;
    } else if (jugada == 7) {
        renglon = 2;
        columna = 0;
    } else if (jugada == 8) {
        renglon = 2;
        columna = 1;
    } else if (jugada == 9) {
        renglon = 2;
        columna = 2;
    }

    if (jugador == HUMANO)
        tablero[renglon][columna] = valor;
    else
        tableroPrueba[renglon][columna] = valor;
}

bool revisarGanador(string jugador) {
    bool existeGanador = false;

    if (jugador == HUMANO) {
        if (tablero[0][0] != ' ' && 
            tablero[0][1] == tablero[0][0] &&
            tablero[0][2] == tablero[0][0])
            existeGanador = true;
        else if (tablero[1][0] != ' ' && 
                 tablero[1][1] == tablero[1][0] &&
                 tablero[1][2] == tablero[1][0])
            existeGanador = true;
        else if (tablero[2][0] != ' ' && 
                 tablero[2][1] == tablero[2][0] &&
                 tablero[2][2] == tablero[2][0])
            existeGanador = true;
        else if (tablero[0][0] != ' ' && 
                 tablero[1][0] == tablero[0][0] &&
                 tablero[2][0] == tablero[0][0])
            existeGanador = true;
        else if (tablero[0][1] != ' ' && 
                 tablero[1][1] == tablero[0][1] &&
                 tablero[2][1] == tablero[0][1])
            existeGanador = true;
        else if (tablero[0][2] != ' ' && 
                 tablero[1][2] == tablero[0][2] &&
                 tablero[2][2] == tablero[0][2])
            existeGanador = true;
        else if (tablero[0][0] != ' ' && 
                 tablero[1][1] == tablero[0][0] &&
                 tablero[2][2] == tablero[0][0])
            existeGanador = true;
        else if (tablero[0][2] != ' ' && 
                 tablero[1][1] == tablero[0][2] &&
                 tablero[2][0] == tablero[0][2])
            existeGanador = true;
        else
            existeGanador = false;
    } else {
        if (tableroPrueba[0][0] != ' ' &&
            tableroPrueba[0][1] == tableroPrueba[0][0] &&
            tableroPrueba[0][2] == tableroPrueba[0][0])
            existeGanador = true;
        else if (tableroPrueba[1][0] != ' ' &&
                 tableroPrueba[1][1] == tableroPrueba[1][0] &&
                 tableroPrueba[1][2] == tableroPrueba[1][0])
            existeGanador = true;
        else if (tableroPrueba[2][0] != ' ' &&
                 tableroPrueba[2][1] == tableroPrueba[2][0] &&
                 tableroPrueba[2][2] == tableroPrueba[2][0])
            existeGanador = true;
        else if (tableroPrueba[0][0] != ' ' &&
                 tableroPrueba[1][0] == tableroPrueba[0][0] &&
                 tableroPrueba[2][0] == tableroPrueba[0][0])
            existeGanador = true;
        else if (tableroPrueba[0][1] != ' ' &&
                 tableroPrueba[1][1] == tableroPrueba[0][1] &&
                 tableroPrueba[2][1] == tableroPrueba[0][1])
            existeGanador = true;
        else if (tableroPrueba[0][2] != ' ' &&
                 tableroPrueba[1][2] == tableroPrueba[0][2] &&
                 tableroPrueba[2][2] == tableroPrueba[0][2])
            existeGanador = true;
        else if (tableroPrueba[0][0] != ' ' &&
                 tableroPrueba[1][1] == tableroPrueba[0][0] &&
                 tableroPrueba[2][2] == tableroPrueba[0][0])
            existeGanador = true;
        else if (tableroPrueba[0][2] != ' ' &&
                 tableroPrueba[1][1] == tableroPrueba[0][2] &&
                 tableroPrueba[2][0] == tableroPrueba[0][2])
            existeGanador = true;
        else
            existeGanador = false;
    }
    return existeGanador;
}

void crearTableroPrueba() {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            tableroPrueba[row][col] = tablero[row][col];
}

int obtenerMejorJugada() {
    srand(time(0));
    int jugada;

    // Revisar si PC puede ganar
    jugada = existeCasillaGanadora( MAQUINA);
    if (jugada != -1) return jugada;
    // Revisar si humano puede ganar
    jugada = existeCasillaGanadora( HUMANO);
    if (jugada != -1) return jugada;
    return 1 + rand() % 9;
}

int existeCasillaGanadora(string tipoFicha) {
    /*Revisa si existe una posible casilla ganadora
    Param: tipoFicha: X, O
    Retorna la mejor jugada en entero
    */
    bool jugadaCorrecta = false;
    // Vamos a probar todas las jugadas
    for (int jugada = 1; jugada <= 9; jugada++) {
        // Se crea una copia del tablero de juego
        crearTableroPrueba();
        jugadaCorrecta = revisarJugada(jugada, TABLERO_MAQUINA);
        if (jugadaCorrecta == true) {
            colocarJugada(jugada, TABLERO_MAQUINA, tipoFicha);
            if (revisarGanador(TABLERO_MAQUINA) == true) 
                //Retorno la jugada ganadora
                return jugada;
        }
    }
    //Si no se encuentra casilla ganadora retorno -1
    return -1;
}

void colocarMensaje(int tipoMensaje) {
    gotoxy(18, 2);
    if (tipoMensaje == 1)
        cout << "EL JUGADOR 1 ES EL GANADOR";
    else if (tipoMensaje == 2)
        cout << "EL JUGADOR 2 ES EL GANADOR";
    else if (tipoMensaje == 3)
        cout << "JUEGO EMPATADO";
    cout << endl;
    gotoxy(0, 8);
}

void darBienvenida(){
    int longitud = 50;
    for (int row = 0; row < longitud; row++)
        cout<< "-";
    cout << endl; 
    cout << "       BIENVENIDO AL JUEGO DEL GATO"<< endl;
    for (int row = 0; row < longitud; row++)
        cout<< "-";
    cout << endl;   
    
}