#include "global.h"
#include "generador.h"
#include "estructurador.h"

//ESTE ARCHIVO FUE HECHO UNICAMENTE POR NATALIA CARDOZO
//© Todos los Derechos Reservados ©

void  decapitar(int na);
void eliminar(struct cola **cola,struct elemento *aux);
void generadorts(){
	int i;
	FILE *ptrcf;
	if((ptrcf=fopen("solicitudes.dat","w"))!=NULL)
		for (i=1;i<=ts;i++) generador(i);
}

void leerparametros(){
	int na;
	FILE *ptrcf;
	puts("leerparametros");
	if((ptrcf=fopen("parametros.dat","r"))!=NULL){
		fscanf(ptrcf,"%d %d %d %d",&na,&c,&tu,&tp);
		fclose(ptrcf);
	}
	
	if (na!=n && n){
		puts("redimensionar");
		*Colas=realloc(*Colas,na * sizeof(struct cola));
		if (na<n){
			n=na;
			decapitar();
		}
	}
	n=na;
}

void decapitar(){
	puts("DECAPITANDO EDIFICIO: HABRA PERSONAS MUERTAS AL FINALIZAR PROCESO");
	if ((*Colas[1])->primero!=NULL){
		struct elemento *aux=(*Colas[1])->primero;
		eliminar(Colas[1]);
	}
}

void eliminar(struct cola **cola){
	puts("ELIMINANDO NODO");
    struct elemento *actual;
	int i;
	for (i=1;i<=n;i++){
		actual=(*cola)->primero;
		while (actual!=NULL){
			if (actual->pdestino>n){
				if(actual!=NULL){
			        if(actual==((*cola)->primero)){
			        	(*cola)->primero=actual->sig;
			        	if(actual->sig!=NULL){
			        		actual->sig->ant=NULL;
			        	}	
					} else if(actual->sig!=NULL){
						actual->ant->sig=actual->sig;
						actual->sig->ant=actual->ant;
					}
			        else{
			        	actual->ant->sig=NULL;
			        	(*cola)->ultimo=actual->ant;
			        }
			        free(actual);
				}
			}
		}
	}
	puts("ELIMINADO");
}

int valido(char x[]){
	int i;
	for (i=0;i<strlen(x);i++){
		if(!isdigit(x[i])) return 0;
	}
	return 1;
}

void cargaparametros(){
	FILE *ptrcf;
	char aux[10];
	if((ptrcf=fopen("parametros.dat","w"))!=NULL){
		printf("%s\n", "Ingrese Cantidad de pisos del edificio" );
		do{
			puts("5 - 10");
			scanf("%s",aux);
			if (valido(aux)) n=atoi(aux);
			else printf("\a\nERROR\n");
		}while (n>10 || n<5);

		printf("%s\n", "Ingrese Cantidad maxima de personas para el elevador" );
		do{
			puts("4 - 20");
			scanf("%s",aux);
			if (valido(aux)) c=atoi(aux);
			else printf("\a\nERROR\n");
		}while (c>20 || c<4);

		printf("%s\n", "Tiempo en segundos para que un usuario suba o baje del ascensor" );
		do{
			puts("1 - 60");
			scanf("%s",aux);
			if (valido(aux)) tu=atoi(aux);
			else printf("\a\nERROR\n");
		}while(tu<1 || tu>60); //minimo 1 segundo - maximo 1 minuto 

		printf("%s\n", "Tiempo en segundos del desplazamiento del ascensor de un piso a otro" );
		do{
			puts("1 - 60");
			scanf("%s",aux);
			if (valido(aux)) tp=atoi(aux);
			else printf("\a\nERROR\n");
		}while(tp<1 || tp>60); //minimo 1 segundo - maximo 1 minuto
		
		fprintf(ptrcf, "%d %d %d %d\n",n,c,tu,tp);
		fclose(ptrcf);
	}
}



int main(int argc, char const *argv[])
{
	//cargaparametros();
	scanf("%d", &ts);
	leerparametros();
	generadorts();
	leerarchivo(**Colas);
	printf("%d\n", n);
	sleep(10);
	leerparametros();
	printf("%d\n", n);
	generadorts();

	return 0;
}
