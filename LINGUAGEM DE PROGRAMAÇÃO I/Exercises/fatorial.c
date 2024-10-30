#include <stdio.h>

int calcular_fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int fatorial = 1;
    for (int i = 2; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    int resultado = calcular_fatorial(numero);
    printf("O fatorial de %d eh %d\n", numero, resultado);

    return 0;
}