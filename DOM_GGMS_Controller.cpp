//DOM-GGMS-Controller.cpp - Projeto Dominó - Etapa 2
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Controller.h"
#include "DOM_GGMS_View.cpp"
#include <stdlib.h>
#include <time.h>

void jogo(){
    fMostra(pecas);
    fEmbaralha(pecas);
    
    fMostra(pecas);
    fEmbaralha(pecas);
    
    fMostra(pecas);
    fEmbaralha(pecas);
    
    fMostra(pecas);
}

void fEmbaralha(tipopeca pecas[28]) {
    srand(time(NULL));
    
    for (int i = 0; i < 28; i++) {
        int j = rand() % 28;
        
        //Troca as pecas de lugar
        tipopeca temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}
