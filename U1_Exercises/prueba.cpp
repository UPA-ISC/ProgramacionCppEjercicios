
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    for (int row = 1; row <= 4; row++)
    {
        for (int col = 1; col <= 3; col++)
        {
            cout << "/";
        }
        cout << endl;
        
    }

    int c = 0;
    int par = 0;
    int num;
    while (c<5)
    {       
        cout <<"Numero: ";
        cin >> num;
        par = (num%2==0)?par+num:par;
        c++;
    }
    cout << par << endl;

    for (int contador = 1; contador < 15; contador++)
    {
        (contador%4==0)?cout<<contador<<endl: cout<<"";
    }
    
    
    return 0;
}
