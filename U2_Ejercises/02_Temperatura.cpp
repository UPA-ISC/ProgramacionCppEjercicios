/* Hacer un programa en el que se ingresen 6 temperaturas y determine el promedio, la mas 
 baja y la mas alta */
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int tempBaja;
    int tempAlta;
    int tempActual;
    int contador = 1;
    float tempMedia=0;

    do{
        cout << "Ingrese el valor de la temperatura " << contador << ": ";
        cin >> tempActual;
        tempMedia += tempActual;
        if(contador == 1){
            tempBaja = tempActual;
            tempAlta = tempActual;
        }else{
            if(tempActual <= tempBaja){
                tempBaja = tempActual;
            }
            if (tempActual >= tempAlta){
                tempAlta = tempActual;
            }
        }
        
        contador++;
    }while(contador <= 6);

    cout << "La temperatura media es de " << tempMedia/6 << "°C" <<endl;
    cout << "La temperatura mas baja es de " << tempBaja << "°C" <<endl;
    cout << "La temperatura mas alta es de " << tempAlta << "°C" <<endl;
    return 0;
}