

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função com parâmetro reutilizável (usado na função "filtrar")
typedef int (*letra_inicial_ptr)(char, char);

// Função de alocação dinâmica quando for um array de números
int* alocar_dinamicamente_array_n(int tamanho) {
    int *colecao = (int*)malloc(tamanho * sizeof(int));
    return colecao;
}

// Função de alocação dinâmica quando for um array de strings
char** alocar_dinamicamente_array_str(int tamanho) {
    char **colecao = (char**)malloc(tamanho * sizeof(char*));
    return colecao;
}

// Função p/ obter valor ascii inteiro de um caractere (através da tipagem da função)
int ascii(char caractere) {
    return caractere;

    /*
      char *alfabeto = "abcdefghijklmnopqrstuvwxyz";
      for (int i = 0; i < strlen(alfabeto); i++) {
        printf("alfabeto[%d] = %c = %d\n", i, alfabeto[i], ascii(alfabeto[i]));
      }
    */
}

// Função que compara strings (muito útil p/ encerrar loops que recebem entrada de texto)
int comparar_strings(char strA[], char strB[]) {
    int i = 0, diferenca = 0;

    while (strA[i] != '\0' && strB[i] != '\0') {
        if (strA[i] != strB[i]) {
            diferenca = 1;
            break;
        }
        i++;
    }

    if (diferenca == 0 && strA[i] == '\0' && strB[i] == '\0') 
        return 1;
    else
        return 0;

    /*
        ========== main =========
        char entrada[20] = "a";
        char fim[2] = "0";
        
        while (comparar_strings(entrada, fim) != 1) {
            printf("Informe um texto ou 0 p/ sair >>> ");
            scanf("%s", entrada);
        }
    */
}

// Encerrar loop while com número inteiro 0
int encerrar(int cmd) {
    return cmd == 0;
}

// Função que ajuda na compreensão de alocação dinâmica em array de strings
char** filtrar(letra_inicial_ptr criterio, char **colecao, int colecao_t, char ref) {
    int i;
    int j = 0;
    int qtd_i = 0; 
    
    for (i = 0; i < colecao_t; i++) {
        if (criterio(colecao[i][0], ref) == 1) {
            qtd_i++;
        }
    }
    
    // Como é a alocação caso seja um array de strings
    char **array = (char**)malloc(qtd_i * sizeof(char*));
    
    for (i = 0; i < colecao_t; i++) {
        if (criterio(colecao[i][0], ref) == 1) {
            array[j] = strdup(colecao[i]);
            j++;
        }
    }
    
    /*
      No contexto da função, o array criado dinamicamente (char **array) não consegue informar seu tamanho
      Ou seja, fora da função, se eu quiser ver seus dados, estes não serão apresentados corretamente
      Para resolver isso, é preciso ter algo dentro da função que torne possível a obtenção esse valor
      A linha de código abaixo consegue fazer isso
      Ao anexar NULL, em C, temos o índicio do fim de um array
      Com isso, podemos criar uma função simples "tamanho", que consegue substituir "sizeof"
      Combinando esta linha com a função "tamanho", se pode percorrer os dados do array dinâmico corretamente
    */
    array[qtd_i] = NULL;

    return array;
}

// Função critério p/ exemplificar o uso da função "filtrar"
int letra_inicial(char letra, char ref) {
    return letra == ref;
}

// Função que ajuda na compreensão de como liberar memória em array de strings
void liberar_memoria(char **colecao, int t) {
    for (int i = 0; i < t; i++) {
        free(colecao[i]);
    }
}

// Função útil p/ obter tamanhos de array criados dinamicamente (pelo fato de "sizeof" não funcionar)
int tamanho(char **colecao) {
    int i = 0;
    while (colecao[i] != NULL) {
        i++;
    }
    return i;
}

void array_dinamico_obter_tamanho() {
    /*
      Um array dinamicamente criado não consegue usar a função "sizeof"
      Se criado no escopo main, existirá alguma var. que guarde seu tamanho, desprezando o uso de "sizeof"
      Se criado no escopo de uma função, ai será preciso procedimentos !=
      A explicação disso está na função "filtrar" e na função "tamanho" (ambas tornam possível)
    */
}

