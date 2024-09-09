//DOM-GGMS-Controller.cpp - Projeto Domino - Etapa 5
//03/09/24 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro
 
#include "DOM_GGMS_Controller.h"
#include "DOM_GGMS_View.cpp"
#include <stdlib.h>
#include <time.h>
#include <string.h>
 
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
    if (mesa.posicaoLivreMesa < 28) { //A mesa so pode ter 28 pecas, entao mesa.posicaoLivreMesa avalia se ha espaco para novas pecas
        mesa.pecasNaMesa[mesa.posicaoLivreMesa] = peca; //pecasNaMesa e' uma array de 28 slots (pecas). Se houver espaco, 'peca' e' adicionada a posicao de mesa.posicaoLivreMesa
        mesa.posicaoLivreMesa++; //Depois de alocar espaco para uma peca, mesa.posicaoLivreMesa e' incrementada para disponibilizar uma proxima posicao 
    }
}
//Exclusao da inicializacao em 0 de mesa.posicaoLivreMesa = como sempre inicializava em 0, impedia a adicao de novas pecas a mesa
 
void primeiroLance() {
    int i, pj, dupla;
    pj = -1;
    dupla = -1;
    tipopeca pecaJogada;
 
    // Procurar a maior dupla:
/* Se os lados da peca escolhida forem iguais, pj recebe o indice da peca e dupla, seu valor. A comparacao com -1 e' realizada para determinar se a dupla
existe; caso nao exista, pj == -1, e o algoritmo passa a procurar a peca com a maior soma disponivel.
*/
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
 
    // Se nao tiver dupla, procurar a peca com a maior soma
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
 
 /* Se jvez = 'J', pecaJogada (tipopeca) torna-se a peca de maior dupla/soma, e o numero de pecas do jogador 1 reduz em uma unidade. E vice-versa.
 */
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
 
    //Necessario para alternar as vezes dos jogadores.
    if (jvez == 'J') {
    	apresentarMensagem("Jogador 1 jogou.\n");
        jvez = 'j';
    } else {
    	apresentarMensagem("Jogador 2 jogou.\n");
        jvez = 'J';
    }
 
    atualizaPecas(jvez); // pecas de quem jogou
    subMenu();
    system("cls");
}
 
