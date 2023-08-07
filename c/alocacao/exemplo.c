

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
    /*
      Quando for passar uma entrada p/ "scanf", é recomendável que ela já venha com alocação
      O dado retornado aqui é uma string que será um índice de um array
      
      Vamos supor o seguinte:
          O array alvo seja       => char **array = alocação dinâmica de 3 slots (3 índices);
          A string retornada seja => "Ash"
      
      "Ash" será o índice 0 de "array"
      A alocação dinâmica sobre "Ash" acontece por não se saber de qual tamanho "Ash" será até ele ser passado
      Na função "anexar", a string recebida ("Ash"), precisa ser alocada em (**array)
      Para que "Ash" se torne um índice de (**array), é preciso saber seu tamanho, p/ depois copiá-la p/ lá
      
      Ao todo temos 3 procedimentos (1 acontece aqui, os outros 2 na função "anexar")
          . Alocação p/ "Ash"
              * Que é estipulada, pois o usuário não se importa de contar o tamanho da string
              * Não se pede ao usuário p/ contar, p/ que ele passe esse valor e você atribuia ele a string
          . Alocação de "Ash" p/ o índ. do array, ou seja, o tamanho da string deste índice (strlen("Ash") + 1)
          . Cópia de "Ash" p/ o índice alvo do array
    */
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

void percorrer(char *colecao[], int t) {
    printf("\n{\n");
    for (int i = 0; i < t; i++) {
        printf("    %s,\n", colecao[i]);
    }
    printf("\n}");
}

void liberar_memoria(char *colecao[], int t) {
    for (int i = 0; i < t; i++) {
        free(colecao[i]);
    }
    free(colecao);
}

int main() {
    int n_indices = nova_entrada("Informe a qtd. de índices do array >>> ");
    char **array = array_indefinido(n_indices);
    novo_loop_for(n_indices, "Informe a dado >>> ", array);
    percorrer(array, n_indices);
    liberar_memoria(array, n_indices);
    return 0;
}
