#include <stdio.h>

// função que verifica se um vetor é uma progressão aritmética recursivamente
int pa_recursiva(int *v, int primeiro, int ultimo)
{

    // se o primeiro elemento for maior ou igual ao ultimo, retorna 1
    if (primeiro >= ultimo)
    {
        return 1;
    }

    // calcula a razão da progressão aritmética
    int razao = v[primeiro + 1] - v[primeiro];

    // se a soma do primeiro elemento com a razão for diferente do segundo elemento, retorna 0
    if (v[primeiro] + razao != v[primeiro + 1])
    {
        return 0;
    }

    int soma = v[primeiro] + v[ultimo];

    int soma2 = v[primeiro + 1] + v[ultimo - 1];

    // se a soma dos elementos do inicio e do fim do vetor forem diferentes, retorna 0
    if (soma != soma2)
    {
        return 0;
    }
    // chama a função recursivamente com o primeiro elemento incrementado e o ultimo decrementado
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}