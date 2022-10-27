/*
    Realice un programa en el que se ingrese un monto de dinero e imprima su
   desgloce en cantidad de billetes o monedas.
*/

#include <iostream>

using namespace std;

void obtenerCambio(int);
void obtenerMonedas(int);
void imprimirCambio();

int denominacionesBilletes[5] = {500, 200, 100, 50, 20};
int denominacionesMonedas[4] = {10, 5, 2, 1};
int cambioBilletes[5];
int cambioMonedas[4];

int main() {
    int dinero;

    cout << "Dame la cantidad de dinero: ";
    cin >> dinero;

    obtenerCambio(dinero);
    imprimirCambio();

    return 0;
}

void obtenerCambio(int monto) {
    int residuo;

    for (int denominacion = 0; denominacion <= 4; denominacion++) {
        residuo = (denominacion == 0) ? monto : residuo;
        cambioBilletes[denominacion] =
            residuo / denominacionesBilletes[denominacion];
        residuo %= denominacionesBilletes[denominacion];
    }
    obtenerMonedas(residuo);
}

void obtenerMonedas(int monto) {
    int residuo;

    for (int denominacion = 0; denominacion <= 3; denominacion++) {
        residuo = (denominacion == 0) ? monto : residuo;
        cambioMonedas[denominacion] =
            residuo / denominacionesMonedas[denominacion];
        residuo %= denominacionesMonedas[denominacion];
    }
}

void imprimirCambio() {
    cout << "Tu cambio es: " << endl;
    for (int denominacion = 0; denominacion <= 4; denominacion++) {
        cout << "Billetes de $" << denominacionesBilletes[denominacion] << ": "
             << cambioBilletes[denominacion] << endl;
    }
    for (int denominacion = 0; denominacion <= 3; denominacion++) {
        cout << "Monedas de $" << denominacionesMonedas[denominacion] << ": "
             << cambioMonedas[denominacion] << endl;
    }
}