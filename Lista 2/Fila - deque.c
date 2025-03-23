#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct deque {
    ITEM vet[TAM];
    int front, rear;
} TDeque;

void create(TDeque *d) {
    d->rear = 0;
}

void destroy(TDeque *d) {
    //não há alocação dinâmica
}

int isfull(TDeque *d) {
    return (d->rear == TAM);
}

int isempty(TDeque *d) {
    return (d->rear == 0);
}

void store(TDeque *d, int extremidade, ITEM x) {
    if (isfull(d))
        return;

    if (extremidade == 1) {
        //Inserir no início
        for (int i = d->rear; i > 0; i--) {
            d->vet[i] = d->vet[i - 1];
        }
        //novo item na posição 0
        d->vet[0] = x;
        d->rear++;
    } else if (extremidade == 2) {
        //inserir no fim
        d->vet[d->rear] = x;
        //incrementa o índice rear.
        d->rear++;
    }
}

ITEM retrieve(TDeque *d, int extremidade) {
    ITEM ret;
    if (isempty(d))
        return '\0';

    if (extremidade == 1) {
        ret = d->vet[0];
        //desloca os elementos para a esquerda, sobrescrevendo a posição 0
        for (int i = 0; i < d->rear - 1; i++) {
            d->vet[i] = d->vet[i + 1];
        }
        //decrementa o índice rear, pois removeu um item.
        d->rear--;
        return ret;
    } else if (extremidade == 2) {
        d->rear--;
        ret = d->vet[d->rear];
        return ret;
    }
    return '\0';
}

void preenche(TDeque *d) {
    ITEM x;
    int qtd, extremidade, i;

    scanf("%d%*c", &qtd);

    for( i=0; i<qtd; i++ ) {
        scanf("%c %d%*c", &x, &extremidade);
        store(d, extremidade, x);
    }
}

void exibe(TDeque *d) {
    int extremidade;

    while( scanf("%d", &extremidade) != EOF ) {
        if( extremidade==1 )
            printf("INICIO = %c\n", retrieve(d, extremidade));
        else
            printf("FIM = %c\n", retrieve(d, extremidade));
    }
}

int main(void) {
    TDeque d;

    create(&d);
    preenche(&d);
    exibe(&d);
    destroy(&d);

    return 0;
}

