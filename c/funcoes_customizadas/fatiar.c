

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Instâncias com *, pois a função (fatiar) possui retorno (*fatiar)
char *fatiar(char colecao[], int min, int max) {

    int n_indices = max - min;
    char *string = (char*)malloc((n_indices + 1));

    if (string == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        exit(1);
    }

    for (int i = 0; i < n_indices; i++) {
        string[i] = colecao[min + i];
    }
    
    string[n_indices] = '\0';
    
    return string;
}

int main() {
    char palavra[] = "Universo";

    // Instâncias com *, pois a função (fatiar) possui retorno (*fatiar)
    char *palavraA = fatiar(palavra, 0, 3);
    char *palavraB = fatiar(palavra, 1, 4);
    char *palavraC = fatiar(palavra, 3, sizeof(palavra) / sizeof(palavra[0]) - 1);
    
    printf("%s\n", palavraA);
    printf("%s\n", palavraB);
    printf("%s", palavraC);
    
    // Strings não precisam de loop para liberar cada caractere
    free(palavraA);
    free(palavraB);
    free(palavraC);
}
