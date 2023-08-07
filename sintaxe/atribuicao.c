

void atribuicao_indireta() {
    /*
      Não há relação direta entre "a" e "b"
      "b" recebe o valor de "a", que no momento era "0"
      "a" é modificado na linha seguinte, mas não altera "b"
    */
    int a = 0;
    int b = a;
    a = 1;
    printf("a = %i\nb = %i", a, b);
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    return 0;
}
