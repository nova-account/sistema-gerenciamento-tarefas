#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

enum TaskPriority {
    PRIORITY_LOW,
    PRIORITY_MEDIUM,
    PRIORITY_HIGH
};

struct Task {
    int id;
    char nome[100];
    int is_completed;
    enum TaskPriority prioridade;
};

#endif
