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

 typedef struct Vertice *str_vertice;

 /* Tipo refer�ncia para um grafo */
 typedef struct Grafo *str_grafo;


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

		 	 	 Grafo_CondRetNãoAchou

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
    grafo_tpCondRet CriaGrafo(void* pGrafo);
