/***************************************************************************
*  $MCD M�dulo de defini��o: Grafo
*
*  Arquivo gerado:              grafo.h
*  Letras identificadoras:      grafo
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software:
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: ere
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       ere   18/set/2018 in�cio desenvolvimento
*
***************************************************************************/



	#include "LISTA.H"


 /* Tipo refer�ncia para um v�rtice do grafo */

 typedef struct Vertice Vertice;

 /* Tipo refer�ncia para um grafo */
 typedef struct Grafo Grafo;


 /***********************************************************************
*
*  $TC Tipo de dados: grafo Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do grafo
*
***********************************************************************/
typedef enum {

         Grafo_CondRetOK ,
               /* Concluiu corretamente */

         Grafo_CondRetNaoAchou ,
               /* N�o encontrou o valor procurado */

         Grafo_CondRetFaltouMemoria,
               /* Faltou mem�ria ao tentar criar (...)*/
		 		 Grafo_CondRetDeuMerda,

		 	 	 Grafo_CondRetNotFound,
					
				 Grafo_CondRetFimDoGrafo

   } grafo_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o:
*
*  $ED Descri��o da fun��o
*     Cria o grafo alocando a lista de ponteiros para os vertices e a propria lista de vertices e o no corrente como null
*
*  $EP Par�metros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/
   grafo_tpCondRet CriaGrafo(Grafo* ppGrafo);
	/*
		Insere o nó no grafo  e acertar as ligações direcionadas
		pGrafo- ponteiro pro Grafo 
		nome- rotulo do no 
		ListAnt- Lista de Antecessores
		ListSuc-Lista de Sucessores
		Valor-Valor arbitrario atribuido ao no 

	*/
	grafo_tpCondRet Insere_No_Grafo(Grafo* pGrafo,char nome[150], char ant[],char suc[], int Valor);

	/*Acha o Valor de um no através de um nome 
		pGrafo- ponteiro pro Grafo 
		nome- rotulo do no 
		Valor- o valor a ser retornado 
	*/
	grafo_tpCondRet ObterValor(Grafo  *pGrafo, char *nome, int *Valor);
	/*
	 Obtem o valor do no corrente 
	*/
	grafo_tpCondRet ObterValorCorrente(Grafo *pGrafo, int *Valor);
	/* Obtem o primeiro no inserido no grafo */
	grafo_tpCondRet IrInicioGrafo(Grafo *pGrafo);
	/*Obtem o ultimo no inserido no grafo */
	grafo_tpCondRet IrFinalGrafo(Grafo *pGrafo);
	/*Avança o no corrente para frente ou pra tras baseado no n */
	grafo_tpCondRet Avanca_Corrente(Grafo *pGrafo, int n);
	/*Elimina um elemento do grafo */
	grafo_tpCondRet EliminaNo(Grafo  *pGrafo);