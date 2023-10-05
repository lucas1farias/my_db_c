

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

// Append method which always places on start (left side)
ArrayNumber append(int i, ArrayNumber array) {
    /* Two ways to allocate dynamically in C
        1. ArrayNumber dynamicArray = malloc(sizeof(struct arrayNumber));
        2. ArrayNumber dynamicArray = (ArrayNumber)(malloc(sizeof(ArrayNumber)));

        PS: 
            As "ArrayNumber" is a pointer, the syntaxes on 1 and 2 ignore *
            If "ArrayNumber" wasn't a pointer, 1 and 2 would be:

            1. ArrayNumber *dynamicArray = malloc(sizeof(struct *arrayNumber));
            2. ArrayNumber *dynamicArray = (ArrayNumber*)(malloc(sizeof(ArrayNumber)));
    */ 
    ArrayNumber newElement = (ArrayNumber)(malloc(sizeof(ArrayNumber)));
    newElement->indexValue = i;
    newElement->next = array;
    return newElement;
}

ArrayNumber last(ArrayNumber target) {
    ArrayNumber index = target;
    while (index != NULL && index->next != NULL) {
        index = index->next;
    }
    return index;
}

ArrayNumber appendRight(int newNumber, ArrayNumber target) {
    // Requirements: Pointer of original array & new dynamic element
    ArrayNumber eachIndex = target;
    ArrayNumber newElement = (ArrayNumber)(malloc(sizeof(ArrayNumber)));
    newElement->indexValue = newNumber;
    newElement->next = NULL;
    
    // If original array is empty, it receives new element
    if (target == NULL) {
        return newElement;
    }
    
    // Loop until last element
    while (eachIndex->next != NULL) {
        eachIndex = eachIndex->next;
    }
    
    // When the last is found, point it to the new element
    eachIndex->next = newElement;
    return target;
}

ArrayNumber erase(int atrib, ArrayNumber target) {
    ArrayNumber index = target;
    ArrayNumber previous = NULL;
    while (index != NULL && index->indexValue != atrib) {
        previous = index;
        index = index->next;
    }
    // Loop not interrupted, atrib. not found
    if (index == NULL) {
        return target;
    }
    // Loop interrupted, atrib. found
    if (previous != NULL) {
        previous->next = index->next;
    } 
    // If atrib. is the first index
    else {
        target = index->next;
    }
    free(index);
    return target;
}

// Attribute used for the search: indexValue
int search(int value, ArrayNumber target) {
    int pos = 0;
    for (ArrayNumber eachIndex = target; eachIndex != NULL; eachIndex = eachIndex->next) {
        if (eachIndex->indexValue == value) {
            return pos;
        }
        pos++;
    }
    return -1;
}

int main() {
    // It works as a "stack", where the last in is the first out
    ArrayNumber indexPtr = append(10, NULL);
    indexPtr = append(70, indexPtr);
    indexPtr = append(100, indexPtr);
    
    // Display each number from the numeric array
    show(indexPtr);

    // Search an object from one of its attributes
    printf("\nIndex of item 70? %d\n", search(70, indexPtr));
    printf("Index of item 100? %d\n", search(100, indexPtr));
    printf("Index of item 10? %d\n", search(10, indexPtr));
    printf("Index of item 1? %d\n", search(1, indexPtr));

    erase(10, indexPtr);
    show(indexPtr);

    indexPtr = append(25, indexPtr);
    show(indexPtr);
    
    printf("%d", last(indexPtr)->indexValue);
    
    indexPtr = appendRight(7, indexPtr);
    show(indexPtr);
    indexPtr = appendRight(77, indexPtr);
    show(indexPtr);
    
    return 0;
}
