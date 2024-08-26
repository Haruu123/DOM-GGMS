//DOM-GGMS-Model.cpp - Projeto Dominó - Etapa 2
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"

Mesa mesa[28];
tipopeca pecas[28];
int j1[7], j2[7];

void fCriar(tipopeca pecas[28]) {
    int k = 0;
    
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[k].lado1 = i;    //contador atribuido pra lado1
            pecas[k].lado2 = j;    //contador atribuido pra lado2
            k++;
        }
    }
}

void distribuiPecas() {
    for (int i = 0; i < 7; i++) {
        jogador1[i] = i;             
        jogador2[i] = i + 7;         
    }
}

//void exibePecas() {
//    for (int i = 0; i < 7; i++) {
//        tipopeca pecas = pecas[jogador[]];
//        printf("[%d|%d] ", pecas.lado1, pecas.lado2);
//    }
//    printf("\n");
//} /////ESBOCO NAO FUNFA 
