#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia.h"

void carregarEstoque(Estoque *estoque, const char *caminhoArquivo) {
    FILE *arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s .\n", caminhoArquivo);
        return;
    }

    while (!feof(arquivo)) {
        Produto p;
        if (fscanf(arquivo, "%d,%49[^,],%d,%f\n", &p.codigo, p.nome, &p.quantidade, &p.preco) == 4) {
            inserirProduto(estoque, p);
        }
    }

    fclose(arquivo);
}

void salvarEstoque(Estoque *estoque, const char *caminhoArquivo) {
    FILE *arquivo = fopen(caminhoArquivo, "w");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s .\n", caminhoArquivo);
        return;
    }

    for (int i = 0; i < estoque->tamanho; i++) {
        Produto p = estoque->produtos[i];
        fprintf(arquivo, "%d,%s,%d,%.2f\n", p.codigo, p.nome, p.quantidade, p.preco);
    }

    fclose(arquivo);
}
