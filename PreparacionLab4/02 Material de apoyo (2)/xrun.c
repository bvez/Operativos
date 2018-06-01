#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <math.h>

void *xmalloc (size_t nbytes);

void main(void)
{ int x,unidad,base;
  void *pt;

  unidad=1024; 
  x=0;

  do {
    base=pow(2,x)+.5;
    if(pt=xmalloc(base*unidad)) 
       fprintf(stdout,"Se solicitaron %d bytes y estan ubicados en %p\n",base*unidad,pt);
    else
       fprintf(stderr,"No hay suficiente memoria\n");
       
    x++; }
  while(x<=20);      
                    
  
}


