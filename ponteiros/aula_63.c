

#include <stdio.h>

int main() {
    // Tipo de dado estrutrua em C
    struct horario {
        int hora;
        int minuto;
        int segundo;
    };
    
    // Tipo, nome, ponteiro (onde o ponteiro "tempo_pt" é usado p/ alterar dados de "tempo" via "&")
    struct horario tempo, *tempo_pt = &tempo;
    // Forma A
    (*tempo_pt).hora = 11;
    (*tempo_pt).minuto = 12;
    (*tempo_pt).segundo = 13;
    printf("%ih:%imin:%iseg\n", tempo.hora, tempo.minuto, tempo.segundo);
    // Forma B
    tempo_pt->hora = 13;
    tempo_pt->minuto = 12;
    tempo_pt->segundo = 11;
    printf("%ih:%imin:%iseg", tempo.hora, tempo.minuto, tempo.segundo);
    return 0;
}
