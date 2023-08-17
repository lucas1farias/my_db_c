

// Converta essa funções para C++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(char strA[], char strB[]) {
    if (strlen(strA) != strlen(strB)) {
        return 0;
    } 
    else {
        int i = 0, j = 0;
        int dif = 0;
        
        for (i = 0; i < strlen(strA); i++, j++) {
            if (strA[i] != strB[j]) {
                dif = 1;
                break;
            }
        }

        if (dif == 0 && strA[i] == '\0' && strB[j] == '\0') {
            return 1;
        } else {
            return 0;
        }
    }
}

int comparar2(char strA[], char strB[]) {
    int i = 0;
    while (strA[i] != '\0' && strB[i] != '\0') {
        if (strA[i] != strB[i]) {
            return 0;
        }
        i++;
    }
    return (strA[i] == '\0' && strB[i] == '\0');
}

int main() {
    char entradaA[20];
    char entradaB[20];
    
    printf("Palavra 1 >>> ");
    scanf("%s", entradaA);
    printf("Palavra 2 >>> ");
    scanf("%s", entradaB);

    if (comparar2(entradaA, entradaB) == 1) {
        printf("Palavras similares");
    } else {
        printf("Palavras diferentes");
    }

    return 0;
}
