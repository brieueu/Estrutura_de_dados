#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct node {
    int item;
    struct node *next;
} node;

// Função que insere um novo nó no início da lista
node* add(node *head, int item) {
    // Aloca memória para o novo nó
    node *new_node = (node*) malloc(sizeof(node));
    // Atribui o valor ao novo nó
    new_node->item = item;
    // Faz o campo 'next' apontar para o nó que atualmente é o head (início da lista)
    new_node->next = head;
    // Retorna o novo nó, que passará a ser o novo head da lista
    return new_node;
}

// Função para imprimir a lista encadeada
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->item);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Inicialmente, a lista está vazia (head aponta para NULL)
    node *head = NULL;
    
    // Inserindo elementos na lista
    // Ao chamar add, o novo nó se torna a nova cabeça da lista
    head = add(head, 10); // Lista: 10 -> NULL
    head = add(head, 20); // Lista: 20 -> 10 -> NULL
    head = add(head, 30); // Lista: 30 -> 20 -> 10 -> NULL

    // Exibe a lista encadeada
    printf("Lista encadeada: ");
    print_list(head);

    // Liberação da memória alocada para cada nó
    node *current = head;
    node *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}