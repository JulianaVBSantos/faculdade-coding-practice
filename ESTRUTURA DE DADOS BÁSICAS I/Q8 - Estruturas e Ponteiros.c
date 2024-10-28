#include <stdio.h>

struct Retangulo {
    float largura;
    float altura;
};

float leituraecalculo(struct Retangulo *retangulo);

int main () {
    struct Retangulo retangulo;
    printf("Digite os valores da largura e altura: ");
    printf("A area do retangulo eh: %.2f", leituraecalculo(&retangulo));
    return 0;
}

float leituraecalculo(struct Retangulo *retangulo) {
    scanf("%f", &retangulo->largura);
    scanf("%f", &retangulo->altura);
    float area = retangulo->largura * retangulo->altura;
    return area;
}