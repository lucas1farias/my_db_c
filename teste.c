

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fatorial(int num) {
    int fatorial = 1;
    int i = 1;
    while (i <= num) {
        fatorial *= i;
        i++;
    }
    return fatorial;
}

int main() {
    // Estrutura 1: terá relação com outra (será parte dela) (instanciar antes)
    struct docs {
        char rg[20];
        char cpf[20];
        char cep[20];
    };
    
    // Estrutura 2: recebe a estrutura 1 dentro de si
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[30];
        
        // A primeira estrutura é anexada à segunda, e o acesso se dá pelo nome da variável
        struct docs credenciais;
    };
    
    // Objeto e ponteiro apotando p/ o EM do objeto
    struct pessoa sujeito = {"Ravena", 1988, {"Dora", "Corva"}, "1.111.111", "123.456.789-00", "64-001-002"};
    struct pessoa *sujeito_ptr;
    sujeito_ptr = &sujeito;
    
    // Acessando os dados do objeto pertencente a segunda estrutura (pessoa)
    printf("%s\n", sujeito_ptr->nome);
    printf("%d\n", sujeito_ptr->nascimento);
    
    // Observe que neste loop, não está sendo usado o ponteiro
    for (int i = 0; i < 2; i++) {
        printf("%s\n", sujeito.apelidos[i]);
    }

    // Acessando os dados do objeto pertencente a primeira estrutura usando um ponteiro
    printf("%s\n", sujeito_ptr->credenciais.rg);
    printf("%s\n", sujeito_ptr->credenciais.cpf);
    printf("%s\n", sujeito_ptr->credenciais.cep);
    return 0;
}
