

#include <stdio.h>

void copiar_str(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }

    str2[i] = '\0';
}

void terminal_copiar_str() {
    char str1[100], str2[100];

    printf("Informe um texto >>> ");
    scanf("%s", str1);

    copiar_str(str1, str2);

    printf("===== Resultado =====\n>>> %s", str2);
}

int main() {
    // terminal_copiar_str();
    char pessoas[3][20] = {"Brock", "Ash", "Misty"};
    char pessoa[1][20];
    copiar_str(pessoas[0], pessoa[0]);
    printf("%s", pessoa[0]);
    return 0;
}
