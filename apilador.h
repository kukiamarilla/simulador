
int subir=0;


int desencolar(struct cola * C){						//DESENCOLA EL VECTOR DE COLAS DE ESTRUCTURADOR.H Y RETORNA UN "TIPO ESTRUCTURA"
	
	struct elemento *temporal;
	struct elemento aux;
    if(C->primero!=NULL){
        temporal=C->primero;
        C->primero=C->primero->sig;
	    
    }else{
    	return NULL;
    }
	return temporal;
}


void insertar( struct nodo * persona){
	if(lista != NULL){
		lista->ant=persona;
		persona->sig=lista;
		persona->ant=NULL;
		lista=persona;
	}else{
		lista=persona;
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

void apilador( int piso){				//FUNCION DENTRO DEL MAIN ENCARGADO DE LLAMAR A LAS FUNCIONES AUXILIARES
    int dato;
    int time;
    int eliminado=1;
    struct nodo persona;
    if(piso != -1){
    	if(lista!= NULL){
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
    	}else{
    		eliminado=0;
    	}
    	if(eliminado==0){
	    	if(personas < c &&Colas[direccion][piso]->primero != NULL && Colas[direccion][piso]->primero->tiempo <= tiempo){
	    		if(subir==0){
	    			time=tiempo;
	    		}
	    		subir=1;
	    	}
	    	if(subir==1 && tiempo-time >= tu){
	    		subir=0;
	    		persona=desencolar(Colas[direccion][piso]);
	    		if (persona != NULL)
	    		{
		    		insertar(persona);
		    		personas++;
	    		}
	    	}
    	}
    }
}

