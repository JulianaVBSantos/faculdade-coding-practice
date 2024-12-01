#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargas.h"
#include "persistencia.h"

void menu();

int main() {
    iniciarFila();
    carregarCargas("./data/cargas.csv");
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
        case 1: {
            exibir();
            break;
        }
        case 2: {
            Carga nova;
            printf("ID: "); scanf("%s", nova.id);
            printf("Tipo: "); scanf("%s", nova.tipo);
            printf("Peso: "); scanf("%f", &nova.peso);
            printf("Prioridade (Baixa/Normal/Alta): "); scanf("%s", nova.prioridade);
            getchar();
            printf("Descricao: ");
            fgets(nova.descricao, sizeof(nova.descricao), stdin);
            nova.descricao[strcspn(nova.descricao, "\n")] = '\0';

            if (insercao(nova)) {
                printf("Carga adicionada com sucesso!\n");
            } else {
                printf("Erro ao adicionar carga.\n");
            }
            break;
        }
        case 3: {
            Carga *removida = remocao();
            if (removida) {
                printf("Carga processada: ID: %s | Tipo: %s | Peso: %.2f | Prioridade: %s | Descricao: %s\n",
                    removida->id, removida->tipo, removida->peso, removida->prioridade, removida->descricao);
                free(removida);
            } else {
                printf("Nenhuma carga a processar.\n");
            }
            break;
        } 
        case 4: {
            char id[10];
            printf("ID da carga: "); scanf("%s", id);
            Carga *carga = buscar(id);
            if (carga) {
                printf("ID: %s | Tipo: %s | Peso: %.2f | Prioridade: %s | Descricao: %s\n",
                    carga->id, carga->tipo, carga->peso, carga->prioridade, carga->descricao);
            } else {
                printf("Carga nao encontrada.\n");
            }
            break;
        }
        case 5: {
            salvarAlteracoes("./data/cargas_alt.csv");
            break;
        }
        case 6: {
            printf("Programa encerrado");
            break;}
        default:
            printf("Opcao nao encontrada!");
        }
            
    } while (opcao != 6);

    liberarFila();
    return 0;
}

void menu () {
    printf("\n--- Gestao de Cargas Portuarias ---\n");
    printf("1. Exibir cargas\n");
    printf("2. Adicionar nova carga\n");
    printf("3. Processar proxima carga\n");
    printf("4. Buscar carga por ID\n");
    printf("5. Salvar alteracoes\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
}