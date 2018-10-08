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


/***********************************************************************
*
*  $FC Função: 
*		Destroi Vertice
*  $ED Descrição da função
*     Destrói o vertice fornecido.
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/
void Destroi_Vertice(void *v);

/***********************************************************************
*
*  $FC Função:
*	getNome
*  $ED Descrição da função
*      Devolve o nome do Vertice recebido
*  $EP Parâmetros
*		v - Vertice contendo o nome
*
*  $FV Valor retornado
*	char* com o nome do Vertice
*
***********************************************************************/

char* getNome(vertice* v);


/***********************************************************************
*
*  $FC Função:
*	getValor
*  $ED Descrição da função
*      Devolve o valor do Vertice recebido
*  $EP Parâmetros
*		v - Vertice contendo o valor
*
*  $FV Valor retornado
*	void* com o Valor do vertice
*
***********************************************************************/

void* getValor(vertice* v);


LIS_tppLista getLIS_SUC(vertice*v);
LIS_tppLista getLIS_Ant(vertice*v);

/***********************************************************************
*
*  $FC Função:
*	PrintVertice
*  $ED Descrição da função
*      Imprime na tela o Nome, Valor e as listas de sucessores e antecessores do Vertice
*  $EP Parâmetros
*		v - Vertice a ser impresso
*
*  $FV Valor retornado
*	A função retorna void após imprimir os valores
*
***********************************************************************/
void PrintVertice(vertice* v);
