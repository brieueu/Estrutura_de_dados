#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int *data;
    int size;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int *nums, int size) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->size = size;
    node->data = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        node->data[i] = nums[i];
    }
    node->next = top;
    top = node;
}

void pop() {
    if (top == NULL) {
        printf("EMPTY STACK\n");
        return;
    }
    Node *node = top;
    top = top->next;
    for (int i = 0; i < node->size; i++) {
        printf("%d", node->data[i]);
        if (i != node->size - 1)
            printf(" ");
    }
    printf("\n");
    free(node->data);
    free(node);
}

int main() {
    char command[10];
    // Para ler linhas de números após o comando PUSH
    char line[1000];
    int nums[1000];
    
    printf("Digite os comandos (PUSH ou POP) e os números a serem inseridos na pilha:\n");
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "PUSH") == 0) {
            // Lê a linha com os inteiros
            // Consome o '\n' residual se necessário
            fgets(line, sizeof(line), stdin);
            // Se a linha estiver vazia, tenta novamente
            if (strlen(line) <= 1)
                fgets(line, sizeof(line), stdin);
            
            int size = 0;
            char *token = strtok(line, " \n");
            while (token != NULL) {
                nums[size++] = atoi(token);
                token = strtok(NULL, " \n");
            }
            push(nums, size);
        } else if (strcmp(command, "POP") == 0) {
            pop();
        }
    }
    
    return 0;
}
