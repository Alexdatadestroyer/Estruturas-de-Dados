/*	Algoritmo para implementa��o da TAD Pilha Din�mica por meio de utiliza��o de Ponteiros.

	Autor: Alexandre Gadelha da Silva Carvalho.

	O algoritmo ir� incorporar as fun��es e m�todos configurados na biblioteca [TADPilhaDinamica.h].
	
	OBS: A TAD Pilha Din�mica respeita o lema LIFO (Last In First Out) onde o �ltimo a Entrar � o Primeiro a Sair!
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#include "..\Biblioteca\TADPilhaDinamica.h"

int main ()
{
	int op, item;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=115 lines=55");
	
	inicializaPilhaDinamica (true);
	
	do
	{
		system ("cls");
		printf ("\t\t\t----------------------------------------------------\n");
		printf ("\t\t\t|        Menu de opera��es da TAD Pilha Din�mica   |\n");
		printf ("\t\t\t----------------------------------------------------\n");
		printf ("\t\t\t| Op��o |         A��o correspondente              |\n");
		printf ("\t\t\t----------------------------------------------------\n");
		printf ("\t\t\t|   1   |     Empilhar um elemento nesta Pilha     |\n");
		printf ("\t\t\t|   2   |    Desempilhar um elemento desta Pilha   |\n");
		printf ("\t\t\t|   3   |      Pesquisar um Valor nesta Pilha      |\n");
		printf ("\t\t\t|   4   |      Exibir dados da Pilha Din�mica      |\n");
		printf ("\t\t\t|   5   | Restaurar a Pilha aos padr�es de f�brica |\n");
		printf ("\t\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha uma op��o com base na a��o correspondente a ser executada na Pilha Din�mica (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa est� sendo encerrado...");
				break;
			case 1:
				printf ("\n\nInforme o Valor que deseja Empilhar na Pilha Din�mica: ");
				scanf ("%d", &item);
				empilhaItem (item);
				break;
			case 2:
				desempilhaItem ();
				break;
			case 3:
				printf ("\n\nInforme o Valor que deseja pesquisar na Pilha Din�mica: ");
				scanf ("%d", &item);
				pesquisaItem (item);
				break;
			case 4:
				printf ("\n\nExibindo o conte�do da TAD Pilha Din�mica...");
				exibirPilhaDinamica ();
				break;
			case 5:
				printf ("\n\nA TAD Pilha Din�mica foi RESETADA com sucesso!");
				inicializaPilhaDinamica (false);
				break;
			default:
				printf ("\n\nA op��o digitada � INV�LIDA! Tente novamente!");
				break;
		}
		getch ();
		
	}while (op != 0);
}
