#include <stdlib.h>
#include <stdio.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y)
{
    // fila vazia retorna 0
    if (f->p == f->u)
    {
        return 0;
    }
    // atribui a y o valor do primeiro elemento da fila
    *y = f->dados[f->p];

    // incrementa o ponteiro p para o próximo elemento
    f->p++;
    return 1;
}
