#include <stdio.h>

void regua(int n)
{
    if (n > 0)
    {
        // chama a função recursivamente com n-1 e imprime .- e - n vezes
        regua(n - 1);

        printf(".");

        // imprime - n vezes para formar a régua
        for (int i = 0; i < n; i++)
        {
            printf("-");
        }

        printf("\n");

        // chama a função novamente para imprimir a parte de baixo da régua
        regua(n - 1);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    regua(n);

    return 0;
}
