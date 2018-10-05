#pragma once

#include "LISTA.H"



typedef struct Vertice vertice;

 typedef enum {

         VER_CondRetOK ,
               /* Concluiu corretamente */

         VER_CondRetVertVazio ,
               /* O Vertice n�o cont�m elementos */


   } VER_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o:
*	Cria Vertice
*  $ED Descri��o da fun��o
*       Aloca espa�o e cria um Vertice incluindo seu nome valor e uma Lista de Antecessores e outra de Sucessores
*  $EP Par�metros
*		nome - Nome do Vertice
*		Valor - Valor inteiro do Vertice
*		ListaAnt - Lista que guarda os Vertices anteriores
*		ListaSuc - Lista que guarda os Vertices sucessores
*
*  $FV Valor retornado
*	Retorna um ponteiro do tipo estruturado vertice
*
***********************************************************************/
vertice* Cria_Vertice(char *nome, int Valor, LIS_tppLista ListaAnt,  LIS_tppLista ListaSuc);

/***********************************************************************
*
*  $FC Fun��o:
*	setValorVertice
*  $ED Descri��o da fun��o
*      Altera o valor do Vertice recebido
*  $EP Par�metros
*		v - Vertice a ser alterado
*		Valor - Novo valor do vertice
*
*  $FV Valor retornado
*	 VER_CondRetOK se conseguiu alterar o valor do vertice
*	  VER_CondRetVertVazio se o ponteiro de vertice fornecido esta vazio
*
***********************************************************************/
VER_tpCondRet setValorVertice(vertice*v,int Valor);

void Destroi_Vertice(vertice *v);


char* getNome(vertice* v);
int getValor(vertice* v);
LIS_tppLista getLIS_SUC(vertice*v);
LIS_tppLista getLIS_Ant(vertice*v);


void PrintVertice(vertice* v);
