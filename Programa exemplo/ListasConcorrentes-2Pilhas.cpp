#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include "TAD2Pilhas.h"

char menu(){
    system("cls");
    textcolor(15);
    printf("\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
    printf("\t\t\t\t    SIMULACAO LISTAS CONCORRENTES - 2 PILHAS           \n");
    printf("\t\t\t\t==============================================\n");
    printf("\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t==============================================\n");

    return toupper(getch());
}

int main(){
    TpPilhaM pilhaM;

    char op, letra, elemTopo1, elemTopo2;
    int ut;

    op = menu();
    while(op == 13){

        //desenhos
        system("cls");
        desenhaDescricao();
        desenhaVetor(12, 30);
        desenhaPlacaInformacoes(23, 5);
        gotoxy(50, 25);
        textcolor(4);printf("Obs.: Exclusoes sao feitas de 7/8 em 7/8 unidades de tempo");textcolor(15);

        //inicializacoes
        inicializar(pilhaM);
        ut = 1;
        letra = 65;
        elemTopo1 = elemTopo2 = ' ';

        while(!cheia(pilhaM.topo1, pilhaM.topo2) && !kbhit()){

            gotoxy(12, 25);
            printf("UT = %d", ut);
            gotoxy(12, 26);
            printf("Ultimo elemento do topo 1 a sair = %c", elemTopo1);
            gotoxy(12, 27);
            printf("Ultimo elemento do topo 2 a sair = %c", elemTopo2);
            exibir(pilhaM, 1);
            exibir(pilhaM, 2);

            //insercao
            if(ut % 3 == 0){
                if(!cheia(pilhaM.topo1, pilhaM.topo2))
                    inserir(pilhaM, letra++, 1);
            }
            if(ut % 4 == 0){
                if(!cheia(pilhaM.topo1, pilhaM.topo2))
                    inserir(pilhaM, letra++, 2);
            }

            //exclusao
            if(ut % 7 == 0){
                if(!vazia(pilhaM.topo1, 1));
                    elemTopo1= retirar(pilhaM, 1);
            }
            if(ut % 8 == 0){
                if(!vazia(pilhaM.topo2, 2));
                    elemTopo2 = retirar(pilhaM, 2);
            }

            Sleep(1000);
            ut++;
        }

        getch();
        op = menu();
    }
}
