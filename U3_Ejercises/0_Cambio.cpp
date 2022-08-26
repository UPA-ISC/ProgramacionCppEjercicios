
#include <iostream>

using namespace std;

void cambio(int, int&, int&, int&, int&, int&, int&, int&, int&);

int main(){
    int dinero;
    int quinientos = 0, doscientos = 0, cien = 0;
    int cincuenta = 0, veinte = 0;
    int diez = 0, cinco = 0, uno = 0;

    cout << "Dame la cantidad de dinero: ";
    cin >> dinero;
    cambio (dinero, quinientos, doscientos, cien, cincuenta, veinte, diez, cinco, uno);

    cout << "Tu cambio es: " << endl;
    cout << "Billetes de $500: " << quinientos<< endl;
    cout << "Billetes de $200: " << doscientos<< endl;
    cout << "Billetes de $100: " << cien<< endl;
    cout << "Billetes de $50: " << cincuenta<< endl;
    cout << "Billetes de $20: " << veinte<< endl;
    cout << "Monedas de $10: " << diez<< endl;
    cout << "Monedas de $5: " << cinco<< endl;
    cout << "Monedas de $1: " << uno<< endl;
}

void cambio(int dinero, int& quinientos, int& doscientos, int& cien, int& cincuenta, int& veinte, int& diez, int& cinco, int& uno){
    int residuo;
    quinientos = dinero/500;
    residuo = dinero%500;

    doscientos = residuo/200;
    residuo %= 200;

    cien = residuo/100;
   residuo %= 100;

    cincuenta = residuo/50;
    residuo %= 50;

    veinte = residuo/20;
    residuo %= 20;

    diez = residuo/10;
    residuo %= 10;

    cinco = residuo/5;
    residuo %= 5;

    uno = residuo;

}