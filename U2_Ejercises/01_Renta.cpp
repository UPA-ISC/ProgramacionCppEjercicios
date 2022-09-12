/*
Los tramos impositivos para la declaración de la renta en un determinado país son los siguientes:

Renta	Tipo impositivo
Menos de $10,000	5%
Entre $10,000 y $20,000	15%
Entre $20,000 y $35,000	20%
Entre $35,000 y $60,000	30%
Más de $60,000	45%
Escribir un programa que pregunte al usuario su renta anual y muestre por 
pantalla el tipo impositivo que le corresponde.
*/

#include <iostream>

using namespace std;

int main(){
    double renta;
    double porcentaje;

    cout << "Ingresa el valor de la renta anual: ";
    cin >> renta;

    if (renta < 10000)
        porcentaje = 0.05;
    else if ((renta >= 10000) || (renta < 20000))
        porcentaje = 0.15;
    else if ((renta >= 20000) || (renta < 35000))
        porcentaje = 0.2;
    else if ((renta >= 35000) || (renta < 60000))
        porcentaje = 0.3;
    else if ((renta >= 60000))
        porcentaje = 0.45;

    cout << "El porcentaje de renta es de " << porcentaje*100 << "%" << endl;
    cout << "El impuesto por su renta es de $" << renta*porcentaje << endl;

    return 0; 
// fin amigo
}