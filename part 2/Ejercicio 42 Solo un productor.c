#define R valueR
#define S valueS
void consumidor(void){
	int* sig_vaciarA;
	int* sig_vaciarB;
	while(true){
		//HACERLO 4 VECES
		wait(datosA);
		e1=BA[sig_vaciarA];
		sig_vaciarA=(sig_vaciarA+1)%R;
		signal(espacioA);
		//FIN DE HACERLO 4 VECES.
		wait(datosB);
		eB=BB[sig_vaciarB];
		sig_vaciarB=(sig_vaciarB+1)%s;
		signal(espacioB);
	}
}
void rec_compartidos(void){
	sem datosA;
	sem espacioA;
	sem datosB;
	sem espacioB;
	inic_sem(datosA,0);
	inic_sem(datosA, R);
	inic_sem(datosB, 0);
	inic_sem(espacioB, S);
}
//TERMINAR