

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ponteiro_alocacao_dinamica() {
    /*
      A função "sizeof" não é capaz de obter o tamanho de um array alocado dinamicamente
      Normalmente nesse contexto, temos uma entrada que recebe o tamanho a ser desejado
      Esse dado passado como entrada é que servirá de tamanho oficial deste array
      Exemplo: void ponteiro_alocacao_dinamica_array_numeros (repr: "n")
    */
}

void ponteiro_alocacao_dinamica_array_numeros() {
    int n, i, *ponteiro= 0;
    printf("Informe a qtd. de indices que o array de numeros tera >>> ");
    scanf("%d", &n);

    // Procedimento de alocação no ponteiro
    ponteiro = (int *) malloc(n * sizeof(int));
    
    // Tratamento padrão caso alocação não funcione corretamente por algum motivo
    if (ponteiro == NULL) {
        printf("\n======= Aviso =======\nMemoria nao pode ser alocada. Programa encerrado!\n");
        return 0;
    }
    
    /* 
      Aqui temos algo que eu considero estranho, pois C não foi minha primeira linguagem
      O conteúdo no "for" está fazendo o equivalente em JS:

          ponteiro = []
          ponteiro_i = 0
          ponteiro[ponteiro_i] = ponteiro[i]
      
      A questão é que a prática acima, em C, não é a convencional
      Em um contexto de alocação dinâmica, a forma apresentada abaixo é mais conhecida
      Ao invés de ser usado a notação de [], se faz uma operação de + entre a coleção e o índice
      Portanto: ponteiro[ponteiro_i] = ponteiro[i] == scanf("%d", ponteiro + i);
    */
    printf("Informe cada el. do array \n");
    for (i = 0; i < n; ++i) {
        printf("ponteiro[%d] >>> ", i);
        scanf("%d", ponteiro + i);
    }

    printf("Cada el. do array anexado\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ponteiro[i]);
    }

    // Memória liberada após todos os procedimentos
    free(ponteiro);
}

void ponteiro_alocacao_dinamica_array_numeros_exemplo_incrementacao() {
    /*
      A incrementação é estranha, mas é a forma mais apropriada
    */
    int n, i, somatorio = 0;
    int *rank;
    printf("N de i do array >>> ");
    scanf("%d", &n);
    rank = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", rank + i);
        somatorio += *(rank + i); // aqui
    }
    printf("%d", somatorio);
    printf("Qtd. de índices do array 'rank': %d\n", n);
    for (i = 0; i < n; i++) {
        printf("%d.", rank[i]);
    }
    free(rank);
}

void ponteiro_alteracao_indireta() {
    int c = 0;
    int* d = &c;
    int e = 1;
    printf("%i %i %i\n", c, *d, e);
    /*
      "d" é um ponteiro que => p/ o EM de "c", então até o momento "c" e "d" = 0, pois "c" = 0
      quando "*d" é usado, se está alterando o seu valor
      como "d" => p/ o EM de "c", os valores de "d" e "c" são alterados simultaneamente
      o valor de "d", por => p/ um EM, só é visto via uso do "*"
    */
    *d = e; 
    printf("%i %i %i", c, *d, e);
}

void ponteiro_editar_valor_nao_iteravel(int *ponteiro, int valor) {
    *ponteiro = valor;
    /*
      int nota = 2;
      printf("%d\n", nota);
      ponteiro_editar_valor_nao_iteravel(&nota, 7);
      printf("%d\n", nota);
    */
}

void ponteiro_editar_valor_indice_array_str(char *colecao, int i, char novo) {
    colecao[i] = novo;
    /*
      char pessoa[30] = {'A', 'n', 'a', '\0'};
      printf("%s\n", pessoa);
      ponteiro_editar_valor_indice_array_str(pessoa, 2, 'i');
      printf("%s\n", pessoa);
    */
}

