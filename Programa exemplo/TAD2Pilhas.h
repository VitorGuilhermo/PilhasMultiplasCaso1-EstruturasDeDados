#define MAXPILHA 11

struct TpPilhaM{
    int topo1, topo2;
    char pilha[MAXPILHA];
};

void inicializar(TpPilhaM &pilha){
    pilha.topo1 = -1;
    pilha.topo2 = MAXPILHA;
}

void inserir(TpPilhaM &pm, char elem, int nPilha){
    if(nPilha == 1)
        pm.pilha[++pm.topo1] = elem;
    else
        pm.pilha[--pm.topo2] = elem;
}

char retirar(TpPilhaM &pm, int nPilha){
    if(nPilha == 1)
        return pm.pilha[pm.topo1--];
    else
        return pm.pilha[pm.topo2++];
}

char elementoTopo(TpPilhaM pm, int nPilha){
    if(nPilha == 1)
        return pm.pilha[pm.topo1];
    else
        return pm.pilha[pm.topo2++];
}

int cheia(int topo1, int topo2){
    return topo1 == topo2-1;
}

int vazia(int topo, int nPilha){
    if(nPilha == 1)
        return topo == -1;
    else
        return topo == MAXPILHA;
}

void exibir(TpPilhaM pm, int nPilha){
    int coluna1 = 36, coluna2 = 82;
    if(nPilha == 1){
        while(!vazia(pm.topo1, nPilha)){
            gotoxy(coluna1, 14);
            printf("%c", retirar(pm, nPilha));
            coluna1 += 5;
        }
    }
    else{
        while(!vazia(pm.topo2, nPilha)){
            gotoxy(coluna2, 14);
            printf("%c", retirar(pm, nPilha));
            coluna2 -= 5;
        }
    }
}



//desenhos
void desenhaVetor(int linha, int coluna){
    char vetor[][100] = {
                                "     _________________________________________________  ",
                                "    |    |    |    |    |    |    |    |    |    |    |",
                                "    |    |    |    |    |    |    |    |    |    |    |",
                                "    |____|____|____|____|____|____|____|____|____|____|",
                                "      0    1    2    3    4    5    6    7    8    9"
                                };
    textcolor(3);
    for(int i = 0; i<5; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", vetor[i]);
    }
    textcolor(15);
}
void desenhaDescricao(){
    textcolor(11);
    gotoxy(8, 1);
    printf("==========================================================================================================");
    gotoxy(38, 2);
    printf("SIMULACAO DE UMA PILHA MULTIPLA - 2 PILHAS               ");
    gotoxy(8, 3);
    printf("==========================================================================================================");
    textcolor(15);
}
void desenhaPlacaInformacoes(int linha, int coluna){
    int i;
    char placa [][150] = {
                        " _____________________________________________________________________________________________________________",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|_____________________________________________________________________________________________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}
