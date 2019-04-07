/*	Algoritmo para a implementa��o da TAD Fila Est�tica Circular que possui algumas regras a seguir:

	a) A Fila Est�tica segue o esquema FIFO (First In First Out [O Primeiro que entra � o Primeiro que sai]),
	   sendo assim, a remo��o ocorrer� a partir do primeiro valor que for acrescentado (Frente) e a inser��o
	   do valor ocorrer� na �ltima posi��o da Fila (Tr�s).
	   
	b) Ser�o utilizadas 3 vari�veis de controle: FRENTE, TR�S e TAMANHO onde:
	
		-> FRENTE ser� incrementado todas as vezes em que ALGU�M FOR ATENDIDO, ou seja, quando um item for retirado
	       da Fila (Desenfileirar).
	
		-> TR�S ser� incrementado todas as vezes em que ALGU�M ENTRAR, ou seja, quando um item for inserido na Fila
		   (Enfileirar).
	
 		-> TAMANHO ser� incrementada todas as vezes em que houver inser��o de valor (Enfileirar) e ser� decrementada
		   todas as vezes em que houver remo��o de valor (Desenfileirar).
	 
	c) A Fila Est�tica tamb�m possui reset de vari�veis como a Lista e Pilha ao inicializar. Na Fila:
	
		-> A vari�vel de FRENTE ir� come�ar com o valor 0.
		-> A vari�vel de TR�S ir� come�ar com o valor -1.
		-> A vari�vel de TAMANHO ir� come�ar com o valor 0.
	
	d) Fun��es booleanas e Procedimentos geralmente tamb�m s�o utilizados nessa TAD. Outra coisa que tamb�m ser� usada
	   ser� o Conceito de Refer�ncia (&) para forma de altera��o da Fila diretamente na Mem�ria, caso seja necess�rio.
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 15

struct FilaCircular
{
	int elementos[MAX], frente, tras, tamanho;
};

bool vaziaFila (struct FilaCircular F)
{
	if (F.tamanho == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cheiaFila (struct FilaCircular F)
{
	if ((F.tamanho == MAX) || (F.frente - F.tras == 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pesquisaFila (struct FilaCircular F, int val)
{
	int i;
	bool item = false;
	
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Circular est� VAZIA! Imposs�vel de realizar a pesquisa de valores!");
	}
	else
	{
		printf ("\n\n");
		
		if (F.tras < F.frente) 	   	// Apenas quando o TAMANHO chega ao MAX. TR�S passa a ser MENOR do que FRENTE.
		{
			for (i = 0; i <= F.tras; i++)
			{
				if (F.elementos[i] == val)
				{
					printf ("O elemento informado %d foi encontrado na posi��o %d da Fila Circular! \n", val, i);
					item = true;
				}
			}
			
			for (i = F.frente; i < MAX; i++)
			{
				if (F.elementos[i] == val)
				{
					printf ("O elemento informado %d foi encontrado na posi��o %d da Fila Circular! \n", val, i);
					item = true;
				}
			}
		}						
		else				// Operacional apenas no comportamento de Fila Est�tica Comum (TR�S maior que FRENTE).
		{
			for (i = F.frente; i <= F.tras; i++)
			{
				if (F.elementos[i] == val)
				{
					printf ("O elemento informado %d foi encontrado na posi��o %d da Fila Circular! \n", val, i);
					item = true;
				}
			}
		}
		
		if (!item)
		{
			printf ("N�O foram encontrados elementos na Fila Circular com o valor %d informado!", val);
		}
	}
}

void desenfileirar (struct FilaCircular &F)
{
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Circular est� VAZIA! Imposs�vel remover itens da Fila!");
	}
	else
	{
		printf ("\n\nO valor %d foi removido com sucesso da Fila Circular!", F.elementos[F.frente]);
		
		F.frente++;
		
		if (F.frente == MAX)
		{
			F.frente = 0;	
		}
		
		F.tamanho--;
	}
}

void enfileirar (struct FilaCircular &F, int val)
{
	if (cheiaFila (F))
	{
		printf ("\n\nA Fila Circular est� CHEIA! Imposs�vel inserir mais itens na Fila!");
	}
	else
	{
		printf ("\n\nO valor %d foi inserido na Fila Circular com sucesso!", val);
		
		F.tras++;
		
		if (F.tras == MAX)
		{
			F.tras = 0;
		}
		
		F.elementos[F.tras] = val;
		F.tamanho++;
	}
}

void exibirFila (struct FilaCircular F)
{
	int i;
	
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Circular est� VAZIA! Imposs�vel exibir seu conte�do!");
	}
	else
	{
		printf ("\n\nExibindo o conte�do da Fila Circular... \n\n");
		
		if (F.tras < F.frente)     	// Apenas quando o TAMANHO chega ao MAX. TR�S passa a ser MENOR do que FRENTE.
		{
			for (i = 0; i <= F.tras; i++)
			{
				printf ("Fila Circular [%d] = %d \n", i, F.elementos[i]);
			}
			
			for (i = F.frente; i < MAX; i++)
			{
				printf ("Fila Circular [%d] = %d \n", i, F.elementos[i]);
			}
		}
		else				// Operacional apenas no comportamento de Fila Est�tica Comum (TR�S maior que FRENTE).
		{
			for (i = F.frente; i <= F.tras; i++)
			{
				printf ("Fila Circular [%d] = %d \n", i, F.elementos[i]);
			}
		}
		printf ("\nFRENTE: %d", F.frente);
		printf ("\nTR�S: %d", F.tras);
		printf ("\nTAMANHO: %d", F.tamanho);
	}
}

void inicializaFila (struct FilaCircular &F)
{
	F.frente = 0;
	F.tras = -1;
	F.tamanho = 0;
}

int main ()
{
	struct FilaCircular F;
	int op, val, pos;
	
	setlocale (LC_ALL, "English");
	system ("mode con cols=100 lines=50");
	
	inicializaFila (F);
	
	do
	{
		system ("cls");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|        Menu de opera��es da Fila Circular        |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Op��o |         A��o correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |   Enfileirar um valor na Fila Circular   |\n");
		printf ("\t\t|   2   | Desenfileirar um valor na Fila Circular  |\n");
		printf ("\t\t|   3   |     Pesquisar itens na Fila Circular     |\n");
		printf ("\t\t|   4   |       Exibir dados da Fila Circular      |\n");
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
				printf ("\n\nInforme um valor a ser enfileirado na Fila Circular: ");
				scanf ("%d", &val);
				enfileirar (F, val);
				break;
			case 2:
				desenfileirar (F);
				break;
			case 3:
				printf ("\n\nInforme um valor que deseja que este seja pesquisado na Fila Circular: ");
				scanf ("%d", &val);
				pesquisaFila (F, val);
				break;
			case 4:
				exibirFila (F);
				break;
			case 5:
				printf ("\n\nA Fila Circular foi resetada com sucesso!");
				inicializaFila (F);
				break;
			default:
				printf ("\n\nOp��o informada � INV�LIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
