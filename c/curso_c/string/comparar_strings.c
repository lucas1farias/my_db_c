

#include<stdio.h>

int strings_similares(char str1[], char str2[]) {
    int i = 0, diferente = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            diferente = 1;
            break;
        }
        i++;
    }

    if (diferente == 0 && str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;
}

void terminal_strings_similares() {
    char str1[100], str2[100];
    int comparacao;

    printf("Informe a primeira palavra >>> ");
    scanf("%s", str1);

    printf("Informe a segunda palavra >>> ");
    scanf("%s", str2);

    comparacao = strings_similares(str1, str2);

    if (comparacao == 1)
        printf("Strings similares? sim");
    else
        printf("Strings similares? nao");
}

int main()
{
    // terminal_strings_similares();
    char nulo[2] = "0";
    char nuloB[2] = "0";
    printf("%d", strings_similares(nulo, nuloB));
    return 0;
}
