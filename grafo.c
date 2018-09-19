/***************************************************************************
*  $MCI Módulo de implementação: Grafo
*
*  Arquivo gerado:              grafo.c
*  Letras identificadoras:      grafo
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software:
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: ere   - Eduardo Junqueira, Rodrigo Monteiro, Evelyn Rhaiara
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data         Observações
*     3       Evelyn   19/set/2018  Testes da função de criação
      2       Rodrigo  18/set/2018  início desenvolvimento , implementação da função de criação
      1       Rodrigo  15/set/2018  Estudo do modulo lista e da estrutura do modulo grafo
*
***************************************************************************/
  #include   <stdio.h>
  #include   <string.h>
  #include   <memory.h>
  #include   <malloc.h>
  #include   <assert.h>
  #include	 "grafo.h"
  #include "LISTA.h"

/***************************************************
*
* $TC Tipo de dado: Estrutura do grafo
*
*
****************************************************/
  typedef struct Grafo
    {
      LIS_tppLista* ponteirosHead;
			/*que aponta para os vertices de forma similar a uma lista de adjacencias*/

      LIS_tppLista* ponteirosVertices;
			/*aguarda as estruturas dos vertices , estou considerando usar apenas um vetor ja que ponteirosHead já aponta pro Vertices*/

      void* No_Corrente;
			 /*No_Corrente aponta para no corrente */

    }Grafo;


  /* Acredito ser auto explicativo
Obs.: nada é auto explicativo quando se quer um 10*/


  /***************************************************
  *
  * $TC Tipo de dado:	Elemento do Grafo
  *
  *
  ****************************************************/

    typedef struct Vertices
    {
      int Valor;
      LIS_tppLista* Lista_Antecessores;
      LIS_tppLista* Lista_Sucessores;
      char Nome [150];
    }Vertices;

/*Cria o grafo alocando a lista de ponteiros para os vertices e a propria lista de vertices e o no corrente como null */

     grafo_tpCondRet CriaGrafo(void* pGrafo)
    {
      Grafo* ponteiroGrafo;
      ponteiroGrafo=(Grafo*)malloc(sizeof(Grafo));
      if(ponteiroGrafo==NULL)
      {
        return Grafo_CondRetFaltouMemoria;
      }

      ponteiroGrafo->ponteirosHead=LIS_CriarLista(Função de excluir valor);
      ponteiroGrafo->ponteirosVertices=LIS_CriarLista(Função de excluir valor);
      ponteiroGrafo->No_Corrente=NULL;
      pGrafo=ponteiroGrafo;
      return Grafo_CondRetOK;
    }



    grafo_tpCondRet InsereGrafo(void* pGrafo, int valor , char orig[][],char dest[])
    {
      LIS_tpCondRet ret;
      ret=LIS_InserirElementoApos(*pGrafo->ponteirosHead , &valor);
      if(ret!=LIS_CondRetOK)
      {
        return Grafo_CondRetDeuMerda;/*isso é TEMPORARIO*/
      }



    }
