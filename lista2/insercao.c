#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) // insere no início da lista 
{
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes(celula *le, int x, int y)
{
    celula *novo = malloc(sizeof(celula));

    novo->dado = x;

    // enquanto o próximo nó não for NULL e o próximo nó não for igual a y vai para o próximo nó
    while (le->prox != NULL && le->prox->dado != y)
    {
        le = le->prox;
    }

    
    novo->prox = le->prox; // aponta para o nó novo->prox para o nó igual a y ou NULL se y não foi encontrado
    le->prox = novo; // aponta o nó le->prox para o nó novo
}

void imprime(celula *le)
{
    for (celula *aux = le->prox; aux != NULL; aux = aux->prox)
    {
        printf("%d -> ", aux->dado);
    }
    printf("NULL\n");
}

// int main()
// {
//     celula *le = malloc(sizeof(celula));
//     le->prox = NULL;

//     insere_inicio(le, 5);
//     insere_inicio(le, 10);
//     insere_inicio(le, 15);

//     imprime(le);

//     insere_antes(le, 20, 10);
//     insere_antes(le, 25, 100);

//     imprime(le);

//     return 0;
// }