#define _CRT_SECURE_NO_WARNINGS
#include "jogo.h"
#include <stdio.h>

int sorteio(limSup)
{
	return  rand() % limSup;
}

int menu()
{
	int opcao;

	system("cls||clear");
	puts("\n");
	puts("\t+======================= JOGO DA FORCA ==========================+");
	puts("\t+----------------------------------------------------------------+");
	puts("\t|                        MENU                                    |");
	puts("\t+----------------------------------------------------------------+");
	puts("\t|  1 - Jogar                                                     |");
	puts("\t|  2 - Sair                                                      |");
	puts("\t+----------------------------------------------------------------+");

	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao);

	return opcao;
}
void instrucoes()
{
	system("cls||clear");
	puts("\n");
	puts("\t+=================== BEM-VINDO AO JOGO DA FORCA =================+");
	puts("\t+----------------------------------------------------------------+");
	puts("\t|                           INSTRUCOES                           |");
	puts("\t+----------------------------------------------------------------+");
	puts("\t| - O Jogador possui 5 tentativas para acertar a palavra.        |");
	puts("\t| - Digite '?' para tentar adivinhar a palavra completa.         |");
	puts("\t| - Se errar o chute direto, o jogo acaba imediatamente.         |");
	puts("\t+----------------------------------------------------------------+\n");

}
void forca(int erros)

{
	if (erros >= 0)
	{
		puts("\n\t\t FORCA");
		puts("\t\t +-------+");
		puts("\t\t |       |");


		if (erros >= 1) puts("\t\t |       O");
		if (erros >= 2) puts("\t\t |       |");
		if (erros >= 3) puts("\t\t |      /|\\");
		if (erros >= 4) {
			puts("\t\t |       | ");
			puts("\t\t |      / ");
		}

		if (erros >= 5)
			mensagemDerrota();
		else
		{
			puts("\t\t |");
			puts("\t\t============+");
		}
	}
}
void valida(char letra, char jogo[], char escondida[], int tam, int* erro, int* acerto)
{
	int contErroAcerto = 0;

	for (int i = 0; i < tam; i++)
	{
		if (jogo[i] == letra)
		{
			contErroAcerto++;
			escondida[i] = letra;
		}
	}
	if (contErroAcerto == 0)
		(*erro)++;
	else
		(*acerto)++;
}
void mostraletra(char usada[], int contador)
{
	printf("\tLetras Usadas : ");
	for (int i = 0; i < contador; i++) 
		printf(" %c,", usada[i]);		
}
void limpaBuffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF); 
}
void mensagemVitoria()
{
	puts("\n\t##############################");
	puts("\t#       VOCE VENCEU!!!       #");
	puts("\t##############################");
	puts("\t           __________");
	puts("\t          '._==_==_=_.'");
	puts("\t          .-\\:      /-.");
	puts("\t         | (|:.     |) |");
	puts("\t          '-|:.     |-'");
	puts("\t            \\::.    /");
	puts("\t             '::. .'");
	puts("\t               ) (");
	puts("\t             _.' '._");
	puts("\t            '-------'");
	puts("\t      Pressione enter...\n");
	limpaBuffer();
	getchar();
}
void mensagemDerrota()
{

	puts("\n\t##########################################");
	puts("\t#               GAME OVER...             #");
	puts("\t##########################################");
	puts("");
	puts("\t\t        +-------+");
	puts("\t\t        |   |   |");
	puts("\t\t        |   O   |");
	puts("\t\t        |  /|\\  |");
	puts("\t\t        |   |   |");
	puts("\t\t        |  / \\  |");
	puts("\t\t        |       |");
	puts("\t\t      +-----------+");
	puts("\t\t      | ENFORCADO |");
	puts("\t\t      +-----------+");
	puts("");
	puts("\t      Pressione enter...\n");
	limpaBuffer();
	getchar();
}
void saidaJogo()
{
	system("cls||clear");
	puts("\t+================================================================+");
	puts("\t|                                                                |");
	puts("\t|                OBRIGADO POR JOGAR JOGO DA FORCA                |");
	puts("\t|                                                                |");
	puts("\t+================================================================+");
	printf("\n\tPressione ENTER para fechar...");
	getchar();
}