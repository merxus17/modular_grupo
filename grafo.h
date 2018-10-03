/***************************************************************************
*  $MCD Módulo de definiçãoo: Grafo
*
*  Arquivo gerado:              grafo.h
*  Letras identificadoras:      grafo
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software:
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: ere
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       ere   18/set/2018 início desenvolvimento
*
***************************************************************************/



#include "LISTA.H"


 /* Tipo referência para um vértice do grafo */

 typedef struct Vertice Vertice;

 /* Tipo referência para um grafo */
 typedef struct Grafo Grafo;


 /***********************************************************************
*
*  $TC Tipo de dados: grafo Condições de retorno
*
*  $ED Descriçõeo do tipo
*     Condições de retorno das funções do grafo
*
***********************************************************************/
typedef enum {

         Grafo_CondRetOK ,
               /* Concluiu corretamente */

         Grafo_CondRetNaoAchou ,
               /* Não encontrou o valor procurado */

         Grafo_CondRetFaltouMemoria,
               /* Faltou memória ao tentar criar */
	 Grafo_CondRetDeuMerda,
		/* */
		
	 Grafo_CondRetNotFound,
		/**/		
	 Grafo_CondRetFimDoGrafo,
		/**/
	 Grafo_CondRetGrafoVazio
		/**/

   } grafo_tpCondRet ;


/***********************************************************************
*
*  $FC Função:
*	Cria Grafo
*  $ED Descrição da função
*       Cria o grafo alocando a lista de ponteiros para os vertices e a propria lista de vertices e o no corrente como null
*  $EP Parâmetros
*	
*
*  $FV Valor retornado
*
*
***********************************************************************/
   grafo_tpCondRet CriaGrafo(Grafo** ppGrafo);


/**********************************************************************
* $FC Função:
*	Insere No Grafo
* $ED Descrição da função
*		Insere o nó no grafo  e acertar as ligações direcionadas
* $EP Parâmetros
*		pGrafo- ponteiro pro Grafo 
*		nome- rotulo do no 
*		ListAnt- Lista de Antecessores
*		ListSuc-Lista de Sucessores
*		Valor-Valor arbitrario atribuido ao no 
* $FV Valor retornado
***********************************************************************/
	grafo_tpCondRet Insere_No_Grafo(Grafo* pGrafo,char nome[150], char ant[],char suc[], int Valor);

/***********************************************************************
* $FC Função:
*	Obter Valor
* $ED Descrição da função:
*	Acha o Valor de um no através de um nome 
* $EP Parâmetros:
*		pGrafo- ponteiro pro Grafo 
*		nome- rotulo do no 
*		Valor- o valor a ser retornado 
* $FV Valor retornado:
*************************************************************************/
	grafo_tpCondRet ObterValor(Grafo  *pGrafo, char *nome, int *Valor);

/*************************************************************************
* $FC Função:
*	Obter Valor Corrente
* $ED Descrição da função:
*	 Obtem o valor do no corrente
* $EP Parâmetros:
*		pGrafo- ponteiro pro Grafo 
*		Valor-  
* $FV Valor retornado: 
**************************************************************************/
	grafo_tpCondRet ObterValorCorrente(Grafo *pGrafo, int *Valor);

/*************************************************************************
* $FC Função:
*	Ir Inicio Grafo
* $ED Descrição da função:
*	Obtem o primeiro no inserido no grafo
* $EP Parâmetros:
*	pGrafo- ponteiro pro Grafo 
* $FV Valor retornado:
***************************************************************************/
	grafo_tpCondRet IrInicioGrafo(Grafo *pGrafo);

/*************************************************************************
* $FC Função:
*	Ir Final Grafo
* $ED Descrição da função:
*	Obtem o ultimo no inserido no grafo
* $EP Parâmetros:
*		pGrafo- ponteiro pro Grafo 
* $FV Valor retornado:	 
 *************************************************************************/
	grafo_tpCondRet IrFinalGrafo(Grafo *pGrafo);

/*************************************************************************
* $FC Função:
*	Avança Corrente
* $ED Descrição da função:
*	Avança o no corrente para frente ou pra tras baseado no n 
* $EP Parâmetros:
*		pGrafo - ponteiro pro Grafo 
*		n -
* $FV Valor retornado:	
***************************************************************************/
	grafo_tpCondRet Avanca_Corrente(Grafo *pGrafo, int n);

/************************************************************************
* $FC Função:
*	Elimina No
* $ED Descrição da função:
*	Elimina um elemento do grafo
* $EP Parâmetros:
*	pGrafo- ponteiro pro Grafo 	
* $FV Valor retornado:	 
*************************************************************************/
	grafo_tpCondRet EliminaNo(Grafo  *pGrafo);
/*
$FC Função:
*	Set Valor
* $ED Descrição da função:
*	
* $EP Parâmetros:
*		pGrafo- ponteiro pro Grafo 
*		nome- rotulo do no 
*		Valor- 
* $FV Valor retornado:
*/
	grafo_tpCondRet setValor(Grafo* pGrafo, char* nome ,int Valor);
