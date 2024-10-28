#include <stdio.h>
#include <stdlib.h>

void leituraesoma(int* num);

int main () {
    int* num = (int*)malloc(5*sizeof(int));
    if (num == NULL) {
        printf("Erro ao alocar a memória!\n");
        return 1;
    }

    leituraesoma(num);
    free(num);

    return 0;
}

void leituraesoma (int* num) {
    int soma = 0;
    printf("Digite os 5 numeros inteiros: \n");
    for (int i=0;i<5;i++) {
        scanf("%d", &num[i]);
        soma+=num[i];
    }
    printf("A soma dos numeros eh %d\n", soma);
}