#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    // Verifica se a fila está vazia
    if (f->p == f->u) {
        return 0;
    }

    // Salva o elemento a ser removido em y
    *y = f->dados[f->p];

    // Incrementa p, considerando a fila circular (módulo N) 
    f->p = (f->p + 1) % f->N;

    return 1;
}