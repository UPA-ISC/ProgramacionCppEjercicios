/* 
En una determinada empresa, sus empleados son evaluados al final de cada año. 
Los puntos que pueden obtener en la evaluación comienzan en 0.0 y pueden ir aumentando, 
traduciéndose en mejores beneficios. Los puntos que pueden conseguir 
los empleados pueden ser 0.0, 0.4, 0.6 o más, pero no valores intermedios 
entre las cifras mencionadas. A continuación se muestra una tabla con los 
niveles correspondientes a cada puntuación. La cantidad de dinero conseguida
en cada nivel es de $2,400 multiplicada por la puntuación del nivel.

Nivel	Puntuación
Inaceptable	0.0
Aceptable	0.4
Meritorio	0.6 o más
Escribir un programa que lea la puntuación del usuario e indique su nivel de rendimiento, 
así como la cantidad de dinero que recibirá el usuario.
*/
#include <iostream>

using namespace std;

int main(){
    double puntuacion;
    
    cout << "Ingrese la puntuación de la persona: ";
    cin >> puntuacion;

    if ((puntuacion == 0) || (puntuacion == 0.4) || (puntuacion >= 0.6)){
        cout << "El nivel de rendimiento fue del " << puntuacion*100 << "%"<< endl;
        cout << "Los beneficios son: $" << puntuacion*2400 << endl;
    }
    else
        cout << "La puntuación ingresada no corresponde a ningún valor permitido" << endl;
    

    return 0;
}