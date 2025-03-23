#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **top, int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *top;
    *top = new_node;
}

void pop(Node **top) {
    if (*top == NULL)
        return;
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

// Printa do topo para a base, em uma única linha
void printStack(Node *top) {
    Node *current = top;
    int first = 1;
    while(current != NULL) {
        if(!first)
            printf(" ");
        printf("%d", current->value);
        first = 0;
        current = current->next;
    }
    printf("\n");
}

int main() {
    char line[100];
    Node *stack = NULL;

    // Lê comandos até encontrar a linha "Fim"
    while (fgets(line, sizeof(line), stdin)) {
        // remove o caractere de nova linha, se houver
        line[strcspn(line, "\n")] = '\0';

        if(strcmp(line, "Fim") == 0)
            break;

        //push
        if(strncmp(line, "Empilhar", 8) == 0) {
            int value;
            sscanf(line, "%*s %d", &value);
            push(&stack, value);
        }
        //pop
        else if(strncmp(line, "Desempilhar", 11) == 0) {
            pop(&stack);
        }

        printStack(stack);
    }

    //Liberação da memória
    while(stack != NULL)
        pop(&stack);

    return 0;
}

