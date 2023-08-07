

#include <stdio.h>

int tamanho(char* colecao) {
    int n_indices = 0;
    while (colecao[n_indices] != '\0') {
        n_indices++;
    }
    return n_indices;
}

char letra_codigo(char procurado) {
    int minusculas[26];
    int maiusculas[26];
    int maiusc = 65; // Não precisa do 91 (maior maiúscula)
    int minusc = 97;
    int minusc_fim = 123;
    int i = 0;
    char* alfabeto = "abcdefghijklmnopqrstuvwxyz";
    char* alfabeto_maiusculo = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while (minusc < minusc_fim) {
        minusculas[i] = minusc;
        maiusculas[i] = maiusc;
        i++;
        minusc++;
        maiusc++;
    }
    // Não cabe uma função tamanho em arrays numéricos, apenas arrays de strings
    for (int i = 0; i < sizeof(minusculas) / sizeof(minusculas[0]); i++) {
        if (minusculas[i] == procurado) {
            return alfabeto[i];
        }
    }

    for (int i = 0; i < sizeof(maiusculas) / sizeof(maiusculas[0]); i++) {
        if (maiusculas[i] == procurado) {
            return alfabeto_maiusculo[i];
        }
    }
    return '*';
}

int main() {
    printf(
        "%c%c%c%c%c\n", 
        letra_codigo(108), letra_codigo(117), letra_codigo(99), letra_codigo(97), letra_codigo(115)
    );
    printf(
        "%c%c%c%c%c\n", 
        letra_codigo(76), letra_codigo(85), letra_codigo(67), letra_codigo(65), letra_codigo(83)
    );
    printf("%c", letra_codigo(50));
    char* nums[] = {"Ash", "Brock", "Misty"};
    printf("%i", tamanho_array_int(nums));
}
