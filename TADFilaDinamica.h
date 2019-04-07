/*	Biblioteca de implementa��o da TAD Fila Encadeada Din�mica

	Autor: Alexandre Gadelha da Silva Carvalho
	
	Nesta TAD Fila Din�mica, teremos uma Estrutura que constituir� de dois elementos:
	
	a) O ELEMENTO que ir� guardar um Valor X digitado pelo usu�rio.
	b) O PONTEIRO que ir� apontar para o PR�XIMO Bloco de Mem�ria da TAD.
	
	Teremos tamb�m a utiliza��o de dois Ponteiros e mais um extra de Aspecto Global:
	
	a) FRONT que ir� apontar para o elemento que estar� na FRENTE da Fila.
	b) BEHIND que ir� apontar para o elemento que estar� ATR�S da Fila.
	c) ALCE que ser� respons�vel por percorrer, inserir elementos ou remover elementos da Fila.
	
	As opera��es da TAD Fila Din�mica s�o:
	
	1) Enfileirar elemento (Inserir elemento).
	2) Desenfileirar elemento (Remover elemento).
	3) Pesquisar elemento na Fila.
	4) Exibir elementos da Fila.
	5) Inicializa��o e Reset da TAD Fila dependendo da ocasi�o.
	
	A implementa��o da TAD se dar� pela utiliza��o do m�todo do N� CABE�A (ou BLOCO CABE�A), um Bloco de Mem�ria
	Vazio a servir APENAS como refer�ncia para o FRENTE e, inicialmente, o TR�S da Fila Din�mica.
*/
struct FilaDinamica *front, *behind, *alce;

//----------- Estrutura da TAD Fila Din�mica ------------//
struct FilaDinamica
{
	int elemento;
	struct FilaDinamica *next;
};
//--------------------------------------------------------//

//------- Exibi��o do Conte�do da Fila Din�mica ----------//
void exibirConteudoFila ()
{
	int i = 1;
	
	alce = front->next;
	
	if (!alce)				// FRENTE aponta pra NULL: Fila Din�mica VAZIA!
	{
		printf ("\n\n\nA Fila Din�mica est� VAZIA! Imposs�vel exibir seu conte�do!");
	}
	else					// FRENTE N�O aponta pra NULL: Fila Din�mica cont�m elementos!
	{
		printf ("\n\n\nExibindo o conte�do da TAD Fila Din�mica... \n\n");
		
		while (alce)			// while (alce != NULL).
		{
			printf ("\nElemento [%d] = %d", i, alce->elemento);
			i++;
			alce = alce->next;
		}
		printf ("\n\nElemento da parte da FRENTE da Fila: %d", front->next->elemento);
		printf ("\nElemento da parte de TR�S da Fila: %d", behind->elemento);
	}
}
//--------------------------------------------------------//

//---------- Pesquisar um Item na Fila Din�mica ----------//
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
		printf ("\n\n\nNENHUM Valor igual a %d foi encontrado na Fila Din�mica!", elemento);
	else
		printf ("\n\n\nTivemos %d ocorr�ncia(s) do Valor %d na Fila Din�mica!", contador, elemento);
}
//--------------------------------------------------------//

//-------- Desempilhar um Item da Fila Din�mica ----------//
void desenfileiraItem ()
{
	alce = front->next;
	
	if (alce)					// Fila Din�mica cont�m elementos! FRENTE N�O aponta pra NULL.
	{
		printf ("\n\nO Primeiro Valor da Fila Din�mica, que � o %d, foi removido com sucesso!", alce->elemento);
		
		if (alce == behind)
		{
			behind = front;
		}
		
		front->next = alce->next;
		free (alce);
	}
	else						// Fila Din�mica est� VAZIA! FRENTE aponta pra NULL.
	{
		printf ("\n\nA Fila Din�mica n�o possui elementos para exclus�o! Imposs�vel desenfileirar!");
	}
}
//--------------------------------------------------------//

//----------- Empilhar um Item da Fila Din�mica ----------//
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

//--------- Inicializa��o e RESET da Fila Din�mica -------//
void inicializaFila (bool flag)
{
	int cont = -1;
	
	/* Flag TRUE:   Opera��o de INICIALIZA��O da Fila Din�mica. */
	/* Flag FALSE:  Opera��o de RESET e LIMPEZA da Fila Din�mica. */
	
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
	
	((cont == 0) || (cont == -1)) ? /* Continue... */ : printf ("\n\nForam limpos %d Blocos de Mem�ria utilizados na Fila Din�mica!", cont);
	
	alce = (struct FilaDinamica *) malloc (sizeof (struct FilaDinamica));
	alce->next = NULL;
	front = alce;
	behind = front;
}
//--------------------------------------------------------//
