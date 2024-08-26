//DOM-GGMS-Model.h - Projeto Dominó - Etapa 2
//09/08/2024 - Grupo: GGMS
//Gabriel Azevedo Cruz 
//Giulia Meninel Mattedi
//Matheus Gomes Costa Castanho Giacomini
//Sthefany Viveiros Cordeiro

//estrutura tipo peca
typedef struct {
    int lado1;
    int lado2;
    char status; //NULL = indisponivel, 1 = player1, 2 = player2, M = localizado na mesa
} tipopeca;

typedef struct {
    int mesaE;
    int mesaD;
} Mesa; 

void fCriar(tipopeca pecas[28]);
void distribuiPecas();
void exibePecas();
