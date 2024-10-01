#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    
    int comprimento = strlen(string) - 1;
    printf("O numero de caracteres na string eh %d\n", comprimento);

    return 0;
}
