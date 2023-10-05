

#include "exemplo_estrutura.h"

/* Two ways to allocate dynamically in C
    1. ArrayNumber dynamicArray = malloc(sizeof(struct arrayNumber));
    2. ArrayNumber dynamicArray = (ArrayNumber)(malloc(sizeof(ArrayNumber)));

    PS: 
        As "ArrayNumber" is a pointer, the syntaxes on 1 and 2 ignore *
        If "ArrayNumber" wasn't a pointer, 1 and 2 would be:

        1. ArrayNumber *dynamicArray = malloc(sizeof(struct *arrayNumber));
        2. ArrayNumber *dynamicArray = (ArrayNumber*)(malloc(sizeof(ArrayNumber)));
*/ 

// Append method which always places on start (left side)
ArrayNumber append(int i, ArrayNumber array) {
    ArrayNumber newElement = (ArrayNumber)(malloc(sizeof(ArrayNumber)));
    newElement->indexValue = i;
    newElement->next = array;
    return newElement;
}

int main() {
    // It works as a "stack", where the last in is the first out
    ArrayNumber indexPtr = append(10, NULL);
    indexPtr = append(70, indexPtr);
    indexPtr = append(100, indexPtr);
    
    // Display each number from the numeric array
    show(indexPtr);
    return 0;
}
