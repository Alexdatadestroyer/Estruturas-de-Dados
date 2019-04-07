/*	Algoritmo para a implementação da TAD Fila Estática Circular que possui algumas regras a seguir:

	a) A Fila Estática segue o esquema FIFO (First In First Out [O Primeiro que entra é o Primeiro que sai]),
	   sendo assim, a remoção ocorrerá a partir do primeiro valor que for acrescentado (Frente) e a inserção
	   do valor ocorrerá na última posição da Fila (Trás).
	   
	b) Serão utilizadas 3 variáveis de controle: FRENTE, TRÁS e TAMANHO onde:
	
		-> FRENTE será incrementado todas as vezes em que ALGUÉM FOR ATENDIDO, ou seja, quando um item for retirado
	       da Fila (Desenfileirar).
	
		-> TRÁS será incrementado todas as vezes em que ALGUÉM ENTRAR, ou seja, quando um item for inserido na Fila
		   (Enfileirar).
	
 		-> TAMANHO será incrementada todas as vezes em que houver inserção de valor (Enfileirar) e será decrementada
		   todas as vezes em que houver remoção de valor (Desenfileirar).
	 
	c) A Fila Estática também possui reset de variáveis como a Lista e Pilha ao inicializar. Na Fila:
	
		-> A variável de FRENTE irá começar com o valor 0.
		-> A variável de TRÁS irá começar com o valor -1.
		-> A variável de TAMANHO irá começar com o valor 0.
	
	d) Funções booleanas e Procedimentos geralmente também são utilizados nessa TAD. Outra coisa que também será usada
	   será o Conceito de Referência (&) para forma de alteração da Fila diretamente na Memória, caso seja necessário.
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
		printf ("\n\nA Fila Circular está VAZIA! Impossível de realizar a pesquisa de valores!");
	}
	else
	{
		printf ("\n\n");
		
		if (F.tras < F.frente) 	   	// Apenas quando o TAMANHO chega ao MAX. TRÁS passa a ser MENOR do que FRENTE.
		{
			for (i = 0; i <= F.tras; i++)
			{
				if (F.elementos[i] == val)
				{
					printf ("O elemento informado %d foi encontrado na posição %d da Fila Circular! \n", val, i);
					item = true;
				}
			}
			
			for (i = F.frente; i < MAX; i++)
			{
				if (F.elementos[i] == val)
				{
					printf ("O elemento informado %d foi encontrado na posição %d da Fila Circular! \n", val, i);
					item = true;
				}
			}
		}						
		else				// Operacional apenas no comportamento de Fila Estática Comum (TRÁS maior que FRENTE).
		{
			for (i = F.frente; i <= F.tras; i++)
			{
				if (F.elementos[i] == val)
				{
					printf ("O elemento informado %d foi encontrado na posição %d da Fila Circular! \n", val, i);
					item = true;
				}
			}
		}
		
		if (!item)
		{
			printf ("NÃO foram encontrados elementos na Fila Circular com o valor %d informado!", val);
		}
	}
}

void desenfileirar (struct FilaCircular &F)
{
	if (vaziaFila (F))
	{
		printf ("\n\nA Fila Circular está VAZIA! Impossível remover itens da Fila!");
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
		printf ("\n\nA Fila Circular está CHEIA! Impossível inserir mais itens na Fila!");
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
		printf ("\n\nA Fila Circular está VAZIA! Impossível exibir seu conteúdo!");
	}
	else
	{
		printf ("\n\nExibindo o conteúdo da Fila Circular... \n\n");
		
		if (F.tras < F.frente)     	// Apenas quando o TAMANHO chega ao MAX. TRÁS passa a ser MENOR do que FRENTE.
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
		else				// Operacional apenas no comportamento de Fila Estática Comum (TRÁS maior que FRENTE).
		{
			for (i = F.frente; i <= F.tras; i++)
			{
				printf ("Fila Circular [%d] = %d \n", i, F.elementos[i]);
			}
		}
		printf ("\nFRENTE: %d", F.frente);
		printf ("\nTRÁS: %d", F.tras);
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
		printf ("\t\t|        Menu de operações da Fila Circular        |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Opção |         Ação correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |   Enfileirar um valor na Fila Circular   |\n");
		printf ("\t\t|   2   | Desenfileirar um valor na Fila Circular  |\n");
		printf ("\t\t|   3   |     Pesquisar itens na Fila Circular     |\n");
		printf ("\t\t|   4   |       Exibir dados da Fila Circular      |\n");
		printf ("\t\t|   5   | Restaurar a Fila aos padrões de fábrica  |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha a ação a ser executada na Fila com base nas informações acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa está sendo encerrado...");
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
				printf ("\n\nOpção informada é INVÁLIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
