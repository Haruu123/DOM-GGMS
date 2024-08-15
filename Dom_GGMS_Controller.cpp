void jogo()
{
    fMostra();
    fEmbaralha();
    
    fMostra();
    fEmbaralha();
    
    fMostra();
    fEmbaralha();
}



void fEmbaralha(tipopeca pecas[28]) {
    srand(time(NULL));
    
    for (int i = 0; i < 28; i++) {
        int j = rand() % 28;
        
        //Troca as pecas de lugar
        tipopeca temp = pecas[i];
        pecas[i] = pecas[j];
        pecas[j] = temp;
    }
}