void atualizaPecas(char jvez) {
    char indice; 
    if (jvez == 'J') {
    	indice = 'a'; // Inicializa a ordem de rotulacao das pecas em letras alfabeticas para o jogador 1
        apresentarMensagem("\nPecas do jogador 1:\n");
        for (int i = 0; i < numeroPecasDoJogador1; i++) { // pecas do jogador 1
            apresentarPeca(indice, jogador1[i].lado1, jogador1[i].lado2);
            indice++;
        }
        apresentarMensagem("\n");
    } else {
    	indice = 'a'; // Inicializa a ordem de rotulacao das pecas em letras alfabeticas para o jogador 2
        apresentarMensagem("\nPecas do jogador 2:\n");
        for (int i = 0; i < numeroPecasDoJogador2; i++) { // pecas do jogador 2
            apresentarPeca(indice, jogador2[i].lado1, jogador2[i].lado2);
            indice++;
        }
        apresentarMensagem("\n");
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
    system("cls");
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
                system("cls");
                break;
            case 2:
            	regrasGerais();
            case 3:
            	gravaCadastro();
            	break;
            case 4:
            	recuperaCadastro();
            	break;
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
                atualizaPecas(jvez);
                break;
            case 'p':
                if (jvez == 'J') {
                    jvez = 'j'; // passa a vez para o jogador 2
                    system("cls");
                } else {
                    jvez = 'J'; // Passa a vez para o jogador 1
                    system("cls");                 
                }
                apresentarMensagem("Jogador passou a vez");
                apresentarMesa();
                atualizaPecas(jvez); // atualiza as peças para o jogador que agora tem a vez
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
    int jogadaValida = 0; //nenhuma peça jogavel encontrada ainda
    char indice;

    if (mesa.posicaoLivreMesa > 0) {
        mesaE = mesa.pecasNaMesa[0].lado1;
        mesaD = mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2;
    } else {
        mesaE = mesaD = -1; // mesa vazia
    }

    if (jvez == 'J') {
        indice = 'a';
        for (int i = 0; i < numeroPecasDoJogador1; i++) {
            if (jogador1[i].lado1 == mesaE || jogador1[i].lado2 == mesaE || 
                jogador1[i].lado1 == mesaD || jogador1[i].lado2 == mesaD) {
                if (!jogadaValida) //Se uma peça valida for encontrada, if (!jogadaValida) é verdadeiro pois !0 = 1 (verdadeiro)
				{
                    apresentarMensagem("Pecas possiveis do Jogador 1:");
                }
                apresentarPeca(indice, jogador1[i].lado1, jogador1[i].lado2);
                jogadaValida = 1;
            }
            indice++;
        }
    } else {
        indice = 'a';
        for (int i = 0; i < numeroPecasDoJogador2; i++) {
            if (jogador2[i].lado1 == mesaE || jogador2[i].lado2 == mesaE || 
                jogador2[i].lado1 == mesaD || jogador2[i].lado2 == mesaD) {
                if (!jogadaValida) {
                    apresentarMensagem("Pecas possiveis do Jogador 2:");
                }
                apresentarPeca(indice, jogador2[i].lado1, jogador2[i].lado2);
                jogadaValida = 1;
            }
            indice++;
        }
    } 
    
    if (!jogadaValida) {
        apresentarMensagem("Nao possui pecas jogaveis, compre pecas.");
        subMenu();
    }
    apresentarMensagem("\n");
}

void vencedor() {
    if (numeroPecasDoJogador1 == 0) {
        apresentarMensagem("FIM: jogador 1 venceu");
        exit(0);
    } else if (numeroPecasDoJogador2 == 0) {
        apresentarMensagem("FIM: jogador 2 venceu");
        exit(0);
    }
}

void podeJogarOuNao() {
    int podeJogarJogador1 = 0;
    int podeJogarJogador2 = 0;

    int ladoMesaEsquerda = mesa.pecasNaMesa[0].lado1;
    int ladoMesaDireita = mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2;

    for (int i = 0; i < numeroPecasDoJogador1; i++) {
        if (jogador1[i].lado1 == ladoMesaEsquerda || jogador1[i].lado2 == ladoMesaEsquerda ||
            jogador1[i].lado1 == ladoMesaDireita || jogador1[i].lado2 == ladoMesaDireita) {
            podeJogarJogador1 = 1;
            break;
        }
    }

    for (int i = 0; i < numeroPecasDoJogador2; i++) {
        if (jogador2[i].lado1 == ladoMesaEsquerda || jogador2[i].lado2 == ladoMesaEsquerda ||
            jogador2[i].lado1 == ladoMesaDireita || jogador2[i].lado2 == ladoMesaDireita) {
            podeJogarJogador2 = 1;
            break;
        }
    }

    if (podeJogarJogador1 == 0 && podeJogarJogador2 == 0 && numeroPecasNoMonte == 0) {
        if (numeroPecasDoJogador1 < numeroPecasDoJogador2) {
            apresentarMensagem("Nenhum jogador pode jogar. Jogador 1 venceu com menos pecas.");
        } else if (numeroPecasDoJogador2 < numeroPecasDoJogador1) {
            apresentarMensagem("Nenhum jogador pode jogar. Jogador 2 venceu com menos pecas.");
        } else {
            apresentarMensagem("Nenhum jogador pode jogar. O jogo terminou empatado.");
        }
        exit(0);
    }
}

void jogada() {
    tipopeca pecaEscolhida;
    int indicePecaEscolhida;


    mostrarPecasPossiveis(jogador1, jogador2, jvez);

    apresentarMensagem("Escolha a peca (digite a letra): ");
    escanearEscolha();
    

    if (jvez == 'J') {
        indicePecaEscolhida = escolha - 'a'; //Conceito da tabela ASCII 
        if (indicePecaEscolhida >= 0 && indicePecaEscolhida < numeroPecasDoJogador1) { //Checa se o indice e' valido
            pecaEscolhida = jogador1[indicePecaEscolhida];
            jogador1[indicePecaEscolhida] = jogador1[numeroPecasDoJogador1 - 1]; //Remove a peca escolhida do leque, substituindo-a pela última peça
            numeroPecasDoJogador1--; //Reduz uma peca do leque do jogador 1
        } else {
            apresentarMensagem("Nao pode.");
            return;
        }
    } else {
        indicePecaEscolhida = escolha - 'a';
        if (indicePecaEscolhida >= 0 && indicePecaEscolhida < numeroPecasDoJogador2) {
            pecaEscolhida = jogador2[indicePecaEscolhida];
            jogador2[indicePecaEscolhida] = jogador2[numeroPecasDoJogador2 - 1];
            numeroPecasDoJogador2--;
        } else {
            apresentarMensagem("Nao pode.");
            return;
        }
    }

    int ladoMesaEsquerda = mesa.pecasNaMesa[0].lado1; //Lado esquerdo da primeira peca da mesa
    int ladoMesaDireita = mesa.pecasNaMesa[mesa.posicaoLivreMesa - 1].lado2; //Lado direito da ultima peca da mesa

    if ((pecaEscolhida.lado1 == ladoMesaEsquerda || pecaEscolhida.lado2 == ladoMesaEsquerda) && 
        (pecaEscolhida.lado1 == ladoMesaDireita || pecaEscolhida.lado2 == ladoMesaDireita)) {
   /*Verifica se a peca escolhida pode ser jogada tanto no lado esquerdo quanto no lado direito da mesa. 
	Se for o caso, o jogador pode escolher em qual lado jogar.*/
        apresentarMensagem("'e' para esquerda ou 'd' para direita: ");
        limparBuffer();
        escanearLadoEscolhido();

        if (ladoEscolhido == 'e') {
            if (pecaEscolhida.lado1 == ladoMesaEsquerda) { //Verifica se sera necessario inverter a peca devido a nao compatibilidade numerica das pecas
                inverterPeca(pecaEscolhida);
            }

            for (int i = mesa.posicaoLivreMesa; i > 0; i--) { //Se for necessario inverter, as pecas sao deslocadas para a direita
                mesa.pecasNaMesa[i] = mesa.pecasNaMesa[i - 1];
            }
            mesa.pecasNaMesa[0] = pecaEscolhida;
            mesa.posicaoLivreMesa++;
            
        } else if (ladoEscolhido == 'd') {
            if (pecaEscolhida.lado2 == ladoMesaDireita) { 
                inverterPeca(pecaEscolhida);
            }

            mesa.pecasNaMesa[mesa.posicaoLivreMesa] = pecaEscolhida; //Se for necessario inverter a peca, sera adicionada a direita, sem mover as outras pecas
            mesa.posicaoLivreMesa++;
        } else {
            apresentarMensagem("Nao pode.");
            return;
        }
    } else if (pecaEscolhida.lado1 == ladoMesaEsquerda || pecaEscolhida.lado2 == ladoMesaEsquerda) { //Somente podera ser jogada na esquerda
        if (pecaEscolhida.lado1 == ladoMesaEsquerda) {
            inverterPeca(pecaEscolhida);
        }

        for (int i = mesa.posicaoLivreMesa; i > 0; i--) {
            mesa.pecasNaMesa[i] = mesa.pecasNaMesa[i - 1];
        }
        mesa.pecasNaMesa[0] = pecaEscolhida;
        mesa.posicaoLivreMesa++;
    } else if (pecaEscolhida.lado1 == ladoMesaDireita || pecaEscolhida.lado2 == ladoMesaDireita) { //Somente podera ser jogada na direita 
        if (pecaEscolhida.lado2 == ladoMesaDireita) {
            inverterPeca(pecaEscolhida);
        }

        mesa.pecasNaMesa[mesa.posicaoLivreMesa] = pecaEscolhida;
        mesa.posicaoLivreMesa++;
    } else {
        apresentarMensagem("Nao pode.");
        return;
    }
    
    system("cls");
    apresentarMesa();

    vencedor();
    podeJogarOuNao();

    // Troca vez
    if (jvez == 'J') {
        jvez = 'j';
    } else {
        jvez = 'J';
    }

    atualizaPecas(jvez);
}

void gravaCadastro() {
    FILE *fp, *fpm, *fps;

    // Abrindo os arquivos para gravação
    fp = fopen("CAD_DOMINO.dat", "wb");
    fpm = fopen("CAD_MESA.dat", "wb");
    fps = fopen("CAD_JOGO.dat", "wb");

    if (fp == NULL || fpm == NULL || fps == NULL) {
        printf("Erro ao abrir arquivos para gravacao.\n");
        return;
    }

    // Gravar todas as 28 peças no arquivo CAD_DOMINO
    fwrite(pecas, sizeof(tipopeca), 28, fp);

    // Gravar as peças da mesa no arquivo CAD_MESA
    fwrite(mesa.pecasNaMesa, sizeof(tipopeca), mesa.posicaoLivreMesa, fpm);

    // Atualizar a estrutura sitJogo com as variáveis globais
    sitJogo.qtMesaJogo = mesa.posicaoLivreMesa;
    sitJogo.mesaDJogo = mesa.mesaD;
    sitJogo.mesaEJogo = mesa.mesaE;
    sitJogo.jogadorJogo = (jvez == 'J') ? 1 : 2;

    // Gravar a estrutura sitJogo no arquivo CAD_JOGO
    fwrite(&sitJogo, sizeof(Jogo), 1, fps);

    // Fechar os arquivos
    fclose(fp);
    fclose(fpm);
    fclose(fps);

    apresentarMensagem("Cadastro gravado com sucesso!\n");
}

void recuperaCadastro() {
    FILE *fp, *fpm, *fps;

    // Abrindo os arquivos para leitura
    fp = fopen("CAD_DOMINO.dat", "rb");
    fpm = fopen("CAD_MESA.dat", "rb");
    fps = fopen("CAD_JOGO.dat", "rb");

    if (fp == NULL || fpm == NULL || fps == NULL) {
        printf("Erro ao abrir arquivos para leitura.\n");
        return;
    }

    // Recuperar todas as 28 peças do arquivo CAD_DOMINO
    fread(pecas, sizeof(tipopeca), 28, fp);

    // Recuperar as peças da mesa do arquivo CAD_MESA
    fread(mesa.pecasNaMesa, sizeof(tipopeca), mesa.posicaoLivreMesa, fpm);

    // Recuperar a estrutura sitJogo do arquivo CAD_JOGO
    fread(&sitJogo, sizeof(Jogo), 1, fps);

    // Atualizar as variáveis globais com os dados recuperados
    mesa.posicaoLivreMesa = sitJogo.qtMesaJogo;
    mesa.mesaD = sitJogo.mesaDJogo;
    mesa.mesaE = sitJogo.mesaEJogo;
    jvez = (sitJogo.jogadorJogo == 1) ? 'J' : 'j';

    // Fechar os arquivos
    fclose(fp);
    fclose(fpm);
    fclose(fps);

    apresentarMensagem("Cadastro recuperado com sucesso!\n");
}



