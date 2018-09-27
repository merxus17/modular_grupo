 #include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include "Vertice.h"


typedef struct Vertice
{
	int Valor;
	LIS_tppLista Lista_Antecessores;
	LIS_tppLista Lista_Sucessores;
	char *Nome;
}vertice;


vertice* Cria_Vertice(char* nome, int Valor)
{
	vertice* novo = (vertice*)malloc(sizeof(vertice));
	novo->Nome = nome;
	novo->Valor = Valor;
	novo->Lista_Antecessores = LIS_CriarLista(NULL);
	novo->Lista_Sucessores = LIS_CriarLista(NULL);
	return novo;

}

void Destroi_Vertice(vertice* v)
{
	free(v);
}