void array_indefinidos() {
    /*
       Caso 1: array indefinido com dados seguros pré definidos
       O tamanho foi definido como 3, e o zero foi escolhido como caractere padrão
       O array terá 3 zeros, ao invés de 3 EM aleatórios livres escolhidos pelo computador
    */
    char *pessoas[3] = {0};
    printf("{\n");
    for (int i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        printf("    %d,\n", pessoas[i]);
    }
    printf("}");
    
    /*
       Caso 2: array indefinido com dados aleatórios livres escolhidos pelo computador
       O tamanho foi definido como 3, e receberá 3 EM aleatórios
       Esse método pode gerar erros dependendo da escolha do EM, é melhor não usar
    */
    char *objetos[3];
    printf("\n\n{\n");
    for (int i = 0; i < sizeof(objetos) / sizeof(objetos[0]); i++) {
        printf("    %d,\n", objetos[i]);
    }
    printf("}");
}

void array_str_alterar_indice() {
    char *array[] = {"Ash", "Brock", "Misty"};
    
    printf("%s\n", array[0]);

    // Alteração
    array[0] = (char*)malloc(strlen("Ana") + 1);
    strcpy(array[0], "Ana");

    printf("%s", array[0]);
}

void array_str_fixo_com_null() {
    // Um array é instanciado desta forma somente se for desejado usar um ponteiro sobre ele
    char *array[] = {"Ash", "Brock", "Misty", NULL};
    
    // Até porque o seu tamanho não fica exatamente correto, pois NULL também é contado como índice
    printf("%d\n", sizeof(array) / sizeof(array[0]));

    // Criando um ponteiro
    char **ptr = array;

    // Usando um ponteiro
    printf("\n{\n");
    while (*ptr) {
        printf("    %s,\n", *ptr);
        ptr++;
    }
    printf("\n}");

    // Outra forma
    printf("\n{\n");
    for (int i = 0; array[i] != NULL; i++) {
        printf("    %s,\n", array[i]);
    }
    printf("\n}");
}

// Têm as mesmas funcionalidades de char array[int]
void array_str_fixo_sem_null() {
    // Um array é instanciado desta forma quando se quer flexibilidade p/ obter seu tamanho
    char *array[] = {"Ash", "Brock", "Misty"};
    
    // Como se obtem o tamanho
    int tm = sizeof(array) / sizeof(array[0]);
    printf("%d\n", tm);
    
    // Iteração for
    printf("\n{\n");
    for (int i = 0; i < tm; i++) {
        printf("    %s,\n", array[i]);
    }
    printf("\n}");
    
    // Iteração while
    int i = 0;
    printf("\n{\n");
    while (i < tm) {
        printf("    %s,\n", array[i]);
        i++;
    }
    printf("\n}");
}

void array_str_com_slots_livres() {
    // De 10 slots possíveis de dados, 3 deles estão preenchidos com algum valor
    char *pokemons[10] = {"Articuno", "Moltres", "Zapdos"};
    
    // Usando != NULL como critério, são exibidos somentes os dados já alocados
    printf("\n{\n");
    for (int i = 0; pokemons[i] != NULL; i++) {
        printf("    %s,\n", pokemons[i]);
    }
    printf("\n}");
    
    // Usando "sizeof" como critério de parada, os slots reservados são exibidos
    printf("\n{\n");
    for (int i = 0; i < sizeof(pokemons) / sizeof(pokemons[0]); i++) {
        printf("    %s,\n", pokemons[i]);
    }
    printf("\n}");
    
    // Como há slots não reservados, então qualquer um deles pode ser preenchido com um dado real
    pokemons[7] = (char*)malloc(strlen("Dragonite") + 1);
    strcpy(pokemons[7], "Dragonite");
    
    // Podemos ver que o dado alocado acima, de fato foi anexado ao índice especificado acima
    printf("\n{\n");
    for (int i = 0; i < sizeof(pokemons) / sizeof(pokemons[0]); i++) {
        printf("    %s,\n", pokemons[i]);
    }
    printf("\n}");
    
    // Processo habitual de liberação de memória após alocação dinâmica
    for (int i = 0; i < sizeof(pokemons) / sizeof(pokemons[0]); i++) {
        free(pokemons[i]);
    }
}

