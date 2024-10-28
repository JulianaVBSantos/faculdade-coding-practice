#include <stdio.h>

void troca(int a, int b);

int main () {
    int a, b;
    printf("Digite os dois numeros: ");
    scanf("%d %d", &a, &b);
    printf("Valores de A e B antes da alteracao: %d %d\n", a, b);
    printf("Valores de A e B depois da alteracao: ");
    troca(a, b);
    return 0;
}

void troca (int a, int b) {
    int aux = a;
    a = b;
    b = aux;
    printf("%d %d", a, b);
}