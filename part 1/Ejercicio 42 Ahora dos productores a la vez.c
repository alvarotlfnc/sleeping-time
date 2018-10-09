void P1 (void){
	local_llenar 0;
	while(true){
		d_crear_dato();
		wait(espacio);
		wait(mutex_sig_llenar);
		local_llenar=sig_llenar;
		sig_llenar=(sig_llenar+1)%T;
		signal(mutex_sig_llenar);
		B[local_llenar]=0;
		local_llenar=(local_llenar+1)%T;
	}
	signal(dato);
}
void Cj (void){
	int local_vaciar=0;
	while(true){
		wait(dato);
		wait(mutex_sig_vaciar);
		local_vaciar=sig_vaciar;
		sig_vaciar=(sig_vaciar+1)%T;
		signal(mutex_sig_vaciar);
		e=B[local_vaciar];
	}
	signal(espacio);
}

void recursosCompartidos(void){
	int sig_llenar=0;
	int sig_vaciar=0;
	sem espacio;
	sem dato;
	sem mutex_sig_llenar;
	sem mutex_sig_vaciar;
	inic_sem(espacio, T);
	inic_sem(dato, 0);
	inic_sem(mutex_sig_llenar,1);
	inic_sem(mutex_sig_vaciar,1);
}