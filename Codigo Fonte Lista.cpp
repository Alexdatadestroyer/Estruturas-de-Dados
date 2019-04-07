/*	Algoritmo para a implementa��o da TAD Lista Din�mica que ser� arquiteturada e guiada por Ponteiros.
	
	O algoritmo ir� herdar as fun��es da TAD Lista Din�mica que j� est�o armazenadas anteriormente em uma
	biblioteca chamada [TADListaDinamica.h].
	
	Al�m disso, a Lista Din�mica � composta de 2 elementos: O ELEMENTO e o PONTEIRO apontando para a pr�xima
	Estrutura que ser� criada sob encomenda via comando MALLOC.
	
	Agora, temos o surgimento de 2 comandos novos:
	
	--> Sintaxe de MALLOC: "ponteiro = (casting *) malloc (tamanho do bloco de mem�ria a ser criado pertencente ao tipo)"
	
		No caso do "casting", � necess�rio especificar qual o Tipo Primitivo de Dado pertencente ao Ponteiro criado ou qual
		a Estrutura a que ele pertence. Como se trata de Ponteiros, a especifica��o dever� ser seguida de "*".
		
		Em rela��o ao tamanho do bloco de mem�ria a ser criado, como o tamanho dos Tipos Primitivos de Dados e/ou de uma Estrutura
		podem variar bastante, de c�digo pra c�digo e de computador pra computador, se tem a necessidade de um comando que trate
		isso da forma mais din�mica poss�vel via comando SIZEOF.
		
		L�-SE: "Atribuindo uma quantidade X de bytes do tipo Y ao Ponteiro Z."
		
		Exemplo: 'Z = (int *) malloc (sizeof (int))'. 
	
	--> Sintaxe de FREE: "free (ponteiro)"
	
		Trata-se de livrar o espa�o de mem�ria criado anteriormente para n�o deixar "lixo" espalhados no algoritmo de maneira geral.
		
		Ao executar o comando, recomenda-se que um N�mero Inteiro Nulo (NULL ou 0) seja atribu�do ao ponteiro residente.
		
		Exemplo: 'free (ponteiro)'.
				 'ponteiro = NULL (ou 0)'.
	
	Os comandos MALLOC e FREE, pertencem � biblioteca <stdlib.h> que dever� ser utilizada neste algoritmo.
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#include "..\Biblioteca\TADListaDinamica.h"

int main ()
{
	int item, op;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=115 lines=50");
	
	inicializaListaDinamica (0);			// Valor 0: Opera��o de INICIALIZA��O da Lista Din�mica.
	
	do
	{	
		system ("cls");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|        Menu de opera��es da TAD Lista Din�mica   |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Op��o |         A��o correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |      Inserir um elemento nesta Lista     |\n");
		printf ("\t\t|   2   |      Remover um elemento desta Lista     |\n");
		printf ("\t\t|   3   |      Pesquisar um Valor nesta Lista      |\n");
		printf ("\t\t|   4   |      Exibir dados da Lista Din�mica      |\n");
		printf ("\t\t|   5   | Restaurar a Lista aos padr�es de f�brica |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha uma op��o com base na a��o correspondente a ser executada na Lista Din�mica (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa est� sendo encerrado...");
				break;
			case 1:
				printf ("\n\nInforme o Valor que deseja inserir na Lista: ");
				scanf ("%d", &item);
				inserirElemento (item);
				break;
			case 2:
				printf ("\n\nInforme o Valor que deseja procurar na Lista e remov�-lo: ");
				scanf ("%d", &item);
				removerElemento (item);
				break;
			case 3:
				printf ("\n\nInforme o Valor que deseja pesquisar na Lista: ");
				scanf ("%d", &item);
				pesquisaElemento (item);
				break;
			case 4:
				exibirListaDinamica ();
				break;
			case 5:
				printf ("\n\nA TAD Lista Din�mica foi resetada com sucesso!");
				
				inicializaListaDinamica (1);				// Valor 1: Opera��o de RESET da Lista Din�mica.
				
				break;
			default:
				printf ("\n\nA op��o digitada � INV�LIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
