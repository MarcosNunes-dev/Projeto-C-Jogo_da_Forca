
#pragma once
#define R 99
#define P 21
#define L 30

int sorteio(limSup);
int menu();
void instrucoes();
void forca(int erros);
void valida(char letra, char jogo[], char escondida[], int tam, int* erro, int* acerto);
void mostraletra(char usada[], int contador);
void limpaBuffer();
void mensagemVitoria();
void mensagemDerrota();
void saidaJogo();