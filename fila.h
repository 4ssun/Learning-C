#define fila_h
#include <stdio.h> 
#define MAX 10000
/* Uma estrutura chamada "queue" com 3 campos e 
   definimos como tipo Fila   */
typedef struct queue
{	int vetor[MAX];
	int ini, fim;	
}Fila;

//Declarações de subprogramas:
void inicFila(Fila *fila);
int filaVazia(Fila *fila);
int filaCheia(Fila *fila);
void insereFila(Fila *fila, int e);
int removeFila(Fila *fila);
void liberaFila(Fila *fila);
void exibeFila(Fila *fila);
int tamanhoFila(Fila *fila);

//Um procedimento para iniciar uma estrurua fila
void inicFila(Fila *fila)
{
	fila->ini = 0;
	fila->fim = 0;
}
//Uma função para verificar se a fila está vazia
int filaVazia(Fila *fila)
{
	if (fila->ini == fila->fim)
		return 1;
	else
		return 0;		
}
//Uma função para verificar se a fila está cheia
int filaCheia(Fila *fila)
{
	if(fila->fim > MAX-1)
		return 1;
	else
		return 0;
}
//Um procedimento para inserir um elemento na fila
void insereFila(Fila *fila, int e)
{
	if(!filaCheia(fila))
	{
		fila->vetor[fila->fim] = e;
		fila->fim++;
	}
}
//Uma função para remover um elemento na fila e retorna este elemento
int removeFila(Fila *fila)
{   int e;	
	if(!filaVazia(fila))
	{
		e = fila->vetor[fila->ini];
		fila->ini++;
		return e;
	}
	
}
//Um procedimento para liberar fila
void liberaFila(Fila *fila)
{
	fila->ini = 0;
	fila->fim = 0;
}
//Um procedimento para mostrar os elementos na fila
void exibeFila(Fila *fila)
{
	int i;
	for(i = fila->ini; i < fila->fim; i++)
		printf("%d ->", fila->vetor[i]);
}
//Uma função para retornar o tamanho da fila
int tamanhoFila(Fila *fila)
{
	if (filaVazia(fila))
	   return 0;
	else
	   return (fila->fim - fila->ini + 1); 
}

