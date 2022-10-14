#include <iostream>
#include <cmath>

using namespace std;

float resolverEcuacion(float valor) {
  // Con la ecuación: X^3 + 4X ^2 -10
  return pow(valor, 3) + 4 * (pow(valor, 2)) - 10;
}

int main() {
  int iterador = 1;
  /*
      a = inferior
      b = superior
  */
  float a = 1;
  float b = 2;
  float xi_xi = 0;
  float ultimo_xi = 0;

  printf(
      "|-----------------------------------------------------------------------"
      "--------------------------------------------\n");
  printf(
      "|  i |       a     |      b      |    f(a)     |    f(b)     |      xi  "
      "   |    f(xi)    |f(a) * f(xi) |   xi-xi_  |\n");
  printf(
      "|-----------------------------------------------------------------------"
      "--------------------------------------------\n");
  while (1) {
    float fa = resolverEcuacion(a);
    float fb = resolverEcuacion(b);
    float xi = (a + b) / 2;
    float fxi = resolverEcuacion(xi);
    float fa_fxi = fa * fxi;
    xi_xi = abs(xi - ultimo_xi);
    printf(
        "|%3d |%12.8f |%12.8f |%12.8f |%12.8f |%12.8f |%12.8f |%12.8f "
        "|%12.8f\n",
        iterador, a, b, fa, fb, xi, fxi, fa_fxi, xi_xi);
    iterador++;
    if (fa_fxi > 0) {
      a = xi;
    } else {
      b = xi;
    }
    ultimo_xi = xi;
    if (xi_xi == 0) {
      break;
    }
  }
  return 0;
}