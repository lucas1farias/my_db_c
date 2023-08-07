

// Qual o motivo de "nome" não ser afetada pela função "substituir" e "string" ser afetada pela mesma função?
#include <stdio.h>
#include <string.h>

char* nova_entrada_txt(char* conteudo) {
    static char entrada[100];
    printf("%s", conteudo);
    scanf("%s", entrada); 
    return entrada;
}

void substituir(char* txt, char procurado, char substituto) {
    int tamanho = strlen(txt);
    for (int i = 0; i < tamanho; i++) {
        if (txt[i] == procurado) {
            txt[i] = substituto;
        }
    }
}

void substituirCaractere(char* string, char caractereAntigo, char caractereNovo) {
    int tamanho = strlen(string);
    for (int i = 0; i < tamanho; i++) {
        if (string[i] == caractereAntigo) {
            string[i] = caractereNovo;
        }
    }
}

int main() {
    // char* fim = "0";
    // char entrada;
    // while (entrada != fim[0]) {
    //     char* entrada = nova_entrada_txt("Digite um nome >>> ");
    //     printf("%s", entrada); 
    // }
    // return 0;

    char nome[] = "Ash";
    char antigo = 'A';
    char novo = 'I';
    substituir(nome, antigo, novo);
    printf("%s\n", nome);
}
