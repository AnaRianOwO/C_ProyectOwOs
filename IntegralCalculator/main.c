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

int main() {
  struct Polinomio p = crear_polinomio('x', 0);
  // Para no confundirme después, cada agregar término va: puntero a polinomio, coeficiente, exponente
  agregar_termino(&p, 8, 1);
  agregar_termino(&p, -4, 3);
  agregar_termino(&p, 10, 2);
  agregar_termino(&p, -2, 4);
  agregar_termino(&p, 1, 6);
  agregar_termino(&p, -1, 0);
  agregar_termino(&p, 0, 2);
  
  organizar_polinomio(&p);
  imprimir_polinomio(p);

  /*
  float valor = integral_definida(p, 4, 5);
  printf("El valor de la integral en medio de los dos puntos es: %g\n", valor);
  

  struct Polinomio o = derivar_orden(p, 2);
  printf("El polinomio a dicho orden es:");
  imprimir_polinomio(o);

  float valor = derivar_en_punto(p,2);
  printf("El valor de la derivada en el punto es de %g", valor);
  
  struct Polinomio d = derivar_polinomio(p);
  organizar_polinomio(&d);
  printf("Derivada:\n");
  imprimir_polinomio(d);
  struct Polinomio i = integrar_polinomio(p);
  organizar_polinomio(&i);
  printf("Integral:\n");
  imprimir_polinomio(i);
  */
  
  return 0;
}
