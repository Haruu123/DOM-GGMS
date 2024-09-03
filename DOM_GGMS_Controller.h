//DOM-GGMS-Controller.h - Projeto Dominó - Etapa 3
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

void jogo();
void fEmbaralha(tipopeca pecas[28]);
void iniciarJogo();
void colocarPecaNaMesa(tipopeca peca);
void primeiroLance();
void menuGeral();
void inverterPeca(tipopeca &peca);
void subMenu();
void limparBuffer();
void fComprar(tipopeca monte[], int &numeroPecasNoMonte, tipopeca jogador[], int &numeroPecasDoJogador);
void pepecasPecas(char jvez);
void jogada();
void mostrarPecasPossiveis(tipopeca jogador1[], tipopeca jogador2[], char jogadorAtivo);
void vencedor();
void podeJogarOuNao();

