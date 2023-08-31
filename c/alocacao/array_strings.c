

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    /*
        Array de strings criado dinamicamente com espaço p/ 3 índices
        **     || define array de strings
        char** || alocação p/ array de strings
        char*  || define string
    */
    int i;
    int t = 3;
    char **pessoas = (char**)malloc(t * sizeof(char*));

    if (pessoas == NULL) {
        printf("\nErro ao alocar memória. Encerrando algoritmo.");
        exit(0);
    }

    // Exibindo os dados antes de eles serem alocados
    printf("\n[\n");
    for (i = 0; i < t; i++) {
        printf("    %p,\n", (void*)pessoas[i]);
    }
    printf("]\n");
    
    /* Alocação (FORMA AUMENTADA)
        pessoas[0] = (char*)malloc(strlen("Ash") + 1);
        pessoas[1] = (char*)malloc(strlen("Brock") + 1);
        pessoas[2] = (char*)malloc(strlen("Misty") + 1);
        strcpy(pessoas[0], "Ash");
        strcpy(pessoas[1], "Brock");
        strcpy(pessoas[2], "Misty");
    */

    // Alocação (FORMA REDUZIDA)
    pessoas[0] = strdup("Ash");
    pessoas[1] = strdup("Brock");
    pessoas[2] = strdup("Misty");

    // Exibindo os dados já alocados
    printf("\n[\n");
    for (i = 0; i < t; i++) {
        printf("    %s,\n", pessoas[i]);
    }
    printf("]\n");

    // Limpando o endereço de cada índice do array criado dinamicamente 
    for (i = 0; i < t; i++) {
        free(pessoas[i]);
    }

    // Limpando o endereço do array criado dinamicamente
    free(pessoas);

    return 0;
}
