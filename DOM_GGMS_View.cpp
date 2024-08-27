//DOM-GGMS-View.cpp - Projeto Dominó - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_View.h"
#include <stdio.h>

void fMostra(tipopeca pecas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
    }
    printf("\n\n");
}

void mensagemSair()
{
	printf("Saindo do jogo.\n");
}

void mensagemOpInvalida()
{
	printf("Opcao invalida. Tente novamente.\n\n");
}

void pecasJ1()
{
	printf("\nPecas do jogador 1:\n");
}

void pecasJ2()
{
	printf("Pecas do jogador 2:\n");
}

void jogada1(tipopeca peca) {
    printf("Maior peca:\n[%d|%d]\n\n", peca.lado1, peca.lado2);
}

int apresentarMenuGeral() {
    int op;
    printf("1 - Iniciar jogo (2 jogadores)\n");
    /*printf("2 - Iniciar jogo (contra o computador)\n");
    printf("3 - Retornar ao jogo interrompido\n");
    printf("4 - Regras gerais do Jogo\n");
    printf("5 - Salvar o jogo\n");
    printf("6 - Recuperar o jogo salvo\n");*/
    printf("0 - Sair do programa\n");
    printf("Opcao selecionada: ");
    scanf("%d", &op);
    return op;
}
