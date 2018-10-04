#pragma once

#include "LISTA.H"



typedef struct Vertice vertice;

 typedef enum {

         VER_CondRetOK ,
               /* Concluiu corretamente */

         VER_CondRetVertVazio ,
               /* O Vertice n�o cont�m elementos */


   } VER_tpCondRet ;

vertice* Cria_Vertice(char *nome, int Valor, LIS_tppLista ListaAnt,  LIS_tppLista ListaSuc);


int setValorVertice(vertice*v,int Valor);

void Destroi_Vertice(vertice *v);


char* getNome(vertice* v);
int getValor(vertice* v);
LIS_tppLista getLIS_SUC(vertice*v);
LIS_tppLista getLIS_Ant(vertice*v);