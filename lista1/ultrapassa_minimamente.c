#include <stdio.h>
#include <stdlib.h>

int main()
{
    int limite, soma = 0, i = 0, *v = NULL, *aux = NULL;
    int aux_size = 0;

    // le a sequencia de numeros ate encontrar um 0
    do
    {
        // aloca mais um espaco no vetor e le o valor
        v = realloc(v, (i + 1) * sizeof(int));

        scanf("%d", &v[i]);

    } while (v[i++] != 0);

    // le o limite
    scanf("%d", &limite);

    // processa a sequencia e coloca os valores que ultrapassam o limite no vetor auxiliar
    int j = 0;
    for (j = 0; j < i; j++)
    {
        // soma os valores da sequencia ate o momento 
        soma += v[j];

        // se a soma for maior que o limite, coloca no vetor auxiliar e zera a soma para o proximo valor da sequencia    
        if (soma > limite)
        {

            // aloca mais um espaco no vetor auxiliar e coloca o valor que ultrapassou o limite nele 
            aux = realloc(aux, (aux_size + 1) * sizeof(int));
            aux[aux_size++] = v[j];
            soma = 0;
        }
    }

    // imprime o vetor auxiliar
    for (int j = aux_size - 1; j >= 0; j--)
    {
        printf("%d\n", aux[j]);
    }

    // libera a memoria alocada para os vetores v e aux 
    free(v);
    free(aux);

    return 0;
}