// Arquivo para as implementações de funções ref. ao gerenciam. do estoque

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

void inicializarEstoque(Estoque *estoque, int capacidadeInicial) {
    estoque->produtos = malloc(capacidadeInicial * sizeof(Produto));
    if (estoque->produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    estoque->capacidade = capacidadeInicial;
    estoque->tamanho = 0;
}

void redimensionarEstoque(Estoque *estoque) {
    estoque->capacidade *= 2;
    Produto *novoArray = (Produto *)realloc(estoque->produtos, estoque->capacidade * sizeof(Produto));
    if (novoArray == NULL) {
        printf("Erro ao redimensionar o estoque.\n");
        free(estoque->produtos);
        exit(1);
    }
    estoque->produtos = novoArray;
}

void inserirProduto(Estoque *estoque, Produto novoProduto) {
    if (estoque->tamanho == estoque->capacidade) {
        redimensionarEstoque(estoque);
    }
    estoque->produtos[estoque->tamanho++] = novoProduto;
}

int buscarProduto(Estoque *estoque, int codigo) {
    for (int i = 0; i < estoque->tamanho; i++) {
        if (estoque->produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void removerProduto(Estoque *estoque, int codigo) {
    int indice = buscarProduto(estoque, codigo);
    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }
    for (int i = indice; i < estoque->tamanho - 1; i++) {
        estoque->produtos[i] = estoque->produtos[i + 1];
    }
    estoque->tamanho--;
    printf("Produto removido com sucesso!\n");
}

void atualizarProduto(Estoque *estoque, int codigo, int novaQuantidade, float novoPreco) {
    int indice = buscarProduto(estoque, codigo);
    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }
    estoque->produtos[indice].quantidade = novaQuantidade;
    estoque->produtos[indice].preco = novoPreco;
    printf("Atualização realizada!\n");
}

void listarProdutos(Estoque *estoque) {
    if (estoque->tamanho == 0) {
        printf("Estoque vazio.\n");
        return;
    }
    for (int i = 0; i < estoque->tamanho; i++) {
        Produto p = estoque->produtos[i];
        printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n", p.codigo, p.nome, p.quantidade, p.preco);
    }
}

void liberarEstoque(Estoque *estoque) {
    free(estoque->produtos);
    estoque->produtos = NULL;
    estoque->tamanho = 0;
    estoque->capacidade = 0;
}