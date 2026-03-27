#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task-manager.h"


// função apenas para coleta da criação da Atividade
Task* create_task_coleta(){
   int id;
   char nameTask[100];
   int priority;


    printf("ID da ATIVIDADE : ");
    scanf("%d", &id);
    
    getchar(); // limpa o buffer

    printf("Qual a Atividade ? : ");
    fgets(nameTask, 100, stdin);

    printf("Qual a prioridade?: ");
    scanf("%d", &priority);

    return create_task(id,nameTask,priority);
}