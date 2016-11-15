#include "generador.h"
#include "estructurador.h"
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int ts;
	//cargaparametros();
	leerparametros();
	scanf("%d",&ts);
	generadorts(ts);
	struct cola C[n+1];
	int i;
	for (i=0;i<n+1;i++){
		C[i].primero=NULL;
		C[i].ultimo=NULL;
	}
	leerarchivo(C);
	imprimecola(C);
	time_t start=time(NULL);
//	while(1==1){
//		sleep(1);
//
//		printf("%d\n", n);
//	}
	return 0;
}
