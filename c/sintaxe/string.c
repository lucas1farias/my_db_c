

#include <stdio.h>

void string_ascii() {
    /*
      Quando letras são comparadas (uso do operador), seus códigos ASCII são considerados
      Ou seja, se letras estiverem envolvidas em operações booleanas, seus ASCII são comparados
    */

    // Isso resulta em 0 (equivalente ao falso), pois "d" não é menor que "b"
    char letraD = 'd';
    char letraC = 'b';
    printf("%d", letraD < letraC);
}

void string_caractere_contra_barra_zero() {
  /*
      Strings terminam com o caracter '\0' chamado de "null terminator"
      Ele serve para indicar o fim de ambas as coleções
      Esse caracter é implícito (invisível) em strings em forma de ponteiro (a)
      Esse caracter NÃO é implícito em arrays de caracteres
      Em "b" o '\0' ocupa a posição 4 (implicitamente), já que os outros 3 caracteres ocupam o resto
    */
    char *a = "abc";
    char b[4] = {'a', 'b', 'c'};
}

void string_f_concatenar(char *str_fixa, char *str_complementar) {
    while (*str_fixa) {
        str_fixa++;
    }
    while (*str_complementar) {
        *str_fixa = *str_complementar;
        str_fixa++;
        str_complementar++;
    }
    *str_fixa = '\0';

    /* ====== main =======
      char capital[9] = "Teresina";
      char estado[4] = "/PI";
      string_f_concatenar(capital, estado);
      printf("%s", capital);
    */
}

void string_f_concatenar_v2(char *str_fixa, char *str_complementar) {
    int t_fixa = strlen(str_fixa);
    int i;
    int j = 0;
    
    for (i = 0; str_complementar[j] != '\0'; i++, j++) {
        str_fixa[t_fixa + i] = str_complementar[j];
    }
    str_fixa[t_fixa + i] = '\0';

    /* ====== main =======
      char estado[4] = "/PI";
      char capital[9] = "Teresina";
      string_f_concatenar(capital, estado);
      printf("%s", capital);
    */
}

char* string_f_fatiar(const char* str, int inicio, int fim) {
    // Verifica se os índices são válidos de acordo com o tamanho da coleção
    int tamanho_str = strlen(str);
    if (inicio < 0 || inicio >= tamanho_str || fim <= inicio || fim >= tamanho_str) {
        printf("Indices invalidos!\n");
        return NULL;
    }

    // Tamanho da nova string (+ 1 p/ caractere nulo '\0')
    int n_indices = fim - inicio + 1;

    // Alocação
    char *nova_string = (char*)malloc((n_indices + 1) * sizeof(char));

    // Copia os caracteres correspondentes da string original para a nova string
    int i, j = 0;
    for (i = inicio; i <= fim; i++) {
        nova_string[j] = str[i];
        j++;
    }

    // Adiciona o terminador nulo no final da nova string
    nova_string[j] = '\0'; 

    return nova_string;

    /*
      char nome[29] = "Javascript";
      char *nome_fatiado = fatiar(nome, 0, 3);
      
      printf("%s (%d caracteres)", nome_fatiado, strlen(nome_fatiado));
      free(nome_fatiado);
    */
}

void string_formatacao_fstring() {
    /*
      Sintaxe que têm relação direta com a função "printf"
      Sintaxe || printf("%letra", nome_var)
      Ex      || printf("%i %lc", nome_var, nome_var) (quanto for preciso)

      %d ou %i  || Inteiro decimal
      %f ou %lf || Número de ponto flutuante
      %c        || Caractere
      %s        || String (cadeia de caracteres)
      %p        || Ponteiro
      %x ou %X  || Valor hexadecimal
      %u        || Inteiro decimal sem sinal
      %o        || Inteiro octal
      %e ou %E  || Número em notação científica
      %g ou %G  || Número em formato geral
  */
}

void string_instanciacao() {
    /*
      A primeira forma de instanciamento é a mais apropriada p/ o intuito de modificação 
      Essa forma normalmente envolve informar a qtd. de slots de memória
      O valor 7 é o mínimo esperado neste contexto (pode haver muito + do que isso)
      O valor 7 equivale a: 6 caracteres da string + o caractere nulo '\0'
    */

    // Array de caracteres = é considerado string
    char linguagem[7] = "python";

    // String com ponteiro
    char* linguagemB = "python";

    linguagem[0] = 'v';
    printf("%s", linguagem);
}

void strings_operacoes() {
    /*
      É possível efetuar operações entre strings, pois C leva em consideração os valores ASCII
      Esse tipo de abordagem é usada em algoritmo de anagrama, por exemplo
    */
    printf("%d", 'd' - 'a');
}

void string_tamanho_um() {
    // String de apenas um caractere são instanciados em aspas simples
    char letra = 'a';
    printf("%c", letra);
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    
    return 0;
}
