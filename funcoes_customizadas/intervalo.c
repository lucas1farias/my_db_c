

#include <stdio.h>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}
