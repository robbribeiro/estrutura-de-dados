#include <stdio.h>

int main(int argc, char **argv) {
    // Imprime a quantidade de argumentos menos o nome do programa
    printf("%d\n", argc - 1);

    // Imprime os argumentos passados
    for(int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}

/*
Este programa em C recebe argumentos de linha de comando e os imprime.

A função main() recebe dois argumentos:
- argc: um inteiro que armazena a quantidade de argumentos informados pelo usuário, incluindo o nome do programa.
- argv: um vetor de ponteiros para char listando todos os argumentos.

O programa imprime a quantidade de argumentos informados (descontando o nome do programa) e, em seguida, imprime cada argumento em uma linha separada.

Por exemplo, se o programa for chamado como "./meu_programa alo mundo", a saída será:
2
alo
mundo
*/