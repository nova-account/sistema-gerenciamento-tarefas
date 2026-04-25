#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task-manager.h"

static const char *prioridade_str(TaskPriority p) {
    switch (p) {
        case PRIORIDADE_BAIXA: return "Baixa";
        case PRIORIDADE_MEDIA: return "Média";
        case PRIORIDADE_ALTA:  return "Alta";
        default:               return "?";
    }
}
 
void create_task(Task *tarefas, int *total) {
    if (*total >= 100) {
        printf("Lista cheia!\n");
        return;
    }
 
    Task *t = &tarefas[*total]; /* aponta para a próxima posição livre */
 
    t->id           = *total + 1;
    t->is_completed = 0;
 
    printf("Nome da tarefa: ");
    getchar(); /* limpa o '\n' que sobrou do scanf do menu */
    fgets(t->nameTask, MAX_NOME, stdin);
    /* fgets inclui o '\n' no final — removemos aqui */
    t->nameTask[strcspn(t->nameTask, "\n")] = '\0';
 
    int p;
    printf("Prioridade (0=Baixa, 1=Média, 2=Alta): ");
    scanf("%d", &p);
    t->priority = (TaskPriority)p;
 
    (*total)++; /* só incrementa depois que tudo deu certo */
 
    printf("\nTarefa \"%s\" criada com sucesso!\n", t->nameTask);
}

void list_tasks(Task *tarefas, int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
 
    printf("\n%-4s %-25s %-8s %s\n", "ID", "Nome", "Prior.", "Status");
    printf("─────────────────────────────────────────────\n");
 
    for (int i = 0; i < total; i++) {
        Task *t = &tarefas[i];
        printf("%-4d %-25s %-8s %s\n",
            t->id,
            t->nameTask,
            prioridade_str(t->priority),
            t->is_completed ? "Concluída" : "Pendente");
    }
}