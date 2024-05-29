#include <stdlib.h>
#include <stdio.h>

typedef struct fila
{
    int *dado;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    // verifica se a fila está cheia
    if (f->u == f->N)
    {
        // dobra o tamanho da fila
        f->N *= 2;
        // realoca o ponteiro dado para o novo tamanho da fila
        f->dado = realloc(f->dado, f->N * sizeof(int));
        // se não conseguir realocar, retorna 0
        if (f->dado == NULL)
        {
            return 0;
        }
    }
    // insere o elemento x no final da fila
    f->dado[f->u] = x;
    // incrementa o ponteiro u para o próximo elemento
    f->u++;
    return 1;
}