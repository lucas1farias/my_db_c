

#include <stdio.h>
#include <stdlib.h>

int nova_entrada_num(char* conteudo) {
    int entrada;
    printf("%s", conteudo);
    scanf("%i", &entrada); // Em tipos não iteráveis, se passa o "&"
    return entrada;
}

char* nova_entrada_txt(char* conteudo) {
    char* entrada = malloc(100); // Se for apenas instanciada sem valor, gera erro
    printf("%s", conteudo);
    scanf("%s", entrada); // Em string, não se passa o "&"
    return entrada;
}

int main() {
    int entrada = nova_entrada_num("Digite algum numero >>> ");
    printf("%i\n", entrada);
    char* entrada_txt = nova_entrada_txt("Digite algum texto >>> ");
    printf("%s\n", entrada_txt); // impressão comum não funciona sem a linha abaixo
    free(entrada_txt);
    return 0;
}
