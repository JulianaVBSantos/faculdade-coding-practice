#include <stdio.h>
#include <stdbool.h>

bool eh_primo(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numero;
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    
    if (eh_primo(numero)) {
        printf("O numero %d eh primo.\n", numero);
    } else {
        printf("O numero %d não eh primo.\n", numero);
    }

    return 0;
}