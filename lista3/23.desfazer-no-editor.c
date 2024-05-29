#include <stdio.h>
#include <string.h>

int main()
{
    int n, topo;
    scanf("%d", &n);
    char aux[100];
    topo = -1;
    while(n > 0)
    {
            char str[100];
            scanf("%s", str);

            for(int i=0; str[i] != '\0'; i++)
            {
                if(aux[topo] == str[i])
                {
                }

                if(str[i] == '*' || str[i] == '/' || str[i] == '_')
                {
                    topo++;
                    aux[topo] = str[i];
                }
               
            }

        n--;
    }
}