#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x)
{
    // aloca memória para a nova celula auxiliar
    celula *novo = malloc(sizeof(celula));
    // verifica se a alocação de memória foi bem sucedida
    if (novo == NULL)
        return NULL;

    // preenche a nova celula auxiliar com o valor x
    novo->dado = x;

    // verifica se a fila está vazia e insere o novo elemento no início
    if (f == NULL)
    {
        // se a fila é circular, então o próximo elemento da nova celula é ela mesma
        novo->prox = novo;
        f = novo;
    }
    else
    {
        celula *aux = f;
        // percorre a fila até o último elemento que aponte para o primeiro
        while (aux->prox != f)
            aux = aux->prox;
        // insere o novo elemento no final da fila
        aux->prox = novo;
        // novo elemento aponta para o primeiro elemento da fila
        novo->prox = f;
    }

    // retorna o ponteiro para a fila atualizada
    return f;
}

// teste da função enfileira de lista encadeada
int main()
{
    celula *f = NULL;

    f = enfileira(f, 1);
    f = enfileira(f, 2);
    f = enfileira(f, 3);
    f = enfileira(f, 4);

    celula *aux = f;
    // percorre o vetor duas vezes para verificar se a fila é circular
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }

    return 0;
}