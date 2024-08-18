//DOM-GGMS-View.cpp - Projeto Dominó - Etapa 2
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_View.h"
#include <stdio.h>

void fMostra(tipopeca pecas[28]) {
    for (int i = 0; i < 28; i++) {
        printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
    }
    printf("\n\n");
}
