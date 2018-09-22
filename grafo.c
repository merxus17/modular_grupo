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
*     4       Rodrigo  21/set/2018  Implementação da função de inserção
      3       Evelyn   19/set/2018  Testes da função de criação
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

      Vertice* ponteirosVertices;
			/*aguarda as estruturas dos vertices , estou considerando usar apenas um vetor ja que ponteirosHead já aponta pro Vertices*/

      Vertice* No_Corrente;
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

    typedef struct Vertice
    {
      int Valor;
      LIS_tppLista* Lista_Antecessores;
      LIS_tppLista* Lista_Sucessores;
      char Nome [150];
    }Vertice;

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
      ponteiroGrafo->ponteirosVertices=NULL;
      ponteiroGrafo->No_Corrente=NULL;
      pGrafo=ponteiroGrafo;
      return Grafo_CondRetOK;
    }


/*A função recebe o grafo no qual vai inserir , o nome do Vertice a ser inserido
e as listas de vertices succesores e antecessores.Cria o vertice dinamicamente e insere ele no grafo , depois disso
cria e preenche as listas tanto dele quanto daqueles q ele afeta*/
    grafo_tpCondRet Insere_No_Grafo(void* pGrafo,char nome[150], LIS_tppLista ListaAnt,LIS_tppLista ListaSuc)
    {
      int i,j;
      LIS_tpCondRet retVertice,retAnt,retSuc;
      Vertice* novo =(Vertice*)malloc(sizeof(Vertice))
      novo->Nome=nome;
      novo.Valor=NULL;
      novo->Lista_Antecessores=LIS_CriarLista(NULL);
      novo->Lista_Sucessores=LIS_CriarLista(NULL);
      retVertice=LIS_InserirElementoApos(*pGrafo->ponteirosHead , &novo);
      if(ret!=LIS_CondRetOK)
      {
        return Grafo_CondRetDeuMerda;/*isso é TEMPORARIO*/
      }
      novo->Lista_Antecessores=ListaAnt;
      novo->Lista_Sucessores=ListaSuc;
      Completa_Arestas(novo,ListaAnt,ListaSuc);

      return Grafo_CondRetOK;
    }


    void Completa_Arestas (Vertice* no, LIS_tppLista Ant ,LIS_tppLista Suc)
    {
      for(gg)


    }
