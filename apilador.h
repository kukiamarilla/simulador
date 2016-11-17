
int subir=0;


int desencolar(struct cola * C){						//DESENCOLA EL VECTOR DE COLAS DE ESTRUCTURADOR.H Y RETORNA UN "TIPO ESTRUCTURA"
	
	struct elemento *temporal;
	struct elemento aux;
    if(C->primero!=NULL){
        temporal=C->primero;
        C->primero=C->primero->sig;
        aux=*temporal;
        free(temporal);   
    }else{
    	return NULL;
    }
	return aux;


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

void eliminar(int piso){													//ELIMINA LOS NODOS QUE YA LLEGARON A DESTINO LIBERANDO LUGAR EN EL ASCENSOR
	struct elemento * actual = lista;
	if(lista != NULL){
		while(actual->pdestino != piso && actual != NULL){
			actual=actual->sig;
		}
		if(actual !=NULL){
			personas--;
			if(actual->sig!=NULL){
				actual->ant->sig=actual->sig;
			}
			if(actual->ant!=NULL){
				actual->sig->ant=actual->ant;
			}
			free(actual);
			return 1;
		}
	}
	return 0;
}

void apilador( int piso, int direc){				//FUNCION DENTRO DEL MAIN ENCARGADO DE LLAMAR A LAS FUNCIONES AUXILIARES
    int dato;
    int time;
    int eliminado=1;
    struct nodo persona;
    if(piso != -1){
    	if(lista!= NULL && eliminado == 1){
    		if(subir==0){
    			time=tiempo;
    		}
    		subir=1;
    		if(subir==1 && tiempo-time >= tu){
	    		eliminado=eliminar(piso);
	    		if(eliminado==1){
	    			time=tiempo;
	    		}
	    	}
    	}
    	if(eliminado==0){
	    	if(personas < c &&Colas[direc][piso]->primero != NULL && Colas[direc][piso]->primero->tiempo <= tiempo){
	    		if(subir==0){
	    			time=tiempo;
	    		}
	    		subir=1;
	    	}
	    	if(subir==1 && tiempo-time >= tu){
	    		subir=0;
	    		persona=desencolar(Colas[direc][piso]);
	    		insertar(persona);
	    		personas++;
	    	}
    	}
    }
}