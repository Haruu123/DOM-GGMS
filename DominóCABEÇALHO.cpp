//DOM-GGMS - Projeto Dominó – Etapa 1
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//estrutura tipo peca
typedef struct {
    int lado1;
    int lado2;
} tipopeca;

void fMostra(tipopeca pecas[28]);
void fNumera(tipopeca pecas[28]);
void fEmbaralha(tipopeca pecas[28]);


 int main() {
    tipopeca pecas[28];
    
	fCriar(pecas);      //inicia as pecas
	fMostra(pecas);      //peças numeradas
    	printf("\n\n");
        
    	fEmbaralha(pecas);   //embaralha as pecas
    	fMostra(pecas);      //pecas embaralhadas
        
    	printf("\n\n");
    
    	fEmbaralha(pecas);   //embaralha as pecas
    	fMostra(pecas);      //pecas embaralhadas
    	printf("\n\n");
    
    	fEmbaralha(pecas);   //embaralha as pecas
    	fMostra(pecas);      //pecas embaralhadas
    	printf("\n\n");
}

void fMostra(tipopeca pecas[28]) {
    for (int i = 0; i < 28; i++) {
        printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
    }
}

void fNumera(tipopeca pecas[28]) {
    int k = 0;
    
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[k].lado1 = i;    //contador atribuido pra lado1
            pecas[k].lado2 = j;    //contador atribuido pra lado2
            k++;
        }
    }
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
