#include <stdio.h>

struct Pessoa {
    char nome[100];
    int idade;
    float altura;
};

void leituradados();

int main () {
    struct Pessoa pessoa;
    leituradados(&pessoa);
    printf("Informacoes armazenadas: \n");
    printf("Nome: %s", pessoa.nome);
    printf("Idade: %d anos\n", pessoa.idade);
    printf("Altura: %.2f\n", pessoa.altura);

    return 0;
}

void leituradados (struct Pessoa *pessoa) {
    printf("Digite o nome: ");
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);
    printf("Digite a altura: ");
    scanf("%f", &pessoa->altura);
}