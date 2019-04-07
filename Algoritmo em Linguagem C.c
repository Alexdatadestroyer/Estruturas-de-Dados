#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryTreeSearch
{
	int elemento;
	struct BinaryTreeSearch *left, *right;
};

struct BinaryTreeSearch *root;

void removerValorReal (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, int numeral)
{
	struct BinaryTreeSearch *NoExcluido;
	
	/* IF: Caso de exclus�o de elemento que seja N� FOLHA (GRAU 0). Nesse caso, apenas redireciona-se o Ponteiro da Esquerda ou
	       da Direita do elemento ancestral, de acordo com o seu Valor em compara��o a ele, pra NULL (IF-ELSE internos).
		   
	       No caso exclusivo da RAIZ, esta passar� a apontar pra NULL, uma vez que a �rvore estar� VAZIA!
		   
	       OBS: O Ponteiro "NoExcluido" recebe o elemento da �rvore a ser exclu�do DEPOIS das opera��es do IF principal!
	   
	   ELSE: Caso de exclus�o de elemento que seja N� de GRAU 1, possuindo apenas UM FILHO. Nesse caso, � verificado qual elemento
	         estar� dispon�vel para tomar seu lugar, sendo a Esquerda dele ou a Direita (IF-ELSE em Condi��o Tern�ria superior).
                 O elemento dispon�vel ser� apontado pelo elemento ancestral da Esquerda ou da Direita dependendo de seu Valor perante
		 a ele (IF-ELSE em Condi��o Tern�ria inferior) num processo parecido com o da exclus�o de um N� FOLHA.
			 
		 No caso exclusivo da RAIZ, esta passar� a apontar pra esse elemento ("NoAtual" depois da mudan�a) sendo da Esquerda ou da
		 Direita do elemento a ser exclu�do posteriormente ("NoAtual" antes da mudan�a. Agora, na vari�vel "NoExcluido").
		     
		 OBS: O Ponteiro "NoExcluido" recebe o elemento da �rvore a ser exclu�do ANTES das opera��es do ELSE principal!
	   
	    Depois de realizadas as devidas opera��es antes da exclus�o, o elemento � finalmente eliminado da �rvore Bin�ria de Busca. O
	    antigo elemento "NoAtual" foi atribu�do ao Ponteiro "NoExcluido" pra ser poss�vel as opera��es e tamb�m pra exclus�o dar certo! */
	
	if ((!NoAtual->left) && (!NoAtual->right))
	{		
		if (NoAtual == root)						// Caso espec�fico da exclus�o da RAIZ da �rvore
		{
			root = NULL;
		}
		else								// Para todos os outros casos de exclus�o de elementos...
		{
			(NoAtual->elemento < NoAncestral->elemento) ? (NoAncestral->left = NULL) : (NoAncestral->right = NULL);
		}
		
		NoExcluido = NoAtual;
	}
	else
	{
		NoExcluido = NoAtual;
		
		if (NoAtual == root)						// Caso espec�fico da exclus�o da RAIZ da �rvore
		{
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			root = NoAtual;
		}
		else								// Para todos os outros casos de exclus�o de elementos...
		{	
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			(NoAtual->elemento < NoAncestral->elemento) ? (NoAncestral->left = NoAtual) : (NoAncestral->right = NoAtual);
		}
	}
	free (NoExcluido);
}

