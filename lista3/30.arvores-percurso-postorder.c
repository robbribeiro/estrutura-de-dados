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