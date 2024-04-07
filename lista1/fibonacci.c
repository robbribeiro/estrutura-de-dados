#include <stdio.h>

// função que calcula o n-ésimo número da sequência de Fibonacci
int fibonacci(int n)
{
    // se n for 2 ou 1, retorna 1 
    if (n == 2 || n == 1)
    {
        return 1;
    }
    
    // chama a função recursivamente com n - 1 e n - 2 e soma os resultados 
    return fibonacci(n - 1) + fibonacci(n - 2);
}

