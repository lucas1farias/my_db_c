

#include <stdio.h>
#include <stdlib.h>

// As the alias is a pointer, everything with instance "ArrayNumber" will be a pointer
typedef struct arrayNumber {
    int indexValue;
    struct arrayNumber *next;
} *ArrayNumber; 

void show(ArrayNumber target) {
    printf("[");
    for (ArrayNumber eachIndex = target; eachIndex != NULL; eachIndex = eachIndex->next) {
        printf("%d, ", eachIndex->indexValue);
    }
    printf("]");
}
