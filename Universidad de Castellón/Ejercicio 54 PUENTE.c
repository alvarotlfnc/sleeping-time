#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sentidoA;
sem_t sentidoB;
sem_t pasoPuente;
int pasoA=0;
int pasoB=0;
int activoA=0;
int activoB=0;
void * sentidoACoche(void* ags){
	//cada coche en este sentido tendria un hilo
	sleep(rand()%20+1);
	sem_wait(&pasoPuente);
	activoA++;
	sem_wait(&sentidoA);
	pasoA++;
	sleep(1);
	sem_post(&sentidoA);
	printf("ha pasado un coche A, con numero %d\n", pasoA);
	sem_post(&pasoPuente);
	
	if(pasoA==activoA){
		sem_post(&sentidoB);
	}
}
void* sentidoBCoche(void* ags){
	//cada coche en este sentido tendria un hilo
	sleep(rand()%20+1);
	sem_wait(&pasoPuente);
	activoB++;
	sem_wait(&sentidoB);
	pasoB++;
	sleep(1);
	sem_post(&sentidoB);
	sem_post(&pasoPuente);
	printf("ha pasado un coche B, con numero %d\n", pasoB);
	if(pasoB==activoB){
		sem_post(&sentidoA);
	}
}
void main(void){
	sem_init(&sentidoA,0,1);
	sem_init(&sentidoB,0,1);
	sem_init(&pasoPuente,0,1);
	pthread_t hilosSentidoA[50];
	pthread_t hilosSentidoB[50];
	int contador;
	for(contador=0;contador<50;contador++){
		pthread_create(&hilosSentidoA[contador], NULL, sentidoACoche, NULL);
		pthread_create(&hilosSentidoB[contador], NULL, sentidoBCoche, NULL);
	}
	for(contador=0;contador<50;contador++){
		pthread_join(hilosSentidoA[contador], NULL);
		pthread_join(hilosSentidoB[contador], NULL);
	}
}