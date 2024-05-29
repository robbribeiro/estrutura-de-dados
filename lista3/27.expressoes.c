#include <stdio.h>

int main()
{
    int topo, verifica, n;
    char aux[100000], cadeia[100000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        verifica = 0;
        topo = -1;
        scanf("%s", &cadeia);

        for (int j = 0; cadeia[j] != '\0'; j++)
        {
            if (cadeia[j] == '{' || cadeia[j] == '[' || cadeia[j] == '(')
            {
                topo++;
                aux[topo] = cadeia[j];
            }
            else
            {

                if (topo == -1)
                    verifica = 1;

                if (aux[topo] == '{' && cadeia[j] == '}' ||
                    aux[topo] == '[' && cadeia[j] == ']' ||
                    aux[topo] == '(' && cadeia[j] == ')')
                {
                    topo--;
                }
                else
                {
                    verifica = 1;
                }
            }
        }

        if (topo == -1 && verifica == 0)
            printf("S\n");
        else
            printf("N\n");
    }

    return (0);
}