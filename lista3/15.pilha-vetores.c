#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;

void empilha(pilha *p, int x)
{
    if (p->topo == p->N)
    {
        p->N *= 2;
        p->dados = realloc(p->dados, p->N * sizeof(int));
        if (p->dados == NULL)
            return 0;
    }

    p->dados[p->topo] = x;
    p->topo++;

    return 1;
}

int desempilha(pilha *p, int *y)
{
    if (p->topo == 0)
        return 0;

    p->topo--;

    *y = p->dados[p->topo];

    return 1;
}
