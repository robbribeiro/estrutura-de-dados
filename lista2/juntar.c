#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    // declaração de ponteiros auxiliares
    celula *aux1 = l1->prox, *aux2 = l2->prox, *aux3 = l3;

    while (aux1 != NULL && aux2 != NULL)
    {
        if (aux1->dado < aux2->dado) // compara os dados dos nós de l1 e l2
        {

            aux3->prox = aux1; // se o dado de aux1 for menor, l3 aponta para aux1
            aux1 = aux1->prox; // aux1 avança para o próximo nó da lista 1
        }
        else
        {
            aux3->prox = aux2; // se o dado de aux2 for menor, l3 aponta para aux2
            aux2 = aux2->prox; // aux2 avança para o próximo nó da lista 2
        }
        aux3 = aux3->prox; // l3 avança para o próximo nó da lista 3
    }

    if (aux1 != NULL) // se ainda houver elementos na lista 1
    {
        aux3->prox = aux1; // l3 aponta para o restante da lista 1
    }
    else
    {
        aux3->prox = aux2; // l3 aponta para o restante da lista 2
    }
}

// void imprime(celula *le)
// {
//     for (celula *aux = le->prox; aux != NULL; aux = aux->prox)
//     {
//         printf("%d -> ", aux->dado);
//     }
//     printf("NULL\n");
// }

// int main()
// {
//     celula *l1 = malloc(sizeof(celula));
//     celula *l2 = malloc(sizeof(celula));
//     celula *l3 = malloc(sizeof(celula));
//     l3->prox = NULL;

//     l1->prox = malloc(sizeof(celula));
//     l1->prox->dado = 1;
//     l1->prox->prox = malloc(sizeof(celula));
//     l1->prox->prox->dado = 7;
//     l1->prox->prox->prox = malloc(sizeof(celula));
//     l1->prox->prox->prox->dado = 9;
//     l1->prox->prox->prox->prox = malloc(sizeof(celula));
//     l1->prox->prox->prox->prox->dado = 10;
//     l1->prox->prox->prox->prox->prox = NULL;

//     l2->prox = malloc(sizeof(celula));
//     l2->prox->dado = 2;
//     l2->prox->prox = malloc(sizeof(celula));
//     l2->prox->prox->dado = 3;
//     l2->prox->prox->prox = malloc(sizeof(celula));
//     l2->prox->prox->prox->dado = 8;
//     l2->prox->prox->prox->prox = NULL;

//     imprime(l1);
//     imprime(l2);

//     mescla_listas(l1, l2, l3);

//     imprime(l3);
// }