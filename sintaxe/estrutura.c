

#include <stdio.h>

void estrutura_instanciacao() {
    /*
      Requisitos:
        palavra reservada "struct"
        nome da estrutura
        atribs. da estrutura
    */
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[5];
    };
}

void estrutura_objeto_criacao() {
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[5];
    };

    // Criação de um objeto da estrutura
    struct pessoa sujeito = {"Ana", 1988, {"Vaquinha", "Birutinha", "Magali"}};
}

void estrutura_objeto_acesso() {
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[5];
    };

    struct pessoa sujeito = {"Ana", 1988, {"Vaquinha", "Birutinha", "Magali"}};

    printf("%s\n", sujeito.nome);
    printf("%d\n", sujeito.nascimento);
    printf("%s\n", sujeito.apelidos[0]);
    
    // Atributos do array de strings "*apelidos"
    for (int i = 0; i < sizeof(sujeito.apelidos) / sizeof(sujeito.apelidos[0]); i++) {
        printf("%s\n", sujeito.apelidos[i]);
    }
}

// Ponteiro criado na instanciação da estrutura
void estrutura_com_ponteiro_forma_A() {
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[5];
    } 
    // Criação de um ponteiro customizado antes do fechamento da criação da estrutura
    *ptrA;

    // Criação de um objeto da estrutura
    struct pessoa sujeito = {"Ana", 1988, {"Vaquinha", "Birutinha", "Magali"}};

    // Este ponteiro aponta p/ o EM do objeto
    ptrA = &sujeito;

    // E o acesso de sá via ->
    printf("%s %d %s", ptrA->nome, ptrA->nascimento, ptrA->apelidos[2]);
}

// Ponteiro após a criação do objeto da estrutura
void estrutura_com_ponteiro_forma_B() {
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[5];
    }; 

    // Criação de um objeto da estrutura
    struct pessoa sujeito = {"Ana", 1988, {"Vaquinha", "Birutinha", "Magali"}};

    // Criação de um ponteiro após a criação do objeto
    struct pessoa *ptr;

    // Este ponteiro aponta p/ o EM do objeto
    ptr = &sujeito;

    // E o acesso de sá via ->
    printf("%s %d %s", ptr->nome, ptr->nascimento, ptr->apelidos[2]);
}

void estrutura_aninhada() {
    struct coordenada {
        int local[2];
    };
    
    struct estado {
        char nome[30];
        char regiao[15];
        // Estrutura aninhada recebe um identificador
        struct coordenada xy;
    } pais_ptr;
    

    struct estado piaui = {"Piaui", "Nordeste", {100, 101}};

    printf("%s\n", piaui.nome);
    printf("%s\n", piaui.regiao);
    
    // O atributo da estrutura aninhada é chamada pelo identificador (aqui: xy)
    printf("---o %d\n", piaui.xy.local[0]);

    for (int i = 0; i < sizeof(piaui.xy.local) / sizeof(piaui.xy.local[0]); i++) {
        printf("%d\n", piaui.xy.local[i]);
    }
}

// Quando uma estrutura têm um ARRAY DE STRINGS como atrib. e se deseja usar um ponteiro nele
void estrutura_usar_ponteiro_em_atrib_array() {
    // ========== CONTEXTO : Array de strings FORA de uma estrutura ==========
    char *pessoas[10] = {"Ash", "Brock", "Misty"};
    char **pessoas_ptr;
    pessoas_ptr = pessoas;
    
    // Funcionamento e uso do ponteiro
    for (int i = 0; i < sizeof(pessoas) / sizeof(pessoas[0]); i++) {
        printf("%s\n", *pessoas_ptr);
        pessoas_ptr++;
    }
    printf("\n");
    
    // ========== OUTRO CONTEXTO: Array de strings DENTRO de uma estrutura ==========
    struct amigos {
        char nome_grupo[30];
        char *integrantes[30]; // array de strings
    };

    /* 
      O primeiro ponteiro criado (*ptr) não consegue acessar diretamente os dados do atrib. "integrantes"
      Motivo? O array de strings não é mais independente (caso acima), ele está dentro de 1 estrutura
      A solução é configurar 2 ponteiros (*ptr2) e (*ptr_cada_integrante)
      O segundo ponteiro (*ptr2) não aponta direto p/ o objeto, mas p/ o EM deste objeto
      O terceiro ponteiro, que é o principal, apontará diretamente p/ a estrutrua no atrib. "*integrantes"
      Fazendo isso, temos o resultado similar ao feito acima, onde o array de strings é independente
    */
    struct amigos grupo_lagartixa = {"Lagartixa", {"Ash", "Brock", "Misty"}};
    struct amigos *ptr;                             // ponteiro incapaz 
    struct amigos *ptr2 = &grupo_lagartixa;         // ponteiro que torna o de baixo capaz
    char **ptr_cada_integrante = ptr2->integrantes; // ponteiro capaz
    
    // Com ponteiro
    for (int i = 0; i < sizeof(grupo_lagartixa.integrantes) / sizeof(grupo_lagartixa.integrantes[0]); i++) {
        printf("%s\n", *ptr_cada_integrante);
        ptr_cada_integrante++;
    }

    // Sem ponteiro (forma direta)
    printf("\n");
    for (int i = 0; i < sizeof(grupo_lagartixa.integrantes) / sizeof(grupo_lagartixa.integrantes[0]); i++) {
        printf("%s\n", grupo_lagartixa.integrantes[i]);
    }
}

void estrutura_usar_ponteiro_em_atrib_array_numerico() {
    struct coordenada {
        int xy[2]; // array numérico
    };

    struct coordenada pos = {{100, 101}};

    // 2 ponteiros necessários
    struct coordenada *ptr = &pos;
    int *ptrB = ptr->xy;
    
    // Uso do segundo ponteiro
    for (int i = 0; i < sizeof(pos.xy) / sizeof(pos.xy[0]); i++) {
        printf("%d\n", *ptrB);
        ptrB++;
    }
}

void estrutura_instanciacao_atribuicao() {
    /*
      Instanciação || "struct" e o "tipo do struct"
      "struct"     || palavra reservada
      "horario"    || nome/tipo do "struct" 
    */
    struct horario {
        int hora;
        int minuto;
        int segundo;
    };

    // Instanciação de um objeto + forma de atribuir dados
    struct horario horario;
    horario.hora = 11;
    horario.minuto = 12;
    horario.segundo = 13;
    printf("%ih:%imin:%iseg\n", horario.hora, horario.minuto, horario.segundo);
    
    // Instanciação de um objeto + outra forma de atribuir dados
    struct horario hora, *tempo_pt = &hora;
    tempo_pt->hora = 13;
    tempo_pt->minuto = 12;
    tempo_pt->segundo = 11;
    printf("%ih:%imin:%iseg", hora.hora, hora.minuto, hora.segundo);
}

// Inserir conteúdo dos códigos das funções aqui para os testar
int main() {
    struct pessoa {
        char nome[30];
        int nascimento;
        char *apelidos[5];
    };

    struct info_pessoal {
        char cpf[15];
        char id[15];
        char estado_civil[2];
        struct pessoa pessoa_bdd;
    };

    struct pessoa sujeito = {"Ana", 1988, {"Vaquinha", "Birutinha", "Magali"}};
    return 0;
}