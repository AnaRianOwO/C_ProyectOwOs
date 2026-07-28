#include <stdio.h>
#include "polinomio.h"

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

float evaluar_punto(struct Polinomio p, float x){
  float valor = 0;
  for (int i=0; i<p.num_terminos; i++){
    float potencia = 1;
    for (int j=0; j<p.terminos[i].exponente;j++){
      potencia*=x;
    }
    valor+= p.terminos[i].coeficiente*(potencia);
  }
  return valor;
}

float derivar_en_punto(struct Polinomio p, float x){
  struct Polinomio derivada = derivar_polinomio(p);
  return evaluar_punto(derivada, x);
}

struct Polinomio derivar_orden(struct Polinomio p, int n){
  struct Polinomio resultado = p;

  if (n==0){
    return p;
  }

  for(int i=0; i<n; i++){
    resultado = derivar_polinomio(resultado);
  }
  return resultado;
}

float integral_definida(struct Polinomio p, float a, float b){
  struct Polinomio integral = integrar_polinomio(p);
  return evaluar_punto(integral, b) - evaluar_punto(integral, a);
}
