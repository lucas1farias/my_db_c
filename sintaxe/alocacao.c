

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alocacao_infos() {
    /*
      Se dá através da função "malloc"
      Se esta função for usada, ao final do que for feito com ela, a função "free" deve ser utilizada
      
      A função é usada de forma diferente dependendo do tipo do dado
          -> array de caracteres || "free" na variável do array
          -> array de números    || "free" na variável do array
          -> array de strings    || "free" em cada índice da variável do array (via loop)
    */
}

// Função de alocação dinâmica quando for um array de números
int* alocar_dinamicamente_array_n(int tamanho) {
    /*
      Normalmente não se cria essa função, apenas se usa essa linha da função
    */
    int *colecao = (int *)malloc(tamanho * sizeof(int));
    return colecao;
}

// Função de alocação dinâmica quando for um array de strings
char** alocar_dinamicamente_array_str(int tamanho) {
    char **colecao = (char **)malloc(tamanho * sizeof(char *));
    return colecao;
}

void alocacao_valores_nao_iteraveis() {
    /*
      O que está acontecendo aqui?
    */
    int acumulado, n_giros, i;
    int total = 0;
    
    printf("Informe quantos numeros deseja somar >>> ");
    scanf("%d", &n_giros);
    
    /* 
      Alocação dinâmica em memória
      Equivalente a: <<< int nums[n_giros]; >>> que não é permitido ser feito diretamente
    */
    int *nums = (int *)malloc(n_giros * sizeof(int));

    /*
      Boa prática envolvendo alocação de memória
      Caso a alocação não seja bem sucedida, haverá um ponteiro com retorno NULL
      Com isso, pode haver comportamentos inesperados, e o "if" entre como um tratamento p/ este erro
    */
    if (nums == NULL) {
        printf("======= Aviso =======\nErro ao alocar memoria. Encerrando o programa.\n");
    }

    for (i = 0; i < n_giros; i++) {
        printf("Informe o numero %d da lista >>> ", i + 1);
        scanf("%d", &acumulado);
        total += acumulado;
    }

    printf("TOTAL: %d", total);
    /* Em toda alocação dinâmica, o espaço tende a ser liberado após seu uso */
    free(nums);
}

void alocacao_em_array_numerico() {
    
    /*
      O tamanho de um array precisa ser conhecido em tempo de compilação, o que significa que ele deve ser 
      especificado explicitamente em uma variável ou como uma constante no código-fonte, ou então obtido a 
      partir de uma entrada fornecida pelo usuário. Quando você utiliza a alocação dinâmica de memória com 
      "malloc", o tamanho do array precisa ser conhecido em tempo de execução.
    */

    // Alocação dinâmica em um ponteiro que será um array que espera valores numéricos
    const int TAMANHO = 3;
    int *numeros = alocar_dinamicamente_array_n(TAMANHO);
    
    /* 
      No caso de array de números, eles podem receber dados diretamente
      Se fosse array de strings, precisaria de "malloc" + "strcpy" ou "strdup" (junção das duas)
    */
    numeros[0] = 1;
    numeros[1] = 2;
    numeros[2] = 3;
    
    // Tratamento recomendável caso haja erro na indexação na memória
    if (numeros == NULL) {
        printf("========== Aviso ==========\nErro ao alocar memória. Encerrando o programa.\n");
    }
    
    // Como o tamanho NÃO pode ser obtido de forma dinâmica, a CONSTANTE se torna a referência de tamanho
    printf("========== Elementos do array ==========\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", numeros[i]);
    }

    // Se tratando de um array de números, não é preciso percorrer cada índice
    free(numeros);
}

void alocacao_em_array_numerico_com_entrada() {
    int n;

    printf("Informe a qtd. de indices p/ o array >>> ");
    scanf("%d", &n);
    
    // Array numérico criado dinamicamente
    int *numeros = alocar_dinamicamente_array_n(n);
    
    // Tratamento recomendável caso haja erro na indexação na memória
    if (numeros == NULL) {
        printf("========== Aviso ==========\nErro ao alocar memória. Encerrando o programa.\n");
    }
    
    /*
      ========== DETALHES RELEVANTES ==========
      Em "numeros[i]", != de array de strings, (int) não recebe ponteiro, pois os dados não são iteráveis
      Em "scanf", como estamos tratando de números, usamos "&" seguido do valor
    */
    printf("Informe cada elemento do array abaixo\n");
    for (int i = 0; i < n; i++) {
        numeros[i] = (int)malloc(n * sizeof(int));
        scanf("%d", &numeros[i]);
    }
    
    printf("========== Elementos do array ==========\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    
    // Sendo array de números, a função "free" pode ser usada diretamente sem percorrer cada índice
    free(numeros);
}

void alocacao_dinamica_em_array_strings() {
    const int TAMANHO = 3;

    char **pessoas = alocar_dinamicamente_array_str(TAMANHO);
    
    /*
      ========== OBS ========== 
      forma mais eficiente: alocacao_dinamica_em_array_strings_melhorada
      
      Numa alocação dinâmica, a função "malloc" precisa do tamanho da string como primeiro parâmetro
      Por esse motivo, está sendo usado "strlen("string")"
      E somente depois de alocar, os índices de "pessoas" recebem as strings via "strcpy"
    */
    pessoas[0] = (char *)malloc((strlen("Ash") + 1) * sizeof(char));
    pessoas[1] = (char *)malloc((strlen("Brock") + 1) * sizeof(char));
    pessoas[2] = (char *)malloc((strlen("Misty") + 1) * sizeof(char));
    strcpy(pessoas[0], "Ash");
    strcpy(pessoas[1], "Brock");
    strcpy(pessoas[2], "Misty");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%s ", pessoas[i]);
    }
    
    // Liberação dos índices da variável da memória
    for (int i = 0; i < TAMANHO; i++) {
        free(pessoas[i]);
    }
    
    // Liberação da variável da memória
    free(pessoas);
}

void alocacao_dinamica_em_array_strings_melhorada() {
    const int TAMANHO = 3;

    char **pessoas = alocar_dinamicamente_array_str(TAMANHO);
    
    // Faz ao mesmo tempo o que é feito em "malloc" e "strcpy"
    pessoas[0] = strdup("Ash");
    pessoas[1] = strdup("Brock");
    pessoas[2] = strdup("Misty");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%s ", pessoas[i]);
    }

    for (int i = 0; i < TAMANHO; i++) {
        free(pessoas[i]);
    }
    
    free(pessoas);
}

void alocacao_dinamica_em_array_strings_usando_entrada() {
    int tamanho;
    const int TAMANHO_CADA_STRING = 30;
    
    printf("Informe o tamanho do array: ");
    scanf("%d", &tamanho);

    char **strings = alocar_dinamicamente_array_str(tamanho);

    if (strings == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
    }
    
    // Como é feita a alocação
    printf("Informe as strings do array:\n");
    for (int i = 0; i < tamanho; i++) {
        strings[i] = (char *)malloc(TAMANHO_CADA_STRING * sizeof(char));
        scanf("%s", strings[i]);
    }

    printf("Elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", strings[i]);
    }

    // Liberação dos índices da variável da memória
    for (int i = 0; i < tamanho; i++) {
        free(strings[i]);
    }

    // Liberação da variável da memória
    free(strings);
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    return 0;
}
