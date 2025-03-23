#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

// Inicializa a fila
void initQueue(Queue *q) {
    q->head = q->tail = NULL;
}

// Insere um valor na fila (push)
void push(Queue *q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if(q->tail == NULL) { // fila vazia
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

//remove o valor mais antigo da fila (pop)
void pop(Queue *q) {
    if(q->head == NULL)
        return;
    Node* temp = q->head;
    q->head = q->head->next;
    if(q->head == NULL)
        q->tail = NULL;
    free(temp);
}

//imprime os elementos da fila na ordem de inserção
void printQueue(Queue *q) {
    Node* current = q->head;
    while(current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

//calcula e imprime a soma de todos os elementos da fila
void sumQueue(Queue *q) {
    int sum = 0;
    Node* current = q->head;
    while(current != NULL) {
        sum += current->value;
        current = current->next;
    }
    printf("%d\n", sum);
}

//libera os nós restantes da fila
void freeQueue(Queue *q) {
    while(q->head != NULL)
        pop(q);
}

int main(){
    Queue queue;
    initQueue(&queue);

    char line[256];
    while(fgets(line, sizeof(line), stdin)) {

        line[strcspn(line, "\n")] = '\0';

        if(strcmp(line, "exit") == 0)
            break;

        if(strncmp(line, "push", 4) == 0) {
            int num;
            sscanf(line, "push %d", &num);
            push(&queue, num);
        }
        else if(strcmp(line, "pop") == 0) {
            pop(&queue);
        }
        else if(strcmp(line, "print") == 0) {
            printQueue(&queue);
        }
        else if(strcmp(line, "sum") == 0) {
            sumQueue(&queue);
        }
    }

    freeQueue(&queue);
    return 0;
}

