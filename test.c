
#include <malloc.h>
#include <stdio.h>
#include "grafo.h"


 int main (void)
 {
	 int valor=0;
	 Grafo* ppGrafo=0;
	 char nome[]="As fogosas";
	 char ant[][15]={"A","B","C"};
	 int Valor=4;
	 char suc[][15]={"B","D"};
	 grafo_tpCondRet x;
	 printf("%p\n",&ppGrafo);
	 x=CriaGrafo(&ppGrafo);
	 printf("cria grafo: %d %p %p\n",x,&ppGrafo,ppGrafo);
	 x= Insere_No_Grafo(ppGrafo, nome,  ant[15], suc[15], Valor);
	 printf("insere:%d\n",x);
	 x=ObterValorCorrente(ppGrafo, &valor); 
	 printf(" condição %d\n",x);
	 printf(" valor: %d\n",valor);
	 return 0;

 }
