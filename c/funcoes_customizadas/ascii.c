

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii(char letra) {
    return letra;
}

int *asciiPalavra(char palavra[]) {
    // printf("%d", strlen(palavra));
    int *codigoAscii = (int*)malloc(strlen(palavra) * sizeof(int));
    if (codigoAscii == NULL) {
        printf("Erro ao alocar memória. Encerrando programa.\n");
        exit(1);
    }
    for (size_t i = 0; i < codigoAscii[i] != '\0'; i++) {
        codigoAscii[i] = ascii(palavra[i]);
    }
    return codigoAscii;
}

void exibir(int *colecao, int t) {
    printf("\n[ ");
    for (size_t i = 0; i < t; i++) {
        printf("%d, ", colecao[i]);
    }
    printf("]");
}

int main() {
    // printf("%d", ascii('a'));
    char nome[7] = "banana";
    int *nomeAscii = asciiPalavra(nome);
    exibir(nomeAscii, strlen(nome));
    free(nomeAscii);
    return 0;
}
