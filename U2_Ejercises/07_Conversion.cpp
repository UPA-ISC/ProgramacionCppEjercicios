/* Mediante el uso de ciclo while realice la conversion a binario de un numero
 * entero mayor a 0*/
#include <iostream>

using namespace std;

int main() {
    int numero;
    int resultado;
    string resultadoStr;

    cout << "Dame el número a convertir: ";
    cin >> numero;

    if (numero > 0) {
        cout << "El resultado es: ";
        while (numero != 0) {
            if (numero % 2 == 0) {
                resultado = 0;
                resultadoStr = "0" + resultadoStr;
            } else {
                resultado = 1;
                resultadoStr = "1" + resultadoStr;
            }

            resultadoStr = (numero % 2 == 0) ? "0" : "1" + resultadoStr;

            resultadoStr = to_string(numero % 2) + resultadoStr;

            cout << resultado;
            numero /= 2;
        }
        cout << "\nString: " << resultadoStr << endl;
    } else if (numero == 0)
        cout << "0";
    else
        cout << "Número incorrecto";
    cout << endl;
    int c = getchar();
    return 0;
}