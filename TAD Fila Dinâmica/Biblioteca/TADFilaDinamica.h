/*	Biblioteca de implementação da TAD Fila Encadeada Dinâmica

	Autor: Alexandre Gadelha da Silva Carvalho
	
	Nesta TAD Fila Dinâmica, teremos uma Estrutura que constituirá de dois elementos:
	
	a) O ELEMENTO que irá guardar um Valor X digitado pelo usuário.
	b) O PONTEIRO que irá apontar para o PRÓXIMO Bloco de Memória da TAD.
	
	Teremos também a utilização de dois Ponteiros e mais um extra de Aspecto Global:
	
	a) FRONT que irá apontar para o elemento que estará na FRENTE da Fila.
	b) BEHIND que irá apontar para o elemento que estará ATRÁS da Fila.
	c) ALCE que será responsável por percorrer, inserir elementos ou remover elementos da Fila.
	
	As operações da TAD Fila Dinâmica são:
	
	1) Enfileirar elemento (Inserir elemento).
	2) Desenfileirar elemento (Remover elemento).
	3) Pesquisar elemento na Fila.
	4) Exibir elementos da Fila.
	5) Inicialização e Reset da TAD Fila dependendo da ocasião.
	
	A implementação da TAD se dará pela utilização do método do NÓ CABEÇA (ou BLOCO CABEÇA), um Bloco de Memória
	Vazio a servir APENAS como referência para o FRENTE e, inicialmente, o TRÁS da Fila Dinâmica.
*/
struct FilaDinamica *front, *behind, *alce;

//----------- Estrutura da TAD Fila Dinâmica ------------//
struct FilaDinamica
{
	int elemento;
	struct FilaDinamica *next;
};
//--------------------------------------------------------//

//------- Exibição do Conteúdo da Fila Dinâmica ----------//
void exibirConteudoFila ()
{
	int i = 1;
	
	alce = front->next;
	
	if (!alce)				// FRENTE aponta pra NULL: Fila Dinâmica VAZIA!
	{
		printf ("\n\n\nA Fila Dinâmica está VAZIA! Impossível exibir seu conteúdo!");
	}
	else					// FRENTE NÃO aponta pra NULL: Fila Dinâmica contém elementos!
	{
		printf ("\n\n\nExibindo o conteúdo da TAD Fila Dinâmica... \n\n");
		
		while (alce)			// while (alce != NULL).
		{
			printf ("\nElemento [%d] = %d", i, alce->elemento);
			i++;
			alce = alce->next;
		}
		printf ("\n\nElemento da parte da FRENTE da Fila: %d", front->next->elemento);
		printf ("\nElemento da parte de TRÁS da Fila: %d", behind->elemento);
	}
}
//--------------------------------------------------------//

//---------- Pesquisar um Item na Fila Dinâmica ----------//
void pesquisaItem (int elemento)
{
	int contador = 0;
	
	alce = front->next;
	
	while (alce)				// while (alce != NULL).
	{
		if (alce->elemento == elemento)
		{
			contador++;
		}
		alce = alce->next;
	}
	
	if (contador == 0)
		printf ("\n\n\nNENHUM Valor igual a %d foi encontrado na Fila Dinâmica!", elemento);
	else
		printf ("\n\n\nTivemos %d ocorrência(s) do Valor %d na Fila Dinâmica!", contador, elemento);
}
//--------------------------------------------------------//

//-------- Desempilhar um Item da Fila Dinâmica ----------//
void desenfileiraItem ()
{
	alce = front->next;
	
	if (alce)					// Fila Dinâmica contém elementos! FRENTE NÃO aponta pra NULL.
	{
		printf ("\n\nO Primeiro Valor da Fila Dinâmica, que é o %d, foi removido com sucesso!", alce->elemento);
		
		if (alce == behind)
		{
			behind = front;
		}
		
		front->next = alce->next;
		free (alce);
	}
	else						// Fila Dinâmica está VAZIA! FRENTE aponta pra NULL.
	{
		printf ("\n\nA Fila Dinâmica não possui elementos para exclusão! Impossível desenfileirar!");
	}
}
//--------------------------------------------------------//

//----------- Empilhar um Item da Fila Dinâmica ----------//
void enfileiraItem (int valx)
{	
	alce = (struct FilaDinamica *) malloc (sizeof (struct FilaDinamica));
	alce->next = NULL;
	alce->elemento = valx;
	behind->next = alce;
	behind = alce;
	
	printf ("\n\nO Valor informado %d foi Enfileirado na Fila com sucesso!", valx);
}
//--------------------------------------------------------//

//--------- Inicialização e RESET da Fila Dinâmica -------//
void inicializaFila (bool flag)
{
	int cont = -1;
	
	/* Flag TRUE:   Operação de INICIALIZAÇÃO da Fila Dinâmica. */
	/* Flag FALSE:  Operação de RESET e LIMPEZA da Fila Dinâmica. */
	
	if (!flag)
	{
		alce = front;
		
		while (alce)			// while (alce != NULL).
		{
			free (alce);
			alce = alce->next;
			cont++;
		}
	}
	
	((cont == 0) || (cont == -1)) ? /* Continue... */ : printf ("\n\nForam limpos %d Blocos de Memória utilizados na Fila Dinâmica!", cont);
	
	alce = (struct FilaDinamica *) malloc (sizeof (struct FilaDinamica));
	alce->next = NULL;
	front = alce;
	behind = front;
}
//--------------------------------------------------------//
