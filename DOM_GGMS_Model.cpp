//DOM-GGMS-Model - Projeto Dominó 
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"

tipopeca pecas[28];

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
