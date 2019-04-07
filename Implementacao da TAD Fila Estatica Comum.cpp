/*	Algoritmo para a implementa��o da TAD Fila Est�tica Comum que possui algumas regras a seguir:

	a) A Fila Est�tica segue o esquema FIFO (First In First Out [O Primeiro que entra � o Primeiro que sai]),
	   sendo assim, a remo��o ocorrer� a partir do primeiro valor que for acrescentado (Frente) e a inser��o
	   do valor ocorrer� na �ltima posi��o da Fila (Tr�s).
	   
	b) Ser�o utilizadas 2 vari�veis de controle: FRENTE e TR�S onde:
	
		-> FRENTE ser� incrementado todas as vezes em que ALGU�M FOR ATENDIDO, ou seja, quando um item for retirado
	       da Fila (Desenfileirar).
	
		-> TR�S ser� incrementado todas as vezes em que ALGU�M ENTRAR, ou seja, quando um item for inserido na Fila
		   (Enfileirar).
	 
	c) A Fila Est�tica tamb�m possui reset de vari�veis como a Lista e Pilha ao inicializar. Na Fila:
	
		-> A vari�vel de FRENTE ir� come�ar com o valor 0.
		-> A vari�vel de TR�S ir� come�ar com o valor -1.
	
	d) Fun��es booleanas e Procedimentos geralmente tamb�m s�o utilizados nessa TAD. Outra coisa que tamb�m ser� usada
	   ser� o Conceito de Refer�ncia (&) para forma de altera��o da Fila diretamente na Mem�ria, caso seja necess�rio.
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 15

struct FilaComum
{
	int elementos[MAX], frente, tras;
};

bool vaziaFila (struct FilaComum F)
{
	if (F.tras == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cheiaFila (struct FilaComum F)
{
	if (F.tras == MAX-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pesquisaFila (struct FilaComum F, int val)
{
	int i;
	bool item = false;
	
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Comum est� VAZIA! Imposs�vel de realizar a pesquisa de valores!");
	}
	else
	{
		printf ("\n\n");
		
		for (i = F.frente; i <= F.tras; i++)
		{
			if (F.elementos[i] == val)
			{
				printf ("O elemento informado %d foi encontrado na posi��o %d da Fila Comum! \n", val, i);
				item = true;
			}
		}
		
		if (!item)
		{
			printf ("N�O foram encontrados elementos na Fila Comum com o valor %d informado!", val);
		}
	}
}

void desenfileirar (struct FilaComum &F)
{
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Comum est� VAZIA! Imposs�vel remover itens da Fila!");
	}
	else
	{
		printf ("\n\nO valor %d foi removido com sucesso da Fila Comum!", F.elementos[F.frente]);
		F.frente++;
	}
}

void enfileirar (struct FilaComum &F, int val)
{
	if (cheiaFila (F))
	{
		printf ("\n\nA Fila Comum est� CHEIA! Imposs�vel inserir mais itens na Fila!");
	}
	else
	{
		printf ("\n\nO valor %d foi inserido na Fila Comum com sucesso!", val);
		F.tras++;
		F.elementos[F.tras] = val;
	}
}

void exibirFila (struct FilaComum F)
{
	int i;
	
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Comum est� VAZIA! Imposs�vel exibir seu conte�do!");
	}
	else
	{
		printf ("\n\nExibindo o conte�do da Fila Comum... \n\n");
		for (i = F.frente; i <= F.tras; i++)
		{
			printf ("Fila Comum [%d] = %d \n", i, F.elementos[i]);
		}		
		printf ("\nFRENTE: %d", F.frente);
		printf ("\nTR�S: %d", F.tras);
	}
}

void inicializaFila (struct FilaComum &F)
{
	F.frente = 0;
	F.tras = -1;
}

int main ()
{
	struct FilaComum F;
	int op, val, pos;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=100 lines=50");
	
	inicializaFila (F);
	
	do
	{
		system ("cls");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|          Menu de opera��es da Fila Comum         |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Op��o |         A��o correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |      Enfileirar um valor na Fila Comum   |\n");
		printf ("\t\t|   2   |    Desenfileirar um valor na Fila Comum  |\n");
		printf ("\t\t|   3   |       Pesquisar itens na Fila Comum      |\n");
		printf ("\t\t|   4   |        Exibir dados da Fila Comum        |\n");
		printf ("\t\t|   5   | Restaurar a Fila aos padr�es de f�brica  |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha a a��o a ser executada na Fila com base nas informa��es acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa est� sendo encerrado...");
				break;
			case 1:
				printf ("\n\nInforme um valor a ser enfileirado na Fila Comum: ");
				scanf ("%d", &val);
				enfileirar (F, val);
				break;
			case 2:
				desenfileirar (F);
				break;
			case 3:
				printf ("\n\nInforme um valor que deseja que este seja pesquisado na Fila Comum: ");
				scanf ("%d", &val);
				pesquisaFila (F, val);
				break;
			case 4:
				exibirFila (F);
				break;
			case 5:
				printf ("\n\nA Fila Comum foi resetada com sucesso!");
				inicializaFila (F);
				break;
			default:
				printf ("\n\nOp��o informada � INV�LIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
