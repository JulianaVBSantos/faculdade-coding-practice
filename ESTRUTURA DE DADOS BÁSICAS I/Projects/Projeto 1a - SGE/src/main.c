#include <stdio.h>
#include "estoque.h" // p/ manipulação do vetor de produtos
// #include "persistencia.h" // p/  manipulação de arquivos

int main() {
    Estoque estoque;
    Produto p;
    inicializarEstoque(&estoque, 10);

    //carregarDeArquivo(&estoque, "estoque.txt");

    int opcao;
    do {
        printf("\n1. Inserir produto\n");
        printf("2. Remover produto\n");
        printf("3. Buscar produto\n");
        printf("4. Atualizar produto\n");
        printf("5. Listar produtos\n");
        printf("6. Gravar estoque em arquivo\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Produto p;
                printf("Digite o codigo do produto: ");
                scanf("%d", &p.codigo);
                printf("Digite o nome do produto: ");
                scanf("%49s", p.nome); // Garante que não ultrapasse o limite de 49 caracteres + null-terminator
                printf("Digite a quantidade: ");
                scanf("%d", &p.quantidade);
                printf("Digite o preco: ");
                scanf("%f", &p.preco);
                inserirProduto(&estoque, p);
                break;
            }
            case 2: {
                int codigo;
                printf("Digite o codigo do produto a ser removido: ");
                scanf("%d", &codigo);
                removerProduto(&estoque, codigo);
                break;
            }
            case 3: {
                int codigo;
                printf("Digite o codigo do produto a ser buscado: ");
                scanf("%d", &codigo);
                int indice = buscarProduto(&estoque, codigo);
                if (indice == -1) {
                    printf("Produto nao encontrado.\n");
                } else {
                    Produto p = estoque.produtos[indice];
                    printf("Codigo: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n", p.codigo, p.nome, p.quantidade, p.preco);
                }
                break;
            }
            case 4: {
                int codigo, quantidade;
                float preco;
                printf("Digite o codigo do produto a ser atualizado: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade (nao negativa): ");
                scanf("%d", &p.quantidade);
                    if (p.quantidade < 0) {
                        printf("Quantidade invalida.\n");
                        break;
                    }
                printf("Digite o novo preço: ");
                scanf("%f", &preco);
                atualizarProduto(&estoque, codigo, quantidade, preco);
                break;
            }
            case 5:
                listarProdutos(&estoque);
                break;
            case 6:
                // gravar em arquivo
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcaoo invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    liberarEstoque(&estoque);
    return 0;
}