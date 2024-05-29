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