void alocacao_infos() {
    /*
      Se dá através da função "malloc"
      Se esta função for usada, ao final do que for feito com ela, a função "free" deve ser utilizada
      
      Uso da função "free" dependendo do tipo do dado
          -> array de caracteres || "free" na variável do array
          -> array de números    || "free" na variável do array
          -> array de strings    || "free" em cada índice da variável do array (via loop)
    */
}

void alocacao_funcionamento_escopo_main() {
    
    // Temos um array de caracteres com tamanho definido e tamanho fixo (não será modificado)
    char *jogo[3] = {"pedra", "papel", "tesoura"};
    int jogo_t = sizeof(jogo) / sizeof(jogo[0]);

    // Por "contador" saberemos quantos i possuem uma letra inicial específica (ex. de filtragem)
    int contador = 0;
    int i = 0;
    int j = 0;
    
    // Um ponteiro de array de strings a receberer a alocação dinâmica via "contador"
    char **itens_com_letra_p;
    
    // Contando a qtd. de índices a serem alocados dinamicamente
    for (i = 0; i < jogo_t; i++) {
        if (jogo[i][0] == 'p') {
            contador++;
        }
    }
    
    // Alocação (não precisa necessariamente instanciar antes de alterar, pode instanciar direto)
    itens_com_letra_p = (char**)malloc(contador * sizeof(char*));
    
    /*
      Agora que "itens_com_letra_p" têm o tamanho certo, anexamos nele os dados certos
      A anexação é algo que requer atenção
      
      O que não pode ser feito?
          itens_com_letra_p[j] = jogo[i]

      O que deve ser feito?
          . Usar combinadamente as funções "malloc" e "strcpy"
          . Ou a forma alternativa que usa as duas funções acima ao mesmo tempo: "strdup"

      O que está acontecendo no loop?
          . (char*)               => cada i de "jogo" é uma string, e essa é a sintaxe usada p/ strings
          . (strlen(jogo[i] + 1)) => garantir que o i é alocado dinamicamente (+1 p/ caractere '\0')
          . * sizeof(char)        => calcular corretamente o tamanho da strings adicionada
          . strcpy(strA, strB)    => copiar a string do array alvo vindo do array de origem
    */ 
    for (i = 0; i < jogo_t; i++) {
        if (jogo[i][0] == 'p') {
            // Forma correta
            itens_com_letra_p[j] = (char*)malloc((strlen(jogo[i]) + 1) * sizeof(char));
            strcpy(itens_com_letra_p[j], jogo[i]);
            /* 
              Outra forma correta
              itens_com_letra_p[j] = strdup(jogo[i]);
            */
            j++;
        }
    }
    
    // Verificamos os dados add
    printf("\n{\n");
    for (i = 0; i < contador; i++) {
        printf("    %s,\n", itens_com_letra_p[i]);
    }
    printf("}");

    // Por último, liberar a memória (cada i é liberado, pois neste contexto temos um array de strings)
    for (i = 0; i < contador; i++) {
        free(itens_com_letra_p[i]);
    }
}

/*
  Este exemplo depende das funções: [letra_inicial, filtrar, tamanho, liberar_memoria]
  Para entender este exemplo, ver infos na função "filtrar"
*/
void alocacao_funcionamento_escopo_funcao() {
    char *pessoas[4] = {"Ash", "Brock", "Misty", "Adan"};

    char **nomes_filtrados = filtrar(letra_inicial, pessoas, sizeof(pessoas) / sizeof(pessoas[0]), 'A');
    
    printf("{\n");
    /* 
      A variável "nomes_filtrados" foi criada dinamicamente, ou seja, a função "sizeof" não funciona nela
      Esse loop só funciona corretamente, pois na função "filtrar" existe uma config. que usa NULL
      Essa ferramente + a função "tamanho", auxiliam p/ que "nomes_filtrados" possa ser iterado corretamente
    */
    for (int i = 0; i < tamanho(nomes_filtrados); i++) {
         printf("    %s,\n", nomes_filtrados[i]);
    }
    printf("}");
    liberar_memoria(nomes_filtrados, tamanho(nomes_filtrados));
}

