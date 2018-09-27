#pragma once

#include "LISTA.H"



typedef struct Vertice vertice;

vertice* Cria_Vertice(char *nome, int Valor);




void Destroi_Vertice(vertice *v);


char* getNome(vertice* v);
int getValor(vertice* v);
LIS_tppLista getLIS_SUC(vertice*v);
LIS_tppLista getLIS_Ant(vertice*v);