#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 1000

typedef struct {
    int id;
    int idade;
} Person;

//fila simples com array
typedef struct {
    Person arr[MAX_QUEUE];
    int front;
    int rear;
} Queue;

//inicializa aa fila
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

//retorna 1 se a fila estiver vazia, 0 caso contrário.
int isEmpty(Queue *q) {
    return (q->front == q->rear);
}

//insere (enqueue) uma pessoa na fila.
void enqueue(Queue *q, int id, int idade) {
    // Aqui assumimos que o número de operações não ultrapassa MAX_QUEUE.
    q->arr[q->rear].id = id;
    q->arr[q->rear].idade = idade;
    q->rear++;
}

//se a fila estiver vazia, retorna uma pessoa
Person dequeue(Queue *q) {
    Person p;
    if(isEmpty(q)) {
        p.id = -1;
        p.idade = -1;
        return p;
    }
    p = q->arr[q->front];
    q->front++;
    return p;
}

//se a fila estiver vazia, imprime "fila vazia!".
void printQueue(Queue *q) {
    if(isEmpty(q)) {
        printf("fila vazia!\n");
        return;
    }
    for(int i = q->front; i < q->rear; i++) {
        printf("ID: %d IDADE: %d\n", q->arr[i].id, q->arr[i].idade);
    }
}

int main(void) {
    int n;
    char op;
    int countElderly = 0;

    //duas filas: uma para idosos e outra para não-idosos.
    Queue filaIdosos, filaNaoIdosos;
    initQueue(&filaIdosos);
    initQueue(&filaNaoIdosos);

    scanf("%d", &n);
    getchar();

    while(1) {
        if(scanf(" %c", &op) == EOF)
            break;

        if(op == 'a') { //add pessoa
            int id, idade;
            scanf("%d %d", &id, &idade);
            getchar();
            if(idade > 60)
                enqueue(&filaIdosos, id, idade);
            else
                enqueue(&filaNaoIdosos, id, idade);
        }
        else if(op == 'r') { //remover pessoa
            if(isEmpty(&filaIdosos) && isEmpty(&filaNaoIdosos))
                continue;
            if(isEmpty(&filaIdosos) && !isEmpty(&filaNaoIdosos)) {
                dequeue(&filaNaoIdosos);
                countElderly = 0;
            }
            else if(isEmpty(&filaNaoIdosos) && !isEmpty(&filaIdosos)) {
                dequeue(&filaIdosos);
                countElderly = 0;
            }
            else {
                if(countElderly == n) {
                    dequeue(&filaNaoIdosos);
                    countElderly = 0;
                }
                else {
                    dequeue(&filaIdosos);
                    countElderly++;
                }
            }
        }
        else if(op == 'i') { //print filas
            printf("fila de idosos:\n");
            printQueue(&filaIdosos);
            printf("fila de nao-idosos:\n");
            printQueue(&filaNaoIdosos);
            printf("----------\n\n");
        }
        else if(op == 'f') {
            break;
        }
    }
    return 0;
}

