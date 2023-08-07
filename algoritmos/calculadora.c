

// Qual o problema com o meu código?
#include <stdio.h>

int nova_entrada_num(char* conteudo) {
    int entrada;
    printf("%s", conteudo);
    scanf("%i", &entrada);
    return entrada;
}

int fazer_operacao(int a, int b, int op) {
    if (op == 1) {
        return a + b;
    } else if (op == 2) {
        return a - b;
    } else if (op == 3) {
        return a * b;
    } else if (op == 4) {
        return a / b;
    } else {
        printf("Operação inválida\n");
    }
}

int main() {
    int fim = 0;
    int operacao;
    int entrada;
    int entradaB;
    
    while (operacao != fim) {
        operacao = nova_entrada_num("Digite:\n1: soma\n2: substracao\n3: multiplicacao\n4: divisao\n >>> ");
        
        if (operacao != 1 && operacao != 2 && operacao != 3 && operacao != 4) {
            printf("\nOperacao invalida\n");
            break;
        }
        else {
            entrada = nova_entrada_num("Digite um numero >>> ");
            entradaB = nova_entrada_num("Digite outro numero >>> ");
            int resultado = fazer_operacao(entrada, entradaB, operacao);
            printf("\nResultado da operacao: %i\n", resultado);
        }
        
    }
    return 0;
}
