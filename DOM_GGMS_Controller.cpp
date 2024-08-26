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

void menuGeral()
{
int op = apresentarMenuGeral();
	
    switch (op) {
        case 1:
            iniciarJogo;  
            break;
        case 2:
            jogadaAutomatica();
            break;
        case 3:
            printf("sair");
            exit(0);  
        default:
            printf("de novo\n");
            menuGeral();  
            break;
    }
}

//void iniciarJogo()
//{
//	limparMesa();
//	fEmbaralha();
//	distribuiPecas();
//}	
