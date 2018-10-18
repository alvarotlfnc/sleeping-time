void recursosCompartidos(){
	int sig_llenar=0;
	int sig_vaciar=0;
	int bufferB [n];
	int E[t];
	
	sem_t(espacio_B); 
	sem_init(espacio_B,n);
	sem_t(mutex_P);
	sem_init(mutex_P,1);//para la variable sig_llenar
	sem_t(dato_B);
	sem_init(dato_B,0);
	sem_t(serv_libre);
	sem_init(serv_libre, t);
	sem_t(mutex_E);
	sem_init(mutex_E,1);
	sem_t arraySemServ S[i];
	
	
	
	sem_t(mutex_buffer);
	sem_t(hay_datoServidor);
	sem_t(servidorFree);
	sem_t(vcompServ);
	sem_t(hayServidor);
	
	int vCompServ;
}
//NOT FINISHED YET.
void servidor(void){
	while(1==1){
		wait(servidorFree);
		post(hayServidor);
		wait(vcompServ);
		//cogerDato
		post(vcompServ);
	}
}
//HECHO
void productor(void){
	while(1==1){
		d=creaDato();
		wait(espacio_B);
		wait(mutex_P);
		i=sig_llenar;
		sig_llenar=(sig_llenar+1)%n;
		signal(mutex_P);
		B[i]=d;
		signal(dato_B);
	}
}
//HECHO
void consumidor(void){
	while(1==1){
		wait(mutex_E);
		wait(datos_B);
		e=B[j];
		signal(espacio_B);
		j=(j+1)%n;
		wait(serv_libre);
		for(i=0;i<t;i++){
			if(E[i]==libre){
				E[i]=ocupado;
				break;
			}
		}
		signal(mutex_E);
		
		
	}
}