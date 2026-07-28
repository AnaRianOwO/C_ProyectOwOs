#ifndef POLINOMIO_H
#define POLINOMIO_H

struct Termino {
  float coeficiente;
  int exponente;
};

struct Polinomio {
  char variable;
  struct Termino terminos[20];
  int num_terminos;
};

struct Termino crear_termino(float coef, int exp);
struct Polinomio crear_polinomio(char var, int num);
void agregar_termino(struct Polinomio *p, float coef, int exp);
void imprimir_polinomio(struct Polinomio p);
void comparar_e_intercambiar(struct Polinomio *p, int i);
void organizar_polinomio(struct Polinomio *p);
void derivar_termino(struct Termino t, struct Polinomio *p);
struct Polinomio derivar_polinomio(struct Polinomio p);
void integrar_termino(struct Termino t, struct Polinomio *p);
struct Polinomio integrar_polinomio(struct Polinomio p);
float evaluar_punto(struct Polinomio p, float x);
float derivar_en_punto(struct Polinomio p, float x);
struct Polinomio derivar_orden(struct Polinomio p, int n);
float integral_definida(struct Polinomio p, float a, float b);
#endif
