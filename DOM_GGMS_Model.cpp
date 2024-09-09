//DOM-GGMS-Model.cpp - Projeto Domino - Etapa 5
//03/09/24 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

#include "DOM_GGMS_Model.h"

char jvez;
char escolha;
char ladoEscolhido;
Mesa mesa;
tipopeca pecas[28];
tipopeca jogador1[7];
tipopeca jogador2[7];
tipopeca monte[14]; // monte pecas disponiveis
int numeroPecasNoMonte = 14;
int numeroPecasDoJogador1 = 7;
int numeroPecasDoJogador2 = 7;

void fCriar(tipopeca pecas[]) {
    int k = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[k].lado1 = i;
            pecas[k].lado2 = j;
            pecas[k].status = 'D';
            k++;
        }
    }
}

void distribuiPecas(tipopeca pecas[28]) {
    
    for (int i = 0; i < 7; i++) {
        jogador1[i] = pecas[i];
        jogador1[i].status = 1; // status jogador 1
    }
    for (int i = 7; i < 14; i++) {
        jogador2[i - 7] = pecas[i];
        jogador2[i - 7].status = 2; // status jogador 2
    }
    for (int i = 14; i < 28; i++) {
        monte[i - 14] = pecas[i];
        monte[i - 14].status = 0; // status monte
    }
    numeroPecasDoJogador1 = 7;
    numeroPecasDoJogador2 = 7;
    numeroPecasNoMonte = 14;
}

struct Jogo {
    int qtMesaJogo;      // Quantidade de peças na mesa
    int jogadorJogo;     // Jogador atual (1 ou 2)
    int jogadorComp;     // Se o jogador 2 é o computador (0: não, 2: sim)
    int mesaDJogo;       // Extremidade direita da mesa
    int mesaEJogo;       // Extremidade esquerda da mesa
} sitJogo;               // Variável global da situação do jogo

// Inicialize a estrutura Jogo com valores padrão
void inicializaJogo() {
    sitJogo.qtMesaJogo = 0;
    sitJogo.jogadorJogo = 1;
    sitJogo.jogadorComp = 0;  
    sitJogo.mesaDJogo = -1;   
    sitJogo.mesaEJogo = -1;   
}

