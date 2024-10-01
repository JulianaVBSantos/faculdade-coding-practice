#include <stdio.h>

int soma_array(int numeros[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += numeros[i];
    }
    return soma;
}

int main() {
    int numeros[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    int resultado = soma_array(numeros, 5);
    printf("A soma dos numeros eh %d\n", resultado);

    return 0;
}