#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y)
{
    if (f->prox == NULL)
    {
        return 0;
    }

    celula *lixo = f->prox;
    *y = lixo->dado;
    f->prox = lixo->prox;
    free(lixo);

    return 1;
}

void enfileira(celula **f, int x)
{
    celula *novo = malloc(sizeof(celula));

    novo->dado = x;

    if (*f == NULL)
    {
        novo->prox = novo;
        *f = novo;
    }
    else
    {
        celula *aux = *f;
        while (aux->prox != *f)
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *f;
    }
}

int main()
{
    celula *f = NULL;

    enfileira(&f, 1);
    enfileira(&f, 2);
    enfileira(&f, 3);
    enfileira(&f, 4);

    int removedValue;
    for (int i = 0; i < 1; i++)
    {
        if (desenfileira(f, &removedValue))
        {
            printf("Removed value: %d\n", removedValue);
        }
        else
        {
            printf("Queue is empty\n");
        }
    }

    celula *aux = f;
    for (int i = 0; i < 8; i++)
    {
        
        printf("Value: %d\n", aux->dado);
        aux = aux->prox;
    }

    return 0;
}
