#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    for (celula *aux = le->prox; aux != NULL; aux = aux->prox)
    {
        printf("%d -> ", aux->dado);
    }
    printf("NULL\n");
}

void imprime_rec(celula *le)
{
    if (le->prox == NULL)
    {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->prox->dado);

    imprime_rec(le->prox);
}

// int main()
// {
//     celula *le = malloc(sizeof(celula));

    // // cria a lista le -> 10 -> 4 -> -9 -> 2 -> 7 -> 10 -> NULL
    // le->prox = malloc(sizeof(celula));
    // le->prox->dado = 10;
    // le->prox->prox = malloc(sizeof(celula));
    // le->prox->prox->dado = 4;
    // le->prox->prox->prox = malloc(sizeof(celula));
    // le->prox->prox->prox->dado = -9;
    // le->prox->prox->prox->prox = malloc(sizeof(celula));
    // le->prox->prox->prox->prox->dado = 2;
    // le->prox->prox->prox->prox->prox = malloc(sizeof(celula));
    // le->prox->prox->prox->prox->prox->dado = 7;
    // le->prox->prox->prox->prox->prox->prox = malloc(sizeof(celula));
    // le->prox->prox->prox->prox->prox->prox->dado = 10;
    // le->prox->prox->prox->prox->prox->prox->prox = NULL;

//     imprime(le);
//     imprime_rec(le);
// }