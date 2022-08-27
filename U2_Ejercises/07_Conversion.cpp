/* Mediante el uso de ciclo while realice la conversion a binario de un numero entero mayor a 0*/ 
#include <iostream>

using namespace std;

int main(){
    int numero;
    int resultado;

    cout << "Dame el número a convertir: ";
    cin >> numero;

    if(numero > 0){
        while(numero != 0){
            if (numero %2 == 0)
                resultado = 0;
            else    
                resultado = 1;
            cout << resultado; 
            numero /= 2;
        }
    }
    else if (numero == 0 )
        cout << "0";
    else
        cout << "Número incorrecto";
    cout << endl;

    return 0;
}