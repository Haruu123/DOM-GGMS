//GGMS - Dominó
//Trabalho do dominó PUCSP 08/08/2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Primeira Versão: 







//Prototipo das Funções
void fMostra(int M[2][14]);

 
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

int main() 
{
	
	srand(time(NULL));
	int Mat[2][14]; 
	int i,j; 
	int n = 1;
	fMostra(Mat);

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

void fMostra(int M[2][14])
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 14; j++)
			printf("%2d ", rand() % 6, M[i][j]);
		printf("\n");
	}
	printf("\n\n");	
}

	
	
