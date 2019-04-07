/*	Biblioteca de implementa��o da TAD Pilha Encadeada Din�mica.

	Autor: Alexandre Gadelha da Silva Carvalho.
	
	Inicialmente, essa TAD, ter� APENAS 2 elementos: o ELEMENTO e o PONTEIRO apontando para o pr�ximo elemento.
	
	Numa Pilha Din�mica, teremos o surgimento de dois Ponteiros de Escopo Global. S�o eles:
	
	a) TOP: Que ir� apontar para o TOPO da Pilha.
	b) BOTTOM: Que ir� apontar para o FUNDO da Pilha.
	
	As opera��es da TAD Pilha Din�mica s�o:
	
	a) Inicializar (Reset) da Pilha Din�mica.
	b) Empilhar (inserir Valor).
	c) Desempilhar (remover Valor).
	d) Pesquisa de Valor na Pilha Din�mica.
	e) Exibir itens da Pilha Din�mica.
	
	A implementa��o da TAD se dar� pela utiliza��o do m�todo do N� CABE�A (ou BLOCO CABE�A), um Bloco de Mem�ria
	Vazio a servir APENAS como refer�ncia para o FUNDO e, inicialmente, o TOPO da Pilha Din�mica.
*/
struct pilhaDinamica *top, *bottom;				// Ponteiros Globais: TOPO e FUNDO da Pilha Din�mica.

//----------- Estrutura da TAD Pilha Din�mica ------------//
struct pilhaDinamica
{
	int elemento;
	struct pilhaDinamica *next;
};
//--------------------------------------------------------//

//------- Exibi��o do Conte�do da Pilha Din�mica ---------//
void exibirPilhaDinamica ()
{
	struct pilhaDinamica *alce;
	int cont = 0;
	
	alce = top;
	
	printf ("\n");
	
	while (alce != bottom)
	{
		printf ("\nElemento [%d] = %d", cont+1, alce->elemento);
		cont++;
		alce = alce->next;
	}
	
	if (cont == 0)
	{
		printf ("\n\n\nA Pilha Din�mica est� VAZIA! Imposs�vel exibir seu conte�do!");
	}
	else
	{
		printf ("\n\n\nQuantidade de elementos encontrados na Pilha at� o momento: %d", cont);
		printf ("\nElemento pertencente ao TOPO desta Pilha at� o momento: %d", top->elemento);
	}
}
//--------------------------------------------------------//

//---------- Pesquisar um Item na Pilha Din�mica ---------//
void pesquisaItem (int elemento)
{
	struct pilhaDinamica *alce;
	int cont = 0;
	
	alce = top;
	
	/* Realiza��o de busca do elemento do TOPO at� o FUNDO (BLOCO CABE�A) da Pilha Din�mica. */
	
	while (alce != bottom)
	{
		if (alce->elemento == elemento)
		{
			cont++;
		}
		alce = alce->next;
	}
	
	if (cont == 0)
		printf ("\n\nN�O foi encontrado NENHUM Valor na Pilha Din�mica igual a %d", elemento);
	else
		printf ("\n\nForam encontrada(s) %d ocorr�ncia(s) do Valor %d na Pilha Din�mica!", cont, elemento);
}
//--------------------------------------------------------//

//-------- Desempilhar um Item da Pilha Din�mica ---------//
void desempilhaItem ()
{
	struct pilhaDinamica *alce;
	
	if (top->next)			/* Caso do TOPO N�O apontar para NULL, ou seja, Pilha Din�mica cont�m elementos! */
	{
		printf ("\n\nO elemento TOPO da Pilha Din�mica, que � o %d, foi removido com sucesso!", top->elemento);
		
		alce = top->next;		// O Ponteiro "alce" ir� receber o Bloco de Mem�ria ANTERIOR ao TOPO da Pilha at� o momento.
	
		free (top);				// O �LTIMO a entrar � o PRIMEIRO a sair (LIFO). Sendo assim, apaga-se o Bloco de Mem�ria referente ao TOPO.
	
		top = alce;				// Agora, o TOPO da Pilha Din�mica, passa a ser o antigo PEN�LTIMO Bloco de Mem�ria.
	}
	else					/* Caso do TOPO apontar para NULL, ou seja, Pilha Din�mica VAZIA! */
	{
		printf ("\n\nNENHUM Valor foi removido da Pilha Din�mica, pois ela est� VAZIA!");
	}
}
//--------------------------------------------------------//

//----------- Empilhar um Item da Pilha Din�mica ---------//
void empilhaItem (int val)
{
	struct pilhaDinamica *alce;
	
	printf ("\n\nO Valor informado %d foi inserido na Pilha Din�mica com sucesso!", val);
	
	alce = (struct pilhaDinamica *) malloc (sizeof (struct pilhaDinamica));
	alce->elemento = val;
	
	alce->next = top;			// Esse Bloco de Mem�ria criado, ir� receber o Bloco de Mem�ria pertencente ao TOPO da Pilha!
	
	top = alce;					// Em seguida, o Bloco de Mem�ria agora criado passa a ser o NOVO TOPO da Pilha!
}
//--------------------------------------------------------//

//--------- Inicializa��o e RESET da Pilha Din�mica ------//
void inicializaPilhaDinamica (bool flag)
{
	struct pilhaDinamica *alce;
	int cont = -1;
	
	/* Flag TRUE: Opera��o de INICIALIZA��O da TAD Pilha Din�mica. */
	/* Flag FALSE: Opera��o de RESET da TAD Pilha Din�mica e LIMPEZA dos Blocos de Mem�ria utilizados (incluindo o N� CABE�A). */
	   
	if (!flag)
	{
		alce = top;				// Come�a-se do TOPO da Pilha Din�mica, a fazer o processo de LIMPEZA.
		
		while (alce)
		{
			free (alce);
			alce = alce->next;
			cont++;
		}
	}
	
	((cont == -1) || (cont == 0)) ? /* Continue... */ : printf ("\n\n\nForam exclu�dos %d Blocos de Mem�ria utilizados pelo algoritmo!", cont);
	
	alce = (struct pilhaDinamica *) malloc (sizeof (struct pilhaDinamica));
	bottom = alce;
	top = bottom;
	bottom->next = NULL;
}
//--------------------------------------------------------//
