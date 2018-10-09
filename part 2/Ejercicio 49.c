//ejercicio 49
#include <pthread.h>

void recursosCompartidos(void){
	Buffer circular ebc;//tamańo T
	sem(datos_ebc);
	sem(libre_ebc);
	pthread_create(.....,HServidor);
	inic(datos_ebc,0);//hay_solucion
	inic(libre_ebc,1);//libre_solucion
	sol; //variable compartida servidor HServidor
	sem(sol_cogida);
	init_sem(sol_cogida,0);
	resp;//variable compartida servidor respuesta
	sem(hay_respuesta);
	init_sem(hay_respuesta,0);
	sem(resp_libre);
	init_sem(resp_libre,0);
	sem(resp_recogida)
	init_sem(resp_recogida,0);
}
void servidor(void){
	//pensar en el problema de los bufferes
	sig_leer c;
	while(1==1){
		wait(datos_ebc);
		sol=ebc[sig_leer];
		signal(libre_ebc);
		sig_leer=(sig_leer+1)%T; //T es el tamańo de ebc
		wait(sol_cogida);
		
	}
}
void HServidor(void){
	wait(datos_ebc)
	sol_local=sol;
	signal(datos_ebc);
	wait(sol_cogida);
	resul=bbusca(sol_local);
	wait(resp_libre);
	resp=resul;
	signal(hay_respuesta);
	wait(resp_recogida);
}
void respuesta(void){
	while(1==1){
		wait(hay_respuesta);
		resp_local=resp;
		signal(resp_libre);
		signal(resp_recogida);
		resspuesta(resp_local);
	}
}