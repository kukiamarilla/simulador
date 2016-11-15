/*SIMULADOR:
			Mueve el ascensor segun logica, tiempos e instrucciones de apilador,
			avisa a apilador en que piso esta y a graficador en que piso esta..
*/

#include<stdio.h>
#include<stdlib.h>

//_________________________________AUX___________________________________________

typedef struct lista{
	struct lista *primero;
	struct lista *ultimo;
}lista;

typedef struct nodo{
	struct nodo *despues;
	int dato;
	struct nodo *antes;
}nodolista;

//_______________________________________________________________________________

// recibe lista.
void movimiento ( struct lista **lista, struct lista **ascendente, struct lista **decendente )
{

	int direccion, piso;
	
	struct nodo *ult, *in;
	// acs: apuntador a la lista de pisos a subir.
	struct  nodo *nuevo_asc;
	nuevo_asc=(struct lista *)malloc(sizeof ( struct lista ) );
	
	// desc: apuntador a la lista de pisos a bajar.
	struct nodo *nuevo_desc;
	nuevo_desc=(struct lista *)malloc(sizeof ( struct lista ) );
	
	piso=posicion();

	direccion=acdd();
	
	ult=(*lista)->ultimo;
	in=(*lista)->primero;
	
	if ( direccion == 1 ){ // esta subiendo.
		
		if ( nuevo_asc != NULL ){
		  
		  while( in != ult ){
		  	 
			   if ( in->dato >= piso){
			   	
			   		if( *ascendente != NULL)
					{
						if( verificar() == NULL){
							nuevo_asc=in->dato;
							
							in=in->despues;
						}
			   		}
			  }
		  }
		  if ( in->dato >= piso ){
		  	nuevo_asc=in->dato;
		  }
		  // enlistar los que subiran..
		  enlistar( );
		  
		}
		
	}else{
		
		// enlistar los que bajaran..
		enlistar();
		
	}
	
}


// dira en que piso se encuentra..
int posicion  ( void ){
	
}

//direccion en el que va el ascensor.
	// 1(uno) si sube y 0(cero) si baja....	
	// acdd: acendente decendente.
int acdd( )
{
	
}

// avisa si ya esta ese piso, si esta 1, si no 0.
int verificar( ){
	
}

// buscara pisos por eliminar y los elimina si los hay...
void eliminador( ){
	
}

// crea una lista o carga elementos.
enlistar( ){
	
}










































