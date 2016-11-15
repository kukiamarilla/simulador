
#include "estructurador.h"

struct nodo{
    int piso;						//AL PISO QUE DESEA IR
    int paso;						//CANTIDAD DE PERSONAS QUE QUIEREN IR AL DETERMINADO PISO
    int tiempo;						//TIEMPO EN EL QUE LLAMARON AL ASCENSOR
    //struct nodo *ant;
    struct nodo *sig;				//PARA QUE EL ASCENSOR PUEDA ACCEDER AL ULTIMO O AL PRIMER ELEMENTO DE LA LISTA
};
struct nodo * pila = NULL;
int n,s,c,tu,tp;

int desencolar(struct cola *C){						//DESENCOLA EL VECTOR DE COLAS DE ESTRUCTURADOR.H Y RETORNA UN "TIPO ESTRUCTURA"
	int ax;
	struct elemento *temporal;
    if(C->primero==NULL){
        ax=0;
	}else{
	    ax=C->primero->pdestino;					
	    temporal=C->primero;
	    C->primero=(C->primero)->sig;
	    if(C->primero == NULL){
	        C->ultimo=NULL;
	    }
	    free(temporal);
    }
	
	return ax;

}

void insertar( struct nodo **lista, int dato ){																//ENLISTA A LAS PERSONAS SEGUN EL PISO QUE DESEA IR 
	struct nodo *Nuevo; /* apuntador a un nuevo nodo */
	struct nodo *Anterior; /* apuntador a un nodo previo de la lista */
	struct nodo *Actual; /* apuntador al nodo actual de la lista */
	int b=contar(&lista,dato );			/*si es un piso al que ya debe ir el ascensor no agrega*/			//PREGUNTA SI EL PISO AL QUE DESEA IR YA ESTA EN LA LISTA, SI ESTA ES AGREGADA EN DICHO NODO COMO UNA PERSONA MAS QUE DESEA IR		
	if(b==0){
		Nuevo = malloc( sizeof( struct nodo ) ); /* crea un nodo */
		if ( Nuevo != NULL ) {
			Nuevo->piso = dato;
			Nuevo->sig = NULL;
			//Anterior = NULL;
			Actual = *lista;
			while ( Actual != NULL && dato > Actual->piso ) {
				Anterior = Actual;
				Actual = Actual->sig;
				
				
			}
	
			if ( Anterior == NULL ) {
				Nuevo->sig = *lista;
				*lista = Nuevo;
			} else { /* inserta un nuevo nodo entre ptrAnterior y ptrActual */
				Anterior->sig = Nuevo;
				Nuevo->sig = Actual;
			}
		}
	}
}
void eliminar(struct nodo **pila, int dato){															//ELIMINA LOS NODOS QUE YA LLEGARON A DESTINO LIBERANDO LUGAR EN EL ASCENSOR
    struct nodo *actual,*anterior;
	anterior=NULL;
	actual=*pila;
	int a=0;
	while(actual!=NULL && !a){
        a=(actual->piso==dato);
        if(!a){
            anterior=actual;
            actual=actual->sig;
        }
	}
	if(actual!=NULL){
        if(actual==*pila) *pila=actual->sig;
        else{
            anterior->sig=actual->sig;
        }
        free(actual);
	}
}


int contar(struct nodo **pila,int pis){									//PREGUNTA SI EL PISO AL QUE DESEA IR YA ESTA EN LA LISTA, SI ESTA ES AGREGADA EN DICHO NODO COMO UNA PERSONA MAS QUE DESEA IR
	struct nodo *actual,*anterior;
	anterior=NULL;
	actual=*pila;
	int a=0; int ha=0; int t;
	while(actual!=NULL && !a){
        a=(actual->piso==pis);
	        if(!a){
	            anterior=actual;
	            actual=actual->sig;
	        } else {
		        t=actual->paso; 
				t=t+1;
				actual->paso=t;
				ha=1;
	        }
	}
	return ha;
}
int sumar(struct nodo**pila){						//CALCULA LAS PERSONAS DENTRO DEL ASCENSOR
	leerparametros();
	int cantidad,can;
	int w=1;
	struct nodo *actual,*anterior;
	anterior=NULL;
	actual=*pila;
	while(actual!=NULL){
			can=actual->paso; 					//SUMA LA CANTIDAD DE PERSONAS POR PISO DENTRO DEL ASCENSOR
			cantidad+=can;
			if(cantidad==c){							//SI LLEGA AL LIMITE TERMINA
				w=0;
				break;
			}
			anterior=actual;
			actual=actual->sig;

	}
return w;	
}
void apilador(struct cola C[], int x){				//FUNCION DENTRO DEL MAIN ENCARGADO DE LLAMAR A LAS FUNCIONES AUXILIARES
    int dato;
    int parar;
    do{
        eliminar(&pila, x);
    	dato=desencolar(&(C[x]));
    	insertar(&pila, dato);
    	parar=sumar(&pila);
	}while(parar!=0 && dato!=0);
}

