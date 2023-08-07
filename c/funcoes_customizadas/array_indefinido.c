

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **array_indefinido(int n_indices) {
    char **array = (char**)malloc(n_indices * sizeof(char*));
    
    if (array == NULL) {
        printf("Erro ao alocar memória\n.Enecerrando programa\n");
        exit(1);
    }
    
    return array;
}

int main() {
    // Dados necessários
    int t = 3;
    char **pessoas = array_indefinido(t);
    
    // Alocação dos dados
    pessoas[0] = (char*)malloc(strlen("Ash") + 1);
    pessoas[1] = (char*)malloc(strlen("Brock") + 1);
    pessoas[2] = (char*)malloc(strlen("Misty") + 1);

    strcpy(pessoas[0], "Ash");
    strcpy(pessoas[1], "Brock");
    strcpy(pessoas[2], "Misty");
    
    // Exibição dos dados
    printf("\n{\n");
    for (int i = 0; i < t; i++) {
        printf("    %s,\n", pessoas[i]);
    }
    printf("\n}");

    // Liberação da memória
    for (int i = 0; i < t; i++) {
        free(pessoas[i]);
    }
    
    return 0;
}
