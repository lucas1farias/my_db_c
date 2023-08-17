

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int array_t = 4;
    char **array = (char**)malloc(array_t * sizeof(char*));

    // É recomendável que outro ponteiro seja usado, ao invés do ponteiro do próprio array
    char **array_ptr = array;
    
    // Os dados são inseridos conforme o que foi especificado na alocação (array de tamanho 4)
    array[0] = (char*)malloc(strlen("Ash") + 1);
    strcpy(array[0], "Ash");
    array[1] = (char*)malloc(strlen("Brock") + 1);
    strcpy(array[1], "Brock");
    array[2] = (char*)malloc(strlen("Misty") + 1);
    strcpy(array[2], "Misty");
    array[3] = NULL;
    
    // Neste loop, temos o ponteiro secundário (que não é o **array) percorrendo os dados
    printf("\n{\n");
    while (*array_ptr != NULL) {
        printf("    %s,\n", *array_ptr);
        array_ptr++;
    }
    printf("\n}"); 

    printf("\n");
    
    // Uma segunda opção seria ignorar o ponteiro, percorrendo os dados com loop for via indexação direta
    printf("\n{\n"); 
    for (int i = 0; array[i] != NULL; i++) {
        printf("    %s,\n", array[i]);
    }
    printf("\n}"); 

    for (int i = 0; i < array_t; i++) {
        free(array[i]);
    } 

    return 0;
}
