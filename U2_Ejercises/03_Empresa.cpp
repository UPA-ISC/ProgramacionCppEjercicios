/* Escribir un programa para una empresa que tiene salas de juegos 
para todas las edades y quiere calcular de forma automática el precio que 
debe cobrar a sus clientes por entrar. El programa debe preguntar al usuario 
la edad del cliente y mostrar el precio de la entrada. Si el cliente es menor
 de 4 años puede entrar gratis, si tiene entre 4 y 18 años debe pagar $5 
 y si es mayor de 18 años, $10.*/

#include <iostream>

using namespace std;

int main(){
    int edad;
    int precio;

    cout << "Ingresa tu edad: ";
    cin >> edad;

    if (edad < 4)
        precio = 0;
    else if (edad >= 4 & edad < 18 )
        precio = 5;
    else
        precio = 10;

    if (precio == 0)
        cout << "Tu entrada es gratis" << endl;
    else
        cout << "El precio es de: $" << precio <<endl;

    return 0;
}