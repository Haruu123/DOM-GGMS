//DOM-GGMS-Model.cpp - Projeto Dominó - Etapa 2
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"

char jvez;
Mesa mesa;
tipopeca pecas[28];
tipopeca j1[7], j2[7];

void fCriar(tipopeca pecas[]) {
    int k = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[k].lado1 = i;
            pecas[k].lado2 = j;
            pecas[k].status = 'D';
            k++;
        }
    }
}

void distribuiPecas(tipopeca pecas[]) {
    for (int i = 0; i < 7; i++) {
        j1[i] = pecas[i];
        j1[i].status = 'J';
        j2[i] = pecas[i + 7];
        j2[i].status = 'j';
    }
}

