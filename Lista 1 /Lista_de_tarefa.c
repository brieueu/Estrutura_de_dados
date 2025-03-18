#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct Task {
    char description[MAX];  
    int priority;                       
    struct Task *next;                  
} Task;


Task *priorityList[6] = {NULL, NULL, NULL, NULL, NULL, NULL};

//Inserir nó
void insertTask(const char *desc, int prio) {
    Task *newTask = (Task *) malloc(sizeof(Task));
    if (!newTask) {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        exit(1);
    }
    strcpy(newTask->description, desc);
    newTask->priority = prio;
    // Inserção no início: os mais recentes ficarão na cabeça, 
    newTask->next = priorityList[prio];
    priorityList[prio] = newTask;
}

// Função para exibir as tarefas cadastradas de forma ordenada
// Primeiro exibe uma quebra de linha e depois imprime, do nível 1 ao 5,
void displayTasks() {
    printf("\n");  
    for (int p = 1; p <= 5; p++) {
        Task *current = priorityList[p];
        while (current != NULL) {
            printf("%d. %s\n", p, current->description);
            current = current->next;
        }
    }
}

int main() {
    int option;
    char description[MAX];
    int priority;

    //0 encerra, 1 insere uma tarefa, 2 exibe as tarefas
    while (1) {
        //Ler a opção do menu
        if (scanf("%d", &option) != 1) break;
        if (option == 0) break;

        if (option == 1) {
            //ler uma entrada padrão e retorna em ASCII
            getchar();
            //descrição da tarefa
            fgets(description, MAX, stdin);
            //Remove a quebra de linha
            description[strcspn(description, "\n")] = '\0';
            //nível de prioridade
            scanf("%d", &priority);
            //insere a tarefa na lista correspondente
            insertTask(description, priority);
        } else if (option == 2) {
            displayTasks();
        }
    }

    //libera a memória alocada para cada tarefa
    for (int p = 1; p <= 5; p++) {
        Task *current = priorityList[p];
        while (current != NULL) {
            Task *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}