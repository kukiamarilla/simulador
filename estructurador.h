#include <stdio.h>
#include <stdlib.h>


FILE *ptrCf;  //ptrCf = apuntador al archivo solicitudes.dat




int n,s,c,tu,tp;

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
			puts("primer nodo");
	    	C->ultimo=nuevo;
	    	C->primero=nuevo;
		}else {
	    /* caso general */   
	    	puts("nodo sig");
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
			printf("\nla cola del piso %d es:",i);
			while(c[i].primero!=NULL){
				printf(" %d %d -",c[i].primero->pdestino,c[i].primero->tiempo);
				c[i].primero=c[i].primero->sig;
			}
		}
	}
}

//funcion que lee el archivo solicitudes.dat y pasa los datos del archivo a una cola
void leerarchivo(struct cola C[]){  
	leerparametros();
	int porigen, pdestino, tiempo;
	FILE *ptrcf;
	if((ptrcf=fopen("solicitudes.dat","r"))!=NULL){
		while (!feof(ptrcf)){
			fscanf(ptrcf,"%d%d%d\n", &porigen, &pdestino, &tiempo);
			printf("\n%d %d %d\n",porigen,pdestino,tiempo);
			encolar(&(C[porigen]), pdestino, tiempo);
		}
		fclose(ptrcf);
	}	
	
}
