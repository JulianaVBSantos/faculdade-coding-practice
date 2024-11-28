#include <stdio.h>

void soma (int vetor[5]);

int main () {
    int vetor[5];
    printf("Digite 5 numeros: ");
    for(int i=0;i<5;i++) {
        scanf("%d", &vetor[i]);
    }
    soma(vetor);
    return 0;
}

void soma (int vetor[5]) {
    int soma = 0;
    for(int i=0;i<5;i++) {
        soma += vetor[i];
    }
    printf("A soma dos 5 numeros digitados eh: %d", soma);
}