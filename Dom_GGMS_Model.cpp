void fCriar(tipopeca pecas[28]) {
    int k = 0;
    
    for (int i = 0; i <= 6; i++) {
        for (int j = i; j <= 6; j++) {
            pecas[k].lado1 = i;    //contador atribuido pra lado1
            pecas[k].lado2 = j;    //contador atribuido pra lado2
            k++;
        }
    }
}
