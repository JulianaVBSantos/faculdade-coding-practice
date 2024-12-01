#include <stdio.h>
#include "estoque.h"
#include "persistencia.h"

void menu();

int main() {
    Estoque estoque;
    Produto p;
    inicializarEstoque(&estoque, 10);
    carregarEstoque(&estoque, "./data/estoque.csv");
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Produto p;
                printf("Digite o codigo do produto: "); scanf("%d", &p.codigo);
                printf("Digite o nome do produto: "); scanf("%49s", p.nome);
                printf("Digite a quantidade: "); scanf("%d", &p.quantidade);
                printf("Digite o preco: "); scanf("%f", &p.preco);
                inserirProduto(&estoque, p);
                printf("Produto inserido com sucesso!\n");
                break; }
            case 2: {
                int codigo;
                printf("Digite o codigo do produto a ser removido: "); scanf("%d", &codigo);
                removerProduto(&estoque, codigo);
                break;}
            case 3: {
                int codigo;
                printf("Digite o codigo do produto a ser buscado: "); scanf("%d", &codigo);
                int indice = buscarProduto(&estoque, codigo);
                if (indice == -1) {
                    printf("Produto nao encontrado.\n");
                } else {
                    Produto p = estoque.produtos[indice];
                    printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n", p.codigo, p.nome, p.quantidade, p.preco);
                }
                break;}
            case 4: {
                int codigo, quantidade;
                float preco;
                printf("Digite o codigo do produto a ser atualizado: "); scanf("%d", &codigo);
                printf("Digite a quantidade (nao negativa): "); scanf("%d", &quantidade);
                if (quantidade < 0) {
                    printf("Quantidade invalida.\n");
                    break;
                }
                printf("Digite o novo preco: "); scanf("%f", &preco);
                atualizarProduto(&estoque, codigo, quantidade, preco);
                break; }
            case 5:
                listarProdutos(&estoque);
                break;
            case 6:
                salvarEstoque(&estoque, "./data/estoque.csv");
                break;
            case 7:
                printf("Programa encerrado\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    liberarEstoque(&estoque);
    return 0;
}

void menu () {
    printf("\n--- Sistema de Gerenciamento de Estoque---\n");
    printf("\n1. Inserir produto\n");
    printf("2. Remover produto\n");
    printf("3. Buscar produto\n");
    printf("4. Atualizar produto\n");
    printf("5. Listar produtos\n");
    printf("6. Salvar alteracoes\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}