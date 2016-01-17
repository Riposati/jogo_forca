#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define tamanhoOpcoesPalavras 19 /// o tamanho do array - 1 pra escolher indices

int randomizaPalavra(){

    srand((unsigned)time(NULL)); // pra mudar o valor a todo momento
    int num = rand() % tamanhoOpcoesPalavras;
    return num;
}

void setaPalavras(char palavras[20][50]){

    /** aqui seto algumas opções do joguinho */
    strcpy(palavras[0],"morango");
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
    strcpy(palavras[19],"preguica");
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

int main()
{
    int chances = 6,i,flag,flagResp=0;
    char opcao;

    do{

        char palavra[50],caracterInformado;
        char palavras[20][50];
        chances = 6;

        setaPalavras(palavras);
        int num = randomizaPalavra();
        //printf("num = %d\n",num);
        //printf("palavras[num] = %s\n",palavras[num]);
        strcpy(palavra,palavras[num]); /// copia a palavra escolhida randomicamente pra palavra que iremos jogar

        char tracos[50];
        inicializaTracos(tracos);

        puts("********************* Jogo da forca *********************\n");
        puts("inicio....\n");
        for(i=0;i<strlen(palavra);i++){ /// mostra os traços no inicio da rodada
            printf(" %c ",tracos[i]);
        }
        printf("\n");

        while(chances > 0){ /// enquanto houverem chances

            flag=0; /// flag de controle pra saber se o user acertou o chute o não
            flagResp = 0; /// flag para saber se o jogador venceu o jogo e para a execução caso o tenha feito
            scanf(" "); /// ler lixo do teclado

            printf("\ninforme um caracter e tecle enter\n");
            scanf("%c",&caracterInformado);
            caracterInformado = tolower(caracterInformado); /// deixa minuscula caso seja informado valor maiusculo

            for(i=0;i<strlen(palavra);i++){ /// pra verificar se existe o char na palavra ou não

                if(palavra[i] == caracterInformado){
                    tracos[i] = caracterInformado;
                    flag = 1;
                }
            }

            printf("\n");
            for(i=0;i<strlen(palavra);i++){ /// mostrar o desempenho do jogador

                printf(" %c ",tracos[i]);

                if(tracos[i]!=palavra[i]){

                    flagResp = 1;
                }
            }
            printf("\n");

            if(flagResp==0){
                printf("VOCE GANHOU! PARABENS!\n");
                printf(" \\O/\n  | \n  /\\");
                break;
            }

            if(flag==0){ /// se errar o chute entra aqui
                chances--;
                printf("\n------MENOS UMA CHANCE -- RESTAM %d------\n",chances);
                printf("\ninforme um caracter e tecle enter\n");
            }
        }

        if(chances==0){ /// perdeu entra aqui

            printf("\n------VOCE FOI ENFORCADO!!!------\n\n--]\n  |\n  |\n  |\n \\O/\n  |\n  /\\");
            printf("\n");
            printf("A PALAVRA CERTA ERA --->>>> %s",palavra);
            printf("\n");
            opcao = leOpcao();
        }

        printf("\n");
        opcao = leOpcao();

    }while(opcao!='n' && opcao!='N');
    system("pause");
    return 0;
}
