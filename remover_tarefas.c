#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "remover_tarefas.h"

void remover_por_id(Tarefa *tarefas, int *total, int id) {
    int i, j = 0;
    int encontrado = 0;

    Tarefa *novo = malloc(sizeof(Tarefa) * (*total));

    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    for (i = 0; i < *total; i++) {
        if (tarefas[i].id == id) {
            encontrado = 1;
            continue;
        }
        novo[j++] = tarefas[i];
    }

    if (encontrado) {
        (*total)--;

        for (i = 0; i < *total; i++) {
            tarefas[i] = novo[i];
        }

        printf("Tarefa removida!\n");
    } else {
        printf("Nao encontrada!\n");
    }

    free(novo);
}

void remover_por_nome(Tarefa *tarefas, int *total, char *nome) {
    int i, j = 0;
    int encontrado = 0;

    Tarefa *novo = malloc(sizeof(Tarefa) * (*total));

    if (novo == NULL) {
        printf("Erro de memoria!\n");
        return;
    }

    for (i = 0; i < *total; i++) {
        if (strcmp(tarefas[i].nomeTarefa, nome) == 0) {
            encontrado = 1;
            continue;
        }
        novo[j++] = tarefas[i];
    }

    if (encontrado) {
        (*total)--;

        for (i = 0; i < *total; i++) {
            tarefas[i] = novo[i];
        }

        printf("Tarefa removida!\n");
    } else {
        printf("Nao encontrada!\n");
    }

    free(novo);
}
