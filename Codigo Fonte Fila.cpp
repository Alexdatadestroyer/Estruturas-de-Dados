/*	Algoritmo para implementação da TAD Fila Dinâmica por meio de utilização de Ponteiros.

	Autor: Alexandre Gadelha da Silva Carvalho.

	O algoritmo irá incorporar as funções e métodos configurados na biblioteca [TADFilaDinamica.h].
	
	OBS 1: A TAD Fila Dinâmica respeita o lema FIFO (First In First Out) onde o Primeiro a Entrar é o
		   Primeiro a Sair!
	
	OBS 2: No caso de uma Fila Dinâmica, não teremos a diferenciação entre Fila Circular e Fila Comum, pois
		   isso só é aplicado no caso de Fila Estática.
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
		printf ("\t\t\t|      Menu de operações da TAD Fila Dinâmica     |\n");
		printf ("\t\t\t---------------------------------------------------\n");
		printf ("\t\t\t| Opção |         Ação correspondente             |\n");
		printf ("\t\t\t---------------------------------------------------\n");
		printf ("\t\t\t|   1   |     Enfileirar um elemento na Fila      |\n");
		printf ("\t\t\t|   2   |     Desenfileirar um elemento na Fila   |\n");
		printf ("\t\t\t|   3   |      Pesquisar um Valor nesta Fila      |\n");
		printf ("\t\t\t|   4   |      Exibir dados da Fila Dinâmica      |\n");
		printf ("\t\t\t|   5   | Restaurar a Fila aos padrões de fábrica |\n");
		printf ("\t\t\t---------------------------------------------------\n");
		
		printf ("\n\nEscolha uma operação a ser realizada na Fila Dinâmica de acordo com o Menu acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa está sendo ENCERRADO...");
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
				printf ("\n\nA TAD Fila Dinâmica foi RESETADA com sucesso!");
				inicializaFila (false);
				break;
			default:
				printf ("\n\nA opção digitada é INVÁLIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
