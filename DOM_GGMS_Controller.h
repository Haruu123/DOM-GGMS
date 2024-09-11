//DOM-GGMS-Controller.h - Projeto Domino - Etapa 5
//03/09/24 - Grupo: GGMS
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
void atualizaPecas(char jvez);
void jogada();
void mostrarPecasPossiveis(tipopeca jogador1[], tipopeca jogador2[], char jogadorAtivo);
void recuperaCadastro();
void gravaCadastro();

