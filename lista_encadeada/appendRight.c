

#include "exemplo_estrutura.h"

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

int main() {
    ArrayNumber indexPtr = appendRight(7, NULL);
    show(indexPtr);
    indexPtr = appendRight(77, indexPtr);
    show(indexPtr);
    indexPtr = appendRight(27, indexPtr);
    show(indexPtr);
    return 0;
}
