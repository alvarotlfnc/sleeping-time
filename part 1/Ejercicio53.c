/*
creamos dos vectores, uno llamado v que es el q alberga los valores y otro e que es el q indica si determinada posicion del vector v esta libre o no*/

void productor (void){
	d=crea_dato();
	wait(espacio);
	wait(mutex_E);
	for(i=0;i<T;i++){
		if(E[i]==libre){
			E[i]=ocupado;
			V[i]=d;
			break;
		}
	}
	cont=0;
	for(i=0;i<T;i++){
		if(E[i]==ocupada){
			cont++;
		}
		signal(mutex_E);
		if(cont==T){
			signal(avisar_Cons);
		}
	}
}//del while
void recursoscompartidos(void){
	V[T];
	sem espacio;
	inic_sem(espacio,T);
	sem avisar_Cons;
	inic_sem(avisar_Cons,0);
	E[T] //estado de las celdas
	sem mutex_E;
	inic_sem(mutex_E,1);
	for(i=0;i<T;i++){
		E[i]=libre;
	}
	
}
void consumidor(void){
	wait(avisar_Cons);
	//cuenta positivos
	cpositivos
	//cuenta negativos
	cnegativos
	if(cpositivos>cnegativos){
		for(int i=0;i<T;i++){
			if(V[i]>=0){
				E[i]=libre;
			}
			signal(espacio);
		}
	}
	
}