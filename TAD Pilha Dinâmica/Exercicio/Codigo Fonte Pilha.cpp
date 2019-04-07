/*	Algoritmo para implementação da TAD Pilha Dinâmica por meio de utilização de Ponteiros.

	Autor: Alexandre Gadelha da Silva Carvalho.

	O algoritmo irá incorporar as funções e métodos configurados na biblioteca [TADPilhaDinamica.h].
	
	OBS: A TAD Pilha Dinâmica respeita o lema LIFO (Last In First Out) onde o Último a Entrar é o Primeiro a Sair!
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
		printf ("\t\t\t|        Menu de operações da TAD Pilha Dinâmica   |\n");
		printf ("\t\t\t----------------------------------------------------\n");
		printf ("\t\t\t| Opção |         Ação correspondente              |\n");
		printf ("\t\t\t----------------------------------------------------\n");
		printf ("\t\t\t|   1   |     Empilhar um elemento nesta Pilha     |\n");
		printf ("\t\t\t|   2   |    Desempilhar um elemento desta Pilha   |\n");
		printf ("\t\t\t|   3   |      Pesquisar um Valor nesta Pilha      |\n");
		printf ("\t\t\t|   4   |      Exibir dados da Pilha Dinâmica      |\n");
		printf ("\t\t\t|   5   | Restaurar a Pilha aos padrões de fábrica |\n");
		printf ("\t\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha uma opção com base na ação correspondente a ser executada na Pilha Dinâmica (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa está sendo encerrado...");
				break;
			case 1:
				printf ("\n\nInforme o Valor que deseja Empilhar na Pilha Dinâmica: ");
				scanf ("%d", &item);
				empilhaItem (item);
				break;
			case 2:
				desempilhaItem ();
				break;
			case 3:
				printf ("\n\nInforme o Valor que deseja pesquisar na Pilha Dinâmica: ");
				scanf ("%d", &item);
				pesquisaItem (item);
				break;
			case 4:
				printf ("\n\nExibindo o conteúdo da TAD Pilha Dinâmica...");
				exibirPilhaDinamica ();
				break;
			case 5:
				printf ("\n\nA TAD Pilha Dinâmica foi RESETADA com sucesso!");
				inicializaPilhaDinamica (false);
				break;
			default:
				printf ("\n\nA opção digitada é INVÁLIDA! Tente novamente!");
				break;
		}
		getch ();
		
	}while (op != 0);
}