void ponteiro_editar_valor_indice_array_int(int *colecao, int i, int novo) {
    colecao[i] = novo;
    /*
      int rank[3] = {1, 2, 3};
      int i;
      for (i = 0; i < sizeof(rank) / sizeof(rank[0]); i++) {
          printf("%d; ", rank[i]);
      }
      ponteiro_editar_valor_indice_array_int(rank, 0, 10);
      printf("\n");
      for (i = 0; i < sizeof(rank) / sizeof(rank[0]); i++) {
          printf("%d; ", rank[i]);
      }
    */
}

// Muito importante
void ponteiro_duplo() {
    char *pessoas[10] = {"Ash", "Brock", "Misty"};
    
    /*
      Por qual motivo "**pessoas_ptr" recebe 2 asteríscos?
      Por ser um ponteiro apontando p/ outro ponteiro
      O primeiro ponteiro aponta p/ os índices do array de strings "*pessoas"
      O segundo ponteiro aponta p/ o array de strings "*pessoas"
    */
    char **pessoas_ptr;
    pessoas_ptr = pessoas;
    
    // O ponteiro sendo usado e incrementado
    for (int i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        printf("%s\n", *pessoas_ptr);
        pessoas_ptr++;
    }
}

void ponteiro_funcionamento_iteraveis() {
    /*
      6422299
      6422299
      6422300
      6422301
      6422302
      Em C, o endereço de memória de um array de caracteres e o endereço de memória do seu primeiro índice
      são os mesmos
    */
    
    char linguagem[5] = "Java";

    printf("%i\n", &linguagem);
    printf("%i\n", &linguagem[0]);
    printf("%i\n", &linguagem[1]);
    printf("%i\n", &linguagem[2]);
    printf("%i\n", &linguagem[3]);
}

void ponteiro_funcionamento_nao_iteraveis() {
    /*
      "p" e "q" são definidos como ponteiros (presença de *)
      "first" e "second" são receptores do end. de memória do que o usuário passar como entrada
      Quando ponteiros forem instanciados, eles recebem end. de memória (não usar * na instanciação)
      Quando for acessar os valores nos ponteiros, usar * neles
    */
    int first, second, *p, *q, sum;

    printf("Informe os inteiros >>> \n");
    scanf("%d%d", &first, &second);
    p = &first;
    q = &second;
    sum = *p + *q;
    printf("======= Resultado =======\n%d\n", sum);
}

void ponteiro_funcionamento_nao_iteraveis_exemplo_2() {
    /*
      O contexto envolve ponteiros com dados numéricos
      "p" e "q" são definidos como ponteiros (presença de *)
      "first" e "second" são variáveis comuns que recebem EM do que o usuário passa como entrada
      Quando se cria um ponteiro, o objetivo é que ele recebe o EM de alguma variável (uso do &)
      Justamente por isso, temos "p" e "q" recebendo "&" junto com "nome da var" (não usar * na instanciação)
      Quando for acessar os valores nos ponteiros, usar * neles
    */
    int first, second, *p, *q, sum;

    printf("Informe os inteiros >>> \n");
    scanf("%d%d", &first, &second);
    p = &first;
    q = &second;
    sum = *p + *q;
    printf("======= Resultado =======\n%d\n", sum);
}

