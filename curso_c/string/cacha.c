

#include <stdio.h>
#include <string.h>

void cacha(char txt[], int minuscula) {
    int i;
    for (i = 0; i <= txt[i] != '\0'; i++) {

        if (minuscula == 0) {
            if (txt[i] >= 65 && txt[i] <= 90) {
                txt[i] = (char) (txt[i] + 32);
            }
        }
        else {
            if (txt[i] >= 97 && txt[i] <= 122) {
                txt[i] = (char) (txt[i] - 32);
            }
        }
    }
}

void terminal_cacha_alta() {
    char str[20];
    int i;
    printf("Enter string : ");
    gets(str);

    for (i = 0; i <= strlen(str); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = (char) (str[i] + 32);
        }
    }
    printf("String in lowercase : %s", str);
}

int main() {
    // terminal_cacha_baixa();
    char linguagem[5] = "JAVA";
    printf("A: %s\n", linguagem);
    cacha(linguagem, 0);
    printf("B: %s\n", linguagem);
    cacha(linguagem, 1);
    printf("C: %s", linguagem);
    return 0;
}
