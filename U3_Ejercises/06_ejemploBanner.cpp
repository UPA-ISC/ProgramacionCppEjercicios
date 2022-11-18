/*
Autor:
Fecha:
Descripcion:
*/
#include <unistd.h>
#include <iostream>

using namespace std;

// gotoxy() function definition
void gotoxy(int x, int y) { cout << "\033[" << y << ";" << x << "f"; }

int main() {
    for (int x = 1; x < 10; x++) {
        gotoxy(x + 2, 3);
        system("clear");
        cout << "Hola";
        cout.flush(); //Limpiar la cadena
        usleep(100000);
    }

    cout << endl;

    return 0;
}
