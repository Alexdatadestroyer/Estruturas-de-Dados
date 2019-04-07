/*	Algoritmo para a cria��o de uma Lista Est�tica, uma Estrutura TAD (Tipo Abstrato de Dado) com algumas opera��es
	poss�veis para execu��o, devendo obedecer os seguintes itens:
	
	a) Para todo item RETIRADO ou INSERIDO no meio, deve-se fazer os itens moverem para a ESQUERDA ou DIREITA
	   como forma de NUNCA deixar espa�o vazio na Lista.
	
	b) Toda vez em que for inicializada, a vari�vel que representa o Tamanho dever� ser resetada.
	   Podendo isto tamb�m ocorrer caso o usu�rio solicite no Menu exibido na Fun��o Principal.
	   
	   Na TAD Lista, assume-se o Valor de Reset como 0.
	  
	c) Geralmente, um Menu costuma ser implementado nesses casos como forma de fazer a Lista
	   funcionar como se deve e uma constante como forma de definir o Tamanho M�ximo da mesma.
	
	d) Fun��es booleanas e Procedimentos geralmente tamb�m s�o utilizados nessa TAD. Outra coisa
	   que tamb�m ser� usada ser� o Conceito de Refer�ncia (&) para forma de altera��o da Lista
	   diretamente na Mem�ria, caso seja necess�rio. 
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 10

//------------------ Estrutura da TAD Lista ------------------- //
struct Lista
{
	int item[MAX], tamanho;
};
//------------------------------------------------------------- //

//----------- Fun��o de verifica��o de Lista CHEIA ------------ //
bool cheia_lista (struct Lista L)
{
	if (L.tamanho == MAX)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- Fun��o de verifica��o de Lista VAZIA ------------ //
bool vazia_lista (struct Lista L)
{
	if (L.tamanho == 0)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- M�todo de inserir valor no FINAL ---------------- //
void inserir_final (struct Lista &L, int x)
{
	if (cheia_lista (L))
	{
		printf ("\n\nA Lista est� cheia! Imposs�vel inserir o valor no final!");
	}	
	else
	{
		L.item[L.tamanho] = x;
		L.tamanho++;
		printf ("\n\nO valor %d foi inserido no final da Lista com sucesso!", x);
	}
}
//------------------------------------------------------------- //

//-------- M�todo de inserir valor na posi��o informada ------- //
void inserir_posicao (struct Lista &L, int x, int p)
{
	int i;
	
	if (cheia_lista (L))
	{
		printf ("\n\nA Lista est� cheia! Imposs�vel inserir o valor da posi��o informada!");
	}
	else if ((p > L.tamanho) || (p < 0))
	{
		printf ("\n\nA posi��o informada � inv�lida! Imposs�vel inserir o valor da posi��o informada!");
	}
	else
	{
		for (i = L.tamanho; i > p; i--)
		{
			L.item[i] = L.item[i-1];
		}
		L.item[p] = x;
		L.tamanho++;
		printf ("\n\nO valor %d foi inserido na posi��o %d da Lista com sucesso!", x, p);
	}
}
//------------------------------------------------------------- //

//----------- M�todo de remover valor no FINAL ---------------- //
void remover_final (struct Lista &L)
{
	if (vazia_lista (L))
	{
		printf ("\n\nA Lista est� vazia! Imposs�vel remover o valor no final!");
	}
	else
	{
		L.tamanho--;
		printf ("\n\nO �ltimo item que � o %d da Lista foi removido com sucesso!", L.item[L.tamanho]);
	}	
}
//------------------------------------------------------------- //

//-------- M�todo de remover valor na posi��o informada ------- //
void remover_posicao (struct Lista &L, int p)
{
	int i;
	
	if (vazia_lista (L))
	{
		printf ("\n\nA Lista est� vazia! Imposs�vel remover o valor da posi��o informada!");
	}
	else if ((p >= L.tamanho) || (p < 0))
	{
		printf ("\n\nA posi��o informada � inv�lida! Imposs�vel remover o valor da posi��o informada!");
	}
	else
	{
		printf ("\n\nO item %d da Lista foi removido com sucesso!", L.item[p]);
		for (i = p; i < L.tamanho - 1; i++)
		{
			L.item[i] = L.item[i+1];
		}
		L.tamanho--;
	}
}
//------------------------------------------------------------- //

//----------- M�todo de exibir o conte�do da Lista ------------ //
void exibe_lista (struct Lista L)
{
	int i;
	
	if (vazia_lista (L))
	{
		printf ("\n\nA Lista est� vazia! Imposs�vel exibir o conte�do da Lista!");
	}	
	else
	{
		printf ("\n\nExibindo a Lista completa... \n");
		for (i = 0; i < L.tamanho; i++)
		{
			printf ("\nLista [%d] = %d", i, L.item[i]);
		}
	}
}
//------------------------------------------------------------- //

//----------- M�todo de inicializar o tamanho da Lista -------- //
void inicializa_lista (struct Lista &L)
{
	L.tamanho = 0;
}
//------------------------------------------------------------- //

//------------------- FUN��O PRINCIPAL ------------------------ //
int main ()
{
	struct Lista L;
	int op, val, ind;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=100 lines=40");
	
	inicializa_lista (L);
	
	do
	{
		system ("cls");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|            Menu de opera��es da Lista            |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Op��o |         A��o correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   | Inserir valor no final da Lista          |\n");
		printf ("\t\t|   2   | Inserir valor numa posi��o da Lista      |\n");
		printf ("\t\t|   3   | Remover o �ltimo valor da Lista          |\n");
		printf ("\t\t|   4   | Remover valor numa posi��o da Lista      |\n");
		printf ("\t\t|   5   | Exibir a Lista inteira por completo      |\n");
		printf ("\t\t|   6   | Restaurar a Lista aos padr�es de f�brica |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha a a��o a ser executada na Lista com base nas informa��es acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa est� sendo encerrado!");
				break;
				
			case 1:
				printf ("\n\nInforme um valor a ser inserido na Lista: ");
				scanf ("%d", &val);
				
				inserir_final (L, val);
				break;
			
			case 2:
				printf ("\n\nInforme um valor a ser inserido na Lista: ");
				scanf ("%d", &val);
				printf ("\n\nInforme a posi��o da Lista pra inserir o valor informado: ");
				scanf ("%d", &ind);
				
				inserir_posicao (L, val, ind);
				break;
			
			case 3:
				remover_final (L);
				break;
			
			case 4:
				printf ("\n\nInforme a posi��o da Lista pra remover o valor residente: ");
				scanf ("%d", &ind);
				
				remover_posicao (L, ind);
				break;
			
			case 5:
				exibe_lista (L);
				break;
			
			case 6:
				printf ("\n\nA Lista foi resetada com sucesso!");
				
				inicializa_lista (L);
				break;
			
			default:
				printf ("\n\nOp��o inv�lida! Tente novamente!");
				break;	
		}
		getch ();
	}while (op != 0);
}
//------------------------------------------------------------- //
