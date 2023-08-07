

#include <stdio.h>

int main() {
    int m, n, c, d, first[10][10], second[10][10], sum[10][10];
    printf("\n===== Informe o numero de linhas e colunas da matriz >>> ");
    scanf("%d%d", &m, &n);
    printf("===== Informe os elementos da matriz 1 >>> ");
    
    for (c = 0; c < m; c++) 
        for (d = 0; d < n; d++) 
            scanf("%d", &first[c][d]);

    printf("===== Informe os elementos da matriz 2 >>> ");

    for (c = 0; c < m; c++) 
        for (d = 0; d < n; d++) 
            scanf("%d", &second[c][d]);

    for (c = 0; c < m; c++) 
        for (d = 0; d < n; d++) 
            sum[c][d] = first[c][d] + second[c][d];

    printf("===== Soma das matrizes =====\n");

    for (c = 0; c < m; c++)
    {
        for (d = 0; d < n; d++)
            printf("%d\t", sum[c][d]);

        printf("\n");
    }
    printf("\n");

    for (c = 0; c < m; c++)
        for (d = 0; d < n; d++)
            sum[c][d] = first[c][d] - second[c][d];
    
    printf("===== Diferenca entre as matriz entradas =====\n");

    for (c = 0; c < m; c++)
    {
        for (d = 0; d < n; d++) 
            printf("%d\t", sum[c][d]);

        printf("\n");
        
    }
        
    return 0;
}
