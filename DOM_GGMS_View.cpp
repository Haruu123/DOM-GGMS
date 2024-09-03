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

void jogadorJogou(char jvez)
{
    printf("Jogador %c jogou\n", jvez);
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

void apresentarMesa(tipopeca peca) {
    printf("===========\n\n");
	printf("MESA    [%d|%d]", peca.lado1, peca.lado2);
	printf("\n\n==========\n");
}

void mensagemMonteVazio(){
    printf("Nao ha mais pecas no monte para comprar!");
}

int apresentarMenuGeral() {
    int op;
    printf("1 - Iniciar jogo (2 jogadores)\n");
//    printf("2 - Iniciar jogo (contra o computador)\n");
//    printf("3 - Retornar ao jogo interrompido\n");
    printf("2 - Regras gerais do Jogo\n");
//    printf("5 - Salvar o jogo\n");
//    printf("6 - Recuperar o jogo salvo\n");
    printf("0 - Sair do programa\n");
    printf("Opcao selecionada: ");
    scanf("%d", &op);
    return op;
}


void regrasGerais()
{
    printf("\nREGRAS GERAIS\n");
    printf("\nINICIO = Cada jogador comeca com 7 pecas distribuidas aleatoriamente. ");
    printf("Quem possuir a peca [6|6] inicia o jogo, mas caso ninguem a tenha, joga-se a dupla mais alta do leque.\n");

    printf("\nORDEM DO JOGO = O jogo ocorre no sentido anti-horario, ");
    printf("e as pecas devem ser posicionadas de acordo com os numeros das extremidades da mesa.\n");

    printf("\nCOMPRA DE PECAS = Antes de cada jogada, o jogador pode 'comprar' quantas pecas quiser ");
    printf("do monte de pecas disponiveis, seja por necessidade ou blefe, ");
    printf("mas perde aquele que terminar a partida com maior numero de pecas.\n");

    printf("\nPASSAR A VEZ = Se um jogador nao puder jogar e nao houver mais pecas disponiveis para compra, ");
    printf("ele passa a vez.\n");

    printf("\nFIM DE JOGO = O jogo continua ate que sejam compradas todas as pecas do monte e, ");
    printf("alem disso, um dos jogadores 'bater' seu leque [zerar suas pecas].\n");

    printf("\nCASOS ESPECIAIS = Quando nao ha mais pecas para serem compradas, ");
    printf("e nenhum dos jogadores consegue encaixar suas pecas nas extremidades, ");
    printf("o vencedor sera determinado pela menor quantia de pecas em maos.\n\n");
    
}

int apresentarSubMenu() {
    char op2;
	printf(" j - fazer a jogada\n");
	printf(" c - comprar pecas\n");
	printf(" p - passar a vez\n");
	printf(" s - sair (interromper o jogo)\n");
	printf("\tOpcao selecionada: \n");
	limparBuffer();
	scanf("%c", &op2);
	return op2; 
}
	

