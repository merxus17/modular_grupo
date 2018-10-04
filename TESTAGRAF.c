/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
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
*  $HA Hist�rico de evolu��o:
*     Vers�o    Autor    Data			 Observa��es
*     0.1		ere		13/09/2018		IN�CIO DO DESENVOLVIMENTO
*
*  $ED Descri��o do m�dulo
*     Este modulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo GRAFO.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo grafo:
*
*     
*
***************************************************************************/
#include    <string.h>
#include    <stdio.h>
#include	"grafo.h"
#include    "TST_ESPC.H"
#include    "GENERICO.H"
#include    "LERPARM.H"


static const char CRIAR_GRAFO_CMD         [ ] = "=criagrafo"			;
static const char Insere_No_Grafo_CMD	  [ ] = "inserirnografo"		;
static const char ObterValor_CMD		  [ ] = "obtemvalor"			;
static const char ObterValorCorrente_CMD  [ ] = "obtercorrente"			;
static const char IrInicioGrafo_CMD		  [ ] = "iriniciografo"			;
static const char IrFinalGrafo_CMD		  [ ] = "irfinalgrafo"			;
static const char Avanca_Corrente_CMD	  [ ] = "avancacorrentegrafo"   ;
static const char Elimina_No_CMD		  [ ] = "eliminano"			    ;
static const char Set_No_CMD			  [ ] = "setno"					;


#define DIM_VT_GRAFO 10

Grafo *vetGrafo [DIM_VT_GRAFO]; 

/*Prot�tipo das fun��es enccapsuladas no m�dulo*/
int ValidarIndcVet( int indcgrafo , int Modo );
void DestruirValor( void * pValor );


TST_tpCondRet tst_comando_graf(char * Comandos){
	 int indcgrafo  = -1 ,
         numLidos   = -1 ,
		 ret = -1;

	 char nomes[100];
	 int valorvert;


	  /*In�cio do teste da cria grafo*/
	if(strcmp(Comandos,CRIAR_GRAFO_CMD) == 0){
		
		numLidos = LER_LerParametros("i", &indcgrafo);

		if((numLidos != 1) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}

		ret = CriaGrafo(&vetGrafo[indcgrafo]);

		return TST_CompararPonteiroNulo( 1 , vetGrafo[ indcgrafo ] ,
               "Erro em ponteiro de nova lista."  ) ;
	}/*Fim do teste cria*/

	//In�cio do teste Insere
	else if(strcmp(Comandos,Insere_No_Grafo_CMD)==0){
		numLidos = LER_Parametros("isssi",&indcgrafo,&nomes,,,);//ainda n�o sei

		if((numLidos != 5) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}//numero de parametros errados
		


	}//fim do teste insere

	//Inicio do teste obtem valor
	else if(strcmp(Comandos,  ObterValor_CMD)==0){
		numLidos = LER_Parametros("isi",&vetGrafo,&nomes,&valorvert);


		if((numLidos != 3) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret =  ObterValor(vetGrafo[indcgrafo], nomes, &valorvert);



	}//fim teste obem valor

	//Inicio teste Obter Valor Corrente
	else if(strcmp(Comandos, ObterValorCorrente_CMD )==0){
		numLidos = LER_Parametros("ii",&indcgrafo,&valorvert );

		if((numLidos != 2) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret =  ObterValorCorrente(vetGrafo[indcgrafo], &valorvert);
		
	}//Fim


	//Inicio ir in�cio grafo
	else if(strcmp(Comandos, IrInicioGrafo_CMD )==0){
		numLidos = LER_Parametros("i",&indcgrafo);

		if((numLidos != 1) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret = IrInicioGrafo(vetGrafo[indcgrafo]);
	}
	else if(strcmp(Comandos, IrFinalGrafo_CMD)==0){
		numLidos = LER_Parametros("i",&indcgrafo);

		if((numLidos != 1) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret = IrFinalGrafo(vetGrafo[indcgrafo]);
	}
	else if(strcmp(Comandos, Avanca_Corrente_CMD)==0){
		numLidos = LER_Parametros("ii",&indcgrafo,valorvert);

		if((numLidos != 2) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret = Avanca_Corrente(vetGrafo[indcgrafo], valorvert);
	}
	else if(strcmp(Comandos, Elimina_No_CMD)==0){
		numLidos = LER_Parametros("i",&indcgrafo);

		if((numLidos != 1) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret = EliminaNo(vetGrafo[indcgrafo]);
	}

	else if(strcmp(Comandos, Set_No_CMD)==0){
		numLidos = LER_Parametros("isi",&indcgrafo,&nomes, valorvert);

		if((numLidos != 3) ||  ( ! ValidarIndcVet( indcgrafo , 1 ))){
			return TST_CondRetParam;
		}
		ret = setValor(vetGrafo[indcgrafo], nomes ,valorvert);  


}
	



int ValidarIndcVet( int indcgrafo , int Modo )
   {

      if ( ( indcgrafo <  0 )
        || ( indcgrafo >= DIM_VT_GRAFO ))
      {
         return 1 ;
      } /* if */
         
      if ( Modo == 1 )
      {
         if ( vetgrafo[ indcgrafo ] != 0 )
         {
            return 1 ;
         } /* if */
      } else
      {
         if ( vetgrafo[ indcgrafo ] == 0 )
         {
            return 1 ;
         } /* if */
      } /* if */
         
      return 0 ;
}

 void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } 