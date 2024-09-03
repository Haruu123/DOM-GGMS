//DOM-GGMS-Controller.cpp - Projeto Dominó - Etapa 3
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
    primeiroLance();
}
 
void colocarPecaNaMesa(tipopeca peca) {
	mesa.posicaoLivreMesa = 0; //pos 0 da array
    if (mesa.posicaoLivreMesa < 28) {
        mesa.pecasNaMesa[mesa.posicaoLivreMesa] = peca; //peca vai pra posicao do contador
        mesa.posicaoLivreMesa++; //incremento = avanca o slot da mesa
    }
}
 
void primeiroLance() {
    int i, pj, dupla;
    pj = -1;
    dupla = -1;
    tipopeca pecaJogada;
 
    // Procurar a maior dupla
    for (i = 0; i < 7; i++) {
        if (jogador1[i].lado1 == jogador1[i].lado2 && jogador1[i].lado1 > dupla) {
            dupla = jogador1[i].lado1;
            pj = i;
            jvez = 'J';
        }
        if (jogador2[i].lado1 == jogador2[i].lado2 && jogador2[i].lado1 > dupla) {
            dupla = jogador2[i].lado1;
            pj = i;
            jvez = 'j';
        }
    }
 
    // Se não tiver dupla, procurar a peca com a maior soma
    if (pj == -1) {
        dupla = 0;
        for (i = 0; i < 7; i++) {
            if (jogador1[i].lado1 + jogador1[i].lado2 > dupla) {
                dupla = jogador1[i].lado1 + jogador1[i].lado2;
                pj = i;
                jvez = 'J';
            }
            if (jogador2[i].lado1 + jogador2[i].lado2 > dupla) {
                dupla = jogador2[i].lado1 + jogador2[i].lado2;
                pj = i;
                jvez = 'j';
            }
        }
    }
 
    if (jvez == 'J') {
        pecaJogada = jogador1[pj];
        jogador1[pj] = jogador1[numeroPecasDoJogador1 - 1]; // -1 peca do jogador
        numeroPecasDoJogador1--;
    } else {
        pecaJogada = jogador2[pj];
        jogador2[pj] = jogador2[numeroPecasDoJogador2 - 1]; 
        numeroPecasDoJogador2--;
    }
 
    colocarPecaNaMesa(pecaJogada);
    apresentarMesa();
 
    //troca vez de jogar
    if (jvez == 'J') {
    	jogadorJogou(jvez); //se for 'j' eh o jogador 2, se for 'J' eh o jogador 1 (arrumar para 1 e 2)
        jvez = 'j';
    } else {
    	jogadorJogou(jvez);
        jvez = 'J';
    }
 
    pepecasPecas(jvez); // pecas de quem jogou
    subMenu();
}
 
 
void pepecasPecas(char jvez) {
    char indice = 'a'; // inicio ordem jogador1 
    if (jvez == 'J') {
        printf("pecas do jogador 1:\n");
        for (int i = 0; i < numeroPecasDoJogador1; i++) { // pecas do jogador 1
            printf("%c. [%d|%d] ", indice, jogador1[i].lado1, jogador1[i].lado2);
            indice++;
        }
        printf("\n");
    } else {
        printf("pecas do jogador 2:\n");
        indice = 'a'; // inicio ordem jogador2
        for (int i = 0; i < numeroPecasDoJogador2; i++) { // pecas do jogador 2
            printf("%c. [%d|%d] ", indice, jogador2[i].lado1, jogador2[i].lado2);
            indice++;
        }
        printf("\n");
    }
}
 
 
void fComprar(tipopeca monte[], int &numeroPecasNoMonte, tipopeca jogador[], int &numeroPecasDoJogador) {

    if (numeroPecasNoMonte > 0) {
        jogador[numeroPecasDoJogador] = monte[numeroPecasNoMonte - 1];
        jogador[numeroPecasDoJogador].status = 'J'; // peca era D virou J : pertence ao jogador
        numeroPecasDoJogador++;
        numeroPecasNoMonte--;
    } else {
        mensagemMonteVazio();
    }
    apresentarMesa(); // mostrar a mesa atualizada
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
            case 2:
            	regrasGerais();
            default:
                mensagemOpInvalida();
                break;
        }
    } while (op != 0);
}
 
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void subMenu() {
    char op2;
    do {
        op2 = apresentarSubMenu();
        switch (op2) {
            case 'j':
                jogada();
                break;
            case 'c':
                if (jvez == 'J') {
                    fComprar(monte, numeroPecasNoMonte, jogador1, numeroPecasDoJogador1);
                } else {
                    fComprar(monte, numeroPecasNoMonte, jogador2, numeroPecasDoJogador2);
                }
                pepecasPecas(jvez);
                break;
            case 'p':
                if (jvez == 'J') {
                    jvez = 'j'; // passa a vez para o jogador 2
                } else {
                    jvez = 'J'; // Passa a vez para o jogador 1
                }
                printf("jogador passou a vez\n");
                pepecasPecas(jvez); // atualiza as peças para o jogador que agora tem a vez
                break;
            case 's':
                menuGeral();
                break;
            default:
                mensagemOpInvalida();
                break;
        }
    } while (op2 != 's');
}

