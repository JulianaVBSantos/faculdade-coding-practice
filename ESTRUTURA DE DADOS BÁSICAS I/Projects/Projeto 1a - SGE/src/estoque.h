//Declarações das funções e estruturas relacionadas ao estoque

#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

typedef struct {
    Produto *produtos;
    int tamanho;
    int capacidade;
} Estoque;

void inicializarEstoque(Estoque *estoque, int capacidadeInicial);
void redimensionarEstoque(Estoque *estoque);
void inserirProduto(Estoque *estoque, Produto novoProduto);
int buscarProduto(Estoque *estoque, int codigo);
void removerProduto(Estoque *estoque, int codigo);
void atualizarProduto(Estoque *estoque, int codigo, int novaQuantidade, float novoPreco);
void listarProdutos(Estoque *estoque);
void liberarEstoque(Estoque *estoque);

#endif