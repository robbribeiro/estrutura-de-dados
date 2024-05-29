#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y)
{
    // Verifica se a pilha está vazia
    if (p == NULL || p->prox == NULL)
    {
        return 0;
    }

    celula *lixo = p->prox; // cria um ponteiro para a célula a ser removida
    *y = lixo->dado;        // salva o elemento a ser removido em y
    p->prox = lixo->prox;   // remove a celula, apontando o ponteiro da célula anterior para a próxima célula
    free(lixo);

    return 1;
}
