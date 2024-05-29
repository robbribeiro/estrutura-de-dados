#include <stdlib.h>
#include <stdio.h>

typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;

int desempilha(pilha *p, int *y)
{
    if (p->topo == 0)
        return 0;

    p->topo--;

    *y = p->dados[p->topo];

    return 1;
}

// void inicializa_pilha(pilha *p, int N)
// {
//     p->dados = (int *)malloc(N * sizeof(int));
//     p->N = N;
//     p->topo = 0;
// }

// int empilha(pilha *p, int y)
// {
//     if (p->topo == p->N)
//         return 0;

//     p->dados[p->topo] = y;
//     p->topo++;

//     return 1;
// }

// int main()
// {
//     pilha p;
//     inicializa_pilha(&p, 10);

//     for (int i = 0; i < 10; i++)
//     {
//         empilha(&p, i);
//     }

//     int y;
//     while (desempilha(&p, &y))
//     {
//         printf("%d\n", y);
//     }

//     return 0;
// }