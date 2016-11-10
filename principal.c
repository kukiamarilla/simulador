#include "generador.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
	start=clock();
	while(1==1){
		sleep(5);
		generador();
	}
	return 0;
}