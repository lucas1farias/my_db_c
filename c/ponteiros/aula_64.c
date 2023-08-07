

#include <stdio.h>

int main() {
    char* pessoas[] = {"Ash", "Brock", "Misty"};
    char* ash = pessoas[0];
    printf("%s\n", pessoas[0]);    // acesso direto
    printf("%s\n", ash);           // acesso dentro de variável
    printf("%c\n", pessoas[0][0]); // acesso de um char dentro do índice

    const char* stringCompleta = "AshBrockMisty";
    char primeiroNome[1];
    sscanf(stringCompleta, "%[^B]", primeiroNome);
    printf("Primeiro nome: %s\n", primeiroNome);
    
    return 0;
}
