

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho(char *colecao[]) {
    int i = 0;
    while (*colecao != NULL) {
        colecao++;
        i++;
    }
    return i;
}

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

typedef char* (*fatiar_ptr)(char*, int, int);

char **nova_lista(fatiar_ptr criterio, char colecao[], char separador) {
    int n_indices = 0;
    
    // Método comum p/ saber a qtd. de índices a serem alocados em algo q ser criado dinamicamente
    for (int i = 0; i < strlen(colecao); i++) {
        if (colecao[i] == separador) {
            n_indices++;
        }
    }
    
    // O "algo" a ser criado dinamicamente recebe a qtd. de índices vazio (inicialmente todos os i = NULL)
    char **array = (char**)malloc(n_indices * sizeof(char*));
    int array_i = 0;
    int pos = 0;
    
    for (int i = 0; i < strlen(colecao); i++) {
        if (colecao[i] == separador) {
            // Alocação: define o tamanho do dado alocado, seguido do dado 
            array[array_i] = (char*)malloc(strlen(criterio(colecao, pos, i + 1)));
            strcpy(array[array_i], criterio(colecao, pos, i + 1)); // b
            
            pos = i + 1;
            array_i++;
        }
    }
    
    // P/ ser possível iterar sobre o retorno fora da função, é preciso apontar o fim do array
    array[array_i] = NULL;

    return array;
}

int main() {
    char coordenadas[] = "Norte Sul Leste Oeste ";
    char **array_coordenadas = nova_lista(fatiar, coordenadas, ' ');
    
    // Forma mais correta (por **array_coordenadas ser ponteiro de ponteiro)
    printf("\n{\n");
    while (*array_coordenadas) {
        printf("    %s,\n", *array_coordenadas);
        array_coordenadas++;
    }
    printf("\n}");
    
    // Liberação de memória
    for (int i = 0; i < tamanho(array_coordenadas); i++) {
        free(array_coordenadas[i]);
    }

    return 0;
}
