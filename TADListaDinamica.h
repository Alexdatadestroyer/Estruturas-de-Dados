/*	Criação de uma Biblioteca do Tipo Abstrato de Dado: Lista Dinâmica.
		
	Autor: Alexandre Gadelha da Silva Carvalho.
	
	Numa Lista Dinâmica, teremos 2 Ponteiros (PRIMEIRO e ÚLTIMO) como Variáveis Globais. Como serão utilizadas
	em TODOS OS ESCOPOS, daí o motivo de termos Variáveis de aspecto Global.
	
	As operações padrões da TAD Lista Dinâmica são:
	
	a) Inserir elemento.
	b) Remover elemento.
	c) Pesquisar elemento.
	d) Exibir a Lista Dinâmica completa.
	e) Inicializar (resetar) a Lista Dinâmica.
	
	A implementação da TAD Lista Dinâmica será feita através do Método do NÓ CABEÇA (chamado também de BLOCO CABEÇA)
	que se trata de um Bloco de Memória vazio apenas como referência de INÍCIO e, inicialmente, o FIM da TAD Lista Dinâmica.
*/

struct ListaDinamica *first, *last;   		// Ponteiros GLOBAIS do Tipo Estrutura (STRUCT).

//------------ Estrutura da TAD Lista Dinâmica ---------------//
struct ListaDinamica
{
	int elemento;
	struct ListaDinamica *apontador;
};
//------------------------------------------------------------//

//--------- Pesquisa de um elemento da Lista Dinâmica --------//
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
		printf ("\n\nNão houve ocorrências do elemento %d na Lista Dinâmica!", val);
	}
	else
	{
		printf ("\n\nO elemento %d foi encontrado %d vezes no processo de busca da Lista Dinâmica!", val, cont);
	}
}
//------------------------------------------------------------//

//--------- Remoção de um elemento da Lista Dinâmica ---------//
void removerElemento (int val)
{
	struct ListaDinamica *alceReal, *alceAnterior;
	bool flag = false;
	
	alceReal = first->apontador;				// Variável "alceReal" pega o bloco de memória DEPOIS do bloco vazio criado. 
	alceAnterior = first;						// Variável "alceAnterior" pega o bloco de memória vazio criado (BLOCO CABEÇA).
	
	while (alceReal != NULL)					// LOOP funcional até a variável "alceReal" chegar ao final.
	{
		if (alceReal->elemento == val)			/* Se o Valor informado para remoção for encontrado, ele será removido */
		{
			printf ("\n\nO elemento %d informado foi removido com sucesso!", val);
			
			alceAnterior->apontador = alceReal->apontador;
			
			free (alceReal);					// Removendo o bloco de memória correspondente ao Valor informado...
			flag = true;
			
			if (alceReal == last)				/* Caso específico de remoção do ÚLTIMO VALOR da Lista Dinâmica */
			{
				last = alceAnterior;				// O Ponteiro ÚLTIMO apontará agora para o Bloco de Memória ANTERIOR ao excluído anteriormente.
													// Assim, o ÚLTIMO VALOR da Lista Dinâmica será o Valor contido no antigo PENÚLTIMO Bloco de Memória.
			}
			
			break;								// Se o bloco de memória foi removido, não é necessário mais estar no LOOP...
		}
		else									/* Caso o Valor não tenha sido encontrado ainda... */ 
		{
			alceReal = alceReal->apontador;
			alceAnterior = alceAnterior->apontador;
		}
	}
	
	if (!flag)						/* Se DEPOIS da pesquisa o Valor informado não foi encontrado, então NÃO houve remoção! */
	{
		printf ("\n\nNão foi encontrado o elemento %d informado para remoção!", val);
	}
}
//------------------------------------------------------------//

//--------- Inserção de um elemento na Lista Dinâmica --------//
void inserirElemento (int val)
{
	struct ListaDinamica *alce;
	
	alce = (struct ListaDinamica *) malloc (sizeof (struct ListaDinamica));
	alce->elemento = val;
	alce->apontador = NULL;
	last->apontador = alce;				// Passando o Bloco de Memória criado para o Ponteiro APONTADOR do ÚLTIMO Bloco de Memória existente. 
	last = alce;						// E sendo assim, o Ponteiro ÚLTIMO agora passa a apontar para ESSE Bloco de Memória criado.
	
	printf ("\n\nO Valor informado %d foi inserido na Lista Dinâmica com sucesso!", val);
}
//------------------------------------------------------------//

//--------- Exibição do conteúdo da Lista Dinâmica -----------//
void exibirListaDinamica ()
{
	struct ListaDinamica *alce;
	int i = 0;
	
	alce = first->apontador;
	
	printf ("\n\nExibindo o conteúdo da Lista Dinâmica... \n\n");
	
	while (alce != NULL)
	{
		printf ("Elemento [%d] da Lista = %d \n", i+1, alce->elemento);
		
		alce = alce->apontador;
		i++;
	}
	
	if (i == 0)
	{
		printf ("\n\nA Lista Dinâmica está VAZIA! É necessário, pelo menos, um valor para sua exibição eficaz!");
	}
	else
	{
		printf ("\n\nAtualmente, temos %d elementos presentes na Lista Dinâmica!", i);
		
		printf ("\n\n\nÚltimo elemento da Lista Dinâmica até o momento: %d", last->elemento);
	}
}
//------------------------------------------------------------//

//--------- Inicialização e RESET da Lista Dinâmica ----------//
void inicializaListaDinamica (int flag)
{
	struct ListaDinamica *alce;
	int contador = -1;
	
	/* Sendo 1 o Valor transferido da Função Principal, então é hora de limpar os blocos de memória inúteis antes do RESET. */
	/* Sendo 0 o Valor transferido da Função Principal, então a limpeza NÃO SERÁ executada! */
	
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
	
	((contador == -1) || (contador == 0)) ? /* Continue... */ : printf ("\n\n\nForam liberados %d Bloco(s) de Memória da Lista Dinâmica!", contador);
	
	alce = (struct ListaDinamica *) malloc (sizeof (struct ListaDinamica));
	alce->apontador = NULL;
	first = alce;
	last = first;
}
//------------------------------------------------------------//
