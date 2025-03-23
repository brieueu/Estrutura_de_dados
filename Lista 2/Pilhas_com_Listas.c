#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int *data;            // Vetor de inteiros armazenado neste nó
    int size;             // Quantos inteiros há no vetor
    struct Node *next;    // Próximo nó da pilha
} Node;

// PUSH: insere um novo item no topo da pilha
void push(Node **top, int arr[], int size) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->size = size;
    newNode->data = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        newNode->data[i] = arr[i];
    }
    newNode->next = *top;
    *top = newNode;
}

// POP: remove o item do topo da pilha e o imprime.
// Se a pilha estiver vazia, imprime "EMPTY STACK".
void pop(Node **top) {
    if (*top == NULL) {
        printf("EMPTY STACK\n");
        return;
    }
    Node *temp = *top;
    *top = (*top)->next;
    // Imprime os inteiros do nó removido
    for (int i = 0; i < temp->size; i++) {
        printf("%d", temp->data[i]);
        if (i < temp->size - 1)
            printf(" ");
    }
    printf("\n");
    free(temp->data);
    free(temp);
}

int main() {
    Node *stack = NULL;
    char command[10];
    char line[1000];

    // Lê os comandos até o fim da entrada
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "PUSH") == 0) {
            // Após ler o comando PUSH, a próxima linha contém os inteiros.
            // Consome o restante da linha atual.
            fgets(line, sizeof(line), stdin);
            // Lê a linha com os inteiros (caso tenha sido consumido somente o '\n')
            if (line[0] == '\n')
                fgets(line, sizeof(line), stdin);
            // Separa os inteiros lidos
            int arr[1000];
            int count = 0;
            char *token = strtok(line, " \n");
            while (token != NULL) {
                arr[count++] = atoi(token);
                token = strtok(NULL, " \n");
            }
            push(&stack, arr, count);
        }
        else if (strcmp(command, "POP") == 0) {
            pop(&stack);
        }
    }

    // Opcionalmente, liberar nós remanescentes, se houver
    while (stack != NULL) {
        pop(&stack);
    }

    return 0;
}
