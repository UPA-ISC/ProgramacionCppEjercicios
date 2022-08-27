/* La pizzería Bella Napoli ofrece pizzas vegetarianas y no vegetarianas a sus clientes. 
Los ingredientes para cada tipo de pizza aparecen a continuación.

Ingredientes vegetarianos: Pimiento y tofu.
Ingredientes no vegetarianos: Peperoni, Jamón y Salmón.
Escribir un programa que pregunte al usuario si quiere una pizza vegetariana o no, 
y en función de su respuesta le muestre un menú con los ingredientes disponibles para que elija.
Solo se puede eligir un ingrediente además de la mozzarella y el tomate que están en todas la pizzas.
 Al final se debe mostrar por pantalla si la pizza elegida es vegetariana o no y 
 todos los ingredientes que lleva.*/

#include<iostream>

using namespace std;

int main(){
    //Declaración de variables
    int tipoPizza;
    int ingrediente;

    cout << "Especifique el tipo de pizza que desea. " << endl;
    cout << "1.- Vegetariana" << endl;
    cout << "2.- No Vegetariana" << endl;
    cout << "Presiona el número de tu selección: ";
    cin >> tipoPizza;
    
    if (tipoPizza <= 2 )
        cout << "La pizza seleccionada fue: " << (tipoPizza == 1 ? "Vegetariana" : "No vegetariana") << endl;

    if (tipoPizza == 1){
            //Es vegetariana
            cout << "Selecciona el ingrediente que deseas: " << endl;
            cout << "1.- Pimiento" << endl;
            cout << "2.- Tofu" << endl;
            cout << "Presiona el número de tu selección: ";
            cin >> ingrediente;
            if (ingrediente == 1)
                cout << "El ingrediente seleccionado fue: " << "Pimiento" << endl;
            else if (ingrediente == 2)
                cout << "El ingrediente seleccionado fue: " << "Tofu" << endl;
            else 
                cout << "Selección incorrecta" << endl;
        }
    else if (tipoPizza == 2){
            // No es vegetariana
            cout << "Selecciona el ingrediente que deseas: " << endl;
            cout << "1.- Peperoni" << endl;
            cout << "2.- Jamón" << endl;
            cout << "3.- Salmón" << endl;
            cout << "Presiona el número de tu selección: ";
            cin >> ingrediente;
            if (ingrediente == 1)
                cout << "El ingrediente seleccionado fue: " << "Peperioni" << endl;
            else if (ingrediente == 2)
                cout << "El ingrediente seleccionado fue: " << "Jamón" << endl;
            else if (ingrediente == 3)
                cout << "El ingrediente seleccionado fue: " << "Salmón" << endl;
            else 
                cout << "Selección incorrecta" << endl;
    }else
        cout << "Selección incorrecta, debe ser 1 o 2" << endl;

    return 0;
}