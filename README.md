# Sistema de Gerenciamento de Tarefas

Um sistema básico de gerenciamento de tarefas em C. Implementa operações CRUD para gerenciar tarefas.

#### Pré-requisitos
- GCC ou compilador C compatível
- Make (opcional)

#### Compilação
```bash
gcc -o task-manager main.c task-manager.c -Wall -std=c99
```

### Demonstração Rápida

```c
#include "task-manager.h"

int main() {
    Task* tasks[100];
    int num_tasks = 0;

    // CRIAR - Adicionar novas tarefas
    tasks[num_tasks++] = create_task(1, "Comprar mantimentos", PRIORITY_HIGH);
    tasks[num_tasks++] = create_task(2, "Escrever relatório", PRIORITY_MEDIUM);
    tasks[num_tasks++] = create_task(3, "Exercitar", PRIORITY_LOW);

    // LER - Exibir todas as tarefas
    list_all_tasks(tasks, num_tasks);

    // LER - Ver apenas tarefas pendentes
    list_pending_tasks(tasks, num_tasks);

    // ATUALIZAR - Marcar tarefa como concluída
    mark_task_completed(tasks[0]);

    // LER - Ver apenas tarefas concluídas
    list_completed_tasks(tasks, num_tasks);

    // DELETAR - Remover uma tarefa
    remove_task(&tasks, &num_tasks, 2);

    // Limpeza
    free_task_system(tasks, num_tasks);
    return 0;
}
```

### Operações CRUD

####  CRIAR
**`create_task(id, nome, prioridade)`**
- Cria um novo nó de tarefa
- Retorna ponteiro para tarefa alocada
- Prioridade: `PRIORITY_LOW`, `PRIORITY_MEDIUM`, `PRIORITY_HIGH`

```c
Task* task = create_task(1, "Minha Tarefa", PRIORITY_HIGH);
```

#### LER
**`list_all_tasks(tarefas, num_tarefas)`**
- Exibe todas as tarefas com status e prioridade
- Mostra [X] para concluída, [ ] para pendente

```c
list_all_tasks(tasks, num_tasks);
```

**`list_pending_tasks(tarefas, num_tarefas)`**
- Mostra apenas tarefas pendentes (não concluídas)
- Útil para ver o que ainda precisa ser feito

```c
list_pending_tasks(tasks, num_tasks);
```

**`list_completed_tasks(tarefas, num_tarefas)`**
- Mostra apenas tarefas concluídas
- Útil para rastreamento de progresso

```c
list_completed_tasks(tasks, num_tasks);
```

####  ATUALIZAR
**`mark_task_completed(tarefa)`**
- Marca uma tarefa como concluída
- Define flag `is_completed` para 1
- Imprime mensagem de confirmação

```c
mark_task_completed(tasks[0]);
```

####  DELETAR
**`remove_task(&tarefas, &num_tarefas, id_tarefa)`**
- Remove tarefa pelo ID
- Libera memória alocada
- Atualiza array de tarefas

```c
remove_task(&tasks, &num_tasks, 1);
```

### Estrutura de Dados

```c
enum TaskPriority {
    PRIORITY_LOW,      // Baixa
    PRIORITY_MEDIUM,   // Média
    PRIORITY_HIGH      // Alta
};

typedef struct {
    int id;                    // Identificador único da tarefa
    char name[100];            // Descrição da tarefa
    int is_completed;          // 0 = pendente, 1 = concluída
    enum TaskPriority priority;
} Task;
```

### Referência de Funções

| Função | Propósito |
|--------|----------|
| `create_task()` | Criar nova tarefa |
| `list_all_tasks()` | Exibir todas |
| `list_pending_tasks()` | Exibir apenas pendentes |
| `list_completed_tasks()` | Exibir apenas concluídas |
| `mark_task_completed()` | Marcar como concluída |
| `remove_task()` | Deletar tarefa por ID ou Nome |
| `get_priority_string()` | Converter enum prioridade para texto |
| `free_task_system()` | Limpeza de memória |
| `task_due_to()` | Vencidamento da tarefa |

### Exemplo de Saída

```
=== Todas as Tarefas ===
[ ] ID: 1 | Comprar mantimentos | Prioridade: Alta
[X] ID: 2 | Escrever relatório | Prioridade: Média
[ ] ID: 3 | Exercitar | Prioridade: Baixa
========================
```

### Padrões Comuns

**Criar e exibir:**
```c
tasks[num_tasks] = create_task(1, "Tarefa", PRIORITY_HIGH);
num_tasks++;
list_all_tasks(tasks, num_tasks);
```

**Marcar concluído e verificar:**
```c
mark_task_completed(tasks[0]);
list_completed_tasks(tasks, num_tasks);
```

**Limpar antes de sair:**
```c
free_task_system(tasks, num_tasks);
```

---

### License
MIT
