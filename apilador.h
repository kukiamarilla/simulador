

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
int contar(struct nodo **lista,int pis){									//PREGUNTA SI EL PISO AL QUE DESEA IR YA ESTA EN LA LISTA, SI ESTA ES AGREGADA EN DICHO NODO COMO UNA PERSONA MAS QUE DESEA IR
	struct nodo *actual,*anterior;
	anterior=NULL;
	actual=*lista;
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

void insertar( struct nodo **lista, struct nodo**ultimo,  int dato ){
	int b;
	if(*lista==NULL){
	 	struct nodo *nuevo;
		nuevo= (struct nodo *)malloc( sizeof( struct nodo ) );
		nuevo->piso=dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
		*lista=nuevo;
		*ultimo=nuevo;
		}
	else {
		struct nodo *nuevo;
		struct nodo *actual=*lista;
		b=contar(&(*lista), dato);
		if(b==0){
			nuevo= (struct nodo *)malloc( sizeof( struct nodo ) );
							if(nuevo!=NULL){
								nuevo->piso=dato;
								while(actual!=NULL){
								            
								        if(dato<actual->piso){
								            if(actual==*lista){
								                *lista=nuevo;
								            }
								            nuevo->ant=actual->ant;
								            nuevo->sig=actual;
								            if(actual->ant!=NULL){
								                actual->ant->sig=nuevo;
								            }
								            actual->ant=nuevo;
								            break;
								        }
								        else{
								            if(actual->sig==NULL){
								                nuevo->ant=actual;
								                actual->sig=nuevo;
								                *ultimo=nuevo;
								                break;
								            }
								            actual=actual->sig;
								        }
								}
								
						}
		}
	}
}
void imprimir(struct nodo **lista){
struct nodo *actual;
    actual=*lista;
    while(actual!=NULL){
        printf("%d",actual->piso );
        actual=actual->sig;

    }

}
void eliminar(struct nodo **lista,struct nodo **utlimo,  int dato){															//ELIMINA LOS NODOS QUE YA LLEGARON A DESTINO LIBERANDO LUGAR EN EL ASCENSOR
    struct nodo *actual;
	actual=*lista;
	int a=0;
	while(actual!=NULL && !a){
        a=(actual->piso==dato);
        if(!a){
            actual=actual->sig;
        }
	}
	if(actual!=NULL){
        if(actual==*lista){
        	*lista=actual->sig;
        	if(actual->sig!=NULL){
        		actual->sig->ant=NULL;
        	}	
		} else if(actual->sig!=NULL){
			actual->ant->sig=actual->sig;
			actual->sig->ant=actual->ant;
		}
        else{
        	actual->ant->sig=NULL;
        	*utlimo=actual->ant;
        }
        free(actual);
	}
}



int sumar(struct nodo**lista){						//CALCULA LAS PERSONAS DENTRO DEL ASCENSOR
	int cantidad,can;
	int w=1;
	struct nodo *actual,*anterior;
	anterior=NULL;
	actual=*lista;
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
void apilador(struct cola C[][], int x, int direc){				//FUNCION DENTRO DEL MAIN ENCARGADO DE LLAMAR A LAS FUNCIONES AUXILIARES
    int dato;
    int parar;
    do{
        eliminar(&lista, &ultimo, x);
    	if(direc){
        	dato=desencolar(&(C[1][x]));
		} else{
			dato=desencolar(&(C[0][x]));
		}
    	insertar(&lista, &ultimo,dato);
    	parar=sumar(&lista);
	}while(parar!=0 && dato!=0);
}

