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

void imprimir_polinomio(struct Polinomio p) {
  for (int i=0; i<p.num_terminos; i++){
    if (p.terminos[i].coeficiente == 0){
      printf(".");
    };
    if (i != 0) && (p.terminos[i].coeficiente > 0){
      printf("+");
    }
      //printf("%g%c^%d ", p.terminos[i].coeficiente, p.variable, p.terminos[i].exponente);
  }
  printf("El polinomio se ha imprimido correctamente ");
}



void comparar_e_intercambiar(struct Polinomio *p, int i){
  if(p->terminos[i].exponente < p->terminos[i+1].exponente){
        struct Termino temp = p->terminos[i];
        p->terminos[i] = p->terminos[i+1];
        p->terminos[i+1] = temp;
      }
}

void organizar_polinomio(struct Polinomio *p){
  for (int i=0; i<p->num_terminos-1; i++){
    for (int j=0; j<p->num_terminos-1; j++){
      comparar_e_intercambiar(p, j);
    }
  }
}

int main() {
  struct Polinomio p = crear_polinomio('x', 0);
  agregar_termino(&p, 8, 1);
  agregar_termino(&p, -4, 3);
  agregar_termino(&p, 10, 2);
  agregar_termino(&p, -2, 4);
  agregar_termino(&p, 1, 6);
  organizar_polinomio(&p);
  imprimir_polinomio(p);
  return 0;
}
