#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p)
{
    if (p == NULL || p->prox == NULL)
        return -1;

    celula *lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);

    return 0;
}

void remove_elemento(celula *le, int x)
{
    celula *aux = le;
    while (aux != NULL && aux->prox != NULL)
    {
        if (aux->prox->dado == x)
        {
            celula *lixo = aux->prox;
            aux->prox = lixo->prox;
            free(lixo);
            break;
        }
        aux = aux->prox;
    }
}

void remove_todos_elementos(celula *le, int x)
{
    celula *aux = le;
    while (aux != NULL && aux->prox != NULL)
    {
        if (aux->prox->dado == x)
        {
            celula *lixo = aux->prox;
            aux->prox = lixo->prox;
            free(lixo);
        }
        else
        {
            aux = aux->prox;
        }
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

// // Function to add an element at the end of the list
// void add_element(celula *le, int x)
// {
//     celula *p = le;
//     while (p->prox != NULL)
//     {
//         p = p->prox;
//     }

//     celula *new_celula = malloc(sizeof(celula));
//     new_celula->dado = x;
//     new_celula->prox = NULL;
//     p->prox = new_celula;
// }

// int main()
// {
//     celula *le = malloc(sizeof(celula));
//     le->prox = NULL;

//     // Add some elements to the list
//     add_element(le, 1);
//     add_element(le, 2);
//     add_element(le, 3);
//     add_element(le, 2);
//     add_element(le, 4);
//     add_element(le, 2);
//     add_element(le, 5);

//     imprime(le); // Output: 1 2 3 2 4 2 5

//     // Test the remove_depois function
//     remove_depois(le);
//     imprime(le); // Output: 2 3 2 4 2 5

//     // Test the remove_elemento function
//     remove_elemento(le, 2);
//     imprime(le); // Output: 3 2 4 2 5

//     // Test the remove_todos_elementos function
//     remove_todos_elementos(le, 2);
//     imprime(le); // Output: 3 4 5

//     return 0;
// }
