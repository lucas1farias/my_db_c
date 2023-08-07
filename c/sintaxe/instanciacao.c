

void instanciacao_estranha() {
    /*
      Esta sendo definido um array de possíveis caracteres
      Apesar da palavra "char" estar sendo usada, números podem ser inseridos e o compilador não vê problema
    */
    char a[3];
    a[0] = -1;
    a[1] = 0;
    a[2] = 1;
    
    for (int i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }
}

// Exceção: estruturas
void instanciacao_iteraveis() {
    /*
      OBS || arrays numéricos/strings recebem [] e nelas podem ou não ter um valor inteiro
      OBS || é recomendável que este valor seja preenchido [int]
      OBS || com isso, está sendo informado o limite da qtd. de índices guardados p/ esta variável
      OBS || no caso de array de strings é possível um segundo [int]
      OBS || onde [int][int2] => qtd. de strings e tamanho máx. de cada string
      
      Arrays numéricos e de strings precisam de um loop for
      Strings e strings em forma de array não precisam
    */
    int rank[] = {1, 2, 3};                      // Array numérico
    char* pessoas[] = {"Ash", "Brock", "Misty"}; // Array de strings
    char pessoa[] = {'A', 'S', 'H', '\0'};       // String em forma de array de caracteres
    char* linguagem = "Java";                    // String em forma de ponteiro
    
    /*
      Arrays numéricos e de strings usam a função "sizeof"
      Strings e strings em forma de array usam a função "strlen"
    */
    int a = sizeof(rank) / sizeof(rank[0]);
    int b = sizeof(pessoas) / sizeof(pessoas[0]);
    int c = strlen(pessoa);
    int d = strlen(linguagem);
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    return 0;
}
