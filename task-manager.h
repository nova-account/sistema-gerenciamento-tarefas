#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <stdio.h>

enum TaskPriority {
    prioridade_baixa,
    prioridade_media,
    prioridade_alta
};

// typedef serve para chamar essa Struct apenas pela palavra dada "Task"
typedef struct{
    int id;
    char *nameTask;
    int is_completed;
    enum TaskPriority priority;
    
} Task; // aqui

// O Struct ^ é apenas a "planta" e o "pedreiro" vai mexer nesse Struct

Task* create_task(int id, const char* nameTask, enum TaskPriority priority); // isso é o "pedreiro que vai fazer os dados no Struct"


Task* create_task_coleta(); // essa função está no arquivo .c
#endif
