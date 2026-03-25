#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

enum TaskPriority {
    PRIORIDADE_BAIXA,
    PRIORIDADE_MEDIA,
    PRIORIDADE_ALTA
};

typedef struct{
    int id;
    char *nameTask;
    int is_completed;
    enum TaskPriority priority;
    
    int due_day;
    int due_month;
    int due_year;
} Task;

Task* create_task(int id, const char* nameTask, enum TaskPriority priority);

#endif