void percorrer_dados_iteraveis() {
    int i = 0;
    char objeto[] = "computador";
    char *objetos[3] = {"lanterna", "relogio"}; // Motivo do [3]? receberá NULL
    char *cores[2] = {"branco", "preto"};
    
    // Percorrendo uma string
    while (objeto[i] != '\0') {
        printf("%c ", objeto[i]);
        i++;
    }

    // Percorrendo um array (forma menos comum)
    i = 0;
    int objetos_t = sizeof(objetos) / sizeof(objetos[0]);
    objetos[objetos_t] = NULL;
    
    printf("\n{\n");
    while (objetos[i] != NULL) {
        printf("    %s,\n", objetos[i]);
        i++;
    }
    printf("}");

    // Percorrendo um array (forma mais comum)
    i = 0;
    int cores_t = sizeof(cores) / sizeof(cores[0]);
    printf("\n{\n");
    while (i < cores_t) {
        printf("    %s,\n", cores[i]);
        i++;
    }
    printf("}");
}

// Muito importante
void alocacao_dinamica_string() {
    /*
      "*objeto" possui um ponteiro, o que indica que é um array de caracteres
      O tratamento após a criação da variável é necessário
      A alocação pode ser feita de forma direta (sem usar "malloc" e "strcpy")
      A liberação dos dados não necessita de iteração sobre cada índice
    */

    char *objeto = (char*)malloc(4 * sizeof(char));
    if (objeto == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        // return 1;
    }
    objeto[0] = 'a';
    objeto[1] = 'b';
    objeto[2] = 'c';
    objeto[3] = '\0';
    
    // Impressão direta
    printf("%s", objeto);

    // Liberando os dados alocados
    free(objeto);
}

// Muito importante
void alocacao_dinamica_array_numeros() {
    /*
      "rank" possui um ponteiro, o que indica que é um array, e o "int" indica array de valores
      A alocação pode ser feita de forma direta (sem usar "malloc" e "strcpy")
      O tratamento após a criação da variável é necessário
      A liberação dos dados não necessita de iteração sobre cada índice
    */

    // Array numérico
    int rank_t = 3;
    int *rank = (int*)malloc(rank_t * sizeof(int));
    
    rank[0] = 0;
    rank[1] = 1;
    rank[2] = 2;

    if (rank == NULL) {
        printf("Erro ao alocar memoria. Encerrando o programa.\n");
        // return 1;
    }
    
    // Impressão via loop
    printf("\n{\n");
    for (int i = 0; i < rank_t; i++) {
        printf("    %d,\n", rank[i]);
    }
    printf("}");
    
    // Liberando os dados alocados
    free(rank);
}

// Muito importante
void alocacao_dinamica_array_strings() {
    /*
      "objetos" possui 2 ponteiros, o que indica que é um array de strings
      A alocação precisa do uso de "malloc" seguido de "strcpy" (ou strdup(iter[i]))
      O tratamento após a criação da variável é necessário
      A liberação dos dados necessita de iteração sobre cada índice
    */

    // Array de strings
    int objetos_t = 3;
    char **objetos = (char**)malloc(objetos_t * sizeof(char*));

    if (objetos == NULL) {
        printf("Erro ao alocar memoria. Encerrando o programa.\n");
        // return 1;
    }
    
    /* 
      Atribuição não é direta (ex: objetos[0] = valor)
      A cópia do dado p/ o array ocorre após a alocação "malloc", via "strcpy"
    */
    objetos[0] = (char*)malloc((strlen("Ash") + 1) * sizeof(char));
    strcpy(objetos[0], "Ash");
    objetos[1] = (char*)malloc((strlen("Brock") + 1) * sizeof(char));
    strcpy(objetos[1], "Brock");
    objetos[2] = (char*)malloc((strlen("Misty") + 1) * sizeof(char));
    strcpy(objetos[2], "Misty");

    printf("\n{");
    for (int i = 0; i < objetos_t; i++) {
        printf("    %s,\n", objetos[i]);
    }
    printf("}");

    // Liberando os dados alocados
    for (int i = 0; i < objetos_t; i++) {
        free(objetos[i]);
    }
}

