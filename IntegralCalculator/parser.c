#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "parser.h"
#include "polinomio.h"

struct Polinomio parsear_polinomio(const char *entrada) {
    char* string = "x^6 -2x^4 -4x^3 +10x^2 +8x -1";
    printf("%s", string);
    printf("%s", entrada);
    return crear_polinomio('x', 0);
}

char* entrada = "hola";
parsear_polinomio(const entrada);
