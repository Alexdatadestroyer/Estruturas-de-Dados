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
	
	/* IF: Caso de exclusão de elemento que seja NÓ FOLHA (GRAU 0). Nesse caso, apenas redireciona-se o Ponteiro da Esquerda ou
	       da Direita do elemento ancestral, de acordo com o seu Valor em comparação a ele, pra NULL (IF-ELSE internos).
		   
	       No caso exclusivo da RAIZ, esta passará a apontar pra NULL, uma vez que a Árvore estará VAZIA!
		   
	       OBS: O Ponteiro "NoExcluido" recebe o elemento da Árvore a ser excluído DEPOIS das operações do IF principal!
	   
	   ELSE: Caso de exclusão de elemento que seja NÓ de GRAU 1, possuindo apenas UM FILHO. Nesse caso, é verificado qual elemento
	         estará disponível para tomar seu lugar, sendo a Esquerda dele ou a Direita (IF-ELSE em Condição Ternária superior).
                 O elemento disponível será apontado pelo elemento ancestral da Esquerda ou da Direita dependendo de seu Valor perante
		 a ele (IF-ELSE em Condição Ternária inferior) num processo parecido com o da exclusão de um NÓ FOLHA.
			 
		 No caso exclusivo da RAIZ, esta passará a apontar pra esse elemento ("NoAtual" depois da mudança) sendo da Esquerda ou da
		 Direita do elemento a ser excluído posteriormente ("NoAtual" antes da mudança. Agora, na variável "NoExcluido").
		     
		 OBS: O Ponteiro "NoExcluido" recebe o elemento da Árvore a ser excluído ANTES das operações do ELSE principal!
	   
	    Depois de realizadas as devidas operações antes da exclusão, o elemento é finalmente eliminado da Árvore Binária de Busca. O
	    antigo elemento "NoAtual" foi atribuído ao Ponteiro "NoExcluido" pra ser possível as operações e também pra exclusão dar certo! */
	
	if ((!NoAtual->left) && (!NoAtual->right))
	{		
		if (NoAtual == root)						// Caso específico da exclusão da RAIZ da Árvore
		{
			root = NULL;
		}
		else								// Para todos os outros casos de exclusão de elementos...
		{
			(NoAtual->elemento < NoAncestral->elemento) ? (NoAncestral->left = NULL) : (NoAncestral->right = NULL);
		}
		
		NoExcluido = NoAtual;
	}
	else
	{
		NoExcluido = NoAtual;
		
		if (NoAtual == root)						// Caso específico da exclusão da RAIZ da Árvore
		{
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			root = NoAtual;
		}
		else								// Para todos os outros casos de exclusão de elementos...
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
	
	/* WHILE: De início, hora de buscar o Valor a ser excluído na Árvore Binária de Busca. Se chegar ao final de iteração, o Valor
	          NÃO EXISTE para ser excluído. Se houver interrupção brusca, teremos a operação de exclusão... */
	
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
	
	/* Condição de Existência: Só haverá exclusão de elementos APENAS se eles existirem na Árvore! */
	
	if (NoAtual)
	{
		/* IF: Tratamento de um elemento que possui DOIS FILHOS (GRAU 2). Pra este caso, o Exercício exigiu que fosse tomado o caminho de pegar o 
		       ELEMENTO MAIS À DIREITA DA SUB ÁRVORE DA ESQUERDA como elemento substituto. Pra isso, entra-se em um Segundo WHILE que tem a função
		       de andar com os Ponteiros "NoAncestral" e "NoProfundo" onde "NoProfundo" se tratará de achar ESTE Valor pretendido e substituí-lo
		       com o Valor encontrado anteriormente que possuía dois filhos (NoAtual).
		       
		       Quando o elemento mais a Direita da SAE chegar ao final (NoProfundo->right == NULL), a iteração termina e a troca é realizada por
		       meio da Variável Auxiliar INT "alce". Assim, com os elementos trocados, o foco da exclusão deixará de ser aquele elemento que
		       possuía dois filhos e passará para um elemento que possua APENAS UM FILHO (GRAU 1) ou que seja FOLHA (GRAU 0).
		       
		       Sendo assim, uma outra Função é chamada a realizar de forma real a exclusão.
		    
		   ELSE: Sendo um elemento que seja NÓ FOLHA ou NÓ de GRAU 1, chama-se diretamente a Função responsável pela exclusão real do elemento. */
		
		if ((NoAtual->left) && (NoAtual->right))
		{
			NoAncestral = NoAtual;
			NoProfundo = NoAtual->left;
			
			if (!NoProfundo->right)						// Caso exclusivo de carência de elementos MAIORES na SAE da Árvore Binária
			{
				alce = NoProfundo->elemento;
				NoProfundo->elemento = NoAncestral->elemento;
				NoAncestral->elemento = alce;
				
				NoAncestral->left = NoProfundo->left;
				free (NoProfundo);
			}
			else								// Casos comuns onde, geralmente, há elementos MAIORES na SAE da Árvore Binária
			{
				/* WHILE: Busca do MAIOR ELEMENTO à ESQUERDA da Árvore Binária de Busca: Exigência do Exercício */
			
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
	/* WHILE: Irá funcionar até chegar ao seu fim (NoAtual == NULL) ou até ser interrompido de forma brusca ao encontrar o Valor
	          na Árvore IGUAL ao Valor requisitado anteriormente.
	          
	          Se houver interrupção brusca, significa dizer que o Valor foi encontrado com sucesso na Árvore Binária de Busca (return 1).
	          Caso contrário, chegando até o final real da iteração, significa dizer que o Valor NÃO EXISTE na Árvore (return 0). */
	          
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
		
		/* Aqui, teremos um controle maior. Elementos que são MENORES que a RAIZ serão impressos o Valor e o Espaço em Branco em
		   seguida (ELSE IF). Elementos MAIORES que a RAIZ serão impressos seguidos do Espaço em Branco cada um (ELSE). O elemento
		   da RAIZ será exibido de forma normal sem deixar Espaços em Branco a esquerda e/ou a direita (IF) */
		
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
		/* Aqui, o elemento da RAIZ sempre será o PRIMEIRO elemento a ser exibido (IF). Elementos diferentes dele serão exibidos depois
		   de um Espaço em Branco cada um até o fim (ELSE) */
		
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
		
		/* Como o elemento da RAIZ aqui sempre será o ÚLTIMO a ser exibido (IF), o Valor é impresso seguido de Espaço em Branco
		   em outras ocasiões (ELSE) */
		
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
	/* WHILE: Irá executar até que se chegue ao final (NoAtual == NULL) inserindo o Novo Bloco de Memória no espaço apropriado ou
	          até que seja interrompido de forma brusca caso o Valor informado pra Inserção seja IGUAL a algum elemento já
	          contido na Árvore. Nesse último caso, NÃO HAVERÁ INSERÇÃO do novo elemento em sua estrutura */
	
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
	
	/* Condição de Existência: APENAS Valores NÃO REPETIDOS serão adicionados na Árvore (NoAtual == NULL) */
	
	if (!NoAtual)
	{
		NoAtual = (struct BinaryTreeSearch *) malloc (sizeof (struct BinaryTreeSearch));
		NoAtual->elemento = numeral;
		NoAtual->left = NULL;
		NoAtual->right = NULL;
		
		/* IF: Se o novo elemento adicionado for o Primeiro da estrutura, ele irá pra RAIZ da Árvore!
		   ELSE: Caso contrário, se for MENOR, fará parte da SAE. Se for MAIOR, fará parte da SAD */
		
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
	
	/* Como a Árvore Binária de Busca só será Inicializada APENAS UMA VEZ, pode-se apontar diretamente o Ponteiro RAIZ pra NULL */
	
	root = NULL;
	
	while (scanf ("%[^\n]s", comando) != EOF)
	{
		getchar();					// No Linux: "fflush (stdin)" não funciona corretamente!
		
		/* Analisar entrada válida entre 3 e 10 caracteres podendo conter Letras e Números */
		
		if (strlen(comando) >= 3 && strlen(comando) <= 9)
		{
			/* IF: Se for encontrado um Espaço em Branco na Segunda Posição da String de Entrada, comandos serão executados a seguir:
			   
			   a) Separação de Letra e Número: Letra como a Primeira Posição da String de Entrada (comando[0]) e o Número assumindo
			      até cerca de 7 posições conforme o enunciado do Exercício na parte final da String (1 <= Número <= 10E6)
			      
			   b) Passagem de cada caractere da String de Entrada para uma Segunda String (FOR do I) seguida do finalizador dela (\0).
			   c) Conversão do conteúdo da Segunda String (numeroChar) para um Número Inteiro PURO (charInt) via comando "atoi".
			   d) Análise das opções da Letra sendo "I" pra Inserir elemento, "P" pra Pesquisar e "R" pra Remover elemento da Árvore.
			
			   ELSE: Se a String de Entrada apenas conter Letras escritas com o nome dos Percursos da Árvore Binária de Busca, será
			         realizado o tipo de Percurso solicitado, sendo INFIXA (Ordem Simétrica), PREFIXA (Pré Ordem) e POSFIXA (Pós Ordem) */
			
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
