#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct stack
{
    no *data;
    struct stack *next;
} stack;

stack *newStackNode(no *node)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = node;
    s->next = NULL;
    return s;
}

int isEmpty(stack *root)
{
    return !root;
}

void push(stack **root, no *node)
{
    stack *s = newStackNode(node);
    s->next = *root;
    *root = s;
}

no *pop(stack **root)
{
    if (isEmpty(*root))
        return NULL;
    stack *temp = *root;
    *root = (*root)->next;
    no *popped = temp->data;
    free(temp);
    return popped;
}

void pre_ordem(no *raiz)
{
    if (raiz == NULL)
        return;

    stack *s = newStackNode(raiz);

    while (!isEmpty(s))
    {
        no *node = s->data;
        s = s->next;

        printf("%d ", node->dado);

        if (node->dir)
        {
            stack *temp = newStackNode(node->dir);
            temp->next = s;
            s = temp;
        }
        if (node->esq)
        {
            stack *temp = newStackNode(node->esq);
            temp->next = s;
            s = temp;
        }
    }
}

void pos_ordem(no *raiz)
{
    if (raiz == NULL)
        return;

    stack *s1 = newStackNode(raiz);
    stack *s2 = NULL;

    while (!isEmpty(s1))
    {
        no *node = s1->data;
        s1 = s1->next;

        stack *temp = newStackNode(node);
        temp->next = s2;
        s2 = temp;

        if (node->esq)
        {
            temp = newStackNode(node->esq);
            temp->next = s1;
            s1 = temp;
        }
        if (node->dir)
        {
            temp = newStackNode(node->dir);
            temp->next = s1;
            s1 = temp;
        }
    }

    while (!isEmpty(s2))
    {
        printf("%d ", s2->data->dado);
        s2 = s2->next;
    }
}

void em_ordem(no *raiz)
{
    stack *s = NULL;
    no *curr = raiz;

    while (curr != NULL || !isEmpty(s))
    {
        while (curr != NULL)
        {
            push(&s, curr);
            curr = curr->esq;
        }
        curr = pop(&s);
        printf("%d ", curr->dado);
        curr = curr->dir;
    }
}

no *novoNo(int dado)
{
    no *node = (no *)malloc(sizeof(no));
    node->dado = dado;
    node->esq = node->dir = NULL;
    return (node);
}

no *inserir(no *node, int dado)
{
    if (node == NULL)
        return novoNo(dado);
    if (dado < node->dado)
        node->esq = inserir(node->esq, dado);
    else if (dado > node->dado)
        node->dir = inserir(node->dir, dado);
    return node;
}

void preOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

int main()
{
    no *raiz = NULL;
    int num;
    while (scanf("%d", &num) != EOF)
    {
        raiz = inserir(raiz, num);
    }
    preOrdem(raiz);
    printf(".\n");
    emOrdem(raiz);
    printf(".\n");
    posOrdem(raiz);
    printf(".\n");
    return 0;
}
