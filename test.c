
#include <malloc.h>
#include <stdio.h>
#include "grafo.h"


 int main (void)
 {
	 int valor1=0,valor2=0,valor3=0;
	 Grafo* ppGrafo=0;
	 char nome1[]="A";
	 char nome2[]="B";
	 char nome3[]="C";
	 char nome4[]="D";
	 char antA[1][150]={"C"};
	 char antB[2][150]={"A","C"};
	 char antC[2][150]={"A","B"};
	 int Valor1 = 4, Valor2 = 5, Valor3 = 6;
	 char sucA[2][150]={"C","B"};
	 char sucB[1][150]={"C"};
	 char sucC[2][150]={"A","B"};
	 grafo_tpCondRet x;
	 //printf("%p\n",&ppGrafo);
	 x=CriaGrafo(&ppGrafo);
	 //printf("cria grafo: %d %p %p\n",x,&ppGrafo,ppGrafo);
	 x= Insere_No_Grafo(ppGrafo, nome1,&Valor1,  antA,1, sucA ,2);
	 x= Insere_No_Grafo(ppGrafo, nome2,&Valor2,  antB, 2,sucB,1 );
     x= Insere_No_Grafo(ppGrafo, nome3,&Valor3,  antC,2, sucC,2);
	 //printf("insere:%d\n",x);
	 //x=ObterValorCorrente(ppGrafo, &valor); 
	 //x=setValor(ppGrafo,  nome3 , 17);
	// printf(" condição %d\n", x);
	 //x=ObterValor(ppGrafo, nome2,&valor2);
	 //x = ObterValor(ppGrafo, nome1, &valor1);
	 
	 PrintGrafo(ppGrafo);
	 x= EliminaNo(ppGrafo,nome3);
	 PrintGrafo(ppGrafo);
	 
	 //printf(" condição %d\n", x);
	 x = ObterValor(ppGrafo, nome4, &valor3);
	 //printf(" condição %d\n", x);
	 //printf(" valor: %d  %d\n", valor1, valor2);

	 return 0;

 }
