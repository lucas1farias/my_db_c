

#include <stdio.h>
#include <string.h>
#include <math.h>

int mapear(int (*criterio)(int, int), int* colecao, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        colecao[i] = criterio(colecao[i], valor);
    } 
}

int criterio_elevar(int i, int ref) {
    double resultado = pow(i, ref);
    return resultado;
}

int main() {
    int rank[] = {1, 2, 3};
    int fim_colecao = sizeof(rank) / sizeof(rank[0]);
    
    mapear(criterio_elevar, rank, fim_colecao, 2);
    for (int i = 0; i < fim_colecao; i++) {
        printf("%i ", rank[i]);
    }
}
