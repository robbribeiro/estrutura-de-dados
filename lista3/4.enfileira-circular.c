#include <stdlib.h>
#include <stdio.h>

typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    // verifica se a fila está cheia
    if (f->u + 1 % f->N == f->p)
    {
        // dobra o tamanho da fila
        f->N *= 2;
        // realoca dados para o novo tamanho da fila
        f->dados = realloc(f->dados, f->N * sizeof(int));
        // se não conseguir realocar, retorna 0
        if (f->dados == NULL)
        {
            return 0;
        }
    }

    // adiciona x no final da fila
    f->dados[f->u] = x;
    // incrementa u e faz o modulo N para que a fila seja circular
    f->u = (f->u + 1) % f->N;
    return 1;
}