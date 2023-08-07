

// Qual o problema aqui?
#include <stdio.h>
#include <string.h>

int main() {
    char* fim = "0";
    char* entrada; 
    while (strcmp(entrada, fim) != 0) {
        printf("\nDigite algo ou 0 >>> ");
        scanf("%s", entrada);
        printf("\n%s\n", entrada);
    }
    // printf("%i", strcmp(entrada, fim));
    // printf("%i", strcmp("", ""));
    return 0;
}
