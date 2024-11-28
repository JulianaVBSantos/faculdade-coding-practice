#include <stdio.h>

void leitura (int mat[3][3]);
int soma (int mat[3][3]);

int main () {
    int mat[3][3];
    printf("Digite os valores da matriz: ");
    leitura(mat);
    printf("A soma dos elementos da diagonal principal eh: %d", soma(mat));
    return 0;
}

void leitura (int mat[3][3]) {
    for (int l=0;l<3;l++) {
        for (int c=0;c<3;c++) {
            scanf("%d", &mat[l][c]);
        }
    }
}

int soma (int mat[3][3]) {
    int total = 0;
    for (int l=0;l<3;l++) {
        for (int c=0;c<3;c++) {
            if (l == c) {
                total += mat[l][c];
            }
        }
    }
    return total;
}