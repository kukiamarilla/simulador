#include <stdio.h>
#include <stdlib.h>
#include "generador.h"

FILE *ptrCf;  //ptrCf = apuntador al archivo solicitudes.dat

struct elemento{  //estructura que representa cada uno de los elementos de la cola
	struct elemento *sig;  //puntero al sgte elemento de la cola
	int pdestino;  //piso de destino
	int tiempo;  //tiempo en que llamo
};

struct cola{
	struct elemento * primero;
	struct elemento * ultimo;
};

int n=5;
void leerarchivo(struct cola C[]);  //funcion que lee el archivo solicitudes.dat
void encolar(struct cola *C, int pdestino, int tiempo);  //funcion que pasa los datos del archivo solicitudes.dat a una cola
void imprimecola(struct cola c[]);


void encolar(struct cola *C, int pdestino, int tiempo){
	struct elemento * nuevo;
  
	nuevo = (struct elemento *) malloc(sizeof(struct elemento));
	if (nuevo!=NULL){
		nuevo->sig=NULL;  /* siempre se pone al final */
		nuevo->pdestino=pdestino;
		nuevo->tiempo=tiempo;
	
	  /* ponerlo al final */
	
	  /* si esta vacia la cola */
		if ( C->primero == NULL ){ /* si primero es NULL -> ultimo tambien */
	    	C->ultimo=nuevo;
	    	C->primero=nuevo;
		}else {
	    /* caso general */   
	    	C->ultimo->sig=nuevo;    
			C->ultimo=nuevo;
		}
	}
}

void imprimecola(struct cola c[]){
	int i;
	for(i=0;i<(n+1);i++){
		if(c[i].primero==NULL){
			puts("cola vacia");
		}else{
			printf("la cola es del piso %d es:",i);
			while(c[i].primero!=NULL){
				printf("%d %d",c[i].primero->pdestino,c[i].primero->tiempo);
				c[i].primero=c[i].primero->sig;
			}
		}
	}
}

//funcion que lee el archivo solicitudes.dat y pasa los datos del archivo a una cola
void leerarchivo(struct cola C[]){  
	int porigen, pdestino, tiempo;
	FILE *ptrcf;
	printf("leer archivo: ");
	if((ptrcf=fopen("solicitudes.dat","r"))!=NULL){
		fscanf(ptrcf,"%d %d %d ", &porigen, &pdestino, &tiempo);
		encolar(&(C[porigen]), pdestino, tiempo);
		fclose(ptrcf);
	}	
	
}
