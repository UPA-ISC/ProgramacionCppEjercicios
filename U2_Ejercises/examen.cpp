#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int c = 0;
    int num, par = 0;
    int limite = 5;

    for (int contador = 1; contador < 15; contador++) {
        (contador % 4 == 0) ? cout << contador << endl : cout << "";
    }

    return 0;
}
