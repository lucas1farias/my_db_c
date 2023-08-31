

#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initialize(Set *set) {
    set->size = 0;
}

void addElement(Set *set, int element) {
    set->elements[set->size] = element;
    set->size++;
}

int main() {
    Set mySet;
    initialize(&mySet);

    addElement(&mySet, 5);
    addElement(&mySet, 10);
    addElement(&mySet, 7);
    
    printf("\n{ ");
    for (int i = 0; i < mySet.size; i++) {
        printf("%d, ", mySet.elements[i]);
    }
    printf("}");

    return 0;
}
