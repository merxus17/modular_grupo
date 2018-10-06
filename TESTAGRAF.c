/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTAGRAF.C
*  Letras identificadoras:      TGRAF
*
*  Nome da base de software:    
*  Arquivo da base de software:
*
*  Projeto: Disciplina INF  1301
*  Gestor:  
*  Autores: ere - Eduardo, Rodrigo ou Evelyn
*
*  $HA Histórico de evolução:
*     Versão    Autor    Data			 Observações
*     0.1		ERBS	04/10/2018		INÍCIO DO DESENVOLVIMENTO 2
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo GRAFO.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo grafo:
*
*
***************************************************************************/

#include <stdio.h>
#include <string.h>
#include "grafo.h"
#include "GENERICO.h"
#include "TST_ESPC.H"
#include "LERPARM.H"


static const char CRIAR_GRAFO_CMD         [ ] = "=criagrafo"			; 
static const char Insere_No_Grafo_CMD	  [ ] = "inserirnografo"		; 
static const char ObterValor_CMD	  [ ] = "obtemvalor"			; 
static const char ObterValorCorrente_CMD  [ ] = "obtercorrente"			;
static const char IrInicioGrafo_CMD	  [ ] = "iriniciografo"			;
static const char IrFinalGrafo_CMD	  [ ] = "irfinalgrafo"			;
static const char Avanca_Corrente_CMD	  [ ] = "avancacorrentegrafo"   	;
static const char Elimina_No_CMD	  [ ] = "eliminano"			;
static const char Set_No_CMD		  [ ] = "setno"				;




#define Dim 10 //dimensão para o vetor grafo 
#define Ok	0


Grafo *vetgrafo[Dim];

int ValidarIndcVet( int indcgrafo , int Modo);

TST_tpCondRet tst_comando_graf(char * comandos){

	int indcgraf=-1,
		nparlidos= -1,
		funcao = -1,
		valor;
	char vetnome[100],
		*ant,
		*suc;
	if(strcmp(comandos,CRIAR_GRAFO_CMD)==0){

		nparlidos = LER_LerParametros("i", &indcgraf);

		if ( ( nparlidos != 1 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            } //Caso o indice do vetor ou número de parâmetros errado

		funcao=CriaGrafo(&vetgrafo[indcgraf]);
				
		return TST_CompararPonteiroNulo(Ok,vetgrafo[indcgraf],"Fala de memória");
		
	}        
	if(strcmp(comandos,Insere_No_Grafo_CMD)==0	){

				nparlidos = LER_LerParametros("isssi", &indcgraf,&vetnome,&ant,&suc,&valor);

		if ( ( nparlidos != 5 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao=Insere_No_Grafo(vetgrafo[indcgraf],vetnome,ant,suc,valor); 
		if(funcao == Ok){
			return TST_CondRetOK;
		}
		else
			return TST_CondRetErro;
	}
	if(strcmp(comandos,ObterValor_CMD)==0){

				nparlidos = LER_LerParametros("isi", &indcgraf,&vetnome,&valor);

		if ( ( nparlidos != 1 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao=ObterValor(vetgrafo[indcgraf],vetnome,&valor);
		if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
	if(strcmp(comandos,ObterValorCorrente_CMD)==0){

				nparlidos = LER_LerParametros("ii", &indcgraf,&valor);

		if ( ( nparlidos != 2 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao = ObterValorCorrente(vetgrafo[indcgraf],&valor);
		if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
	if(strcmp(comandos,IrInicioGrafo_CMD)==0){

				nparlidos = LER_LerParametros("i", &indcgraf);

		if ( ( nparlidos != 1 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao = IrInicioGrafo(vetgrafo[indcgraf]) ;
		if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
	if(strcmp(comandos,IrFinalGrafo_CMD)==0){

				nparlidos = LER_LerParametros("i", &indcgraf);

		if ( ( nparlidos != 1 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao = IrFinalGrafo(vetgrafo[indcgraf]);
		if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
	if(strcmp(comandos,Avanca_Corrente_CMD)==0){

				nparlidos = LER_LerParametros("ii", &indcgraf,&valor);

		if ( ( nparlidos != 2 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao=Avanca_Corrente(vetgrafo[indcgraf],valor);
			if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
	if(strcmp(comandos,Elimina_No_CMD)==0){

				nparlidos = LER_LerParametros("is", &indcgraf,&vetnome);

		if ( ( nparlidos != 2 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao=  EliminaNo(vetgrafo[indcgraf],vetnome);
			if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
	if(strcmp(comandos,Set_No_CMD)==0) {

				nparlidos = LER_LerParametros("i", &indcgraf);

		if ( ( nparlidos != 1 )
              || ( ! ValidarIndcVet( indcgraf , 0 )))
            {
               return TST_CondRetParm ;
            }
		funcao=setValor(vetgrafo[indcgraf], vetnome ,valor);
		if(funcao==Ok){
			return TST_CondRetOK;
		}
		else {
			return TST_CondRetErro;
		}
	}
}




int ValidarIndcVet( int indcgrafo , int Modo )
   {

      if ( ( indcgrafo <  0 )
        || ( indcgrafo >=  Dim))
      {
         return 1 ;
      } /* if */
         
      if ( Modo == 1 )
      {
         if ( vetgrafo[ indcgrafo ] != 0 )
         {
            return 1 ;
         } 
      } else
      {
         if ( vetgrafo[ indcgrafo ] == 0 )
         {
            return 1 ;
         } 
      } 
         
      return 0 ;
}
