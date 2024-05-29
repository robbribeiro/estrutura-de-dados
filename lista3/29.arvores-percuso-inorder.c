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
