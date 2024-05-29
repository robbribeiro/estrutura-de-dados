#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int N, inicio, fim;
} fila;

void inicializa_fila(fila *f, int N)
{
    f->dados = malloc(N * sizeof(int));
    f->N = N;
    f->inicio = 0;
    f->fim = 0;
}

void insere_fila(fila *f, int x)
{
    f->dados[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
}

int remove_fila(fila *f)
{
    int x = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return x;
}

int main()
{
    int n;
    scanf("%d", &n);
    fila f;
    inicializa_fila(&f, n);
    for (int i = 1; i <= n; i++)
    {
        insere_fila(&f, i);
    }
    printf("Cartas descartadas:");
    while (f.inicio != f.fim - 1)
    {
        int descartada = remove_fila(&f);
        insere_fila(&f, remove_fila(&f));
        if (f.inicio != f.fim - 1)
            printf(" %d,", descartada);
        else
            printf(" %d", descartada);
    }
    printf("\nCarta restante: %d\n", remove_fila(&f));
    free(f.dados);
    return 0;
}

// 1-2-3-4-5-6
// 3-4-5-6-2
// 5-6-2-4
// 2-4-6
// 6-4
// 4   (inicio == fim)
