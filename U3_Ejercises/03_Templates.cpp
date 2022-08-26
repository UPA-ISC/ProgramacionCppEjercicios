#include <iostream>
#include "04_Template1.h"

using namespace std;

int main(){
    int n1, n2, n3;

    cout << "Dame un numero: ";
    cin >> n1;
    cout << "Dame un numero: ";
    cin >> n2;
    cout << "Dame un numero: ";
    cin >> n3;

    cout << "maximo es: " << maximum(n1, n2,n3)<< endl;
    cout << "minimo es: " << minimum(n1, n2,n3)<< endl;
    return 0;

}