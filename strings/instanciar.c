

#include <stdio.h>

int main() {
    char forma_A[] = "Hello, World A!";
    char forma_B[] = {'H', 'e', 'l', 'l', 'o', ',', 'W', 'o', 'r', 'l', 'd', ' ', 'B', '!', '\0'};
    char* forma_C = "Hello, World C!";
    char forma_D[100];
    // printf("%s\n", forma_A);
    // printf("%s\n", forma_B);
    // printf("%s\n", forma_C);
    // printf("%s\n", forma_D);
    
    forma_A[0] = 'W';
    printf("%s\n", forma_A);
    return 0;
}
