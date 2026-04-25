#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <stdio.h>
#define MAX_NOME 100
 
/* ─── Prioridade ─────────────────────────────────────────── */
typedef enum {
    PRIORIDADE_BAIXA,
    PRIORIDADE_MEDIA,
    PRIORIDADE_ALTA
} TaskPriority;
 

typedef struct {
    int          id;
    char         nameTask[MAX_NOME]; 
    int          is_completed;
    TaskPriority priority;
} Task;
 
/* ─── Protótipos ─────────────────────────────────────────── */
void create_task(Task *tarefas, int *total);
void list_tasks (Task *tarefas, int  total);
 
#endif
 