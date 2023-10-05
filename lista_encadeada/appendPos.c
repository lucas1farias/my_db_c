

#include "exemplo_estrutura.h"

ArrayNumber insertAtIndex(int i, int index, ArrayNumber target) {
    // Create a new dynamic element
    // It does not point to a next index 
    // Why? cuz the target index (-1) needs to be found first
    ArrayNumber newNumber = (ArrayNumber)(malloc(sizeof(struct arrayNumber)));
    newNumber->indexValue = i;
    
    // If index is 0: put it right on start
    if (index == 0) {
        newNumber->next = target;
        return newNumber;
    }
    
    // If not first index, create a pointer and position
    ArrayNumber current = target;
    int pos = 0;
    
    // If the array reaches its end: its length > index offered
    // If not, "current" will stop with a certain value on it
    // It will be used by "newElement"
    while (current != NULL && pos < (index - 1)) {
        current = current->next;
        pos++;
    }
    
    // If index > array length -> remove element allocated and return same array
    if (current == NULL) {
        free(newNumber);
        return target;
    }
    
    // Now the element can have its "next" attrib.
    newNumber->next = current->next;
    current->next = newNumber;
    
    return target;
}
