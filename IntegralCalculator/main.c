#include <stdio.h>
#include "polinomio.h"
#include "parser.h"

int tiene_constante = 0;

int main() {
  
  /*char string[99] = "x^6 -2x^4 -4x^3 +10x^2 +8x -1";
  struct Polinomio p = parsear_polinomio(string);
  imprimir_polinomio(p);
  */
  // Para no confundirme después, cada agregar término va: puntero a polinomio, coeficiente, exponente

  
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
  /*
  float valor_ = integral_definida(p, 4, 5);
  printf("El valor de la integral en medio de los dos puntos es: %g\n", valor_);
  

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
