

void generador(int tiempo){
	int s;
	srand(time(NULL));
	FILE *ptrcf;
	int i,pdestino,porigen;
	if((ptrcf=fopen("solicitudes.dat","a"))!=NULL){
		for (i=1;i<=n;i++){
			s=rand()%10;
			if (s==1){
				porigen=i;
				do{
					pdestino=rand()%n+1;
				}while (pdestino==porigen);
				fprintf(ptrcf, "%d %d %d\n",porigen,pdestino,tiempo);
			}
		}
	}
	fclose(ptrcf);
}
//TODO: cambiar semilla y probaboilidad