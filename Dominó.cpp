
///DESATUALIZADO///



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
    int novamente;
    
    do {
        system("cls");
		fNumera(pecas);      //inicia as pecas
        printf("Pecas antes de embaralhar:\n\n");
        fMostra(pecas);      //peças numeradas
        fEmbaralha(pecas);   //embaralha as pecas
        printf("\n\nPecas depois de embaralhar:\n\n");
        fMostra(pecas);      //pecas embaralhadas
        printf("\n\n");
        
        printf("Deseja embaralhar novamente? digite 0: ");
        scanf("%d", &novamente);
        
    } while (novamente == 0);
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
        
        tipopeca temp = pecas[i];  //troca as pecas de lugar
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}
