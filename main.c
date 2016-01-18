#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "headers/cabecalho_funcoes_jogo_forca.h"

int main()
{
    int chances = 6,i,verificaSeAcertouALetra,flagGanhouOJogo=0;
    char opcao;

    do{

        char palavra[50],caracterInformado;
        char palavras[tamanhoOpcoesPalavras][50];
        chances = 6;

        setaPalavras(palavras);
        int num = randomizaPalavra();
        strcpy(palavra,palavras[num]); /// copia a palavra escolhida randomicamente pra palavra que iremos jogar

        char tracos[50];
        inicializaTracos(tracos);

        puts("********************* Jogo da forca GUSTAVO RIPOSATI *********************\n");
        puts("vamos la, chute uma letra qualquer e tecle enter....\n");

        mostraTracosInicioJogo(palavra,tracos);

        while(chances > 0){ /// enquanto houverem chances

            verificaSeAcertouALetra=0; /// flag de controle pra saber se o user acertou o chute o não
            flagGanhouOJogo = 0; /// flag para saber se o jogador venceu o jogo e para a execução caso o tenha feito
            scanf(" "); /// ler lixo do teclado

            printf("\ninforme uma letra qualquer e tecle enter\n");
            scanf("%c",&caracterInformado);
            caracterInformado = tolower(caracterInformado); /// deixa minuscula caso seja informado valor maiusculo

            verificaSeAcertouALetra = verificaSeExisteLetra(palavra,caracterInformado,tracos);
            flagGanhouOJogo = mostraDesempenhoJogador(palavra,tracos);

            if(flagGanhouOJogo==0){
                printf("VOCE GANHOU! PARABENS!\n");
                printf(" \\O/\n  | \n  /\\");
                break;
            }

            if(verificaSeAcertouALetra==0){ /// se errar o chute entra aqui
                chances--;
                printf("\n------MENOS UMA CHANCE -- RESTAM %d------\n",chances);
                printf("\ninforme um caracter e tecle enter\n");
            }
        }

        mostraPerdeu(palavra,chances);

        printf("\n");
        opcao = leOpcao();

    }while(opcao!='n' && opcao!='N'); /// faça enquanto o jogador quiser jogar!!
    system("pause");
    return 0;
}
