/*En una misma maquina hay N procesos productores, y un proceso consumidor, todos concurrentes entre si. Hay un vector de datos enteros
V[T] de capacidad T, donde T es impar, compartido, a traves del cual pasan la informacion los productores al consumidor (Ano es un buffer circular!).
Proceso Productor. 1.Genera un dato entero d. 2.Almacena el dato en cualquier celda libre del vector. 3.Si no hay mas celdas libres, avisa al consumidor. 4. Vuelve a 1. Proceso Consumidor. Espera a que el vector V este lleno; cuando esto ocurre determina cu ´antos datos son positivos y cuantos son negativos (el 0 es considerado positivo).
-Si hay mas datos positivos que negativos, extrae los datos positivos del vector y los muestra por pantalla, liberando las posiciones que estos ocupaban.
-Si hay mas datos negativos que positivos, extrae los datos negativos y los muestra por pantalla, liberando las posiciones que ocupaban.
Este comportamiento se repite indefinidamente. Resolver el problema con memoria compartida, semaforos y pseudocodigo tipo C para UNIX.*/

void recursosCompartidos(void){
	int n;
	int T=2n+1;
	int V[T];
	int E[T];
	sem hayEspacio;
	init_sem(hayEspacio,T);
	
	
	
	//PROPIO
	sem isVectorFreeSem0;
	sem isVectorFreeSem1;
	sem hayEspacio;
	init_sem(isVectorFreeSem0, 0);
	init_sem(isVectorFreeSem1, 0);
	//fin PROPIO
	
}

void PProductor0 (void){
	while(1==1){
		int d=generaValor();
		wait(hayEspacio);
		for(int i=0; i<T;i++){
			if(E[i]==libre){
				
				E[i]=ocupada;
				V[i]=d;
			}
		}
		
		
		
		//PROPIO
		int libre=0;
		int pos=0;
		wait(isVectorFreeSem0);
		wait(isVectorFreeSem1);
		while(libre==0){
			if(V[pos]==(free)){
				libre=1;
				V[pos]=d;
			}
			pos++;
			if(pos>=T){
				signal(isVectorFreeSem0)
			}
		}
		//fin PROPIO
	}
	}
void PProductor1 (void){
	while(1==1){
		int d=generaValor();
		//PROPIO
		int libre=0;
		int pos=0;
		wait(isVectorFreeSem0);
		wait(isVectorFreeSem1);
		while(libre==0){
			if(V[pos]==(free)){
				libre=1;
				V[pos]=d;
			}
			pos++;
			if(pos>=T){
				signal(isVectorFreeSem1);
			}
		}
		//fin PROPIO
	}
	}
void PConsumidor (void){
	int counter_positivos=0;
	while(1==1){
		//PROPIO
	wait(isVectorFreeSem0);
	wait(isVectorFreeSem1)
	for(int i=0;i<T;i++){
		if(V[i)>-1){
			counter_positivos++;
		}
	}
	if(counter_positivos>(T/2){
		for(int i=0;i<T;i++){
			if (V[i]>-1){
				printf("%d", V[i]);
				V[i]=//extraer valor
			}
		}
	}
	else{
		for(int i=0;i<T;i++){
			if (V[i]<0){
				printf("%d", V[i]);
				V[i]=//extraer valor
			}
		}
		
	}
	signal(isVectorFreeSem0);
	signal(isVectorFreeSem1);		
	}
	//fin PROPIO
}