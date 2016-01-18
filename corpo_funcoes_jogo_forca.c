#ifndef header
#include "headers/cabecalho_funcoes_jogo_forca.h"
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int randomizaPalavra(){

    srand((unsigned)time(NULL)); // pra mudar o valor a todo momento
    int num = rand() % tamanhoOpcoesPalavras;
    return num;
}

char abreArquivoComAsPalavrasDoJogo(char palavras[tamanhoOpcoesPalavras][50]){

    FILE *f = fopen("palavras.txt" , "r+");

    if(f==0){

        printf("ERRO nao encontrei o arquivo com as palavras!\n");
        exit(1);
    }

    int tam,i;
    //fscanf(f,"%d", &tam);

    for(i=0;i<tamanhoOpcoesPalavras;i++){
        fscanf(f,"%s",palavras[i]);
    }

    /*for(i=0;i<tam;i++){ // pra visualizar o que o arquivo possui

        printf("%s ",palavras[i]);
    }*/

    fclose(f);

    return palavras;
}

void setaPalavras(char palavras[tamanhoOpcoesPalavras][50]){

    palavras = abreArquivoComAsPalavrasDoJogo(palavras);
    /** aqui seto algumas opções do joguinho */
    /*strcpy(palavras[0],"morango");
    strcpy(palavras[1],"abacaxi");
    strcpy(palavras[2],"melao");
    strcpy(palavras[3],"banana");
    strcpy(palavras[4],"amarelo");
    strcpy(palavras[5],"melancia");
    strcpy(palavras[6],"videogame");
    strcpy(palavras[7],"programacao");
    strcpy(palavras[8],"alura");
    strcpy(palavras[9],"amoroso");

    strcpy(palavras[10],"floresta");
    strcpy(palavras[11],"alemanha");
    strcpy(palavras[12],"livro");
    strcpy(palavras[13],"fazenda");
    strcpy(palavras[14],"macaco");
    strcpy(palavras[15],"vassoura");
    strcpy(palavras[16],"janela");
    strcpy(palavras[17],"carro");
    strcpy(palavras[18],"malandro");
    strcpy(palavras[19],"preguica");*/
    /********************************/
}

void inicializaTracos(char tracos[50]){

    int i=0;
    while(i < 50){

        tracos[i] = '-';
        i++;
    }
}

char leOpcao(){

    char opcao;

    printf("\nJogar denovo ? diferente de n/N para sim\n");
    scanf(" %c",&opcao);

    return opcao;
}

void mostraTracosInicioJogo(char *palavra, char *tracos){

    int i;

    for(i=0;i<strlen(palavra);i++){ /// mostra os traços no inicio da rodada
        printf(" %c ",tracos[i]);
    }
    printf("\n");
}

void mostraPerdeu(char *palavra, int chances){

    if(chances==0){ /// perdeu entra aqui

            printf("\n------VOCE FOI ENFORCADO!!!------\n\n--]\n  |\n  |\n  |\n \\O/\n  |\n  /\\");
            printf("\n");
            printf("A PALAVRA CERTA ERA --->>>> %s",palavra);
            printf("\n");
        }
}

int verificaSeExisteLetra(char *palavra, char caracterInformado, char *tracos){

    int i,flag=0;

    for(i=0;i<strlen(palavra);i++){ /// pra verificar se existe o char na palavra ou não

        if(palavra[i] == caracterInformado){
            tracos[i] = caracterInformado;
            flag = 1;
        }
    }

    return flag;
}

int mostraDesempenhoJogador(char *palavra, char *tracos){

    int i,flagGanhouOJogo = 0;

    printf("\n");
    for(i=0;i<strlen(palavra);i++){ /// mostrar o desempenho do jogador

        printf(" %c ",tracos[i]);

        if(tracos[i]!=palavra[i]){

            flagGanhouOJogo = 1;
        }
    }
    printf("\n");
    return flagGanhouOJogo;
}

#endif
