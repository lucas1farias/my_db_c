

#include <string.h>
#include <stdio.h>

void intervalo(int colecao[], int min, int max) {
    int i = 0;
    while (min <= max) {
        colecao[i] = min;
        i++;
        min++;
    }
}

int codigo_letra(char letra) {
    int i, j;
    int maiusculas[26], minusculas[26];
    char alfabeto_alto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfabeto_baixo[27] = "abcdefghijklmnopqrstuvwxyz";
    intervalo(maiusculas, 65, 90);
    intervalo(minusculas, 97, 122);
    
    for (i = 0; i < strlen(alfabeto_alto); i++, j++) {
        if (alfabeto_alto[i] == letra) {
            return maiusculas[i];
        }
        if (alfabeto_baixo[i] == letra) {
            return minusculas[i];
        }
    } 
}

int main()
{   
    return 0;
}
