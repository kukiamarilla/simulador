
FILE *ptrCf;  //ptrCf = apuntador al archivo solicitudes.dat




//funcion que pasa los datos leidos del archivo solicitudes.dat a una cola

void encolar(struct cola *C, int pdestino, int tiempo){
	puts("encolar");
	struct elemento * nuevo;
	nuevo = (struct elemento *) malloc(sizeof(struct elemento));
	printf("%p\n",nuevo );
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
	puts("agregado");
}

//funcion que lee el archivo solicitudes.dat y pasa los datos del archivo a una cola
void leerarchivo(){  
	int porigen, pdestino, tempo;
	FILE *ptrcf;
	if((ptrcf=fopen("solicitudes.dat","r"))!=NULL){
		while (!feof(ptrcf)){
			fscanf(ptrcf,"%d%d%d\n", &porigen, &pdestino, &tempo);
			printf("\n%d %d %d\n",porigen,pdestino,tempo);
			// if (tempo==tiempo){
				if(pdestino>porigen){
					
					encolar((Colas[1][porigen]), pdestino, tempo);
				}else {
					encolar((Colas[0][porigen]), pdestino, tempo);
				}
			// }
		}
		fclose(ptrcf);
	}		
}
