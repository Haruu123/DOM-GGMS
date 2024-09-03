//DOM-GGMS-Model.cpp - Projeto Dominó - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"

char jvez;
Mesa mesa;
tipopeca pecas[28];
tipopeca jogador1[7];
tipopeca jogador2[7];
tipopeca monte[14]; // monte de peças disp
int numeroPecasNoMonte = 14;
int numeroPecasDoJogador1 = 7;
int numeroPecasDoJogador2 = 7;

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

void distribuiPecas(tipopeca pecas[28]) {
    for (int i = 0; i < 7; i++) {
        jogador1[i] = pecas[i];
        jogador1[i].status = 1; // status jogador 1
    }
    for (int i = 7; i < 14; i++) {
        jogador2[i - 7] = pecas[i];
        jogador2[i - 7].status = 2; // status jogador 2
    }
    for (int i = 14; i < 28; i++) {
        monte[i - 14] = pecas[i];
        monte[i - 14].status = 0; // status monte
    }
    numeroPecasDoJogador1 = 7;
    numeroPecasDoJogador2 = 7;
    numeroPecasNoMonte = 14;
}



