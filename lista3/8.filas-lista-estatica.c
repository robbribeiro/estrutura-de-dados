#include <stdlib.h>

typedef struct {
    int *v; // Array representing the queue
    int N; // Size of the queue
    int inicio, fim; // Indicators of the beginning and end of the queue
} fila;

int enfileira (fila *f, int x) {
    if ((f->fim + 1) % f->N == f->inicio) {
        // The queue is full
        return 0;
    }
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    return 1;
}

int desenfileira (fila *f, int *y) {
    if (f->inicio == f->fim) {
        // The queue is empty
        return 0;
    }
    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return 1;
}