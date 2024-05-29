#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int empilha(celula *p, int x)
{
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL)
        return 0;
    
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;

    return 1;
}

// int main()
// {
//     celula cabeca;
//     cabeca.prox = NULL;

//         empilha(&cabeca, 10);
//         empilha(&cabeca, 20);
//         empilha(&cabeca, 30);


//     celula *p = cabeca.prox;
//     while (p != NULL)
//     {
//         printf("%d\n", p->dado);
//         p = p->prox;
//     }

//     return 0;
// }