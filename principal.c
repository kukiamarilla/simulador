#include "generador.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int ts;
	cargaparametros();
	leerparametros();
	scanf("%d",&ts);
	generadorts(ts);
	time_t start=time(NULL);
	while(1==1){
		sleep(1);

		printf("%d\n", n);
	}
	return 0;
}