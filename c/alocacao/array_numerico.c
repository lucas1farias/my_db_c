

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int *nums = (int*)malloc(3 * sizeof(int));
    
    // Mostrando os endereços dos dados ainda não alocados
    printf("\n{\n");
    for (int i = 0; i < 3; i++) {
        printf("    %p,\n", (void*)&nums[i]);
    }
    printf("}\n");
    
    // Alocação de índices em array de números (pode ser feita diretamente)
    nums[0] = 2;
    nums[1] = 5;
    nums[2] = 7;
    
    // Mostrando os endereços dos dados já alocados
    printf("\n{\n");
    for (int i = 0; i < 3; i++) {
        printf("    %d,\n", nums[i]);
    }
    printf("}\n");
    
    // Liberação da memória
    free(nums);
    
    return 0;
}
