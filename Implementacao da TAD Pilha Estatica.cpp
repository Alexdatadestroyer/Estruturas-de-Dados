/*	Algoritmo para a cria��o de uma Pilha Est�tica, uma Estrutura TAD (Tipo Abstrato de Dado) com algumas opera��es
	poss�veis para execu��o, devendo obedecer os seguintes itens:
	
	a) A TAD Pilha funciona no esquema LIFO (Last In First Out [O �ltimo que entra � o primeiro que sai]),
	   sendo assim, todo item removido dever� estar na �ltima posi��o desta Pilha e todo item acrescentado ir�
	   para a �ltima posi��o desta Pilha. 
	
	b) Toda vez em que for inicializada, a vari�vel que representa o Topo da Pilha dever� ser resetada.
	   Podendo isto tamb�m ocorrer caso o usu�rio solicite no Menu exibido na Fun��o Principal.
	   
	   Na TAD Pilha, assume-se o Valor de Reset como -1.
	  
	c) Geralmente, um Menu costuma ser implementado nesses casos como forma de fazer a Pilha
	   funcionar como se deve e uma constante como forma de definir o topo M�ximo da mesma.
	
	d) Fun��es booleanas e Procedimentos geralmente tamb�m s�o utilizados nessa TAD. Outra coisa
	   que tamb�m ser� usada ser� o Conceito de Refer�ncia (&) para forma de altera��o da Pilha
	   diretamente na Mem�ria, caso seja necess�rio.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 10

//------------------ Estrutura da TAD Pilha ------------------- //
struct Pilha
{
	int item[MAX], topo;
};
//------------------------------------------------------------- //

//----------- Fun��o de verifica��o de Pilha CHEIA ------------ //
bool cheia_Pilha (struct Pilha P)
{
	if (P.topo == MAX-1)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- Fun��o de verifica��o de Pilha VAZIA ------------ //
bool vazia_Pilha (struct Pilha P)
{
	if (P.topo == -1)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- M�todo de inserir valor no FINAL ---------------- //
void empilha (struct Pilha &P, int x)
{
	if (cheia_Pilha (P))
	{
		printf ("\n\nA Pilha est� cheia! Imposs�vel inserir o valor!");
	}	
	else
	{
		P.topo++;
		P.item[P.topo] = x;
		printf ("\n\nO valor %d foi inserido na Pilha com sucesso!", x);
	}
}
//------------------------------------------------------------- //

//----------- M�todo de remover valor no FINAL ---------------- //
void desempilha (struct Pilha &P)
{
	if (vazia_Pilha (P))
	{
		printf ("\n\nA Pilha est� vazia! Imposs�vel remover o valor!");
	}
	else
	{
		printf ("\n\nO �ltimo item que � o %d da Pilha foi removido com sucesso!", P.item[P.topo]);
		P.topo--;
	}	
}
//------------------------------------------------------------- //

//------- M�todo de pesquisa valores no conte�do da Pilha ----- //
void pesquisa_Pilha (struct Pilha P, int x)
{
	int i, cont;
	
	if (vazia_Pilha (P))
	{
		printf ("\n\nA Pilha est� vazia! Imposs�vel realizar a pesquisa de valores!");
	}
	else
	{
		printf ("\n\n");
		for (i = 0, cont = 0; i <= P.topo; i++)
		{
			if (P.item[i] == x)
			{
				printf ("O valor informado %d foi encontrado na posi��o %d da Pilha! \n", x, i);
				cont++;
			}
		}
		
		if (cont == 0)
		{
			printf ("N�O foram encontrados valores na Pilha iguais a %d", x);
		}
	}
}
//------------------------------------------------------------- //

//----------- M�todo de exibir o conte�do da Pilha ------------ //
void exibe_Pilha (struct Pilha P)
{
	int i;
	
	if (vazia_Pilha (P))
	{
		printf ("\n\nA Pilha est� vazia! Imposs�vel exibir o conte�do da Pilha!");
	}	
	else
	{
		printf ("\n\nExibindo a Pilha completa... \n");
		for (i = 0; i <= P.topo; i++)
		{
			printf ("\nPilha [%d] = %d", i, P.item[i]);
		}
	}
}
//------------------------------------------------------------- //

//----------- M�todo de inicializar o topo da Pilha -------- //
void inicializa_Pilha (struct Pilha &P)
{
	P.topo = -1;
}
//------------------------------------------------------------- //

//------------------- FUN��O PRINCIPAL ------------------------ //
int main ()
{
	struct Pilha P;
	int op, val, ind;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=100 lines=40");
	
	inicializa_Pilha (P);
	
	do
	{
		system ("cls");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|            Menu de opera��es da Pilha            |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Op��o |         A��o correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |        Inserir valor na Pilha            |\n");
		printf ("\t\t|   2   |       Remover um valor da Pilha          |\n");
		printf ("\t\t|   3   |       Pesquisar um item da Pilha         |\n");
		printf ("\t\t|   4   |   Exibir a Pilha inteira por completo    |\n");
		printf ("\t\t|   5   | Restaurar a Pilha aos padr�es de f�brica |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha a a��o a ser executada na Pilha com base nas informa��es acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa est� sendo encerrado!");
				break;
				
			case 1:
				printf ("\n\nInforme um valor a ser inserido na Pilha: ");
				scanf ("%d", &val);
				
				empilha (P, val);
				break;
			
			case 2:
				desempilha (P);
				break;
			
			case 3:
				printf ("\n\nInforme o valor que deseja pesquisar na Pilha: ");
				scanf ("%d", &val);
				
				pesquisa_Pilha (P, val);
				break;
			
			case 4:
				exibe_Pilha (P);
				break;
			
			case 5:
				printf ("\n\nA Pilha foi resetada com sucesso!");
				
				inicializa_Pilha (P);
				break;
			
			default:
				printf ("\n\nOp��o inv�lida! Tente novamente!");
				break;	
		}
		getch ();
	}while (op != 0);
}
//------------------------------------------------------------- //
