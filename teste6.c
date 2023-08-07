

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nova_entrada(char conteudo[]) {
    int qtd;
    printf("%s", conteudo);
    scanf("%d", &qtd);
    return qtd;
}

char **array_indefinido(int tamanho) {
    char **array = (char **)malloc(tamanho * sizeof(char *));
    if (array == NULL) {
        printf("\nErro ao alocar em memória. Encerrando programa\n");
        exit(1);
    }
    return array;
}

char *nova_entrada_txt(char conteudo[]) {
    char *str = (char *)malloc(20 * sizeof(char));
    if (str == NULL) {
        printf("\nErro ao alocar em memória. Encerrando programa\n");
        exit(1);
    }
    printf("%s", conteudo);
    scanf("%s", str);
    return str;
}

void anexar(char *colecao[], char dado[], int i) {
    colecao[i] = (char *)malloc(strlen(dado) + 1);
    if (colecao[i] == NULL) {
        printf("\nErro ao alocar em memória. Encerrando programa\n");
        exit(1);
    }
    strcpy(colecao[i], dado);
}

void novo_loop_for(int n_giros, char conteudo[], char *colecao[]) {
    for (int i = 0; i < n_giros; i++) {
        char *novo_i = nova_entrada_txt(conteudo);
        anexar(colecao, novo_i, i);
    }
}

int main() {
    int n_indices = nova_entrada("Informe a qtd. de índices do array >>> ");
    char **array = array_indefinido(n_indices);

    novo_loop_for(n_indices, "Informe a dado >>> ", array);

    printf("\n{\n");
    for (int i = 0; i < n_indices; i++) {
        printf("    %s,\n", array[i]);
        free(array[i]);  
    }
    printf("\n}");

    free(array);  
    return 0;
}
