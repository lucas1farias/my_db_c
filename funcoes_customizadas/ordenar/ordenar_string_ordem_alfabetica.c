

#include <string.h>
#include <stdio.h>

void shell_sort(char *colecao, int tamanho_colecao)
{
    int subgrupo_i, i, j, intervalo;
    char letra; 
    char subgrupos[5] = {9, 5, 3, 2, 1};

    for (subgrupo_i = 0; subgrupo_i < 5; subgrupo_i++)
    {
        intervalo = subgrupos[subgrupo_i];
        
        for (i = intervalo; i < tamanho_colecao; ++i)
        {
            letra = colecao[i];
            // letra < colecao[j] = comparação ascii
            for (j = i - intervalo; (letra < colecao[j]) && (j >= 0); j = j - intervalo)
            {
                colecao[j + intervalo] = colecao[j];
            }
            
            colecao[j + intervalo] = letra;
        }
    }
}

int main()
{
    // É melhor usar string em forma de array de caracteres
    char linguagem[7] = "python";
    shell_sort(linguagem, strlen(linguagem));
    printf("%s", linguagem);

    return 0;
}
