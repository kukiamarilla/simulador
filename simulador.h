

/*SIMULADOR:
			Mueve el ascensor segun logica, tiempos e instrucciones de apilador,
			avisa a apilador en que piso esta y a graficador en que piso esta..
*/

//_________________________________AUX___________________________________________



//_______________________________________________________________________________

int standBy=1;
int direccion=1;
int posicion=0;
//_______________________________________________________________________________



int seDebeEsperar(int piso){
	int b=0;
	int i;
	struct elemento * actual;
	if(Colas[direccion][i]->primero != NULL && Colas[direccion][i]->primero->tiempo <=tiempo){
		b=1;
	}
	actual=lista;
	while(actual != NULL){
		if(actual->pdestino == piso){
			b=1;
		}
		actual=actual->sig;
	}
	return b;
}


void mover(int piso, int dir)
{
	int b=1;
	if(piso==-1){
		posicion=posicion+dir;
	}else{
		if (seDebeEsperar(piso)==0){
			posicion=posicion+dir;
		}
	}

}

int haySolicitudes(int piso)
{
	struct elemento * actual;
	int b=0;
	int i,j;
	for (j = 0; j < 2; ++j)
	{
		if(Colas[j][i]->primero != NULL && Colas[j][i]->primero->tiempo <=tiempo){
			b=1;
		}
	}
	actual=lista;
	while(actual != NULL){
		if(actual->pdestino == piso){
			b=1;
		}
		actual=actual->sig;
	}
	return b;
}



void simulador()
{
	int piso=posicion%tp==0 ? posicion/tp : -1;
	int b,i;
	if(standBy==1){
		for (i = 0; i < n; ++i)
		{
			if(haySolicitudes(n)==1){
				standBy=0;
			}
		}
		if (standBy==1)
		{
			if(posicion>0){
				posicion--;
				direccion=0;
			}else{
				direccion=1;
			}
		}
	}
	if(standBy==0){
		b=0;
		if (direccion==1)
		{
			for (i = posicion/tp; i < n; ++i)
			{
				if(haySolicitudes(i)==1){
					b=1;
				}
			}
			if(b==1){
				mover(piso, 1);
			}
		}else{
			for (i = posicion/tp; i >= 0; --i)
			{
				if(haySolicitudes(i)==1){
					b=1;
				}

				if(b==1){
					mover(piso,-1);
				}
			}
		}
		if(b==0){
			direccion=1-direccion;
			if (direccion==1)
			{
				for (i = posicion/tp; i < n; ++i)
				{
					if(haySolicitudes(i)==1){
						b=1;
					}
				}
			}else{
				for (i = posicion/tp; i >= 0; --i)
				{
					if(haySolicitudes(i)==1){
						b=1;
					}
				}
			}
			standBy=!b;

		}
	}
}

