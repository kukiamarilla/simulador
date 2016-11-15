#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


int n,s,c,tu,tp;
//clock_t start;
time_t start;

void cargaparametros (void);
void leerparametros (void);
void generadorts(int ts);
void generador(int tiempo);
int valido(char x[]);

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

int valido(char x[]){
	int i;
	for (i=0;i<strlen(x);i++){
		if(!isdigit(x[i])) return 0;
	}
	return 1;
}

void leerparametros(){
	FILE *ptrcf;
	if((ptrcf=fopen("parametros.dat","r"))!=NULL){
		fscanf(ptrcf,"%d %d %d %d",&n,&c,&tu,&tp);
		fclose(ptrcf);
	}
}

void generadorts(int ts){
	int i;
	FILE *ptrcf;
	if((ptrcf=fopen("solicitudes.dat","w"))!=NULL)
		for (i=1;i<=ts;i++) generador(i);
}

void generador(int tiempo){
	srand(time(NULL));
	s=rand()%(n*c*10);
	FILE *ptrcf;
	int i,pdestino,porigen;
	if((ptrcf=fopen("solicitudes.dat","a"))!=NULL){
		for (i=0;i<s;i++){
			porigen=rand()%(n+1);
			if (porigen==0) pdestino=0; //no existen llamados en ese momento
			else{
				do{
					pdestino=rand()%n+1;
				}while (pdestino==porigen);
			}
			//time_t tiempo=time(NULL);
			fprintf(ptrcf, "%d %d %d\n",porigen,pdestino,tiempo);
		}
	}
}