void removerValorArvoreBusca (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, int numeral)
{
	struct BinaryTreeSearch *NoProfundo;
	int alce;
	
	/* WHILE: De in�cio, hora de buscar o Valor a ser exclu�do na �rvore Bin�ria de Busca. Se chegar ao final de itera��o, o Valor
	          N�O EXISTE para ser exclu�do. Se houver interrup��o brusca, teremos a opera��o de exclus�o... */
	
	while (NoAtual)
	{
		if (numeral < NoAtual->elemento)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->left;
		}
		else if (numeral > NoAtual->elemento)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	/* Condi��o de Exist�ncia: S� haver� exclus�o de elementos APENAS se eles existirem na �rvore! */
	
	if (NoAtual)
	{
		/* IF: Tratamento de um elemento que possui DOIS FILHOS (GRAU 2). Pra este caso, o Exerc�cio exigiu que fosse tomado o caminho de pegar o 
		       ELEMENTO MAIS � DIREITA DA SUB �RVORE DA ESQUERDA como elemento substituto. Pra isso, entra-se em um Segundo WHILE que tem a fun��o
		       de andar com os Ponteiros "NoAncestral" e "NoProfundo" onde "NoProfundo" se tratar� de achar ESTE Valor pretendido e substitu�-lo
		       com o Valor encontrado anteriormente que possu�a dois filhos (NoAtual).
		       
		       Quando o elemento mais a Direita da SAE chegar ao final (NoProfundo->right == NULL), a itera��o termina e a troca � realizada por
		       meio da Vari�vel Auxiliar INT "alce". Assim, com os elementos trocados, o foco da exclus�o deixar� de ser aquele elemento que
		       possu�a dois filhos e passar� para um elemento que possua APENAS UM FILHO (GRAU 1) ou que seja FOLHA (GRAU 0).
		       
		       Sendo assim, uma outra Fun��o � chamada a realizar de forma real a exclus�o.
		    
		   ELSE: Sendo um elemento que seja N� FOLHA ou N� de GRAU 1, chama-se diretamente a Fun��o respons�vel pela exclus�o real do elemento. */
		
		if ((NoAtual->left) && (NoAtual->right))
		{
			NoAncestral = NoAtual;
			NoProfundo = NoAtual->left;
			
			if (!NoProfundo->right)						// Caso exclusivo de car�ncia de elementos MAIORES na SAE da �rvore Bin�ria
			{
				alce = NoProfundo->elemento;
				NoProfundo->elemento = NoAncestral->elemento;
				NoAncestral->elemento = alce;
				
				NoAncestral->left = NoProfundo->left;
				free (NoProfundo);
			}
			else								// Casos comuns onde, geralmente, h� elementos MAIORES na SAE da �rvore Bin�ria
			{
				/* WHILE: Busca do MAIOR ELEMENTO � ESQUERDA da �rvore Bin�ria de Busca: Exig�ncia do Exerc�cio */
			
				while (NoProfundo->right)
				{
					NoAncestral = NoProfundo;
					NoProfundo = NoProfundo->right;
				}
				
				alce = NoProfundo->elemento;
				NoProfundo->elemento = NoAtual->elemento;
				NoAtual->elemento = alce;
				
				removerValorReal (NoAncestral, NoProfundo, numeral);
			}
		}
		else
		{
			removerValorReal (NoAncestral, NoAtual, numeral);
		}
	}
}

int pesquisaValorArvoreBusca (struct BinaryTreeSearch *NoAtual, int numeral)
{
	/* WHILE: Ir� funcionar at� chegar ao seu fim (NoAtual == NULL) ou at� ser interrompido de forma brusca ao encontrar o Valor
	          na �rvore IGUAL ao Valor requisitado anteriormente.
	          
	          Se houver interrup��o brusca, significa dizer que o Valor foi encontrado com sucesso na �rvore Bin�ria de Busca (return 1).
	          Caso contr�rio, chegando at� o final real da itera��o, significa dizer que o Valor N�O EXISTE na �rvore (return 0). */
	          
	while (NoAtual)
	{
		if (numeral < NoAtual->elemento)
		{
			NoAtual = NoAtual->left;
		}
		else if (numeral > NoAtual->elemento)
		{
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	if (!NoAtual)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void percursoInfixaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{		
		percursoInfixaArvoreBusca (NoAtual->left);
		
		/* Aqui, teremos um controle maior. Elementos que s�o MENORES que a RAIZ ser�o impressos o Valor e o Espa�o em Branco em
		   seguida (ELSE IF). Elementos MAIORES que a RAIZ ser�o impressos seguidos do Espa�o em Branco cada um (ELSE). O elemento
		   da RAIZ ser� exibido de forma normal sem deixar Espa�os em Branco a esquerda e/ou a direita (IF) */
		
		if (NoAtual->elemento == root->elemento)
		{
			printf ("%d", NoAtual->elemento);
		}
		else if (NoAtual->elemento < root->elemento)
		{
			printf ("%d ", NoAtual->elemento);
		}
		else
		{
			printf (" %d", NoAtual->elemento);
		}
		
		percursoInfixaArvoreBusca (NoAtual->right);
	}
}

void percursoPrefixaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		/* Aqui, o elemento da RAIZ sempre ser� o PRIMEIRO elemento a ser exibido (IF). Elementos diferentes dele ser�o exibidos depois
		   de um Espa�o em Branco cada um at� o fim (ELSE) */
		
		if (NoAtual->elemento == root->elemento)
		{
			printf ("%d", NoAtual->elemento);
		}
		else
		{
			printf (" %d", NoAtual->elemento);
		}
		
		percursoPrefixaArvoreBusca (NoAtual->left);
		percursoPrefixaArvoreBusca (NoAtual->right);
	}
}

void percursoPosfixaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		percursoPosfixaArvoreBusca (NoAtual->left);
		percursoPosfixaArvoreBusca (NoAtual->right);
		
		/* Como o elemento da RAIZ aqui sempre ser� o �LTIMO a ser exibido (IF), o Valor � impresso seguido de Espa�o em Branco
		   em outras ocasi�es (ELSE) */
		
		if (NoAtual->elemento == root->elemento)
		{
			printf ("%d", NoAtual->elemento);
		}
		else
		{
			printf ("%d ", NoAtual->elemento);
		}
	}
}

