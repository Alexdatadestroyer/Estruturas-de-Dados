/*	Algoritmo para implementa��o da TAD Fila Din�mica por meio de utiliza��o de Ponteiros.

	Autor: Alexandre Gadelha da Silva Carvalho.

	O algoritmo ir� incorporar as fun��es e m�todos configurados na biblioteca [TADFilaDinamica.h].
	
	OBS 1: A TAD Fila Din�mica respeita o lema FIFO (First In First Out) onde o Primeiro a Entrar � o
		   Primeiro a Sair!
	
	OBS 2: No caso de uma Fila Din�mica, n�o teremos a diferencia��o entre Fila Circular e Fila Comum, pois
		   isso s� � aplicado no caso de Fila Est�tica.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

#include "..\Biblioteca\TADFilaDinamica.h"

int main ()
{
	int op, item;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=115 lines=55");
	
	inicializaFila (true);
	
	do
	{
		system ("cls");
		printf ("\t\t\t---------------------------------------------------\n");
		printf ("\t\t\t|      Menu de opera��es da TAD Fila Din�mica     |\n");
		printf ("\t\t\t---------------------------------------------------\n");
		printf ("\t\t\t| Op��o |         A��o correspondente             |\n");
		printf ("\t\t\t---------------------------------------------------\n");
		printf ("\t\t\t|   1   |     Enfileirar um elemento na Fila      |\n");
		printf ("\t\t\t|   2   |     Desenfileirar um elemento na Fila   |\n");
		printf ("\t\t\t|   3   |      Pesquisar um Valor nesta Fila      |\n");
		printf ("\t\t\t|   4   |      Exibir dados da Fila Din�mica      |\n");
		printf ("\t\t\t|   5   | Restaurar a Fila aos padr�es de f�brica |\n");
		printf ("\t\t\t---------------------------------------------------\n");
		
		printf ("\n\nEscolha uma opera��o a ser realizada na Fila Din�mica de acordo com o Menu acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa est� sendo ENCERRADO...");
				break;
			case 1:
				printf ("\n\nInforme o Valor que deseja Enfileirar na Fila: ");
				scanf ("%d", &item);
				enfileiraItem (item);
				break;
			case 2:
				desenfileiraItem ();
				break;
			case 3:
				printf ("\n\nInforme o Valor que deseja Pesquisar na Fila: ");
				scanf ("%d", &item);
				pesquisaItem (item);
				break;
			case 4:
				exibirConteudoFila ();
				break;
			case 5:
				printf ("\n\nA TAD Fila Din�mica foi RESETADA com sucesso!");
				inicializaFila (false);
				break;
			default:
				printf ("\n\nA op��o digitada � INV�LIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
