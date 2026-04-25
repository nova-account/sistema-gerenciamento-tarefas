#include "task-manager.h"
#include <stdio.h>


// criado um array para salvar as tarefas
Task tarefas[100];
int  total = 0;
//---------------------------------------

void exibir_menu(){
    printf("\n╔══════════════════════════════════╗\n");
    printf("║   GERENCIADOR DE TAREFAS  v0.1   ║\n");
    printf("╠══════════════════════════════════╣\n");
    printf("║  1. Nova tarefa                  ║\n");
    printf("║  2. Listar tarefas               ║\n");
    printf("║  3. Editar tarefa                ║\n");
    printf("║  4. Remover tarefa               ║\n");
    printf("║  0. Sair                         ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("Escolha: ");
}

int main() {
    int opcao;

    do
    {
        exibir_menu();
        scanf("%d",&opcao);
        switch (opcao) {
            case 1: create_task(tarefas, &total); break;
            case 2: list_tasks (tarefas,  total);  break;
            case 0: printf("Até logo!\n");          break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao !=0);
    
    return 0;
}