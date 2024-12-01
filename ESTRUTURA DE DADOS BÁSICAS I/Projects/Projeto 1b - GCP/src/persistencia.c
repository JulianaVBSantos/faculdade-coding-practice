#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargas.h"
#include "persistencia.h"

void carregarCargas(const char *caminhoArquivo) {
    FILE *arquivo = fopen(caminhoArquivo, "r");
    if (!arquivo) {
        printf("Nao foi possivel abrir o arquivo %s\n", caminhoArquivo);
        return;
    }

    Carga carga;
while (fscanf(arquivo, "%9[^,],%49[^,],%f,%9[^,],%99[^\n]\n", carga.id, carga.tipo, &carga.peso, carga.prioridade, carga.descricao) == 5) {
        if (!insercao(carga)) {
            printf("Nao foi possível inserir carga com ID %s na fila.\n", carga.id);
        }
    }

    fclose(arquivo);
}

void salvarAlteracoes(const char *arquivo) {
    FILE *arq = fopen(arquivo, "w");
    if (arq == NULL) { printf("Erro ao criar arquivo %s\n", arquivo); return; }
 
    Carga *cargaAtual = getInicio();
    while (cargaAtual != NULL) {
        fprintf(arq, "%s,%s,%.2f,%s,%s\n", 
                cargaAtual->id, cargaAtual->tipo, cargaAtual->peso, 
                cargaAtual->prioridade, cargaAtual->descricao);
        cargaAtual = cargaAtual->prox;
    }

    fclose(arq);
    printf("Cargas salvas no arquivo %s\n", arquivo);
}