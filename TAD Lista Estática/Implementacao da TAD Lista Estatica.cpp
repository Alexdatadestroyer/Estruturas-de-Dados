/*	Algoritmo para a criação de uma Lista Estática, uma Estrutura TAD (Tipo Abstrato de Dado) com algumas operações
	possíveis para execução, devendo obedecer os seguintes itens:
	
	a) Para todo item RETIRADO ou INSERIDO no meio, deve-se fazer os itens moverem para a ESQUERDA ou DIREITA
	   como forma de NUNCA deixar espaço vazio na Lista.
	
	b) Toda vez em que for inicializada, a variável que representa o Tamanho deverá ser resetada.
	   Podendo isto também ocorrer caso o usuário solicite no Menu exibido na Função Principal.
	   
	   Na TAD Lista, assume-se o Valor de Reset como 0.
	  
	c) Geralmente, um Menu costuma ser implementado nesses casos como forma de fazer a Lista
	   funcionar como se deve e uma constante como forma de definir o Tamanho Máximo da mesma.
	
	d) Funções booleanas e Procedimentos geralmente também são utilizados nessa TAD. Outra coisa
	   que também será usada será o Conceito de Referência (&) para forma de alteração da Lista
	   diretamente na Memória, caso seja necessário. 
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

//----------- Função de verificação de Lista CHEIA ------------ //
bool cheia_lista (struct Lista L)
{
	if (L.tamanho == MAX)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- Função de verificação de Lista VAZIA ------------ //
bool vazia_lista (struct Lista L)
{
	if (L.tamanho == 0)
		return true;
	else
		return false;
}
//------------------------------------------------------------- //

//----------- Método de inserir valor no FINAL ---------------- //
void inserir_final (struct Lista &L, int x)
{
	if (cheia_lista (L))
	{
		printf ("\n\nA Lista está cheia! Impossível inserir o valor no final!");
	}	
	else
	{
		L.item[L.tamanho] = x;
		L.tamanho++;
		printf ("\n\nO valor %d foi inserido no final da Lista com sucesso!", x);
	}
}
//------------------------------------------------------------- //

//-------- Método de inserir valor na posição informada ------- //
void inserir_posicao (struct Lista &L, int x, int p)
{
	int i;
	
	if (cheia_lista (L))
	{
		printf ("\n\nA Lista está cheia! Impossível inserir o valor da posição informada!");
	}
	else if ((p > L.tamanho) || (p < 0))
	{
		printf ("\n\nA posição informada é inválida! Impossível inserir o valor da posição informada!");
	}
	else
	{
		for (i = L.tamanho; i > p; i--)
		{
			L.item[i] = L.item[i-1];
		}
		L.item[p] = x;
		L.tamanho++;
		printf ("\n\nO valor %d foi inserido na posição %d da Lista com sucesso!", x, p);
	}
}
//------------------------------------------------------------- //

//----------- Método de remover valor no FINAL ---------------- //
void remover_final (struct Lista &L)
{
	if (vazia_lista (L))
	{
		printf ("\n\nA Lista está vazia! Impossível remover o valor no final!");
	}
	else
	{
		L.tamanho--;
		printf ("\n\nO último item que é o %d da Lista foi removido com sucesso!", L.item[L.tamanho]);
	}	
}
//------------------------------------------------------------- //

//-------- Método de remover valor na posição informada ------- //
void remover_posicao (struct Lista &L, int p)
{
	int i;
	
	if (vazia_lista (L))
	{
		printf ("\n\nA Lista está vazia! Impossível remover o valor da posição informada!");
	}
	else if ((p >= L.tamanho) || (p < 0))
	{
		printf ("\n\nA posição informada é inválida! Impossível remover o valor da posição informada!");
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

//----------- Método de exibir o conteúdo da Lista ------------ //
void exibe_lista (struct Lista L)
{
	int i;
	
	if (vazia_lista (L))
	{
		printf ("\n\nA Lista está vazia! Impossível exibir o conteúdo da Lista!");
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

//----------- Método de inicializar o tamanho da Lista -------- //
void inicializa_lista (struct Lista &L)
{
	L.tamanho = 0;
}
//------------------------------------------------------------- //

//------------------- FUNÇÃO PRINCIPAL ------------------------ //
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
		printf ("\t\t|            Menu de operações da Lista            |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Opção |         Ação correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   | Inserir valor no final da Lista          |\n");
		printf ("\t\t|   2   | Inserir valor numa posição da Lista      |\n");
		printf ("\t\t|   3   | Remover o último valor da Lista          |\n");
		printf ("\t\t|   4   | Remover valor numa posição da Lista      |\n");
		printf ("\t\t|   5   | Exibir a Lista inteira por completo      |\n");
		printf ("\t\t|   6   | Restaurar a Lista aos padrões de fábrica |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha a ação a ser executada na Lista com base nas informações acima (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa está sendo encerrado!");
				break;
				
			case 1:
				printf ("\n\nInforme um valor a ser inserido na Lista: ");
				scanf ("%d", &val);
				
				inserir_final (L, val);
				break;
			
			case 2:
				printf ("\n\nInforme um valor a ser inserido na Lista: ");
				scanf ("%d", &val);
				printf ("\n\nInforme a posição da Lista pra inserir o valor informado: ");
				scanf ("%d", &ind);
				
				inserir_posicao (L, val, ind);
				break;
			
			case 3:
				remover_final (L);
				break;
			
			case 4:
				printf ("\n\nInforme a posição da Lista pra remover o valor residente: ");
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
				printf ("\n\nOpção inválida! Tente novamente!");
				break;	
		}
		getch ();
	}while (op != 0);
}
//------------------------------------------------------------- //