// Procedimento padrão
void alocacao_dinamica_tratamento() {
    /*
      Ao instanciar uma variável iterável dinamicamente, esta deve ser submetida a tratamento
      Supondo que a variável seja "strings", ficaria:
      
      if (strings == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        return 1;
      }
    */
}

void funcao_sem_retorno_vs_com_retorno() {
    /* FUNÇÃO SEM RETORNO: funcao_concatenar
      Quando um dos parâmetros é chamado e alterado
      Não há desejo de usar o parâmetro original novamente (este se tornará outra coisa, sem volta)
      Salva memória, pois evita a necessidade de gerenciar alocação 
    */

    /* FUNÇÃO COM RETORNO: funcao_concatenar_
      Quando um novo dado é criado com base no que é oferecido pelos parâmetros
      Há intenção de manter preservado os parâmetros
      Necessita alocação dinâmica e liberação de memória após o uso da função
    */
}

// Parâmetros fora da função devem estar no mesmo formato dos parâmetros da função (aqui: char nome[])
void funcao_concatenar(char s1[], char s2[]) {
    /* TUTORIAL
        Criar uma nova string com base na soma dos tamanhos de duas outras
        Para a função funcionar, não deve haver retorno, uma string será alterada definitivamente
        A partir do tamanho da string fixa, este é aumentado gradualmente com base no tamanho da outra string
        Por ser uma string, o caractere nulo \0 deve ser anexado ao final da nova string
    */

    /* MAIN
        char palavra[] = "Universo";
        printf("%s\n", palavra);
        concatenar(palavra, " =>");
        printf("%s\n", palavra);
        char seta[] = "<= ";
        concatenar(seta, palavra);
        printf("%s", seta);
    */

    int i, j;

    i = strlen(s1);

    for (j = 0; s2[j] != '\0'; i++, j++) {
        s1[i] = s2[j];
    }

    s1[i] = '\0';
}

char *funcao_concatenar_(char a[], char b[]) {
    /* TUTORIAL
        Criar uma nova string com base na soma dos tamanhos de duas outras
        A nova string é criada dinamicamente
        As letras de cada string são add sequencialmente
        Por ser uma string, o caractere nulo \0 deve ser anexado ao final da nova string
    */

    /* MAIN
      char objetoA[] = "sol";
      char objetoB[] = " & lua";
    
      char *objetoC = concatenar_main(objetoA, objetoB);
      printf("%s\n", objetoC);
      free(objetoC);
    */
    
    int i, j;
    int tamanho_final = strlen(a) + strlen(b) + 1;

    char *nova_string = (char*)malloc(tamanho_final);

    if (nova_string == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }

    for (i = 0; i < strlen(a); i++) {
        nova_string[i] = a[i];
    }

    for (j = 0; j < strlen(b); i++, j++) {
        nova_string[i] = b[j];
    }

    nova_string[i] = '\0';

    return nova_string;
}

// Instâncias com *, pois a função (fatiar) possui retorno (*fatiar)
char *funcao_fatiar(char colecao[], int min, int max) {
    /* MAIN
        char palavra[] = "Universo";

        // Instâncias com *, pois a função (fatiar) possui retorno (*fatiar)
        char *palavraA = fatiar(palavra, 0, 4);
        char *palavraB = fatiar(palavra, 1, 4);
        char *palavraC = fatiar(palavra, 3, sizeof(palavra) / sizeof(palavra[0]) - 1);
        
        printf("%s\n", palavraA);
        printf("%s\n", palavraB);
        printf("%s", palavraC);

        free(palavraA);
        free(palavraB);
        free(palavraC);
    */

    int n_indices = max - min;
    char *string = (char*)malloc((n_indices + 1));

    if (string == NULL) {
        printf("Erro ao alocar memória. Encerrando o programa.\n");
        // return 1;
    }

    for (int i = 0; i < n_indices; i++) {
        string[i] = colecao[min + i];
    }
    
    string[n_indices] = '\0';
    
    return string;
}

