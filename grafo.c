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

	  9		  Eduardo  03/10/2018   Esqueci que tinha que datar essas coisas, mas finalmente terminei a EliminaNo com assertiva
	 
	  8       Rodrigo  02/10/2018   Conserto das funções cria insereobtem e procura mediante testes 

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

    

     // Vertice* No_Corrente;
			 /*No_Corrente aponta para no corrente */

    }Grafo;




/*Cria o grafo alocando a lista de ponteiros para os vertices e a propria lista de vertices e o no corrente como null */
     grafo_tpCondRet CriaGrafo(Grafo** ppGrafo)
    {
		
	  Grafo *pGrafo=(Grafo*)malloc(sizeof(Grafo));
	 
	  if(pGrafo==NULL)
      {
        return Grafo_CondRetFaltouMemoria;
      }
	 
      pGrafo->ponteirosHead=LIS_CriarLista(Destroi_Vertice);
      *ppGrafo=pGrafo;
	
      return Grafo_CondRetOK;
    }
	 
	 int Compara_Ant(LIS_tppLista lista, char* nome)
	 {
		 char* nomeLista;
		 LIS_tpCondRet x=LIS_CondRetOK;
		 IrInicioLista(lista);
		 while(x!=LIS_CondRetListaVazia && x!=LIS_CondRetFimLista)
		{
			nomeLista=(char*)LIS_ObterValor(lista);
			if(strcmp(nomeLista,nome)==0)
			{
				return 0;
			}
			x=LIS_AvancarElementoCorrente( lista , 1 ) ;
		 }
	 return 1 ;
	 }

	 /* Retorna aos nós ja inseridos e atualiza suas listas de antessesor e sucessor */
    void Completa_Arestas ( Grafo* grafo ,vertice* no, LIS_tppLista Ant ,LIS_tppLista Suc)
    {
	  int i=0;
      LIS_tpCondRet x=LIS_CondRetOK;
      char* p;
	  vertice*z;
	  vertice* v;
      IrInicioLista( Ant ) ;
      while(x!=LIS_CondRetListaVazia && x!=LIS_CondRetFimLista)
      {
        z=(vertice*)LIS_ObterValor(Ant);
		if(z!=NULL)
		{
			i=Procura_No(grafo , getNome(z)) ;
			if(i==1)
			{
				v=(vertice*)LIS_ObterValor(grafo->ponteirosHead);
				if(Compara_Ant(getLIS_SUC(v),getNome(no)))
				{
				x=LIS_InserirElementoApos( getLIS_SUC(v), getNome(no));
			
				}
			}
		}
		x=LIS_AvancarElementoCorrente( Ant , 1 ) ;
      }
	  x=LIS_CondRetOK;
      IrInicioLista( Suc ) ;
      while(x!=LIS_CondRetListaVazia  &&  x!=LIS_CondRetFimLista)
      {
        p=(char*)LIS_ObterValor(Suc);
		if(p!=NULL)
		{	
			i=Procura_No(grafo , p) ;
			if(i==1)
			{
				v =(vertice*) LIS_ObterValor(grafo->ponteirosHead);
				x = LIS_InserirElementoApos(getLIS_Ant(v), no);
			
			}
		}
		x=LIS_AvancarElementoCorrente( Suc , 1 ) ;
      }

	  return;
    }


