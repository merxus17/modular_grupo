
#include <malloc.h>
#include <stdio.h>
#include "grafo.h"


 int main (void)
 {
	 int valor;
	 Grafo* grafo=0x0;
	 char nome[]="As fogosas";
	 char ant[][15]={"A","B","C"};
	 int Valor=4;
	 char suc[][15]={"B","D"};
	 grafo_tpCondRet x;
	 x=CriaGrafo(grafo);
	 printf("cria grafo: %d %p\n",x,grafo);
	 x= Insere_No_Grafo(grafo, nome,  ant[15], suc[15], Valor);
	 printf("insere:%d\n",x);
	 x=ObterValorCorrente(grafo, &valor); 
	 printf("%d\n",x);
	 printf("%d\n",valor);
	 return 0;

 }
