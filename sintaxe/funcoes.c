

#include <stdio.h>
#include <string.h>

void funcao_scanf() {
    /*
      OBJETIVO   || Receber dados externos vindos de um usuário 
      REQUISITOS || biblioteca <string.h>
      OBS        || Função similar ao "input" de Python
      OBS        || Diferente do input em Python, a mensagem NÃO é parâmetro da função
      OBS        || No C, se passa a mensagem em "printf" e em seguida vêm o uso de "scanf"
      
      Funcionamento
        => scanf("%tipo_do_dado", var_que_recebe_o_dado);
    */

    // Em dados NÃO ITERÁVEIS, é preciso passar "&" (End. de memória)
    int n_giros;
    printf("Defina um limite de giros >>> ");
    scanf("%i", &n_giros);
    printf("%d", n_giros);

    /*
      Em dados ITERÁVEIS, (ex: array de caracteres) não é preciso usar "&", se passa a variável diretamente
      Além disso, a variável que recebe dados deve ter um [tamanho_estipulado] antes de receber
    */
    char txt[15];
    printf("Informe um pais >>> ");
    scanf("%s", txt);
    printf("%s", txt);
}

void funcao_scanf_add_dados_sem_entrada_loop_for() {
    /*
      O array a receber dados já possui uma configuração específica
      O primeiro loop add os índices com base no "3" passado em "paises"
      O segundo loop mostra os índices antes indefinidos agora preenchidos por dados reais
    */
    char paises[3][15];
    for (int i = 0; i < sizeof(paises) / sizeof(paises[0]); i++) {
        printf("Informe o nome de um pais >>> ");
        scanf("%s", paises[i]);
    }
    
    for (int i = 0; i < sizeof(paises) / sizeof(paises[0]); i++) {
        printf("paises[%d] = %s\n", i, paises[i]);
    }
}

void funcao_scanf_add_dados_sem_entrada_loop_while() {
    /*
      O array a receber dados já possui uma configuração específica
      O primeiro loop add os índices com base no "3" passado em "paises"
      O segundo loop mostra os índices antes indefinidos agora preenchidos por dados reais
    */
    char paises[3][15];
    int giros = 0;
    int tamanho_array = sizeof(paises) / sizeof(paises[0]);
    while (giros < tamanho_array) {
        printf("Informe o nome de um pais >>> ");
        scanf("%s", paises[giros]);
        giros++;
    }
    for (int i = 0; i < tamanho_array; i++) {
        printf("paises[%d] = %s\n", i, paises[i]);
    }
}

void funcao_sizeof() {
    /*
      Objetivo: saber o tamanho de arrays
      Função se aplica a arrays de strings e numéricas
      Função não se aplica a arrays de caracteres e strings ponteiros (ao invés, usar "strlen")
    */
    int rank[3] = {1, 2, 3};
    char* pessoas[3] = {"Ash", "Brock", "Misty"};
    printf("rank = %i chars", sizeof(rank) / sizeof(rank[0]));
    printf("pessoas = %i chars", sizeof(pessoas) / sizeof(pessoas[0]));
}

void funcao_strcmp() {
    /*
      Uma string nunca terá somente 1 char, pois mesmo tendo 1, o caractere '\0' está lá implicitamente
      Se for tentado comparar '0' com '0', haverá erro
      Por isso as aspas duplas em "encerramento", que indica 1 índice + o caractere nulo '\0'
    */
    char substantivo[4] = "lua";
    char objeto[4] = "lua";
    char encerramento[2] = "0";
    char fim[2] = "0";
    printf("%d\n", strcmp(substantivo, objeto));
    printf("%d\n", strcmp(encerramento, fim));
}

void funcao_strlen() {
    /*
      OBJETIVO: saber o tamanho de strings
      Função só se aplica a strings em forma de ponteiro e arrays de caracteres, que são strings também
      Função não se aplica a arrays de strings e numéricas
    */
    char* pessoa = "Lucas";
    char linguagem[] = {'J', 'a', 'v', 'a', '\0'}; // Isso é uma string (é estranho)
    printf("pessoa = %i chars\n", strlen(pessoa));
    printf("linguagem = %i índices\n", strlen(linguagem));
}

void funcao_parametros(char letra, char *string, char **array, int t1, int *array_n, int t2) {
    /*
      Ordem dos parâmetros: caractere, string ponteiro/array de caracteres, array de str, array numérico
      Nos parâmetros "array" e "array_n" temos a seguinte questão
      Se o intuito for receber arrays numa função, a abordagem correta é processar seus tamanhos fora da função
      Esses tamanhos se tornam parte da função, sendo passados em forma de parâmetro
      
      ======= USAR EM int main() =======
      char letra = 'c';
      char vogais[6] = "aeiou";
      char *pessoas[3] = {"Ash", "Brock", "Misty"};
      int rank[3] = {1, 2, 3};
      int tamanhoA = sizeof(pessoas) / sizeof(pessoas[0]);
      int tamanhoB = sizeof(rank) / sizeof(rank[0]);
      parametros(letra, vogais, pessoas, tamanhoA, rank, tamanhoB);
    */
    printf("%c\n", letra);
    printf("%s\n", string);
    printf("\n");
    for (int i = 0; i < t1; i++) {
      printf("%s\n", array[i]);
    }
    printf("\n");
    for (int j = 0; j < t2; j++) {
      printf("%d\n", array_n[j]);
    }
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    
    return 0;
}
