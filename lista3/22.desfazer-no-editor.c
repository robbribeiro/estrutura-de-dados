#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack {
    int top;
    char* array[MAX_SIZE];
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, char* item) {
    stack->array[++stack->top] = item;
}

char* pop(Stack* stack) {
    if (stack->top == -1) {
        return "NULL";
    }
    return stack->array[stack->top--];
}

int main() {
    Stack* stack = createStack();
    char line[MAX_SIZE];

    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "inserir", 7) == 0) {
            char* change = strdup(line + 8);
            change[strcspn(change, "\n")] = 0;  // remove newline character
            push(stack, change);
        } else if (strcmp(line, "desfazer\n") == 0) {
            printf("%s\n", pop(stack));
        }
    }

    return 0;
}