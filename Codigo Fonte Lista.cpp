/*	Algoritmo para a implementação da TAD Lista Dinâmica que será arquiteturada e guiada por Ponteiros.
	
	O algoritmo irá herdar as funções da TAD Lista Dinâmica que já estão armazenadas anteriormente em uma
	biblioteca chamada [TADListaDinamica.h].
	
	Além disso, a Lista Dinâmica é composta de 2 elementos: O ELEMENTO e o PONTEIRO apontando para a próxima
	Estrutura que será criada sob encomenda via comando MALLOC.
	
	Agora, temos o surgimento de 2 comandos novos:
	
	--> Sintaxe de MALLOC: "ponteiro = (casting *) malloc (tamanho do bloco de memória a ser criado pertencente ao tipo)"
	
		No caso do "casting", é necessário especificar qual o Tipo Primitivo de Dado pertencente ao Ponteiro criado ou qual
		a Estrutura a que ele pertence. Como se trata de Ponteiros, a especificação deverá ser seguida de "*".
		
		Em relação ao tamanho do bloco de memória a ser criado, como o tamanho dos Tipos Primitivos de Dados e/ou de uma Estrutura
		podem variar bastante, de código pra código e de computador pra computador, se tem a necessidade de um comando que trate
		isso da forma mais dinâmica possível via comando SIZEOF.
		
		LÊ-SE: "Atribuindo uma quantidade X de bytes do tipo Y ao Ponteiro Z."
		
		Exemplo: 'Z = (int *) malloc (sizeof (int))'. 
	
	--> Sintaxe de FREE: "free (ponteiro)"
	
		Trata-se de livrar o espaço de memória criado anteriormente para não deixar "lixo" espalhados no algoritmo de maneira geral.
		
		Ao executar o comando, recomenda-se que um Número Inteiro Nulo (NULL ou 0) seja atribuído ao ponteiro residente.
		
		Exemplo: 'free (ponteiro)'.
				 'ponteiro = NULL (ou 0)'.
	
	Os comandos MALLOC e FREE, pertencem à biblioteca <stdlib.h> que deverá ser utilizada neste algoritmo.
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
	
	inicializaListaDinamica (0);			// Valor 0: Operação de INICIALIZAÇÃO da Lista Dinâmica.
	
	do
	{	
		system ("cls");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|        Menu de operações da TAD Lista Dinâmica   |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t| Opção |         Ação correspondente              |\n");
		printf ("\t\t----------------------------------------------------\n");
		printf ("\t\t|   1   |      Inserir um elemento nesta Lista     |\n");
		printf ("\t\t|   2   |      Remover um elemento desta Lista     |\n");
		printf ("\t\t|   3   |      Pesquisar um Valor nesta Lista      |\n");
		printf ("\t\t|   4   |      Exibir dados da Lista Dinâmica      |\n");
		printf ("\t\t|   5   | Restaurar a Lista aos padrões de fábrica |\n");
		printf ("\t\t----------------------------------------------------\n");
		
		printf ("\n\nEscolha uma opção com base na ação correspondente a ser executada na Lista Dinâmica (ou digite 0 para SAIR!): ");
		scanf ("%d", &op);
		
		switch (op)
		{
			case 0:
				printf ("\n\nO programa está sendo encerrado...");
				break;
			case 1:
				printf ("\n\nInforme o Valor que deseja inserir na Lista: ");
				scanf ("%d", &item);
				inserirElemento (item);
				break;
			case 2:
				printf ("\n\nInforme o Valor que deseja procurar na Lista e removê-lo: ");
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
				printf ("\n\nA TAD Lista Dinâmica foi resetada com sucesso!");
				
				inicializaListaDinamica (1);				// Valor 1: Operação de RESET da Lista Dinâmica.
				
				break;
			default:
				printf ("\n\nA opção digitada é INVÁLIDA! Tente novamente!");
				break;
		}
		getch ();
	}while (op != 0);
}
