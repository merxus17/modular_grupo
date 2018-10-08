 #include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include "Vertice.h"

/***************************************************
*
* $TC Tipo de dado:	Elemento do Grafo
*
*
****************************************************/
typedef struct Vertice
{
	void* Valor;
	LIS_tppLista Lista_Antecessores;
	LIS_tppLista Lista_Sucessores;
	char *Nome;
}vertice;


vertice* Cria_Vertice(char *nome, void* Valor, LIS_tppLista ListaAnt,  LIS_tppLista ListaSuc)
{
	vertice* novo = (vertice*)malloc(sizeof(vertice));
	novo->Nome = nome;
	novo->Valor = Valor;
	novo->Lista_Antecessores = ListaAnt;
	novo->Lista_Sucessores = ListaSuc;
	return novo;

}

void Destroi_Vertice(void* v)
{
	if(v!=NULL)
	{
			vertice* x=(vertice*)v;
			if(x->Lista_Antecessores!=NULL)
			{
				free(x->Lista_Antecessores);
			}
			if(x->Lista_Sucessores!=NULL)
				free(x->Lista_Sucessores);
			if(x->Nome)
			free(x->Nome);
	
			free(v);
	}
}

VER_tpCondRet setValorVertice(vertice*v,void* Valor)
{
	if(v!=NULL)
	{
		v->Valor=Valor;
		return VER_CondRetOK;
	}
	return VER_CondRetVertVazio;
}


char* getNome(vertice* v)
{
	return v->Nome;
}

void* getValor(vertice* v)
{
	return v->Valor;
}

LIS_tppLista getLIS_SUC(vertice*v)
{
	return v->Lista_Sucessores;
}

LIS_tppLista getLIS_Ant(vertice*v)
{
	return v->Lista_Antecessores;
}

void PrintVertice(vertice* v)
{
	char* x;
	vertice* z;
	//LIS_tpCondRet z=LIS_CondRetOK;
	printf("No: %s %d \n \n",v->Nome,v->Valor) ;
	IrInicioLista(v->Lista_Antecessores);
	z=(vertice*)LIS_ObterValor(v->Lista_Antecessores);
	printf("lista de antecessores \n %s\n",z->Nome);
	/*x=(char*)LIS_ObterValor(v->Lista_Antecessores);
	printf("lista de antecessores\n %s\n",x);*/
		while (LIS_CondRetFimLista !=LIS_AvancarElementoCorrente( v->Lista_Antecessores,1))
		{
			z=(vertice*)LIS_ObterValor(v->Lista_Antecessores);
			printf(" %s\n",z->Nome);
			/*x=(char*)LIS_ObterValor(v->Lista_Antecessores);
			printf(" %s\n",x);*/
		}
	//z=LIS_CondRetOK;
	IrInicioLista(v->Lista_Sucessores);
	x=(char*)LIS_ObterValor(v->Lista_Sucessores);
	printf("lista de sucessores\n %s\n",x);
 		while (LIS_CondRetFimLista !=LIS_AvancarElementoCorrente( v->Lista_Sucessores,1))
		{
			x=(char*)LIS_ObterValor(v->Lista_Sucessores);
			printf(" %s\n",x);
		}
}