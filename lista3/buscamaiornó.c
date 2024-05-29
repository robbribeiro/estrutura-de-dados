#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Função para encontrar o maior valor na árvore
int acharmax(struct Node* no) {
    if (no == NULL)
        return 0;

    // Busca o valor máximo indo para a direita o máximo possível
    while (no->right != NULL) {
        no = no->right;
    }

    return (no->data);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    printf("O maior valor na árvore é %d", findMax(root));

    return 0;
}