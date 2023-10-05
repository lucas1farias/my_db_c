

#include "exemplo_estrutura.h"

ArrayNumber append(int value, ArrayNumber target) {
    ArrayNumber newElement = (ArrayNumber)(malloc(sizeof(ArrayNumber)));
    newElement->indexValue = value;
    newElement->next = target;
    return newElement;
}

ArrayNumber last(ArrayNumber target) {
    ArrayNumber eachIndex = target;
    while(eachIndex != NULL && eachIndex->next != NULL) {
        eachIndex = eachIndex->next;
    }
    return eachIndex;
}

int main() {
    ArrayNumber array = append(1, NULL);
    array = append(5, array);
    array = append(10, array);
    show(array);
    printf("\nUltimo indice? %d", last(array)->indexValue);
    return 0;
}
