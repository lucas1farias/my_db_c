

#include <stdio.h>
#include <string.h>

// {'*': 'string', '**': 'array'}
char* inverter(char* colecao) {
    int i = 0;
    int i_fim = strlen(colecao) - 1;

    while (i < i_fim) {
        char anterior = colecao[i];
        char posterior = colecao[i_fim];
        
        colecao[i] = posterior;
        colecao[i_fim] = anterior;

        i++;
        i_fim--;
    }
}

char* inverter_for(char* colecao) {
    int i, i_fim;
    char i_atual;

    for (int i = 0, i_fim = strlen(colecao) - 1; i < i_fim; i++, i_fim--) {
        i_atual = colecao[i];
        colecao[i] = colecao[i_fim];
        colecao[i_fim] = i_atual;
    }

    return colecao;
}

int main() {
    char nome[] = "Lucas";
    char sobrenome[] = "Farias";
    
    printf("Antes: %s\n", nome);
    inverter(nome);
    printf("Depois %s\n", nome);
    
    printf("Antes: %s\n", sobrenome);
    inverter_for(sobrenome);
    printf("Depois: %s\n", sobrenome);
    return 0;
}
