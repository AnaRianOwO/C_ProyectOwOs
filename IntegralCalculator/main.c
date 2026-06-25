#include <stdio.h>

int tiene_constante = 0;
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
      continue;
    }
    
    if (i != 0 && p.terminos[i].coeficiente > 0){
      printf("+");
    }
    
    if (p.terminos[i].exponente == 0 && p.terminos[i].coeficiente==1){
      printf("1");
    }

    if (p.terminos[i].exponente == 0 && p.terminos[i].coeficiente==-1){
      printf("-1");
    }

    if (p.terminos[i].coeficiente == -1 && p.terminos[i].exponente != 0){
      printf("-");
    }
    
    if (p.terminos[i].coeficiente != 1 && p.terminos[i].coeficiente != -1){
      printf("%g", p.terminos[i].coeficiente);
    }

    if (p.terminos[i].exponente == 0){
      continue;
    } 

    if (p.terminos[i].exponente == 1){
      printf("%c", p.variable);
    } else {
      printf("%c^%d", p.variable, p.terminos[i].exponente);
    }
    printf(" ");
  }
  extern int tiene_constante;
  if (tiene_constante == 1){
    printf("+ C ");
  }
  
  printf("\n");
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

void derivar_termino(struct Termino t, struct Polinomio *p){
  if (t.exponente == 0){
    return;
  }

  float nuevo_coef = t.coeficiente * t.exponente;
  int nuevo_exp = t.exponente-1;

  agregar_termino(p, nuevo_coef, nuevo_exp);
}

struct Polinomio derivar_polinomio(struct Polinomio p){
  struct Polinomio derivada = crear_polinomio(p.variable, 0);
  for (int i=0; i<p.num_terminos; i++){
    derivar_termino(p.terminos[i], &derivada);
  }
  extern int tiene_constante; 
  tiene_constante = 0;
  return derivada;
}

void integrar_termino(struct Termino t, struct Polinomio *p){
  if (t.exponente == -1){
    return;
  }

  float nuevo_coef = t.coeficiente / (t.exponente+1);
  int nuevo_exp = t.exponente+1;

  agregar_termino(p, nuevo_coef, nuevo_exp);
}

struct Polinomio integrar_polinomio(struct Polinomio p){
  struct Polinomio integral = crear_polinomio(p.variable, 0);
  for (int i=0; i<p.num_terminos; i++){
    integrar_termino(p.terminos[i], &integral);
  }
  extern int tiene_constante; 
  tiene_constante = 1;
  return integral;
}

int main() {
  struct Polinomio p = crear_polinomio('x', 0);
  agregar_termino(&p, 8, 1);
  agregar_termino(&p, -4, 3);
  agregar_termino(&p, 10, 2);
  agregar_termino(&p, -2, 4);
  agregar_termino(&p, 1, 6);
  agregar_termino(&p, -1, 0);
  agregar_termino(&p, 0, 2);
  organizar_polinomio(&p);
  imprimir_polinomio(p);
  struct Polinomio d = derivar_polinomio(p);
  organizar_polinomio(&d);
  printf("Derivada:\n");
  imprimir_polinomio(d);
  struct Polinomio i = integrar_polinomio(p);
  organizar_polinomio(&i);
  printf("Integral:\n");
  imprimir_polinomio(i);

  return 0;
}