void inserirElementoArvoreBusca (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, int numeral)
{
	/* WHILE: Ir� executar at� que se chegue ao final (NoAtual == NULL) inserindo o Novo Bloco de Mem�ria no espa�o apropriado ou
	          at� que seja interrompido de forma brusca caso o Valor informado pra Inser��o seja IGUAL a algum elemento j�
	          contido na �rvore. Nesse �ltimo caso, N�O HAVER� INSER��O do novo elemento em sua estrutura */
	
	while (NoAtual)
	{
		if (numeral < NoAtual->elemento)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->left;
		}
		else if (numeral > NoAtual->elemento)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	/* Condi��o de Exist�ncia: APENAS Valores N�O REPETIDOS ser�o adicionados na �rvore (NoAtual == NULL) */
	
	if (!NoAtual)
	{
		NoAtual = (struct BinaryTreeSearch *) malloc (sizeof (struct BinaryTreeSearch));
		NoAtual->elemento = numeral;
		NoAtual->left = NULL;
		NoAtual->right = NULL;
		
		/* IF: Se o novo elemento adicionado for o Primeiro da estrutura, ele ir� pra RAIZ da �rvore!
		   ELSE: Caso contr�rio, se for MENOR, far� parte da SAE. Se for MAIOR, far� parte da SAD */
		
		if (!NoAncestral)
		{
			root = NoAtual;
		}
		else
		{
			if (NoAtual->elemento < NoAncestral->elemento)
			{
				NoAncestral->left = NoAtual;
			}
			else if (NoAtual->elemento > NoAncestral->elemento)
			{
				NoAncestral->right = NoAtual;
			}
		}
	}
}

int main ()
{
	char comando[10], letra, numeroChar[8];
	int retorno, i, charInt;
	
	/* Como a �rvore Bin�ria de Busca s� ser� Inicializada APENAS UMA VEZ, pode-se apontar diretamente o Ponteiro RAIZ pra NULL */
	
	root = NULL;
	
	while (scanf ("%[^\n]s", comando) != EOF)
	{
		getchar();					// No Linux: "fflush (stdin)" n�o funciona corretamente!
		
		/* Analisar entrada v�lida entre 3 e 10 caracteres podendo conter Letras e N�meros */
		
		if (strlen(comando) >= 3 && strlen(comando) <= 9)
		{
			/* IF: Se for encontrado um Espa�o em Branco na Segunda Posi��o da String de Entrada, comandos ser�o executados a seguir:
			   
			   a) Separa��o de Letra e N�mero: Letra como a Primeira Posi��o da String de Entrada (comando[0]) e o N�mero assumindo
			      at� cerca de 7 posi��es conforme o enunciado do Exerc�cio na parte final da String (1 <= N�mero <= 10E6)
			      
			   b) Passagem de cada caractere da String de Entrada para uma Segunda String (FOR do I) seguida do finalizador dela (\0).
			   c) Convers�o do conte�do da Segunda String (numeroChar) para um N�mero Inteiro PURO (charInt) via comando "atoi".
			   d) An�lise das op��es da Letra sendo "I" pra Inserir elemento, "P" pra Pesquisar e "R" pra Remover elemento da �rvore.
			
			   ELSE: Se a String de Entrada apenas conter Letras escritas com o nome dos Percursos da �rvore Bin�ria de Busca, ser�
			         realizado o tipo de Percurso solicitado, sendo INFIXA (Ordem Sim�trica), PREFIXA (Pr� Ordem) e POSFIXA (P�s Ordem) */
			
			if (comando[1] == ' ')
			{
				letra = comando[0];
				
				for (i = 2; comando[i] != '\0'; i++)
				{
					numeroChar[i-2] = comando[i]; 
				}
				numeroChar[i-2] = '\0';
				
				charInt = atoi (numeroChar);
				
				if (letra == 'I')
				{
					inserirElementoArvoreBusca (root, root, charInt);
				}
				else if (letra == 'P')
				{
					retorno = pesquisaValorArvoreBusca (root, charInt);
					
					(!retorno) ? printf ("%d nao existe\n", charInt) : printf ("%d existe\n", charInt);	
				}
				else if (letra == 'R')
				{
					removerValorArvoreBusca (root, root, charInt);
				}
			}
			else
			{				
				if ((strcmp (comando, "INFIXA") == 0) || (strcmp (comando, "infixa") == 0))
				{
					percursoInfixaArvoreBusca (root);
					printf ("\n");
				}
				else if ((strcmp (comando, "PREFIXA") == 0) || (strcmp (comando, "prefixa") == 0))
				{
					percursoPrefixaArvoreBusca (root);
					printf ("\n");
				}
				else if ((strcmp (comando, "POSFIXA") == 0) || (strcmp (comando, "posfixa") == 0))
				{
					percursoPosfixaArvoreBusca (root);
					printf ("\n");
				}
			}
		}
	}
	return 0;
}