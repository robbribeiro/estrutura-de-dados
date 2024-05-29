#include <stdio.h>

int main()
{
    int D[61], E[61];
    int i, M, r;
    char L;

    r = 0;

    for (i = 0; i < 61; i++)
    {
        D[i] = 0;
        E[i] = 0;
    }

    while (scanf("%d %c", &M, &L) != EOF)
    {
        if (L == 'E')
        {
            E[M]++;
        }
        else
        {
            D[M]++;
        }
        if (E[M] && D[M])
        {
            E[M]--;
            D[M]--;
            r++;
        }
    }
    printf("%d\n", r);
    return 0;
}