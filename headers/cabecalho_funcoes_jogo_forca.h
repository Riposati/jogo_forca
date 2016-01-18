#ifndef CABECALHO_FUNCOES_JOGO_FORCA_H_INCLUDED
#define CABECALHO_FUNCOES_JOGO_FORCA_H_INCLUDED
#define tamanhoOpcoesPalavras 30 /// o tamanho do array - 1 pra escolher indices

int randomizaPalavra();
char abreArquivoComAsPalavrasDoJogo(char palavras[tamanhoOpcoesPalavras][50]);
void setaPalavras(char palavras[tamanhoOpcoesPalavras][50]);
void inicializaTracos(char tracos[50]);
char leOpcao();
void mostraTracosInicioJogo(char *palavra, char *tracos);
void mostraPerdeu(char *palavra, int chances);
int verificaSeExisteLetra(char *palavra, char caracterInformado, char *tracos);
int mostraDesempenhoJogador(char *palavra, char *tracos);

#endif // CABECALHO_FUNCOES_JOGO_FORCA_H_INCLUDED
