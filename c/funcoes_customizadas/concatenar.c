

// Essa função "concatenar" pode ser convertida para C++?
// Se sim, me mostre e explique cada linha de código em forma de comentário múltiplo dentro do código
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concatenar(char strA[], char strB[]) {
    size_t i, j;
    char *novaString = (char*)malloc(strlen(strA) + strlen(strB) + 1);

    if (novaString == NULL) {
        printf("\nErro ao alocar memória. Encerrando programa.\n");
        exit(0);
    }

    for (i = 0; i < strlen(strA); i++) {
        novaString[i] = strA[i];
    }

    for (j = 0; j < strlen(strB); j++) {
        novaString[i + j] = strB[j];
    }

    novaString[i + j] = '\0';
    return novaString;
}

int main() {
    char *pythonScript = concatenar("python", "script");
    printf("%s", pythonScript);
    free(pythonScript);
    return 0;
}