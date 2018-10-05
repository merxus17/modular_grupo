#pragma once

#include "LISTA.H"



typedef struct Vertice vertice;

 typedef enum {

         VER_CondRetOK ,
               /* Concluiu corretamente */

         VER_CondRetVertVazio ,
               /* O Vertice não contém elementos */


   } VER_tpCondRet ;

/***********************************************************************
*
*  $FC Função:
*	Cria Vertice
*  $ED Descrição da função
*       Aloca espaço e cria um Vertice incluindo seu nome valor e uma Lista de Antecessores e outra de Sucessores
*  $EP Parâmetros
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
*  $FC Função:
*	setValorVertice
*  $ED Descrição da função
*      Altera o valor do Vertice recebido
*  $EP Parâmetros
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
