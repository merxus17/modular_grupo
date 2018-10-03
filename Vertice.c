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
	int Valor;
	LIS_tppLista Lista_Antecessores;
	LIS_tppLista Lista_Sucessores;
	char *Nome;
}vertice;


vertice* Cria_Vertice(char *nome, int Valor, LIS_tppLista ListaAnt,  LIS_tppLista ListaSuc)
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
	free(v);
}

int setValorVertice(vertice*v,int Valor)
{
	if(v!=NULL)
	{
		v->Valor=Valor;
		return 1;
	}
	return 0;
}


char* getNome(vertice* v)
{
	return v->Nome;
}

int getValor(vertice* v)
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