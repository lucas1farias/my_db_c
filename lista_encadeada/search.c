

#include "exemplo_estrutura.h"

ArrayNumber append(int value, ArrayNumber target) {
    ArrayNumber newElement = (ArrayNumber)(malloc(sizeof(ArrayNumber)));
    newElement->indexValue = value;
    newElement->next = target;
    return newElement;
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
    ArrayNumber array = append(1, NULL);
    array = append(7, array);
    array = append(2, array);
    array = append(5, array);

    show(array);
    
    // Search an object from one of its attributes
    printf("\nO valor 7 se encontra na lista 'array'? %d\n", search(7, array));
    printf("O valor 5 se encontra na lista 'array'? %d\n", search(5, array));
    printf("O valor 2 se encontra na lista 'array'? %d\n", search(2, array));
    printf("O valor 9 se encontra na lista 'array'? %d\n", search(9, array));
    return 0;
}
