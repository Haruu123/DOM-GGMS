//DOM-GGMS-View - Projeto Dominó 
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include <stdio.h>

void fMostra(tipopeca pecas[28]) {
    for (int i = 0; i < 28; i++) {
        printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
    }
}
