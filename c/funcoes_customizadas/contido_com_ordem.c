

#include <stdio.h>
#include <string.h>

int contido_com_ordem(char* colecao_menor, char* colecao_maior) {
    // Pode ser: subtracao_colecoes - 1 SE for retirado "<=" do loop 1
    int subtracao_colecoes = strlen(colecao_maior) - strlen(colecao_menor);
    
    for (int i = 0; i <= subtracao_colecoes; i++) {
        int nativo = 1;
        for (int j = 0; j < strlen(colecao_menor); j++) {
            if (colecao_menor[j] != colecao_maior[i + j]) {
                nativo = 0;
                break;
            }
        }
        if (nativo == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* fruta = "banana";
    char* silaba = "ba";
    printf("%i\n", contido_com_ordem(silaba, fruta));
    return 0;
}
