#include "global.h"
#include "generador.h"
#include "simulador.h"
#include "apilador.h"
//ESTE ARCHIVO FUE HECHO UNICAMENTE POR NATALIA CARDOZO
//© Todos los Derechos Reservados ©

void  decapitar(void);
void eliminar(void);
void inicializar(void);



void leerparametros(){
	int na;
	FILE *ptrcf;
	puts("leerparametros");
	if((ptrcf=fopen("parametros.dat","r"))!=NULL){
		fscanf(ptrcf,"%d %d %d %d",&na,&c,&tu,&tp);
		fclose(ptrcf);
	}
	puts("leido");
	if(n==0){
		n=na;
		Colas[0]=(struct cola **)malloc(n*sizeof(struct cola *));
		Colas[1]=(struct cola **)malloc(n*sizeof(struct cola *));
		inicializar();
	}else{
		if (na!=n){
			if (na<n){
				n=na;
				decapitar();
			}
			n=na;
			Colas[0]=(struct cola **)realloc(Colas[0],n * sizeof(struct cola *));
			Colas[1]=(struct cola **)realloc(Colas[1],n * sizeof(struct cola *));	
			inicializar();
		}
	}
}

void inicializar(){
	int i, j;
	for (i=0;i<2;i++){
		for (j = 0; j < n; ++j)
		{
			/* code */
			Colas[i][j]=(struct cola *)malloc(sizeof(struct cola));
			Colas[i][j]->primero=NULL;
			Colas[i][j]->ultimo=NULL;
		}
	}
}

void decapitar(){
	puts("DECAPITANDO EDIFICIO: HABRA PERSONAS MUERTAS AL FINALIZAR PROCESO");
	eliminar();
}

void eliminar(){
	puts("ELIMINANDO NODO");
    struct elemento *actual;
    struct elemento *temporal;
	int i;
	for (i=0;i<n;i++){
		actual=Colas[1][i]->primero;
		while (actual!=NULL){
			if (actual->pdestino>n){
		        if(actual==Colas[1][i]->primero){
		        	Colas[1][i]->primero=actual->sig;
		        	actual->sig->ant=NULL;
				}else{
					actual->ant->sig=actual->sig;
					if(actual->sig != NULL){
						actual->sig->ant=actual->ant;
					}else{
						Colas[1][i]->ultimo=actual->ant;
					}
				}
				temporal=actual;
				actual=actual->sig;
		        free(temporal);
				
			}else{
				actual=actual->sig;

			}
		}
	}
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

	return 0;
}