void funcao_parametros_array_vs_ponteiro() {
    /*
      Existe uma lógica a ser seguida com base na escolha dos parâmetros de iteráveis numa função
      
      Aqui temos a instanciação de duas funções similares
          int comparar_strings(char strA[], char strB[]) {}
          int comparar_strings(char *strA, char *strB) {}
      
      A != está na forma como os parâmetros serão lidados
      (Caso 1) par. string array de caracteres || notação indexação || iter[i]
      (Caso 2) par. string ponteiro            || notação ponteiro  || *iter
      
      Ambas percorrem todos os índices de dadis iterável, mas usando notações !=
      Ambas precisam ser ++ dentro de seus loops
    */

    /* PRIMEIRO CASO: parâmetros em forma de array de caracteres
        int i = 0, diferenca = 0;

        while (strA[i] != '\0' && strB[i] != '\0') {
            if (strA[i] != strB[i]) {
                diferenca = 1;
                break;
            }
            i++;
        }

        if (diferenca == 0 && strA[i] == '\0' && strB[i] == '\0') 
            return 1;
        else
            return 0;
    */

    /* SEGUNDO CASO: parâmetros em forma de string ponteiro
       int diferenca = 0;

        while (*strA && *strB) {
            if (*strA != *strB) {
                diferenca = 1;
                break;
            }
            strA++;
            strB++;
        }

        if (diferenca == 0 && *strA == '\0' && *strB == '\0') 
            return 1;
        else
            return 0;
    */
}

// Parâmetros iguais, mas suas formas de uso na função são !=
void funcao_parametro_array_de_strings() {
    /*
      Forma 1 || char *array_de_strings[]
      Forma 1 || usa dados via indexação (ex: array_de_str[i])
      Forma 2 || char **array_de_strings
      Forma 2 || usa dados via ponteiro (ex: *array_de_str == array_de_str[i])
    */
}

void instanciacao_multipla_definida() {
    // Se todos forem do mesmo tipo, sua instanciação pode ser separado por vírgula
    int a = 1, b = 2, c = 3;
    printf("%d %d %d", a, b, c);
}

void instanciacao_multipla_indefinida() {
    /*
      Dados separados por vírgula
      Não é permitido misturar definidos com indefinidos
    */
    int a, b, c;
    printf("%d %d %d", a, b, c);
}

void loop_encerramento_numero() {
    /*
      Uma entrada indefinida que espera um valor inteiro, é iniciada
      O primeiro loop é ignorado, pois "entrada" não possui valor
      No momento em que "scanf" é usado, temos em "entrada" o valor digitado pelo usuário via &
      O loop então verifica se a "entrada" passada p/ a função, é verdadeira (== 1)
      Não sendo (!= de 1), o loop repetirá até que seja
    */
    int entrada;
    while (encerrar(entrada) != 1) {
        printf("Informe um numero ou 0 p/ sair >>> ");
        scanf("%d", &entrada);
    }
}

void loop_encerramento_string() {
    
}

void ponteiro_duplo_vs_ponteiro_reciclado() {
    char *pessoas[4] = {"Ash", "Brock", "Misty"};
    pessoas[3] = NULL;
    
    /*
      ========== PONTEIRO DUPLO ==========
      2 ponteiros apontando p/ o mesmo array (cada um usado num loop !=)
    */
    char **ptr = pessoas;
    char **ptrB = pessoas;
    
    // Ponteiro 1
    printf("\n{\n");
    while (*ptr != NULL) {
        printf("    %s,\n", *ptr);
        ptr++;
    }
    printf("}\n");

    // Ponteiro 2
    printf("\n{\n");
    while (*ptrB) {
        printf("    %s,\n", *ptrB);
        ptrB++;
    }
    printf("\n}");

    /* 
        ========== PONTEIRO RECICLADO ==========
    */
    char *objetos[4] = {"Papel", "Pedra", "Tesoura"};
    objetos[3] = NULL;

    // Apenas 1 ponteiro
    char **ptrC = objetos;

    // Loop 1 usando o ponteiro
    printf("\n{\n");
    while (*ptrC != NULL) {
        printf("    %s,\n", *ptrC);
        ptrC++;
    }
    printf("\n}");
    
    // Ponteiro sendo reciclado
    ptrC -= sizeof(objetos) / sizeof(objetos[0]) - 1;

    // Loop 2 usando o ponteiro resetado
    printf("\n{\n");
    while (*ptrC) {
        printf("    %s,\n", *ptrC);
        ptrC++;
    }
    printf("\n}");
}

