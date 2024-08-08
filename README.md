//GGMS - Dominó
//Trabalho do dominó PUCSP 08/08/2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Primeira Versão: 







//Prototipo das Funções
//void fCriapeca

 
//Criar e mostras a peças.
typedef struct stpeca
{
    int lado1;
    int lado2;
    char status;
} tipoPeca;

	tipoPeca peca[28];
	tipoPeca pecaaux; //cria uma variavel 

//Criar e mostrar as peças.

int main() {
	
	srand(time(NULL));
	
    stpeca pecas[28];
    int indice = 0;

    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[indice].lado1 = i;
            pecas[indice].lado2 = j;
            indice++;
        }
    }

    // Exibir as peças para verificar
    printf("Pecas do Domino:\n\n");
    for (int i = 0; i < 28; i++) 
	{
        printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
    }


	// Misturar as Peças.
	
    
    
    
    
}

	
	
