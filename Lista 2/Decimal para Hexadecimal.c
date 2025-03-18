#include <stdio.h>
#include <stdlib.h>

//Definição da pilha
typedef struct {
    int topo;
    int capacidade;
    char *dados;
} TPilha;

//cria uma pilha com capacidade definida
TPilha* criaPilha(int capacidade) {
    TPilha* p = (TPilha*) malloc(sizeof(TPilha));
    p->topo = -1;  // indica pilha vazia
    p->capacidade = capacidade;
    p->dados = (char*) malloc(capacidade * sizeof(char));
    return p;
}

//insere um elemento na pilha
void push(TPilha* p, char c) {
    if (p->topo < p->capacidade - 1) {
        p->dados[++(p->topo)] = c;
    }
}

//remove e retorna o elemento do topo da pilha
char pop(TPilha* p) {
    if (p->topo >= 0) {
        return p->dados[(p->topo)--];
    }
    return '\0';
}

//liberar memoria
void destroiPilha(TPilha* p) {
    free(p->dados);
    free(p);
}

// Função que converte o número n para uma string com seu valor hexadecimal e usa pilha para armazenar digitos
char *hexadecimal(int n) {
    if (n == 0) {
        char *resultado = (char*) malloc(2 * sizeof(char));
        resultado[0] = '0';
        resultado[1] = '\0';
        return resultado;
    }

    TPilha* p = criaPilha(20);

    // Converte para hexadecimal (obtém os dígitos de trás para frente e os empilha)
    while (n > 0) {
        int resto = n % 16;
        char digito;
        if (resto < 10)
            digito = '0' + resto;
        else
            digito = 'A' + (resto - 10);
        push(p, digito);
        n /= 16;
    }

    int numDigitos = p->topo + 1;
    char *resultado = (char*) malloc((numDigitos + 1) * sizeof(char));
    int i = 0;

    while (p->topo >= 0) {
        resultado[i++] = pop(p);
    }
    resultado[i] = '\0';
    destroiPilha(p);
    return resultado;
}

int main() {
    int n;
    scanf("%d", &n);

    char *hex = hexadecimal(n);
    printf("%s\n", hex);

    free(hex);
    return 0;
}