void ponteiro_em_array_de_strings() {
    // O NULL poderia ser anexado diretamente na instanciação (opcional)
    char *pessoas[4] = {"Ash", "Brock", "Misty"};
    pessoas[3] = NULL;

    // O ponteiro de array de strings usa dois ** (!= de strings, que usa *)
    char **ptr = pessoas;
    char **ptrB = pessoas;

    /*
      O critério de parada agora é garantido pela presença de NULL
      OBS: O loop pode ter duas formas de declaração: *ptr || *ptr != NULL
      No loop 1, é observado a ausência da exibição do NULL (+ apropriado && + legível)
      No loop 2, é observado a  exibição do NULL (- apropriado && - legível)
      Ambos geram resultados similares, mas o loop 1 é a melhor opção
    */

   // Loop 1
    printf("\n{\n");
    while (*ptr != NULL) {
        printf("    %s,\n", *ptr);
        ptr++;
    }
    printf("}\n");

    // Loop 2
    printf("\n{\n");
    while (*ptrB) {
        printf("    %s,\n", *ptrB);
        ptrB++;
    }
    printf("\n}");
}

void ponteiro_em_array_de_strings_dinamico() {
    int array_t = 4;
    char **array = (char**)malloc(array_t * sizeof(char*));

    // É recomendável que outro ponteiro seja usado, ao invés do ponteiro do próprio array
    char **array_ptr = array;
    
    // Os dados são inseridos conforme o que foi especificado na alocação (array de tamanho 4)
    array[0] = (char*)malloc(strlen("Ash") + 1);
    strcpy(array[0], "Ash");
    array[1] = (char*)malloc(strlen("Brock") + 1);
    strcpy(array[1], "Brock");
    array[2] = (char*)malloc(strlen("Misty") + 1);
    strcpy(array[2], "Misty");
    array[3] = NULL;
    
    // Neste loop, temos o ponteiro secundário (que não é o **array) percorrendo os dados
    printf("\n{\n");
    while (*array_ptr != NULL) {
        printf("    %s,\n", *array_ptr);
        array_ptr++;
    }
    printf("\n}"); 

    printf("\n");
    
    // Uma segunda opção seria ignorar o ponteiro, percorrendo os dados com loop for via indexação direta
    printf("\n{\n"); 
    for (int i = 0; array[i] != NULL; i++) {
        printf("    %s,\n", array[i]);
    }
    printf("\n}"); 

    for (int i = 0; i < array_t; i++) {
        free(array[i]);
    } 
}

void ponteiro_em_strings() {
    // String em forma de array de caracteres com tamanho fixo alocado pelo compilador
    char palavra[] = "Universo";

    // O ponteiro em strings usa apenas um * (!= de um array de strings, que usa **)
    char *palavra_pt = palavra;
    
    /*
      Ponteiros usam loop while (apesar de strings serem percorridas com a função "printf" também)
      Loop for não faz sentido no ponteiro, pois seu valor incrementável têm a mesma função do ponteiro
    */
    printf("\n{\n");
    while (*palavra_pt != '\0') {
        printf("    %c,\n", *palavra_pt);
        palavra_pt++;
    }
    printf("\n}");
}

