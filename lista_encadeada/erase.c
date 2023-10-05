

#include "exemplo_estrutura.h"

ArrayNumber append(int value, ArrayNumber target) {
    ArrayNumber newElement = (ArrayNumber)(malloc(sizeof(ArrayNumber)));
    newElement->indexValue = value;
    newElement->next = target;
    return newElement;
}

ArrayNumber erase(int value, ArrayNumber target) {
    ArrayNumber current = target;
    ArrayNumber previous = NULL;
    while (current != NULL && current->indexValue != value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return target;
    }
    if (previous != NULL) {
        previous->next = current->next;
    } else {
        target = current->next;
    }
    free(current);
    return target;
}

int main() {
    ArrayNumber array = append(1, NULL);
    array = append(5, array);
    array = erase(1, array);
    show(array);
    return 0;
}
