#define _CRT_SECURE_NO_WARNINGS
#ifdef _MSC_VER
#endif
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h> // para fazer o sorteio
#include <time.h>
#include "jogo.h" // inclui nossa biblioteca (header file)

int main()
{
	char palavras[R][P], jogo[P], escondida[P], chute[P], letra;
	int pSorteada, erros, acertos, tam, escolha, contador;
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL)); // inicia o sorteio

	// palavras para o sorteio
	strcpy(palavras[0], "TPSI");
	strcpy(palavras[1], "PROGRAMADOR");
	strcpy(palavras[2], "ESTUDANTE");
	strcpy(palavras[3], "DOMINGO");
	strcpy(palavras[4], "SEMANA");
	strcpy(palavras[5], "COMPUTADOR");
	strcpy(palavras[6], "JANELA");
	strcpy(palavras[7], "ESCOLA");
	strcpy(palavras[8], "PORTO");
	strcpy(palavras[9], "CAMINHO");
	strcpy(palavras[10], "LIVRO");
	strcpy(palavras[11], "CIDADE");
	strcpy(palavras[12], "TRABALHO");
	strcpy(palavras[13], "CASTELO");
	strcpy(palavras[14], "FOGUETE");
	strcpy(palavras[15], "TECLADO");
	strcpy(palavras[16], "MOCHILA");
	strcpy(palavras[17], "GUITARRA");
	strcpy(palavras[18], "DINHEIRO");
	strcpy(palavras[19], "ALDEIA");
	//inicio ciclo
	do
	{
		escolha = menu();
		if (escolha == 1)
		{
			pSorteada = sorteio(20); // escreve na variavel o númeuro que foi sorteado
			strcpy(jogo, palavras[pSorteada]); // copia para array jogo a palavra sorteada

			tam = strlen(jogo); // define o tamanho da palavra 
			for (int i = 0; i < tam; i++) {
				escondida[i] = '*';
			}
			escondida[tam] = '\0'; // para marcar o final

			erros = 0;
			acertos = 0;
			contador = 0;
			char usada[L] = { 0 };
			do
			{
				instrucoes(); // chama a função
				forca(erros); // chama a função

				printf("\t\t\t\t\t\t PALAVRA SECRETA :  %s\n\n", escondida);
				//printf("\t\t\t\t\t\t PALAVRA SECRETA :  %s\n\n", jogo); usado para teste
				mostraletra(usada, contador); // função de mostras as letradas já usadas
				puts("\n");
				printf("\tNº de Erros  : %d\n", erros);
				printf("\tNº de Acertos: %d\n\n", acertos);


				
				printf("\tLetra: ");
				scanf(" %c", &letra);
				limpaBuffer();

				// ciclo para aceitar só letras ou '?'
				while (!((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || (letra == '?')))
				{
					printf("\tLetra inválida! Digite novamente: ");
					scanf(" %c", &letra);
					limpaBuffer();
				}
				// transforma a letra minúscula em maiúscula
				if (letra >= 'a' && letra <= 'z')
					letra = letra - 32;
				// opção do chute
				if (letra == '?')
				{
					printf("\t Digite a palavra em MAIÚSCULA\n");
					printf("\t Boa sorte no seu CHUTE: ");
					scanf(" %s", chute);

					if (strcmp(chute, jogo) == 0)
						strcpy(escondida, jogo);
					else
						erros = 5;
						break;
				}
				// caso não chute, vai jogar letra a letra
				else
					usada[contador] = letra; // guarda a letra na array usada nã posição 0
					contador++; // depois adiciona +1 ao contador
					valida(letra, jogo, escondida, tam, &erros, &acertos);

			} while ((erros <= 4) && (strcmp(escondida, jogo) != 0));
			system("cls||clear");
			if (strcmp(escondida, jogo) == 0)
				mensagemVitoria();
			else
				mensagemDerrota();
		}
		else
			saidaJogo();
	} while (escolha != 2);
}