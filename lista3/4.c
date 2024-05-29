#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira (fila *f, int x) {
    if ((f->u + 1) % f->N == f->p) {
        int *new_data = (int *) realloc(f->dados, 2 * f->N * sizeof(int));
        if (new_data == NULL) {
            return 0;
        }
        f->dados = new_data;
        if (f->p > f->u) {
            int i;
            for (i = 0; i < f->p; i++) {
                f->dados[i + f->N] = f->dados[i];
            }
            f->u += f->N;
        }
        f->N *= 2;
    }
    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}