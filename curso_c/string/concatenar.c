

#include<stdio.h>
#include<string.h>

void concatenar(char palavra_nativa[], char palavra_estrangeira[]) {
    /*
      Ex: palavra_nativa = 'lua' / palavra_estrangeira = 'sol'
      j = 3 ('lua' têm 3 chars, excluindo '\0')
      for (i = 0; 'sol' != '\0'; j++, i++) (loop executado x3)
      'lua'[3] = 'sol'[0] => 'luas'
      'lua'[4] = 'sol'[1] => 'luaso'
      'lua'[5] = 'sol'[2] => 'luasol'
      Ao final, é preciso anexar 
    */
    int j;
    int i = strlen(palavra_nativa);

    for (j = 0; palavra_estrangeira[j] != '\0'; i++, j++) {
        palavra_nativa[i] = palavra_estrangeira[j];
    }
    
    palavra_nativa[i] = '\0';
}

void terminal_concatenar() {
    char palavra_nativa[30], palavra_estrangeira[30];
    printf("\nInforme a primeira palavra >>> ");
    gets(palavra_nativa);
    printf("Informe a segunda palavra >>> ");
    gets(palavra_estrangeira);
    concatenar(palavra_nativa, palavra_estrangeira);
    printf("===== Mesclagem =====\n>>> %s", palavra_nativa);
}

int main()
{
    // terminal_concatenar();
    char palavraA[4] = "lua";
    char palavraB[4] = "sol";
    concatenar(palavraA, palavraB);
    printf("\n===== Mesclagem =====\n>>> %s", palavraA);
    return 0;
}
