/*
    Realice un programa en el que se ingrese un monto de
    dinero e imprima su desgloce en cantidad de billetes
    o monedas.
*/

#include <iostream>

using namespace std;

int quinientos = 0, doscientos = 0, cien = 0;
int cincuenta = 0, veinte = 0;
int diez = 0, cinco = 0, uno = 0;

void obtenerMonedas(int);
void obtenerCambio(int);
void imprimirCambio();

int main() {
    int dinero;

    cout << "Dame la cantidad de dinero: ";
    cin >> dinero;

    obtenerCambio(dinero);
    imprimirCambio();

    return 0;
}

void obtenerMonedas(int monto) {
    int residuo;

    diez = monto / 10;
    residuo = monto % 10;

    cinco = residuo / 5;
    residuo %= 5;

    uno = residuo;
}

void obtenerCambio(int monto) {
    int residuo;
    quinientos = monto / 500;
    residuo = monto % 500;

    doscientos = residuo / 200;
    residuo %= 200;

    cien = residuo / 100;
    residuo %= 100;

    cincuenta = residuo / 50;
    residuo %= 50;

    veinte = residuo / 20;
    residuo %= 20;
    obtenerMonedas(residuo);
}

void imprimirCambio() {
    cout << "Tu cambio es: " << endl;
    cout << "Billetes de $500: " << quinientos << endl;
    cout << "Billetes de $200: " << doscientos << endl;
    cout << "Billetes de $100: " << cien << endl;
    cout << "Billetes de $50: " << cincuenta << endl;
    cout << "Billetes de $20: " << veinte << endl;
    cout << "Monedas de $10: " << diez << endl;
    cout << "Monedas de $5: " << cinco << endl;
    cout << "Monedas de $1: " << uno << endl;
}