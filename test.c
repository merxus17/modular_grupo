
#include <malloc.h>
#include <stdio.h>
#include "grafo.h"


 int main (void)
 {
	 int valor1=0,valor2=0;
	 Grafo* ppGrafo=0;
	 char nome1[]="A";
	 char nome2[]="B";
	 char nome3[]="C";
	 char nome4[]="D";
	 char antA[][15]={NULL};
	 char antB[][15]={"A"};
	 char antC[][15]={"B"};
	 int Valor1 = 4, Valor2 = 5, Valor3 = 6;
	 char sucA[][15]={NULL};
	 char sucB[][15]={"A"};
	 char sucC[][15]={"B"};
	 grafo_tpCondRet x;
	 //printf("%p\n",&ppGrafo);
	 x=CriaGrafo(&ppGrafo);
	 //printf("cria grafo: %d %p %p\n",x,&ppGrafo,ppGrafo);
	 x= Insere_No_Grafo(ppGrafo, nome1,  antA[15], sucA[15], Valor1);
	 x= Insere_No_Grafo(ppGrafo, nome2,  antB[15], sucB[15], Valor2);
	 x= Insere_No_Grafo(ppGrafo, nome3,  antC[15], sucC[15], Valor3);
	 //printf("insere:%d\n",x);
	 //x=ObterValorCorrente(ppGrafo, &valor); 
	 x=setValor(ppGrafo,  nome1 , 17);
	 x=ObterValor(ppGrafo, nome2,&valor2);
	 x = ObterValor(ppGrafo, nome1, &valor1);
	 printf(" condi��o %d\n",x);
	 printf(" valor: %d  %d\n",valor1,valor2);
	 return 0;

 }