void string_alterar_indices() {
    char objeto[] = "computador";
    
    // Alteração caso o objeto seja trocar índices específicos
    printf("%s\n", objeto);
    objeto[0] = 'v';
    printf("%s", objeto);
    
    // Alteração quando se troca a palavra inteira (via strcpy)
    char linguagem[] = "py";
    printf("\n%s\n", linguagem);
    strcpy(linguagem, "js");
    printf("%s", linguagem);
}

// Operadores usados em caracteres através de seus valores ascii
void string_ascii() {
    /*
      Quando letras são comparadas seus códigos ASCII são considerados
      Ou seja, strings envolvidas com operadores = comparação de seus valores ASCII
    */

    // Isso resulta em 0 (equivalente ao falso), pois "d" não é menor que "b"
    char vogal = 'a';
    char consoante = 'b';
    printf("%c > %c = %d\n", vogal, consoante, vogal > consoante);
    printf("%c < %c = %d", vogal, consoante, vogal < consoante);
}

// Contêm conceitos importantes de alocação
void string_tipos() {
    /*
      Tipos de instanciação
        1. char *pessoa = "Ana";     => {'alterar': 'não', 'adicionar': 'não'}
        2. char pessoa[] = "Ana";    => {'alterar': 'sim', 'adicionar': 'não'}
        3. char pessoa[int] = "Ana"; => {'alterar': 'sim', 'adicionar': 'sim'}

        1. alocação automática do compilador
        2. alocação automática do compilador
        3. alocação customizada
    */

    // Caso 1
    char *dispositivo = "teclado";
    
    printf("%s ", dispositivo);
    
    
    printf("\n");
    
    // Caso 2
    char dispositivoB[] = "carregador";
    dispositivoB[0] = 'x';
    printf("%s\n", dispositivoB);
    
    // Caso 3: sem espaço p/ add
    char dispositivoC[11] = "computador";
    dispositivoC[0] = 'y';
    printf("%s\n", dispositivoC);
    
    // Caso 3: com espaço p/ add
    /*
      A variável "dispositivo" possuirá 11 slots
      No momento da instanciação, "dispositivoD" possui 7 slots ocupados por: 'celular'
      Os slots 8, 9, 10 podem ter 3 caracteres adicionais e o slot 11 é dedicado ao '\0'
    */
    char dispositivoD[11] = "celular";
    printf("%s\n", dispositivoD);
    
    // Já alocados em "dispositivoD"
    printf("%c\n", dispositivoD[0]);
    printf("%c\n", dispositivoD[1]);
    printf("%c\n", dispositivoD[2]);
    printf("%c\n", dispositivoD[3]);
    printf("%c\n", dispositivoD[4]);
    printf("%c\n", dispositivoD[5]);
    printf("%c\n", dispositivoD[6]);
    
    // A serem alocados em "dispositivoD"
    dispositivoD[7] = ',';
    printf("%c\n", dispositivoD[7]);
    dispositivoD[8] = '.';
    printf("%c\n", dispositivoD[8]);
    dispositivoD[9] = ';';
    printf("%c\n", dispositivoD[9]);
    dispositivoD[10] = '/';
    printf("%c\n", dispositivoD[10]);

    // Realocar a posição da contra barra (devendo estar sempre ao final)
    dispositivoD[11] = '\0';
    printf("%c\n", dispositivoD[11]);
    
    // Confirmar o tamanho correto (aqui: 11, onde 11 é a contra-barra)
    printf("%d\n", strlen(dispositivoD));
}

void string_tipos_parte2() {
    // String em forma de array de caracteres com tamanho fixo alocado pelo compilador
    char palavra[] = "Universo";

    // String em forma de ponteiro, que usa loop while para ser percorrida
    char *palavraB = "Universo";
    
    // String em forma de array de caracteres com tamanho customizado (tamanho + 1 para o caractere nulo \0)
    char palavraC[9] = "Universo";

    // String em forma de array de caracteres com tamanho customizado com slots livres (para possíveis alterações)
    char palavraD[20] = "Universo";

    // while(*palavraB) {
    //     printf("%c ", *palavraB);
    //     palavraB++;
    // }
}

int main() {
    // Fazer item relacionado ao assunto "typedef int (*letra_inicial_ptr)(char, char);"
    return 0;
}
