#include <stdio.h>

//função que troca o valor de duas variáveis
void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