/*A função recebe o grafo no qual vai inserir , o nome do Vertice a ser inserido
e as listas de vertices succesores e antecessores.Cria o vertice dinamicamente e insere ele no grafo , depois disso
cria e preenche as listas tanto dele quanto daqueles q ele afeta*/
    grafo_tpCondRet Insere_No_Grafo(Grafo* pGrafo,char nome[150], int Valor,char ant[][150],int a,char suc[][150],int s )
    {
	  int i,g;
	  //int j,k;
	   Vertice* novo;
	   Vertice* v;
	  LIS_tpCondRet retVertice;
      LIS_tppLista ListaSuc=LIS_CriarLista(Destroi_Vertice);
      LIS_tppLista ListaAnt=LIS_CriarLista(Destroi_Vertice);
	  novo = Cria_Vertice( nome,  Valor, ListaAnt , ListaSuc);
	  retVertice=LIS_InserirElementoApos(pGrafo->ponteirosHead , novo);
      if(retVertice!=LIS_CondRetOK)
      {
        return Grafo_CondRetDeuMerda;
      }
	  for(i=0;i<a;i++)
	  {
		g=Procura_No(pGrafo, ant[i]);
		
		if(g==1)
		{
			v=(vertice*)LIS_ObterValor(pGrafo->ponteirosHead);
			LIS_InserirElementoApos( ListaAnt, v );
		}
	  }

	  for(i=0;i<s;i++)
	  {
		LIS_InserirElementoApos( ListaSuc, &suc[i]);
	  
	  }
      
	 
      Completa_Arestas(pGrafo,novo,ListaAnt,ListaSuc);
	  return Grafo_CondRetOK;
    }
	
	

	/* Obtem o nome do nó Corrente
	  pgrafo- ponteiro para o grafo
	  Valor - ponteiro que recebe o valor */
	grafo_tpCondRet ObterValorCorrente(Grafo* pGrafo, int* Valor)
	{
		Vertice* Corrente = (Vertice*)LIS_ObterValor(pGrafo->ponteirosHead);
		if(Corrente==NULL)
		{
			return Grafo_CondRetGrafoVazio;
		}
		*Valor = getValor(Corrente);
		return Grafo_CondRetOK;
	}


	
	/*Trecho em Obra  ,Desculpe o transtorno   */
	int  Procura_No(Grafo* pGrafo, char* nome)
	{

		LIS_tpCondRet x;
		
		IrInicioLista(pGrafo->ponteirosHead );
		while (strcmp(getNome((vertice*)LIS_ObterValor(pGrafo->ponteirosHead)) ,nome)!=0)
		{ 
			x=LIS_AvancarElementoCorrente(pGrafo->ponteirosHead, 1);
			if(x==LIS_CondRetFimLista)
			{
				
				return 0;
			}
			if (x ==LIS_CondRetListaVazia)
			{
				return -1;
			}
		}	

	return 1;
	}




	/*Acha o valor em qualquer no do grafo 
		pgrafo- ponteiro para o grafo
		nome - nome do nó
		Valor - ponteiro que recebe o valor 
		*/
	grafo_tpCondRet ObterValor(Grafo* pGrafo, char* nome, int* Valor)
	{

		int p =Procura_No(pGrafo, nome);
		if (p==0)
		{
			*Valor=NULL;
			return Grafo_CondRetNotFound;
		}
		if(p==-1)
		{
			*Valor = NULL;
			return Grafo_CondRetGrafoVazio;
		}
		*Valor=getValor((vertice*)LIS_ObterValor(pGrafo->ponteirosHead));
		return Grafo_CondRetOK;
	}


	grafo_tpCondRet setValor(Grafo* pGrafo, char* nome ,int Valor)
	{
		int p ,s ;
		p=Procura_No(pGrafo, nome);
		if (p==0)
		{
			
			return Grafo_CondRetNotFound;
		}
		if (p == -1)
		{
			return Grafo_CondRetGrafoVazio;
		}
		s=setValorVertice((vertice*)LIS_ObterValor(pGrafo->ponteirosHead), Valor);
		if(s==0)
		{
		  return Grafo_CondRetDeuMerda;
		}
		return Grafo_CondRetOK;

	
	}


	/*Torna o primeiro Vertice o no corrente*/
	grafo_tpCondRet IrInicioGrafo(Grafo* pGrafo)
	{
		vertice* v;
		IrInicioLista(pGrafo->ponteirosHead);
		v=(vertice*)LIS_ObterValor(pGrafo->ponteirosHead);
		if(v==NULL)
		{
		return Grafo_CondRetGrafoVazio;
		}
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
		if (x == LIS_CondRetListaVazia)
		{
			return Grafo_CondRetGrafoVazio;
		}

		return Grafo_CondRetOK;
	}


	
	/* A Função chama a função de eliminar o elemento da lista, tanto na lista de antecessores quanto na de sucessores e depois remove o elemento em sí*/
	grafo_tpCondRet EliminaNo(Grafo  *pGrafo,char* nome )
	{
		vertice* v;
		vertice* a;
		LIS_tppLista Ant=LIS_CriarLista(Destroi_Vertice);
		LIS_tppLista Suc=LIS_CriarLista(Destroi_Vertice);
		LIS_tppLista AuxAnt=LIS_CriarLista(Destroi_Vertice);
		LIS_tppLista AuxSuc=LIS_CriarLista(Destroi_Vertice);
		int i=Procura_No(pGrafo, nome);
		if (i == 0)
		{
			return Grafo_CondRetNotFound;
		}
		
		v=(vertice*)LIS_ObterValor(pGrafo->ponteirosHead);
		if(v==NULL)
		{
			return Grafo_CondRetGrafoVazio;
		}
		Suc=getLIS_SUC(v);
		Ant=getLIS_Ant(v) ;
		a=(vertice*)LIS_ObterValor(Ant);
		a=(vertice*)LIS_ObterValor(Ant);
		a=(vertice*)LIS_ObterValor(Ant);
		AuxAnt=getLIS_Ant(a) ;
		AuxSuc=getLIS_SUC(a);
		while(LIS_AvancarElementoCorrente(Ant,1)!=LIS_CondRetFimLista) 
		{
			LIS_AvancarElementoCorrente(Ant,-1);
			a=(vertice*)LIS_ObterValor(Ant);
			AuxSuc=getLIS_SUC(a);
			while(LIS_ObterValor(AuxSuc)!=v)
			{
				LIS_AvancarElementoCorrente(AuxSuc,1);
			}
			LIS_ExcluirElemento(AuxSuc) ;
			LIS_AvancarElementoCorrente(Ant,1);
		}
		while(LIS_AvancarElementoCorrente(Suc,1)!=LIS_CondRetFimLista) 
		{
			LIS_AvancarElementoCorrente(Suc,-1);
			a=(vertice*)LIS_ObterValor(Suc);
			AuxAnt=getLIS_Ant(a);
			while(LIS_ObterValor(AuxAnt)!=v)
			{
				LIS_AvancarElementoCorrente(AuxAnt,1);
			}
			LIS_ExcluirElemento(AuxAnt) ;
			LIS_AvancarElementoCorrente(Suc,1);
		}
		LIS_ExcluirElemento(getLIS_SUC(v)) ;
		LIS_ExcluirElemento(getLIS_Ant(v)) ;
		Destroi_Vertice(v);
		return Grafo_CondRetOK;
	}




	void PrintGrafo (Grafo* pGrafo)
	{
		//LIS_tpCondRet x=LIS_CondRetOK;
		vertice* v;
		IrInicioLista(pGrafo->ponteirosHead );
		v=(vertice*)LIS_ObterValor(pGrafo->ponteirosHead);
		PrintVertice(v);
		while (LIS_CondRetFimLista !=LIS_AvancarElementoCorrente( pGrafo->ponteirosHead,1))
		{
			v=(vertice*)LIS_ObterValor(pGrafo->ponteirosHead);
			PrintVertice(v);
		}
	}



