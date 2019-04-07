/*	Biblioteca de implementação da TAD Pilha Encadeada Dinâmica.

	Autor: Alexandre Gadelha da Silva Carvalho.
	
	Inicialmente, essa TAD, terá APENAS 2 elementos: o ELEMENTO e o PONTEIRO apontando para o próximo elemento.
	
	Numa Pilha Dinâmica, teremos o surgimento de dois Ponteiros de Escopo Global. São eles:
	
	a) TOP: Que irá apontar para o TOPO da Pilha.
	b) BOTTOM: Que irá apontar para o FUNDO da Pilha.
	
	As operações da TAD Pilha Dinâmica são:
	
	a) Inicializar (Reset) da Pilha Dinâmica.
	b) Empilhar (inserir Valor).
	c) Desempilhar (remover Valor).
	d) Pesquisa de Valor na Pilha Dinâmica.
	e) Exibir itens da Pilha Dinâmica.
	
	A implementação da TAD se dará pela utilização do método do NÓ CABEÇA (ou BLOCO CABEÇA), um Bloco de Memória
	Vazio a servir APENAS como referência para o FUNDO e, inicialmente, o TOPO da Pilha Dinâmica.
*/
struct pilhaDinamica *top, *bottom;				// Ponteiros Globais: TOPO e FUNDO da Pilha Dinâmica.

//----------- Estrutura da TAD Pilha Dinâmica ------------//
struct pilhaDinamica
{
	int elemento;
	struct pilhaDinamica *next;
};
//--------------------------------------------------------//

//------- Exibição do Conteúdo da Pilha Dinâmica ---------//
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
		printf ("\n\n\nA Pilha Dinâmica está VAZIA! Impossível exibir seu conteúdo!");
	}
	else
	{
		printf ("\n\n\nQuantidade de elementos encontrados na Pilha até o momento: %d", cont);
		printf ("\nElemento pertencente ao TOPO desta Pilha até o momento: %d", top->elemento);
	}
}
//--------------------------------------------------------//

//---------- Pesquisar um Item na Pilha Dinâmica ---------//
void pesquisaItem (int elemento)
{
	struct pilhaDinamica *alce;
	int cont = 0;
	
	alce = top;
	
	/* Realização de busca do elemento do TOPO até o FUNDO (BLOCO CABEÇA) da Pilha Dinâmica. */
	
	while (alce != bottom)
	{
		if (alce->elemento == elemento)
		{
			cont++;
		}
		alce = alce->next;
	}
	
	if (cont == 0)
		printf ("\n\nNÃO foi encontrado NENHUM Valor na Pilha Dinâmica igual a %d", elemento);
	else
		printf ("\n\nForam encontrada(s) %d ocorrência(s) do Valor %d na Pilha Dinâmica!", cont, elemento);
}
//--------------------------------------------------------//

//-------- Desempilhar um Item da Pilha Dinâmica ---------//
void desempilhaItem ()
{
	struct pilhaDinamica *alce;
	
	if (top->next)			/* Caso do TOPO NÃO apontar para NULL, ou seja, Pilha Dinâmica contém elementos! */
	{
		printf ("\n\nO elemento TOPO da Pilha Dinâmica, que é o %d, foi removido com sucesso!", top->elemento);
		
		alce = top->next;		// O Ponteiro "alce" irá receber o Bloco de Memória ANTERIOR ao TOPO da Pilha até o momento.
	
		free (top);				// O ÚLTIMO a entrar é o PRIMEIRO a sair (LIFO). Sendo assim, apaga-se o Bloco de Memória referente ao TOPO.
	
		top = alce;				// Agora, o TOPO da Pilha Dinâmica, passa a ser o antigo PENÚLTIMO Bloco de Memória.
	}
	else					/* Caso do TOPO apontar para NULL, ou seja, Pilha Dinâmica VAZIA! */
	{
		printf ("\n\nNENHUM Valor foi removido da Pilha Dinâmica, pois ela está VAZIA!");
	}
}
//--------------------------------------------------------//

//----------- Empilhar um Item da Pilha Dinâmica ---------//
void empilhaItem (int val)
{
	struct pilhaDinamica *alce;
	
	printf ("\n\nO Valor informado %d foi inserido na Pilha Dinâmica com sucesso!", val);
	
	alce = (struct pilhaDinamica *) malloc (sizeof (struct pilhaDinamica));
	alce->elemento = val;
	
	alce->next = top;			// Esse Bloco de Memória criado, irá receber o Bloco de Memória pertencente ao TOPO da Pilha!
	
	top = alce;					// Em seguida, o Bloco de Memória agora criado passa a ser o NOVO TOPO da Pilha!
}
//--------------------------------------------------------//

//--------- Inicialização e RESET da Pilha Dinâmica ------//
void inicializaPilhaDinamica (bool flag)
{
	struct pilhaDinamica *alce;
	int cont = -1;
	
	/* Flag TRUE: Operação de INICIALIZAÇÃO da TAD Pilha Dinâmica. */
	/* Flag FALSE: Operação de RESET da TAD Pilha Dinâmica e LIMPEZA dos Blocos de Memória utilizados (incluindo o NÓ CABEÇA). */
	   
	if (!flag)
	{
		alce = top;				// Começa-se do TOPO da Pilha Dinâmica, a fazer o processo de LIMPEZA.
		
		while (alce)
		{
			free (alce);
			alce = alce->next;
			cont++;
		}
	}
	
	((cont == -1) || (cont == 0)) ? /* Continue... */ : printf ("\n\n\nForam excluídos %d Blocos de Memória utilizados pelo algoritmo!", cont);
	
	alce = (struct pilhaDinamica *) malloc (sizeof (struct pilhaDinamica));
	bottom = alce;
	top = bottom;
	bottom->next = NULL;
}
//--------------------------------------------------------//
