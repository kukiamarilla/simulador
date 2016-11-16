

/*SIMULADOR:
			Mueve el ascensor segun logica, tiempos e instrucciones de apilador,
			avisa a apilador en que piso esta y a graficador en que piso esta..
*/

//_________________________________AUX___________________________________________



//_______________________________________________________________________________

int pisoActual=0
int tiempo=0;
int standBy=1;
int direccion=1;
//_______________________________________________________________________________


void simulador(int time){
	Lista lista;
	pila *destinos=NULL;
	//leer solicitudes
	//apilador(); //ver estado apilador
  	cargar();
	movimiento(*desapilar(&destinos),time);
	eliminar();
}
// recibe lista.
void cargar (){
	//solicitudes
	//pila de ascensor
	if (direccion()){
		while(lista.primero!=NULL){
			if((lista.primero->piso)>=pisoActual) agregar(destinos,lista.primero->piso);
			lista.primero=lista.primero->sig;
		}
	}else{
		while(lista.ultimo!=NULL){
			if((lista.ultimo->piso)<=pisoActual) agregar(destinos,lista.ultimo->piso);
			lista.ultimo=lista.ultimo->ant;
		}
	}
}

void movimiento(int piso,int tiempo){

	if (piso>pisoActual && piso <=n){
		do
		{
			++pisoActual;
			tiempoespera(tp);
		}
		while (pisoActual<piso);
	}
	else if (piso<pisoActual && piso>=1){
		do
		{
			--pisoActual;
			tiempoespera(tp);
		}
		while (pisoActual>piso);
	}
}
// dira en que piso se encuentra..
int posicion  ( void ){
	
}

//direccion en el que va el ascensor.
	// 1(uno) si sube y 0(cero) si baja....	
	// acdd: acendente decendente.
// avisa si ya esta ese piso, si esta 1, si no 0.
int verificar( ){
	
}

// buscara pisos por eliminar y los elimina si los hay...
void eliminar( ){
	
}

// realiza el tiempo de espera
void tiempoespera(int t){

}

void agregar(pila **lista,int dat){
	pila *ptrNuevo; /* apuntador a un nuevo nodo */
	pila *ptrAnterior; /* apuntador a un nodo previo de la lista */
	pila *ptrActual; /* apuntador al nodo actual de la lista */
	ptrNuevo = malloc( sizeof( struct pila ) ); /* crea un nodo */
	if ( ptrNuevo != NULL ) {
		ptrNuevo->dato = dat; 
		ptrNuevo->sig = NULL; 
		ptrAnterior = NULL;
		ptrActual = *lista;
		while ( ptrActual != NULL && comparar(ptrActual->dato,dat)) {
			ptrAnterior = ptrActual; 
			ptrActual = ptrActual->sig; 
		}

		if (ptrAnterior == NULL){
			ptrNuevo->sig = *lista;
			*lista = ptrNuevo;
		} else { /* inserta un nuevo nodo entre ptrAnterior y ptrActual */
			ptrAnterior->sig = ptrNuevo;
			ptrNuevo->sig = ptrActual;
		}
	} else {
		printf("No se inserto %d. No hay memoria disponible.\n", dat );
	}
} 
/*void agregar(pila **lista,int x){
    if(*lista==NULL){//Si la lista esta vacia se inicializa y se inserta
        (*lista)=malloc(sizeof(pila));
        (*lista)->sig=NULL;
        (*lista)->ant=NULL;
        (*lista)->dato=x;
    }
    else{//Sino se inserta por orden ascendente o descendente (dependiendo de la direccion del movimiento)
        pila *actual;
        pila *aux;//Nodo nuevo creado
        aux=crearNodo(x);
        actual=*lista;//auxiliar para buscar en la lista
        int a;
        while(actual!=NULL){
        	if (actual->dato!=x){
	            a=comparar(actual->dato,x);
	            if(a==1){//Si el dato a insertar es [mayor (asc) o menor (des)] que el nodo actual, se inserta antes de ese nodo actual
	                if(actual==*lista){//Si el nodo elegido es el primero
	                  *lista=aux;//El nodo nuevo es el primero
	                }
	                aux->ant=actual->ant;
	                aux->sig=actual;
	                if(actual->ant!=NULL){//Si el nuevo no va sustituir al primero, el nodo anterior ,con respecto al nodo actual, apunta al nodo nuevo, y el nodo nuevo apunta al nodo actual
	                    actual->ant->sig=aux;
	                }
	                actual->ant=aux;
	                break;
	            }
	            else{//Si el nodo actual no es [menor (asc) o mayor (des)] se busca en el siguiente nodo
	                if(actual->sig==NULL){//Si es el fin de la lista, se inserta alli
	                    aux->ant=actual;
	                    actual->sig=aux;
	                    break;
	                }
	                actual=actual->sig;
	            }

        }
    }
}*/

pila *crearNodo(int dat){
    pila *aux=malloc(sizeof(pila));
    aux->dato=dat;
    aux->sig=NULL;
    //aux->ant=NULL;
    return aux;
}

int comparar(int a,int b){
	if (direccion) return a<b;
	return a>b;
}

int *desapilar(pila **cima){
    static int q;
    int *ret;
    ret=NULL;
    if (*cima != NULL){
        pila *aux;
        aux=*cima;
        q=(aux->dato);
        ret=&q;
        *cima=(*cima)->sig;
        free(aux);
    }
    return ret;
}