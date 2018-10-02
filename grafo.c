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
	  7		  Rodrigo  27/09/2018   Criando as funções de navegação manual 
      6		  Rodrigo  27/09/2018	Criando as funções obtervalor e procurar , estudando navegação "manual" do grafo 
	  5       Rodrigo  26/07/2018   Termino da implementação da inserção e implementação da função obtervalorcorrente
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
  #include   "Vertice.h"
  

  /* Acredito ser auto explicativo
Obs.: nada é auto explicativo quando se quer um 10*/


typedef struct Vertice Vertice;

   

/***************************************************
*
* $TC Tipo de dado: Estrutura do grafo
*
*
****************************************************/
  typedef struct Grafo
    {
      LIS_tppLista ponteirosHead;
			/*que aponta para os vertices de forma similar a uma lista de adjacencias*/

    //  Vertice* ponteirosVertices;
			/*aguarda as estruturas dos vertices , estou considerando usar apenas um vetor ja que ponteirosHead já aponta pro Vertices*/

      Vertice* No_Corrente;
			 /*No_Corrente aponta para no corrente */

    }Grafo;




/*Cria o grafo alocando a lista de ponteiros para os vertices e a propria lista de vertices e o no corrente como null */
     grafo_tpCondRet CriaGrafo(Grafo* ppGrafo)
    {
		
	  Grafo *pGrafo=(Grafo*)malloc(sizeof(Grafo));
	  printf("%p %p \n",&ppGrafo,pGrafo);
	  if(pGrafo==NULL)
      {
        return Grafo_CondRetFaltouMemoria;
      }
	 
      pGrafo->ponteirosHead=LIS_CriarLista(NULL);
     // ponteiroGrafo->ponteirosVertices=NULL;
      pGrafo->No_Corrente=NULL;

	  ppGrafo=pGrafo;
	  printf("%p %p %p\n",&ppGrafo,ppGrafo,pGrafo);
      return Grafo_CondRetOK;
    }
	 


	 /* Retorna aos nós ja inseridos e atualiza suas listas de antessesor e sucessor */
    void Completa_Arestas ( Grafo* grafo ,vertice* no, LIS_tppLista Ant ,LIS_tppLista Suc)
    {
      LIS_tpCondRet x=LIS_CondRetOK;
      void* p;
	  vertice* v;
      IrInicioLista( Ant ) ;
      while(x!=2)
      {
        p=LIS_ObterValor(Ant);
        x=LIS_ProcurarValor(grafo->ponteirosHead , p) ;
        //atualizar as listas aki
		v=(vertice*)LIS_ObterValor(grafo->ponteirosHead);
		x=LIS_InserirElementoApos( getLIS_SUC(v), no);
        x=LIS_AvancarElementoCorrente( Ant , 1 ) ;

      }
      IrInicioLista( Suc ) ;
      while(x!=2)
      {
        p=LIS_ObterValor(Suc);
        x=LIS_ProcurarValor(grafo->ponteirosHead , p) ;
        //atualizar as listas aki
		v =(vertice*) LIS_ObterValor(grafo->ponteirosHead);
		x = LIS_InserirElementoApos(getLIS_Ant(v), no);
        x=LIS_AvancarElementoCorrente( Suc , 1 ) ;

      }

	  return;
    }


