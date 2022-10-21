/*
    Realice un programa en el que se ingrese un monto de dinero e imprima su desgloce en cantidad de billetes o monedas.
*/

#include <iostream>

using namespace std;

void obtenerCambio(int);
void obtenerMonedas(int);
void imprimirCambio(string);


int quinientos = 0, doscientos = 0, cien = 0;
int cincuenta = 0, veinte = 0;
int diez = 0, cinco = 0, uno = 0;
int denominaciones[9] = {500,200,100,50,20,10,5,2,1};
int cambio[9];

int main(){
    int dinero;
   

    cout << "Dame la cantidad de dinero: ";
    cin >> dinero;

    obtenerCambio (dinero);
    imprimirCambio("Total");
    
    obtenerMonedas (dinero);
    imprimirCambio("Monedas");

    return 0;
}

void obtenerCambio(int monto)
{
    int residuo;

    for (int denominacion = 0; denominacion <= 8; denominacion++)
    {
        residuo = (denominacion==0)?monto:residuo;
        cambio[denominacion] = residuo/denominaciones[denominacion];
        residuo %= denominaciones[denominacion];
    }
    
   
}

void obtenerMonedas(int monto){
    int residuo;

    diez = monto/10;
    residuo = monto%10;

    cinco = residuo/5;
    residuo %= 5;

    uno = residuo;
}

void imprimirCambio(string tipo){
    if (tipo == "Total"){
        cout << "Tu cambio es: " << endl;
        for (int denominacion = 0; denominacion <= 8; denominacion++)
        {
            cout << "Billetes de $" << denominaciones[denominacion] << ": " << cambio[denominacion] << endl;
        }
        
    }
    else if (tipo=="Monedas"){
        cout << "Tu cambio es: " << endl;
        cout << "Monedas de $10: " << diez<< endl;
        cout << "Monedas de $5: " << cinco<< endl;
        cout << "Monedas de $1: " << uno<< endl;
    }
}   