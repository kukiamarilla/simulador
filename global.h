#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int n,c,tp,tu,ts;
int tiempo;
int parar;
int personas=0;
struct elemento{  //estructura que representa cada uno de los elementos de la cola
	struct elemento *sig;  //puntero al sgte elemento de la cola
	struct elemento *ant;  //puntero al anterior elemento de la cola
	int pdestino;  //piso de destino
	int tiempo;  //tiempo en que llamo
};

struct cola{
	struct elemento * primero;
	struct elemento * ultimo;
};

struct cola **Colas[2];

struct elemento * lista;