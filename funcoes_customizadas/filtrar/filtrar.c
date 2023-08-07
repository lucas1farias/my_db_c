

// Código não está funcionando
#include <stdio.h>

int criterio_impar(int i)
{
    if (i % 2 == 1)
    {
        return 0;
    } 
    else 
    {
        return 1;
    }
    
}

void filtrar(int (*criterio)(int), int* colecao, int* nova_colecao, int tamanho) {
    
    for (int i = 0; i < tamanho; i++)
    {
        if (criterio(colecao[i]) == 0)
        {
            scanf("%d", &nova_colecao[i]);
        }
    }
}

int main() {
    int colecao[] = {1, 7, 2};
    int tamanho = sizeof(colecao) / sizeof(colecao[0]);
    // int maior = reduzir(criterio_maior, colecao, tamanho, colecao[0]);
    // int menor = reduzir(criterio_menor, colecao, tamanho, colecao[0]);
    // int soma = reduzir(criterio_somar, colecao, tamanho, 0);
    // printf("%d\n", maior);
    // printf("%d\n", menor);
    // printf("%d\n", soma);
    int impares[tamanho];
    filtrar(criterio_impar, colecao, impares, tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d\n", impares[i]);
    }
    return 0;
}
