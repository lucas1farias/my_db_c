

void float_abreviacao() {
    /*
      Versão comum     || %f
      Versão abreviada || %intf
    */
    printf("%f", 1 + 10.59);
    printf("%.2f", 1 + 10.59);
}

void float_imprevisibilidade_calculo() {
    /*
      FATO: não há garantia de que o usuário vai fornecer dados que gerem cálculo exato
      Como prevenção, podemos colocar um dos valores envolvidos como "float"
      Do mesmo modo, é preciso usar %f, p/ garantir que erros de cálculo não sejam feitos
      Portanto: a variável recebe "float" e o printf recebe "%f"
    */
    int par = 6;
    float impar = 4;
    printf("%.2f", par / impar);
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {

    return 0;
}
