#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int id;
    int valor;
    int prox;
    struct celula *proximo;
} celula;

celula *nova_celula(int id, int valor, int prox)
{
    celula *nova = malloc(sizeof(celula));
    nova->id = id;
    nova->valor = valor;
    nova->prox = prox;
    nova->proximo = NULL;
    return nova;
}

void adicionar_celula(celula *cabeca, int id, int valor, int prox)
{
    celula *atual = cabeca;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = nova_celula(id, valor, prox);
}

celula *encontrar_celula(celula *cabeca, int id)
{
    celula *atual = cabeca;
    while (atual != NULL)
    {
        if (atual->id == id)
        {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

int main()
{
    int n, id, valor, prox;

    scanf("%d", &n);

    scanf("%d %d %d", &id, &valor, &prox);
    celula *cabeca = nova_celula(id, valor, prox);

    for (int i = 1; i < n; i++)
    {
        scanf("%d %d %d", &id, &valor, &prox);
        adicionar_celula(cabeca, id, valor, prox);
    }

    celula *atual = cabeca;
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        atual = encontrar_celula(cabeca, atual->prox);
    }

    return 0;
}