#include <stdio.h>

int suma(int a, int b){
  return a+b;
}

int resta(int a, int b){
  return a-b;
}

float division(float a, float b){
  return a/b;
}

int multiplicacion(int a, int b){
  return a*b;
}

int main() {
  printf("¡Hola, bestie! Esta calculadora será épica uwu\n");
  int x, y;
  scanf("%d\n", &x);
  scanf("%d", &y);

  int resultado = suma(x, y);
  printf("La suma es:%d\n", resultado);
  resultado = resta(x,y);
  printf("La resta es:%d\n", resultado);
  float resul = division(x,y);
  printf("La división es:%f\n", resul);
  resultado = multiplicacion(x,y);
  printf("La multiplicación es:%d\n", resultado);

  return 0;
}
