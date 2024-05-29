#include <stdio.h>

int main()
{
    int circulos, tiros, acertos = 0;

    scanf("%d %d", &circulos, &tiros);

    int raios[circulos];
    for (int i = 0; i < circulos; i++)
    {
        scanf("%d", &raios[i]);
    }

    for (int i = 0; i < tiros; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        for (int j = 1; j <= circulos; j++)
        {
            if(x <= raios[j] && y <= raios[j])
            {
                acertos += j;
            }
 
        }
    }
    printf("%d\n", acertos);
}