

#include <stdio.h>
#include <string.h>

void loops_inc_comum() {
    int f;
    int w = 0;
    
    for (f = 0; f < 3; f++) {
        printf("valor atual: %d\n", f);
    }

    while (w < 3) {
        printf("valor atual: %d\n", w);
        w++;
    }
}

void loops_inc_incomum() {
    int f;
    int w = 0;
    
    for (f = 0; f < 3; ++f) {
        printf("valor atual: %d\n", f);
    }

    while (w < 3) {
        printf("valor atual: %d\n", w);
        ++w;
    }
}

void loops_encerramento_array() {
    /*
      Forma mais útil? sizeof()
    */
    char *pessoas[3] = {"Ash", "Brock", "Misty"};
    for (int i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        printf("%s\n", pessoas[i]);
    }
    printf("\n");
    int i = 0;
    while (i < sizeof(pessoas) / sizeof(pessoas[0])) {
        printf("%s\n", pessoas[i]);
        i++;
    }
}

void loops_encerramento_string() {
    /*
      Em ambos os casos temos um array de caracteres como alvo
      Formas? '\0' e strlen(iter) 
    */
    char palavra[4] = "lua";
    int i = 0;
    
    while (palavra[i] != '\0') {
        printf("%c", palavra[i]);
        i++;
    }
    
    printf("\n");
    
    i = 0;
    // ____________ palavra[i] != '\0';
    for (i = 0; i < strlen(palavra); i++) {
        printf("%c", palavra[i]);
    }
}

void loop_while() {
    int acumulador = 0;
    int valor = 0;
    while(acumulador < 10) {
        printf("Informe um valor >>> ");
        scanf("%i", &valor);
        acumulador += valor;
        printf("%i\n", acumulador);
    }
}

void loop_while_saida_string() {
    /*
      Biblioteca || #include <stdio.h, #include <string.h>
      OBS        || Não aprendi como fazer de forma sem usar o built-in "strcmp"
    */
    char* fim = "0";
    char* entrada; 
    while (strcmp(entrada, fim) != 0) {
        printf("\nDigite algo ou 0 >>> ");
        scanf("%s", entrada);
        printf("\n%s\n", entrada);
    }
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {

    return 0;
}
