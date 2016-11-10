#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*piso_origen
piso_destino
tiempo: cantidad de segundos, a partir del inicio de la simulación en que el usuario realiza la solicitud de servicio*/

int n,s,c,tu,tp;
clock_t start;

void cargaparametros(){
	FILE *ptrcf;
	char aux;
	if((ptrcf=fopen("parametros.dat","w"))!=NULL){
		printf("%s\n", "Ingrese Cantidad de pisos del edificio" );
		do{
			scanf("%d",&n);
		}while (n>10 || n<5);
		printf("%s\n", "Ingrese Cantidad maxima de personas para el elevador" );
		do{
			scanf("%d",&c);
		}while (c>20 || c<4);
		printf("%s\n", "Tiempo en segundos para que un usuario suba o baje del ascensor" );
		scanf("%d",&tu);
		printf("%s\n", "Tiempo en segundos desplazamiento del ascensor de un piso a otro" );
		scanf("%d",&tp);
		fprintf(ptrcf, "%d %d %d %d\n",n,c,tu,tp);
		fclose(ptrcf);
	}
}

void leerparametros(){
	FILE *ptrcf;
	if((ptrcf=fopen("parametros.dat","r"))!=NULL){
		fscanf(ptrcf,"%d %d %d %d",&n,&c,&tu,&tp);
		fclose(ptrcf);
	}
}

void generador(){
	srand(time(NULL));
	s=rand()%(n*c);
	printf("%d\n",(int)start);
	FILE *ptrcf;
	int i,pdestino,porigen;
	if((ptrcf=fopen("solicitudes.dat","w"))!=NULL){
		for (i=0;i<s;i++){
			clock_t tiempo=clock();
			porigen=rand()%n+1;
			do{
				pdestino=rand()%n+1;
			}while (pdestino==porigen);
			fprintf(ptrcf, "%d %d %d\n",porigen,pdestino,(int)(tiempo-start));
		}
	}
}
