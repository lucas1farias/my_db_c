

#include <stdio.h>

int criterio_maior(int i, int ref)
{
    if (i > ref)
    {
        return i;
    } 
    else
    {
        return ref;
    }
}

int criterio_menor(int i, int ref)
{
    if (i < ref)
    {
        return i;
    } 
    else
    {
        return ref;
    }
}

int criterio_somar(int i, int ref)
{
    ref = ref + i;
    return ref;
}

int reduzir(int (*criterio)(int, int), int* colecao, int tamanho, int vi)
{
    int acumulador = vi;
    for (int i = 0; i < tamanho; i++)
    {
        acumulador = criterio(colecao[i], acumulador);
    }
    return acumulador;
}

int main() {
    int colecao[] = {1, 7, 2};
    int tamanho = sizeof(colecao) / sizeof(colecao[0]);
    int maior = reduzir(criterio_maior, colecao, tamanho, colecao[0]);
    int menor = reduzir(criterio_menor, colecao, tamanho, colecao[0]);
    int soma = reduzir(criterio_somar, colecao, tamanho, 0);
    printf("%d\n", maior);
    printf("%d\n", menor);
    printf("%d\n", soma);
    return 0;
}

