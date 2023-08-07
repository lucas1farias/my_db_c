

/* 
  Programar em C - Introdução Ponteiros(Prática) - Aula 61
  https://www.youtube.com/watch?v=AdyGxhYWhoM
*/

/*
PERGUNTA: Porque meu código está tendo esse retorno?
aula_61.c: In function 'main':
aula_61.c:26:18: warning: initialization makes pointer from integer without a cast [-Wint-conversion]
    int* local = 4214929;
*/

#include <stdio.h>

int main() {
    int x;  // A memória do pc é requisitada com um pedido de espaço de memória p/ uma variável chamada "x"
    x = 10; // No espaço de memória eu estou armazenando o valor "10"
    printf("valor de 'x' = %i\n", x);
    printf("endereco de 'x' = %i\n", &x); // endereço de memória que está contendo "x"
    
    // Uma string
    char* nome = "Lucas";     // Ela possui um ponteiro
    printf("%i\n", &nome);    // Acesso ao valor de endereço de "nome"
    printf("%i\n", &nome[0]); // Acesso ao valor de endereço de "nome" na posição [0]
    printf("%i\n", &nome[1]); // idem [1]
    printf("%i\n", &nome[2]); // idem [2]
    printf("%i\n", &nome[3]); // idem [3]
    printf("%i\n", &nome[4]); // idem [4]
    
    // Está sendo inserido dentro de "local" um valor de endereço que pode está guardando algo
    // Tecnicamente, por debaixo dos panos: int* local = &nomes[4]
    int* local = 4214929;  
    
    // O ponteiro é aplicado na instância "int* local" e na sua chamada "*local")
    printf("%c\n", *local);
    
    // Um array
    // char** nomes = {"Ash", "Misty", "Brock"};
    // printf("Endereço de memória de 'nomes' = %i", &nomes);

    printf("\n========== CASO: ponteiro apontando para valor do endereço de memoria ==========\n");
    int* ponteiro = &x;        // Se aponta para um endereço de memória:
    printf("%i\n", ponteiro);  // Chamada sem * retorna o valor de endereço
    printf("%i\n", *ponteiro); // Chamada com * chama o valor no endereço
    
    char* letra_l = &nome[0];
    printf("%i\n", letra_l);
    printf("%c\n", *letra_l);
    
    printf("\n========== CASO: nao ha relacao direta de 'b' com 'a' ==========\n");
    int a = 0;
    int b = a;
    a = 1;
    printf("a = %i / b = %i", a, b);

    printf("\n========== CASO: alterando a referencia do ponteiro + o ponteiro ==========\n");
    int c = 0;
    int* d = &c;
    int e = 1;
    printf("%i %i %i\n", c, *d, e);
    /*
      "d" é um ponteiro que => p/ o VEM de "c", então até o momento "c" e "d" = 0, pois "c" = 0
      quando "*d" é usado, se está alterando o seu valor
      como "d" => p/ o VEM de "c", os valores de "d" e "c" são alterados simultaneamente
      o valor de "d", por => p/ um VEM, só é visto via uso do "*"
    */
    *d = e; 
    printf("%i %i %i", c, *d, e);
    return 0;
}
