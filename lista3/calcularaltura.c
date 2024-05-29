#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Função para criar um novo nó
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        // Calcula a altura de cada subárvore
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Retorna a maior altura
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


