#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "parser.h"
#include "polinomio.h"

void limpiar_espacios(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    printf("%s", str);
}

struct Polinomio parsear_polinomio(char *entrada) {
  limpiar_espacios(entrada);
  return crear_polinomio('x', 0);
}


