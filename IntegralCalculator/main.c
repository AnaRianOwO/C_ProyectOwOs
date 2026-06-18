#include <stdio.h>

int main() {
  struct Termino {
    float coeficiente;
    int exponente;
  };

  struct Polinomio {
    char variable;
    struct Termino terminos[20];
    int num_terminos;
  };

  struct Termino crear_termino(float coef, int exp) {
    struct Termino t;
    t.coeficiente = coef;
    t.exponente = exp;
    return t;
  };

  struct Termino t = crear_termino(9, 2);
  printf("%f x^%d", t.coeficiente, t.exponente);

  return 0;
}
