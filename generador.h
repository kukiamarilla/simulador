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
	char aux[10];
	if((ptrcf=fopen("parametros.dat","w"))!=NULL){
		printf("%s\n", "Ingrese Cantidad de pisos del edificio" );
		do{
			puts("5 - 10")
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

void generador(){
	srand(time(NULL));
	s=rand()%1001;
	printf("%d\n",(int)start);
	FILE *ptrcf;
	int i,pdestino,porigen;
	if((ptrcf=fopen("solicitudes.dat","w"))!=NULL){
		if (s==0) fprintf(ptrcf, "%d %d %d\n",0,0,0); //no existe llamado al ascensor en ese momento
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
