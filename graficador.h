#include "global.h
#include "generador.h"
#include "estructurador.h"
#include "apilador.h"
void graficar(int piso, int porigen, int tiempo){
	int i,j;
	char Edificio[n][8];
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<7; j++){
			Edificio[i][j]=177;
		}
	}
	system("cls");
	Edificio[piso][4]=58-persona;
	printf("\tSimulacion \n\n\t\t  ");
		for(i=0; i<4; i++)
	{
		
			printf("%c", Edificio[5][5]);
	}
	printf("\n");
		for (i=n-2;i>0;i--){
		printf("\t\t");
		for (j=7;j>0;j--){
			printf("%c",Edificio[i][j]);
			if (i==8 && j==1){
				printf("\tSolicitud del cliente en el piso: %d", porigen);
			}
		}
		printf("\n");
	}
		printf("\n\n \t\t Piso actual %d\n\n", piso);
		printf("\n\n \t\t Piso actual %d\n\n", tiempo);

	
}

