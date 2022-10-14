

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int numero;
    int contador;
    int limite = 15;
    cout << "¿De qué número deseas la tabla?: ";
    cin >> numero;

    cout << "|";
    for (int renglon = 1; renglon <= 40; renglon++) {
        cout << "-";
    }
    cout << endl;

    for (int contador = 1; contador <= limite; contador++) {
        cout << "| " << contador << "\tX\t" << numero << "\t=\t"
             << contador * numero << "\t|" << endl;
        cout << "|";
        for (int renglon = 1; renglon <= 40; renglon++) {
            cout << "-";
        }
        cout << endl;
    }
    cout << "Presiona enter para terminar.";
    getchar();
    getchar();

    return 0;
}
