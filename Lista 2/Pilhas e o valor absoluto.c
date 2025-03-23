#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    int current_min;
    int current_max;
    struct Node *next;
} Node;

Node *top = NULL;

// Função para empilhar
void push(int x) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = x;
    if (top == NULL) {
        new_node->current_min = x;
        new_node->current_max = x;
    } else {
        new_node->current_min = (x < top->current_min) ? x : top->current_min;
        new_node->current_max = (x > top->current_max) ? x : top->current_max;
    }
    new_node->next = top;
    top = new_node;
}

// Função para desempilhar; retorna o valor desempilhado
int pop() {
    Node *temp = top;
    int value = temp->value;
    top = top->next;
    free(temp);
    return value;
}

int absoluto() {
    return top->current_max - top->current_min;
}

int main() {
    char line[256];
    // Lê comandos até o fim da entrada
    while (fgets(line, sizeof(line), stdin)) {
        // Remove o caractere de nova linha, se houver
        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "push", 4) == 0) {
            int x;
            sscanf(line, "push %d", &x);
            push(x);
        } else if (strcmp(line, "pop") == 0) {
            int popped = pop();
            printf("%d\n", popped);
        } else if (strcmp(line, "abs") == 0) {
            int diff = absoluto();
            printf("%d\n", diff);
        }
    }

    while(top != NULL) {
        pop();
    }

    return 0;
}

