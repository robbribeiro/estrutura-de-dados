#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y)
{
    // verifica se a fila está vazia
    if (f->prox == NULL)
    {
        return 0;
    }

    // cria um ponteiro para a celula que será removida
    celula *lixo = f->prox;
    // armazena o valor da celula que será removida em y
    *y = lixo->dado;
    // atualiza o ponteiro da fila para a próxima celula
    f->prox = lixo->prox;
    free(lixo);

    return 1;
}

