#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void divide_lista(celula *l, celula *l1, celula *l2)
{
    celula *p1 = l1, *p2 = l2;
    l = l->prox; // pula o nó cabeça de l para o proximo nó

    while (l != NULL)
    {
        if (l->dado % 2 != 0) // se o dado for ímpar
        {
            p1->prox = l;  // adiciona a p1
            p1 = p1->prox; // move p1 para o próximo nó
        }
        else
        {                  // se o dado for par
            p2->prox = l;  // adiciona a l2
            p2 = p2->prox; // move p2 para o próximo nó
        }
        l = l->prox; // move para o próximo nó em l
    }

    p1->prox = NULL; // termina l1
    p2->prox = NULL; // termina l2
}

// int main()
// {
//     celula *l = malloc(sizeof(celula));
//     celula *l1 = malloc(sizeof(celula));
//     celula *l2 = malloc(sizeof(celula));

// // cria a lista l -> 10 -> 4 -> -9 -> 2 -> 7 -> 10 -> NULL
// l->prox = malloc(sizeof(celula));
// l->prox->dado = 10;
// l->prox->prox = malloc(sizeof(celula));
// l->prox->prox->dado = 4;
// l->prox->prox->prox = malloc(sizeof(celula));
// l->prox->prox->prox->dado = -9;
// l->prox->prox->prox->prox = malloc(sizeof(celula));
// l->prox->prox->prox->prox->dado = 2;
// l->prox->prox->prox->prox->prox = malloc(sizeof(celula));
// l->prox->prox->prox->prox->prox->dado = 7;
// l->prox->prox->prox->prox->prox->prox = malloc(sizeof(celula));
// l->prox->prox->prox->prox->prox->prox->dado = 10;
// l->prox->prox->prox->prox->prox->prox->prox = NULL;

//     divide_lista(l, l1, l2);

//     // print de l1 e l2
//     printf("l1: ");
//     for (celula *p = l1->prox; p != NULL; p = p->prox)
//         printf("%d ", p->dado);
//     printf("\n");

//     printf("l2: ");
//     for (celula *p = l2->prox; p != NULL; p = p->prox)
//         printf("%d ", p->dado);
//     printf("\n");

//     return 0;
// }