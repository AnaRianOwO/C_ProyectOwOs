#include <stdio.h>

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

struct Polinomio crear_polinomio(char var, int num) {
  struct Polinomio p;
  p.variable = var;
  p.num_terminos = num;
  return p;
}

void agregar_termino(struct Polinomio *p, float coef, int exp){
  if(p->num_terminos >=20){
    printf("Error\n");
  }

  int num = p->num_terminos;
  struct Termino t = crear_termino(coef, exp);
  p->terminos[num] = t;
  p->num_terminos++;
}

int main() {
  struct Polinomio p = crear_polinomio('y', 0);
  agregar_termino(&p, -8, 3);
  printf("%f %c^%d. El polinomio tiene %d", p.terminos[0].coeficiente, p.variable, p.terminos[0].exponente, p.num_terminos);
  return 0;
}
