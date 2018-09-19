/***************************************************************************
*  $MCD Módulo de definição: Grafo
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

 typedef struct Vertices;

 /* Tipo referência para um grafo */
 typedef struct Grafo;


 /***********************************************************************
*
*  $TC Tipo de dados: grafo Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do grafo
*
***********************************************************************/
typedef enum {

         Grafo_CondRetOK ,
               /* Concluiu corretamente */

         Grafo_CondRetNaoAchou ,
               /* Não encontrou o valor procurado */

         Grafo_CondRetFaltouMemoria
               /* Faltou memória ao tentar criar (...)*/

   } grafo_tpCondRet ;


/***********************************************************************
*
*  $FC Função:
*
*  $ED Descrição da função
*     Cria o grafo alocando a lista de ponteiros para os vertices e a propria lista de vertices e o no corrente como null
*
*  $EP Parâmetros
*
*
*  $FV Valor retornado
*
*
***********************************************************************/
    grafo_tpCondRet CriaGrafo(void* pGrafo);
