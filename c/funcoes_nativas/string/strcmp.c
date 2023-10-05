

#include <stdio.h>
#include <string.h>

/*
Se for igual: retorno 0
Se for diferente: retorno -1
*/

int main() {
    char str1[] = "hello";
    char str2[] = "hello";

    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("Iguais.\n");
    } else if (result < 0) {
        printf("A primeira: menor.\n");
    } else {
        printf("A primeira: maior.\n");
    }

    return 0;
}