/*
  No loop 1 é usado percorrimento de índices com ponteiro (comum em C)
  No loop 2 é usado indexação direta (comum em linguagens de alto nível)

  No primeiro loop com o uso de ponteiro (*rank_ptr), você está avançando o ponteiro para acessar cada elemento 
  do array, o que é uma abordagem mais comum em C quando você precisa trabalhar com ponteiros ou quando quer 
  evitar criar uma nova variável para o índice, economizando assim em uso de memória.

  No segundo loop com a abordagem de índice direto (rank[i]), você está acessando diretamente os elementos do 
  array usando o índice i, que é uma abordagem mais simples e direta, e é a forma mais comum em outras 
  linguagens como Python e JavaScript.

  Em muitos casos, é preferível usar a abordagem mais simples com índices diretos, a menos que o uso de 
  ponteiros seja realmente necessário (por exemplo, para trabalhar com alocação dinâmica de memória ou passar 
  argumentos para funções por referência). Em muitos outros casos, a otimização não é uma preocupação imediata, 
  e a legibilidade e a simplicidade do código devem ser priorizadas.
*/
void ponteiro_percorrer_dados_em_array_numerico() {
    const int MAX = 3;
    int rank[] = {1, 2, 3};
    int i, *rank_ptr;

    /* O ponteiro indefinido agora detêm o EM do array "rank" */
    rank_ptr = rank;

    for (i = 0; i < MAX; i++) {
        /*
            Demonstração de acesso: endereço e valor
            O valor do ponteiro é sempre acessado via *nome_do_ponteiro
            printf("Endereco || rank[%d] = %p\n", i, ptr);
            printf("Valor    || rank[%d] = %d\n", i, *ptr);
        */

        // Demonstração de que o ponteiro se mexe sem a necessidade do "i"
        if (*rank_ptr == 1) {
            printf("Inicio do loop: %d\n", *rank_ptr);
        }
        else if (*rank_ptr == 2) {
            printf("Centro do loop: %d\n", *rank_ptr);
        }
        else {
            printf("Fim do loop: %d\n", *rank_ptr);
        }

        /* Movimento do ponteiro p/ o próximo i */
        rank_ptr++;
    }

    printf("\n");

    for (i = 0; i < MAX; i++) {
        if (rank[i] == 1) {
            printf("Inicio do loop: %d (2)\n", rank[i]);
        }
        else if (rank[i] == 2) {
            printf("Centro do loop: %d (2)\n", rank[i]);
        }
        else {
            printf("Fim do loop: %d (2)\n", rank[i]);
        }
    }
}

void ponteiro_percorrer_dados_em_array_strings() {
    char *pessoas[10] = {"Ash", "Brock", "Misty"};
    char **pessoas_ptr;
    pessoas_ptr = pessoas;

    for (int i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        printf("%s\n", *pessoas_ptr);
        pessoas_ptr++;
    }
}

void ponteiro_percorrer_array_em_estrutura() {
    char *pessoas[10] = {"Ash", "Brock", "Misty"};
    char **pessoas_ptr;
    pessoas_ptr = pessoas;
    
    // Em um array de strings fora de uma estrutura, o ponteiro funciona normalmente
    for (int i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        printf("%s\n", *pessoas_ptr);
        pessoas_ptr++;
    }
    printf("\n");
    
    // O problema é quando o array de strings se encontra dentro de uma estrutura
    struct amigos {
        char nome_grupo[30];
        char *integrantes[30]; // um array de strings que não é mais independente
    };

    /* 
      O primeiro ponteiro criado (*ptr) não consegue acessar diretamente os dados do atrib. "integrantes"
      Motivo? O array de strings não é mais independente (caso acima), ele está dentro de 1 estrutura
      A solução é configurar 2 ponteiros (*ptr2) e (*ptr_cada_integrante)
      O segundo ponteiro (*ptr2) não aponta direto p/ o objeto, mas p/ o EM deste objeto
      O terceiro ponteiro, que é o principal, apontará diretamente p/ a estrutrua no atrib. "*integrantes"
      Fazendo isso, temos o resultado similar ao feito acima, onde o array de strings é independente
    */
    struct amigos grupo_lagartixa = {"Lagartixa", {"Ash", "Brock", "Misty"}};
    struct amigos *ptr;
    struct amigos *ptr2 = &grupo_lagartixa;
    char **ptr_cada_integrante = ptr2->integrantes;
    
    // Com ponteiro
    for (int i = 0; i < sizeof(grupo_lagartixa.integrantes) / sizeof(grupo_lagartixa.integrantes[0]); i++) {
        printf("%s\n", *ptr_cada_integrante);
        ptr_cada_integrante++;
    }

    // Sem ponteiro (forma direta)
    printf("\n");
    for (int i = 0; i < sizeof(grupo_lagartixa.integrantes) / sizeof(grupo_lagartixa.integrantes[0]); i++) {
        printf("%s\n", grupo_lagartixa.integrantes[i]);
    }
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    return 0;
}
