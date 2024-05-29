#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int items[1000];
} stack;

void push(stack *s, int item)
{
    s->items[++(s->top)] = item;
}

int pop(stack *s)
{
    return s->items[(s->top)--];
}

int main()
{
    int n, i, curr;
    stack s;
    while (scanf("%d", &n), n)
    {
        int a[n];
        s.top = -1;
        curr = 1;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n; i++)
        {
            if (a[i] == curr)
            {
                curr++;
                while (s.top != -1 && s.items[s.top] == curr)
                {
                    pop(&s);
                    curr++;
                }
            }
            else
            {
                push(&s, a[i]);
            }
        }
        if (s.top == -1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}