/*A função recebe o grafo no qual vai inserir , o nome do Vertice a ser inserido
e as listas de vertices succesores e antecessores.Cria o vertice dinamicamente e insere ele no grafo , depois disso
cria e preenche as listas tanto dele quanto daqueles q ele afeta*/
    grafo_tpCondRet Insere_No_Grafo(Grafo* pGrafo,char nome[150], char ant[][15],char suc[][15], int Valor)
    {
	  int i;
	   Vertice* novo;
	  LIS_tpCondRet retVertice;
      LIS_tppLista ListaSuc=LIS_CriarLista(NULL);
      LIS_tppLista ListaAnt=LIS_CriarLista(NULL);
	  for(i=0;i<3;i++)
	  {
		LIS_InserirElementoApos( ListaAnt, &ant[i]);
	    
	  }

	  for(i=0;i<2;i++)
	  {
		LIS_InserirElementoApos( ListaAnt, &suc[i]);
	  
	  }
      
	  novo = Cria_Vertice( nome,  Valor, ListaAnt , ListaSuc);
	  
      retVertice=LIS_InserirElementoApos(pGrafo->ponteirosHead , novo);
      if(retVertice!=LIS_CondRetOK)
      {
        return Grafo_CondRetDeuMerda;/*isso é TEMPORARIO*/
      }
      Completa_Arestas(pGrafo,novo,ListaAnt,ListaSuc);
	  pGrafo->No_Corrente = novo;
      return Grafo_CondRetOK;
    }
	
	

	/* Obtem o nome do nó Corrente
	  pgrafo- ponteiro para o grafo
	  Valor - ponteiro que recebe o valor */
	grafo_tpCondRet ObterValorCorrente(Grafo* pGrafo, int* Valor)
	{
		if(pGrafo->No_Corrente)
		{
			return Grafo_CondRetNotFound;
		}
		*Valor = getValor(pGrafo->No_Corrente);
		return Grafo_CondRetOK;
	}


	
	/*Trecho em Obra  ,Desculpe o transtorno   */
	void Procura_No(Grafo* pGrafo, char* nome)
	{
		//SeiLÀ	dfs
		LIS_tppLista visitados;
		IrInicioLista(pGrafo->ponteirosHead);
		visitados = LIS_CriarLista(NULL);
		while (strcmp(getNome(pGrafo->No_Corrente) ,nome)!=0)
		{ 
			LIS_AvancarElementoCorrente(pGrafo->ponteirosHead, 1);			
		}
			
			/*for each w adjacent to i
				if (!visited[w])
					DFS(w);*/

		
	
	}



	/*Acha o valor em qualquer no do grafo 
		pgrafo- ponteiro para o grafo
		nome - nome do nó
		Valor - ponteiro que recebe o valor 
		*/
	grafo_tpCondRet ObterValor(Grafo* pGrafo, char* nome, int* Valor)
	{
		grafo_tpCondRet x;
		Procura_No(pGrafo, nome);
		x = ObterValorCorrente(pGrafo, Valor);
		return Grafo_CondRetOK;
	}



	/*Torna o primeiro Vertice o no corrente*/
	grafo_tpCondRet IrInicioGrafo(Grafo* pGrafo)
	{
		IrInicioLista(pGrafo->ponteirosHead);
		return Grafo_CondRetOK;
	}


	/*Torna o primeiro Vertice o no corrente*/
	grafo_tpCondRet IrFinalGrafo(Grafo* pGrafo)
	{
		IrFinalLista(pGrafo->ponteirosHead);
		return Grafo_CondRetOK;
	
	
	}
	

	/* Eduardo e evelyn ver a função  LIS_AvancarElementoCorrente funciona igualzinho*/
	grafo_tpCondRet Avanca_Corrente(Grafo* pGrafo, int n)
	{
		LIS_tpCondRet x;
		x = LIS_AvancarElementoCorrente(pGrafo->ponteirosHead, n);
		if (x == LIS_CondRetFimLista)
		{
			return Grafo_CondRetFimDoGrafo;
		}

		return Grafo_CondRetOK;
	}

	/* A Função chama a função de eliminar o elemento da lista, tanto na lista de antecessores quanto na de sucessores e depois remove o elemento em sí*/
	grafo_tpCondRet EliminaNo(Grafo  *pGrafo)
	{
		vertice* v;
		LIS_tppLista Ant=LIS_CriarLista(NULL);
		LIS_tppLista Suc=LIS_CriarLista(NULL);
		v=pGrafo->No_Corrente;
		Suc=getLIS_SUC(v);
		Ant=getLIS_Ant(v) ;
		while(LIS_AvancarElementoCorrente(Ant,0)!=LIS_CondRetListaVazia) 
		{
			if(LIS_ObterValor(Ant)==v)
				{
					LIS_ExcluirElemento(Ant);
				}
		}
		while(LIS_AvancarElementoCorrente(Suc,0)!=LIS_CondRetListaVazia) 
		{
			if(LIS_ObterValor(Suc)==v)
				{
					LIS_ExcluirElemento(Suc);
				}
		}
		LIS_ExcluirElemento(getLIS_SUC(v)) ;
		LIS_ExcluirElemento(getLIS_Ant(v)) ;
		Destroi_Vertice(v);
		return Grafo_CondRetOK;
	}








