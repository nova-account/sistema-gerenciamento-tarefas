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

    getchar(); // limpa os espaços vazios

    printf("Qual a Atividade ? : ");
    fgets(nameTask, 100, stdin);

    printf("Qual a prioridade?: ");
    scanf("%d", &priority);

    return create_task(id,nameTask,priority);
}

// é necessario criar uma função MALLOC para armazenar os dados pois uma função normal não guarda os dados !

Task* create_task(int id, const char* nameTask, enum TaskPriority priority){
    Task *ponteiro = malloc(sizeof(Task));
      if (!ponteiro) return NULL; // sempre em um MAllOC, deve verificar se funcionou

    ponteiro->id=id;
    ponteiro->is_completed = 0;
    ponteiro->priority = priority;

// par armazenar um texto é bem complicado e precisa utilizar o STRCPY mas antes precisa alocar ele primeiro
                    // essa função aloca ele e após isso utiliza-se o STRCPY.  

    ponteiro->nameTask = malloc(strlen(nameTask) + 1); // é uma verificação
    if (!ponteiro->nameTask){
        free(ponteiro);        
        return NULL;
    }
    strcpy(ponteiro->nameTask, nameTask);

    return ponteiro;
}