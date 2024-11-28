#include <stdio.h>

void troca(int* a, int* b);

int main () {
    int a, b;
    int* ponteiroA = &a;
    int* ponteiroB = &b;
    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);
    printf("Numeros digitados antes da troca: %d %d\n", a, b);
    printf("Numeros digitados depois da troca: ");
    troca(ponteiroA, ponteiroB);
    return 0;
}

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("%d %d", *a, *b); 
}