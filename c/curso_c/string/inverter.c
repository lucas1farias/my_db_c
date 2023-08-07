

#include <stdio.h>
#include <string.h>

void inverter_str(char colecao[]) {
    /*
      colecao = "java";
      while (0 < 3)
          "java"[0] = "java[3]"
          "java[3]" = "java[0]"
          colecao = "aavj"
          "aavj[1]" = "aavj[2]"
          "aavj[2]" = "aavj[1]"
          colecao = "avaj"
          i = 2 
          i_fim = 1
          fim

    */
    int i = 0;
    int i_fim = strlen(colecao) - 1;

    while (i < i_fim) {
        // Isso aqui não pode ser passado direto
        char anterior = colecao[i];
        
        colecao[i] = colecao[i_fim];
        colecao[i_fim] = anterior;

        i++;
        i_fim--;
    }
}

void terminal_inverter_str() {
    char palavra[30];
    printf("\nInforme a palavra a ser invertida >>> ");
    scanf("%s", palavra);
    inverter_str(palavra);
    printf("===== Resultado =====\n>>> %s", palavra);
}

int main() {
    // terminal_inverter_str();
    char fruta[7] = "banana";
    inverter_str(fruta);
    printf("%s", fruta);
    return 0;
}