void inverterPeca(tipopeca &peca) {
    int temp = peca.lado1;
    peca.lado1 = peca.lado2;
    peca.lado2 = temp;
}

void mostrarPecasPossiveis(tipopeca jogador1[], tipopeca jogador2[], char jvez) {
    int mesaE, mesaD;
 
    if (mesa.posicaoLivreMesa > 0) {
        mesaE = mesa.pecasNaMesa[0].lado1;
        mesaD = mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2;
    } else {
        mesaE = mesaD = -1; // mesa vazia
    }
 
    
    if (jvez == 'J') {
        printf("pecas possiveis do Jogador 1:\n");
        for (int i = 0; i < numeroPecasDoJogador1; i++) {
            if (jogador1[i].lado1 == mesaE || jogador1[i].lado2 == mesaE || jogador1[i].lado1 == mesaD || jogador1[i].lado2 == mesaD) {
                if (jogador1[i].lado1 == mesaD) {
                    inverterPeca(jogador1[i]);
                }
                printf(" [%d|%d] ", jogador1[i].lado1, jogador1[i].lado2);
            }
        }
        printf("\n");
    } else {
        printf("pecas possiveis do Jogador 2:\n");
        for (int i = 0; i < numeroPecasDoJogador2; i++) {
            if (jogador2[i].lado1 == mesaE || jogador2[i].lado2 == mesaE || jogador2[i].lado1 == mesaD || jogador2[i].lado2 == mesaD) {
                if (jogador2[i].lado1 == mesaD) {
                    inverterPeca(jogador2[i]);
                }
                printf(" [%d|%d] ", jogador2[i].lado1, jogador2[i].lado2);
            }
        }
        printf("\n");
    }
}
void jogada() {
    tipopeca pecaEscolhida;
    int indicePecaEscolhida;
    char escolha;


    mostrarPecasPossiveis(jogador1, jogador2, jvez);

    
    printf("peca a ser jogada (digite a letra): ");
    scanf(" %c", &escolha);


    if (jvez == 'J') {
        indicePecaEscolhida = escolha - 'a'; 
        if (indicePecaEscolhida >= 0 && indicePecaEscolhida < numeroPecasDoJogador1) {
            pecaEscolhida = jogador1[indicePecaEscolhida];
            jogador1[indicePecaEscolhida] = jogador1[numeroPecasDoJogador1 - 1];
            numeroPecasDoJogador1--;
        } else {
            printf("nao pode\n");
            return;
        }
    } else {
        indicePecaEscolhida = escolha - 'a'; 
        if (indicePecaEscolhida >= 0 && indicePecaEscolhida < numeroPecasDoJogador2) {
            pecaEscolhida = jogador2[indicePecaEscolhida];
            jogador2[indicePecaEscolhida] = jogador2[numeroPecasDoJogador2 - 1]; 
            numeroPecasDoJogador2--;
        } else {
            printf("nao pode\n");
            return;
        }
    }

    // pode ou nao pode
    if (mesa.posicaoLivreMesa > 0 && (pecaEscolhida.lado1 == mesa.pecasNaMesa[0].lado1 || pecaEscolhida.lado2 == mesa.pecasNaMesa[0].lado1 || pecaEscolhida.lado1 == mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2 || pecaEscolhida.lado2 == mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2)) {
        
        if (pecaEscolhida.lado2 == mesa.pecasNaMesa[0].lado1) {
            inverterPeca(pecaEscolhida);
        }
        if (pecaEscolhida.lado1 == mesa.pecasNaMesa[0].lado1 || pecaEscolhida.lado2 == mesa.pecasNaMesa[0].lado1) {
            // esquerda
            for (int i = mesa.posicaoLivreMesa; i > 0; i--) {
                mesa.pecasNaMesa[i] = mesa.pecasNaMesa[i - 1];
            }
            mesa.pecasNaMesa[0] = pecaEscolhida;
            mesa.posicaoLivreMesa++;
        } else if (pecaEscolhida.lado1 == mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2 || pecaEscolhida.lado2 == mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2) {
            if (pecaEscolhida.lado1 == mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2) {
                inverterPeca(pecaEscolhida);
            }
            //direita
            mesa.pecasNaMesa[mesa.posicaoLivreMesa] = pecaEscolhida;
            mesa.posicaoLivreMesa++;
        } else {
            printf("peca nao pode ser jogada!\n");
            return;
        }
    } else if (mesa.posicaoLivreMesa == 0) {
        //poe a peca na mesa se vtiver vazia
        mesa.pecasNaMesa[0] = pecaEscolhida;
        mesa.posicaoLivreMesa++;
    } else {
        printf("nao pode\n");
        return;
    }

    apresentarMesa();

    // muda vez
    if (jvez == 'J') {
        jvez = 'j';
    } else {
        jvez = 'J';
    }

    pepecasPecas(jvez);
}
