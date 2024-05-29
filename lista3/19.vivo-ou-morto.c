#include <stdio.h>
#include <stdlib.h>

int nTest = 1, p, r, rest, ordem;

int main()
{
    while (~scanf("%d%d", &p, &r))
    {
        int *partic = (int *)calloc(p, sizeof(int));
        if (!p && !r)
            break;
        for (int i = 0; i < p; i++)
        {
            scanf("%d", &partic[i]);
        }
        while (r-- > 0)
        {
            scanf("%d%d", &rest, &ordem);
            int *aux = (int *)calloc(rest, sizeof(int));
            for (int i = 0, j = 0; i < rest; i++)
            {
                int nCmd;
                scanf("%d", &nCmd);
                if (nCmd == ordem)
                {
                    aux[j++] = partic[i];
                }
            }
            for (int i = 0; i < rest; i++)
                partic[i] = aux[i];
            free(aux);
        }
        printf("Teste %d\n%d\n", nTest++, partic[0]);
        free(partic);
    }
    return 0;
}
