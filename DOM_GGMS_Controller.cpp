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
	menuGeral();
	iniciarJogo();   
}

void fEmbaralha(tipopeca pecas[28]) {
    srand(time(NULL));
    for (int i = 0; i < 28; i++) {
        int j = rand() % 28;
        tipopeca temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}

void iniciarJogo() {
    fEmbaralha(pecas);
    distribuiPecas(pecas);

    pecasJ1(); //Mensagem para as pecas do jogador 1
    fMostra(j1, 7);
    pecasJ2(); //Mensagem para pecas do jogador 2
    fMostra(j2, 7);

    primeiroLance();
}

void colocarPecaNaMesa(tipopeca peca) {
	mesa.posicaoLivreMesa = 0; //Inicializa a mesa, posicao 0 da array
    if (mesa.posicaoLivreMesa < 28) {
        mesa.pecasNaMesa[mesa.posicaoLivreMesa] = peca; //Peca sera alocada na posicao indicada
        mesa.posicaoLivreMesa++; //Incremento ao indice para a proxima posicao
    }
}

void primeiroLance() {
    int i, pj, dupla;
    pj = -1;
    dupla = -1;
    tipopeca pecaJogada;

    for (i = 0; i < 7; i++) { //Para tentar encontrar a maior dupla
        if (j1[i].lado1 == j1[i].lado2 && j1[i].lado1 > dupla) {
            dupla = j1[i].lado1;
            pj = i;
            jvez = 'J';
        }
        if (j2[i].lado1 == j2[i].lado2 && j2[i].lado1 > dupla) {
            dupla = j2[i].lado1;
            pj = i;
            jvez = 'j';
        }
    }

    if (pj == -1) { //Caso nao tenha a maior dupla, o programa procura pela peca com a maior soma
        dupla = 0;
        for (i = 0; i < 7; i++) {
            if (j1[i].lado1 + j1[i].lado2 > dupla) {
                dupla = j1[i].lado1 + j1[i].lado2;
                pj = i;
                jvez = 'J';
            }
            if (j2[i].lado1 + j2[i].lado2 > dupla) {
                dupla = j2[i].lado1 + j2[i].lado2;
                pj = i;
                jvez = 'j';
            }
        }
    }

    if (jvez == 'J') { //Caso seja o primeiro jogador, 'J'
        pecaJogada = j1[pj];
        j1[pj].status = 'M'; 
    } else { //Caso seja o segundo jogador
        pecaJogada = j2[pj];
        j2[pj].status = 'M'; 
    }

    colocarPecaNaMesa(pecaJogada);
    jogada1(pecaJogada);
    }   

void menuGeral() {
    int op;
    do {
        
		op = apresentarMenuGeral();
		switch (op) {
            case 0:
				mensagemSair();
				exit(0);
			case 1:
                iniciarJogo();
                system("pause");
                system("cls");
                break;
            /*case 2:
                jogadaAutomatica();
            case 3:
            	retornarJogo()
            case 4:
            	regrasGerais()
        	case 5:
        		salvarJogo()
            case 6:
            	recuperarJogo()*/
            default:
                void mensagemOpInvalida();
                break;
        }
    } while (op != 0);
}
