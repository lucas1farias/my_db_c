

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *array_indefinido_n(int n_indices) {
    int *array = (int*)malloc(n_indices * sizeof(int));
    
    if (array == NULL) {
        printf("Erro ao alocar memória\n.Enecerrando programa\n");
        exit(1);
    }
    
    return array;
}

int main() {
    // Dados necessários
    int t = 3;
    int *rank = array_indefinido_n(t);
    
    // Alocação dos dados
    rank[0] = 1;
    rank[1] = 2;
    rank[2] = 3;
    
    // Exibição dos dados
    printf("\n{\n");
    for (int i = 0; i < t; i++) {
        printf("    %d,\n", rank[i]);
    }
    printf("\n}");

    // Liberação da memória
    free(rank);
    return 0;
}

