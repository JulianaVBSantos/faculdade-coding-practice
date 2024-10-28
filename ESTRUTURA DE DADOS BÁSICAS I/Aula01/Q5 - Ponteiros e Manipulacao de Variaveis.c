#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca (int* a, int* b);

int main () {
    int num01, num02;
    int* pont01 = &num01;
    int* pont02 = &num02;
    srand(time(0));
    num01 = rand() % 100;
    num02 = rand() % 100;
    printf("Os valores antes da alteracao sao %d e %d\n", num01, num02);
    troca(pont01, pont02);
    printf("Os valores depois da alteracao sao %d e %d", *pont01, *pont02);
    return 0;
}

void troca (int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}