

#include <stdio.h>
#include <string.h>

int tamanho_str_v1(char *colecao) {
    int n_indices = 0;

    
    while (*colecao) {
        n_indices++;
        colecao++;
    }
    return n_indices;
}

int tamanho_str_v2(char colecao[], char tipo[]) {
    int n_indices = 0;

    if (tipo == "while") {
        while (colecao[n_indices] != '\0') {
            n_indices++;
        }
    } else {
        for (int i = 0; colecao[i] != '\0'; i++) {
            n_indices++;
        }
    }

    return n_indices;
}

int tamanho_array_n(int colecao[]) {
    int n_indices = 0;

    while (colecao[n_indices] != -0) {
        n_indices++;
    }

    return n_indices;
}

int tamanho_array_n_v2(int *colecao) {
    int n_indices = 0;

    while (*colecao != -0) {
        n_indices++;
        colecao++;
    }

    return n_indices;
}

int tamanho_array_str(char *colecao[]) {
    int n_indices = 0;
    
    while (*colecao) {
        n_indices++;
        colecao++;
    }

    return n_indices;
}

int tamanho_array_str_v2(char **colecao) {
    int n_indices = 0;
    
    while (*colecao) {
        n_indices++;
        colecao++;
    }

    return n_indices;
}

int main() {
    char *palavra = "Universo";
    char palavraB[] = "Luva";
    int rank[] = {1, 2, 3, -0};
    char *pessoas[] = {"Ash", "Brock", "Misty", NULL};
    char *pessoasB[4] = {"Ash", "Brock", "Misty"};
    
    // Primeira função
    printf("%d\n", tamanho_str_v1(palavra));

    // Segunda função
    printf("%d\n", tamanho_str_v2(palavraB, "while"));
    printf("%d", tamanho_str_v2(palavraB, "for"));
    
    // Terceira função
    printf("%d\n", tamanho_array_n(rank));

    // Quarta função
    printf("%d\n", tamanho_array_n_v2(rank));

    // Quinta função
    printf("%d\n", tamanho_array_str(pessoas));
    printf("%d\n", tamanho_array_str(pessoasB));

    // Sexta função
    printf("%d\n", tamanho_array_str_v2(pessoas));
    printf("%d\n", tamanho_array_str_v2(pessoasB));
    return 0;
}
