/*	Cria��o de uma Biblioteca do Tipo Abstrato de Dado: Lista Din�mica.
		
	Autor: Alexandre Gadelha da Silva Carvalho.
	
	Numa Lista Din�mica, teremos 2 Ponteiros (PRIMEIRO e �LTIMO) como Vari�veis Globais. Como ser�o utilizadas
	em TODOS OS ESCOPOS, da� o motivo de termos Vari�veis de aspecto Global.
	
	As opera��es padr�es da TAD Lista Din�mica s�o:
	
	a) Inserir elemento.
	b) Remover elemento.
	c) Pesquisar elemento.
	d) Exibir a Lista Din�mica completa.
	e) Inicializar (resetar) a Lista Din�mica.
	
	A implementa��o da TAD Lista Din�mica ser� feita atrav�s do M�todo do N� CABE�A (chamado tamb�m de BLOCO CABE�A)
	que se trata de um Bloco de Mem�ria vazio apenas como refer�ncia de IN�CIO e, inicialmente, o FIM da TAD Lista Din�mica.
*/

struct ListaDinamica *first, *last;   		// Ponteiros GLOBAIS do Tipo Estrutura (STRUCT).

//------------ Estrutura da TAD Lista Din�mica ---------------//
struct ListaDinamica
{
	int elemento;
	struct ListaDinamica *apontador;
};
//------------------------------------------------------------//

//--------- Pesquisa de um elemento da Lista Din�mica --------//
void pesquisaElemento (int val)
{
	struct ListaDinamica *alce;
	int cont = 0;
	
	alce = first->apontador;
	
	while (alce != NULL)
	{
		if (alce->elemento == val)
		{
			cont++;
		}
		alce = alce->apontador;
	}
	
	if (cont == 0)
	{
		printf ("\n\nN�o houve ocorr�ncias do elemento %d na Lista Din�mica!", val);
	}
	else
	{
		printf ("\n\nO elemento %d foi encontrado %d vezes no processo de busca da Lista Din�mica!", val, cont);
	}
}
//------------------------------------------------------------//

//--------- Remo��o de um elemento da Lista Din�mica ---------//
void removerElemento (int val)
{
	struct ListaDinamica *alceReal, *alceAnterior;
	bool flag = false;
	
	alceReal = first->apontador;				// Vari�vel "alceReal" pega o bloco de mem�ria DEPOIS do bloco vazio criado. 
	alceAnterior = first;						// Vari�vel "alceAnterior" pega o bloco de mem�ria vazio criado (BLOCO CABE�A).
	
	while (alceReal != NULL)					// LOOP funcional at� a vari�vel "alceReal" chegar ao final.
	{
		if (alceReal->elemento == val)			/* Se o Valor informado para remo��o for encontrado, ele ser� removido */
		{
			printf ("\n\nO elemento %d informado foi removido com sucesso!", val);
			
			alceAnterior->apontador = alceReal->apontador;
			
			free (alceReal);					// Removendo o bloco de mem�ria correspondente ao Valor informado...
			flag = true;
			
			if (alceReal == last)				/* Caso espec�fico de remo��o do �LTIMO VALOR da Lista Din�mica */
			{
				last = alceAnterior;				// O Ponteiro �LTIMO apontar� agora para o Bloco de Mem�ria ANTERIOR ao exclu�do anteriormente.
													// Assim, o �LTIMO VALOR da Lista Din�mica ser� o Valor contido no antigo PEN�LTIMO Bloco de Mem�ria.
			}
			
			break;								// Se o bloco de mem�ria foi removido, n�o � necess�rio mais estar no LOOP...
		}
		else									/* Caso o Valor n�o tenha sido encontrado ainda... */ 
		{
			alceReal = alceReal->apontador;
			alceAnterior = alceAnterior->apontador;
		}
	}
	
	if (!flag)						/* Se DEPOIS da pesquisa o Valor informado n�o foi encontrado, ent�o N�O houve remo��o! */
	{
		printf ("\n\nN�o foi encontrado o elemento %d informado para remo��o!", val);
	}
}
//------------------------------------------------------------//

//--------- Inser��o de um elemento na Lista Din�mica --------//
void inserirElemento (int val)
{
	struct ListaDinamica *alce;
	
	alce = (struct ListaDinamica *) malloc (sizeof (struct ListaDinamica));
	alce->elemento = val;
	alce->apontador = NULL;
	last->apontador = alce;				// Passando o Bloco de Mem�ria criado para o Ponteiro APONTADOR do �LTIMO Bloco de Mem�ria existente. 
	last = alce;						// E sendo assim, o Ponteiro �LTIMO agora passa a apontar para ESSE Bloco de Mem�ria criado.
	
	printf ("\n\nO Valor informado %d foi inserido na Lista Din�mica com sucesso!", val);
}
//------------------------------------------------------------//

//--------- Exibi��o do conte�do da Lista Din�mica -----------//
void exibirListaDinamica ()
{
	struct ListaDinamica *alce;
	int i = 0;
	
	alce = first->apontador;
	
	printf ("\n\nExibindo o conte�do da Lista Din�mica... \n\n");
	
	while (alce != NULL)
	{
		printf ("Elemento [%d] da Lista = %d \n", i+1, alce->elemento);
		
		alce = alce->apontador;
		i++;
	}
	
	if (i == 0)
	{
		printf ("\n\nA Lista Din�mica est� VAZIA! � necess�rio, pelo menos, um valor para sua exibi��o eficaz!");
	}
	else
	{
		printf ("\n\nAtualmente, temos %d elementos presentes na Lista Din�mica!", i);
		
		printf ("\n\n\n�ltimo elemento da Lista Din�mica at� o momento: %d", last->elemento);
	}
}
//------------------------------------------------------------//

//--------- Inicializa��o e RESET da Lista Din�mica ----------//
void inicializaListaDinamica (int flag)
{
	struct ListaDinamica *alce;
	int contador = -1;
	
	/* Sendo 1 o Valor transferido da Fun��o Principal, ent�o � hora de limpar os blocos de mem�ria in�teis antes do RESET. */
	/* Sendo 0 o Valor transferido da Fun��o Principal, ent�o a limpeza N�O SER� executada! */
	
	if (flag == 1)											
	{
		alce = first;
	
		while (alce != NULL)
		{
			free (alce);
			alce = alce->apontador;
			contador++;
		}
	}
	
	((contador == -1) || (contador == 0)) ? /* Continue... */ : printf ("\n\n\nForam liberados %d Bloco(s) de Mem�ria da Lista Din�mica!", contador);
	
	alce = (struct ListaDinamica *) malloc (sizeof (struct ListaDinamica));
	alce->apontador = NULL;
	first = alce;
	last = first;
}
//------------------------------------------------------------//
