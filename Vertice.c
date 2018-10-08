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

void Destroi_Vertice(vertice* v)
{
	if(v!=NULL)
	{
			
			if(v->Lista_Antecessores!=NULL)
			{
				LIS_DestruirLista(v->Lista_Antecessores);
				v->Lista_Antecessores = NULL;
			}
			if (v->Lista_Sucessores != NULL)
			{
				LIS_DestruirLista(v->Lista_Sucessores);
				v->Lista_Sucessores = NULL;
			}
			v->Nome=NULL;
			
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
	if (v != NULL)
	{
		return v->Nome;
	}
	return NULL;
}

void* getValor(vertice* v)
{
	if (v != NULL)
	{
		return v->Valor;
	}
	return NULL;
}

LIS_tppLista getLIS_SUC(vertice*v)
{
	if (v != NULL)
	{
		return v->Lista_Sucessores;
	}
	return NULL;
}

LIS_tppLista getLIS_Ant(vertice*v)
{
	if (v != NULL)
	{
		return v->Lista_Antecessores;

	}
	return NULL;
}

void PrintVertice(vertice* v)
{
	char* x;
	vertice* z=NULL;
	int *i=(int*)(v->Valor);
	printf("No: %s %d \n \n",v->Nome,*i) ;
	printf("lista de antecessores \n");
	IrInicioLista(v->Lista_Antecessores);
	
	z=(vertice*)LIS_ObterValor(v->Lista_Antecessores);

	if(z->Nome!=NULL)
	{
		printf(" %s\n",z->Nome);
	}
		while (LIS_CondRetFimLista !=LIS_AvancarElementoCorrente( v->Lista_Antecessores,1))
		{
			z=(vertice*)LIS_ObterValor(v->Lista_Antecessores);
			if(z!=NULL)
			{
			printf(" %s\n",z->Nome);
			}
		}
	printf("lista de sucessores\n");
	IrInicioLista(v->Lista_Sucessores);
	z=(vertice*)LIS_ObterValor(v->Lista_Sucessores);
	if(z->Nome!=NULL)
	{
		printf(" %s\n",z->Nome);
	}
 		while (LIS_CondRetFimLista !=LIS_AvancarElementoCorrente( v->Lista_Sucessores,1))
		{
			z=(vertice*)LIS_ObterValor(v->Lista_Sucessores);
			if(z!=NULL)
			{
			printf(" %s\n",z->Nome);
		
			}
		}
}
