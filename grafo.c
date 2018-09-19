
  #include   <stdio.h>
  #include   <string.h>
  #include   <memory.h>
  #include   <malloc.h>
  #include   <assert.h>

/* Possui 3 membros :
  1- ponteiroheads q aponta para os vertices de forma similar a uma lista de adjacencias
  2- ponteirosVertices aguarda as estruturas dos vertices , estou considerando usar apenas um vetor ja que ponteirosHead já aponta pro Vertices
  3-No_Corrente aponta para no corrente */
  typedef struct Grafo
    {
      LIS_tppLista* ponteirosHead;

      LIS_tppLista* ponteirosVertices;

      void* No_Corrente;

    }
/* Acredito ser auto explicativo*/
    typedef struct Vertices
    {
      LIS_tppLista* Lista_Antecessores;
      LIS_tppLista* Lista _Sucessores;
      char Nome [150];
    }

/*Cria o grafo alocando a lista de ponteiros pros vertices e a propria lista de vertices e o no corrente como null */

    Grafo* CriaGrafo(void)
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
      return Grafo_CondRetOK;
    }
