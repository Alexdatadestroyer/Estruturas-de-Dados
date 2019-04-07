/*	Algoritmo para a criação de uma Pilha Estática, uma Estrutura TAD (Tipo Abstrato de Dado) com algumas operações
	possíveis para execução, devendo obedecer os seguintes itens:
	
	a) A TAD Pilha funciona no esquema LIFO (Last In First Out [O último que entra é o primeiro que sai]),
	   sendo assim, todo item removido deverá estar na última posição desta Pilha e todo item acrescentado irá
	   para a última posição desta Pilha. 
	
	b) Toda vez em que for inicializada, a variável que representa o Topo da Pilha deverá ser resetada.
	   Podendo isto também ocorrer caso o usuário solicite no Menu exibido na Função Principal.
	   
	   Na TAD Pilha, assume-se o Valor de Reset como -1.
	  
	c) Geralmente, um Menu costuma ser implementado nesses casos como forma de fazer a Pilha
	   funcionar como se deve e uma constante como forma de definir o topo Máximo da mesma.
	
	d) Funções booleanas e Procedimentos geralmente também são utilizados nessa TAD. Outra coisa
	   que também será usada será o Conceito de Referência (&) para forma de alteração da Pilha
	   diretamente na Memória, caso seja necessário.
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

//----------- Função de verificação de Pilha CHEIA ------------ //
bool cheia_Pilha (struct Pilha P)
{
	if (P.topo == MAX-1)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- Função de verificação de Pilha VAZIA ------------ //
bool vazia_Pilha (struct Pilha P)
{
	if (P.topo == -1)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- Método de inserir valor no FINAL ---------------- //
void empilha (struct Pilha &P, int x)
{
	if (cheia_Pilha (P))
	{
		printf ("\n\nA Pilha está cheia! Impossível inserir o valor!");
	}	
	else
	{
		P.topo++;
		P.item[P.topo] = x;
		printf ("\n\nO valor %d foi inserido na Pilha com sucesso!", x);
	}
}
//------------------------------------------------------------- //

//----------- Método de remover valor no FINAL ---------------- //
void desempilha (struct Pilha &P)
{
	if (vazia_Pilha (P))
	{
		printf ("\n\nA Pilha está vazia! Impossível remover o valor!");
	}
	else
	{
		printf ("\n\nO último item que é o %d da Pilha foi removido com sucesso!", P.item[P.topo]);
		P.topo--;
	}	
}
//------------------------------------------------------------- //

//------- Método de pesquisa valores no conteúdo da Pilha ----- //
void pesquisa_Pilha (struct Pilha P, int x)
{
	int i, cont;
	
	if (vazia_Pilha (P))
	{
		printf ("\n\nA Pilha está vazia! Impossível realizar a pesquisa de valores!");
	}
	else
	{
		printf ("\n\n");
		for (i = 0, cont = 0; i <= P.topo; i++)
		{
			if (P.item[i] == x)
			{
				printf ("O valor informado %d foi encontrado na posição %d da Pilha! \n", x, i);
				cont++;
			}
		}
		
		if (cont == 0)
		{
			printf ("NÃO foram encontrados valores na Pilha iguais a %d", x);
		}
	}
}
//------------------------------------------------------------- //

//----------- Método de exibir o conteúdo da Pilha ------------ //
void exibe_Pilha (struct Pilha P)
{
	int i;
	
	if (vazia_Pilha (P))
	{
		printf ("\n\nA Pilha está vazia! Impossível exibir o conteúdo da Pilha!");
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

//----------- Método de inicializar o topo da Pilha -------- //
void inicializa_Pilha (struct Pilha &P)
{
	P.topo = -1;
}
//------------------------------------------------------------- //

//------------------- FUNÇÃO PRINCIPAL ------------------------ //
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
		printf ("\t\t|            Menu de operações da Pilha            |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Opção |         Ação correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |        Inserir valor na Pilha            |\n");
		printf ("\t\t|   2   |       Remover um valor da Pilha          |\n");
		printf ("\t\t|   3   |       Pesquisar um item da Pilha         |\n");
		printf ("\t\t|   4   |   Exibir a Pilha inteira por completo    |\n");
		printf ("\t\t|   5   | Restaurar a Pilha aos padrões de fábrica |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha a ação a ser executada na Pilha com base nas informações acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa está sendo encerrado!");
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
				printf ("\n\nOpção inválida! Tente novamente!");
				break;	
		}
		getch ();
	}while (op != 0);
}
//------------------------------------------------------------- //
