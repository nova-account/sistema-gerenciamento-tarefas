#include "task-manager.h"
#include <stdio.h>

int main() {
    Task* tarefa = create_task(1, "Estudar C", PRIORIDADE_ALTA);

    printf("ID: %d\n", tarefa->id);
    printf("Tarefa: %s\n", tarefa->nameTask);
    printf("Concluída: %d\n", tarefa->is_completed);
    printf("Prioridade: %d\n", tarefa->prioridade);

    free(tarefa->nameTask);
    free(tarefa);

    return 0;
}