/*
Leer cantidades y precios y al final indique el total de la factura.
Introduzca primero la cantidad vendida y luego ingrese el precio, si alguno es 
cero se dara el resultado final.

*/
#include <iostream>
using namespace std;

int main(){
    double precio;
    int cantidad;
    double cuenta = 0;

    do{
       
        cout << "Ingrese la cantidad vendida: ";
        cin >> cantidad;
        if (cantidad <= 0){
            cout << "Finalizando la factura" << endl;
            break;
        }

        cout << "Ingrese el precio del articulo: ";
        cin >> precio;
        if (precio <= 0){
            cout << "Finalizando la factura" << endl;
            break;
        }
        else
            cuenta += cantidad*precio;

    }while((precio > 0) && (cantidad > 0));


    cout << "La cuenta total es de " << cuenta << endl;
    return 0;
}