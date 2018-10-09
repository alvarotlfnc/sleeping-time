//el problema de las impresoras ejercicio 48
/*NO ES UN BUFER CIRCULAR, PUEDO MANDAR UN TRABAJO A CADA IMPRESORA
PROCESO
<----------------------->
pide imprimir
do{hay impresoras libres?
-si.
-cual
-usarla (marcarla como ocupada, usarla y luego liberarla),
-no-> esperar} while(!hay impresoras libres?);


*/

void recursoscompartidos(void){
	sem impr_libres;
	int E[I]; //estado impresoras libre ocupado
	inic(impr_libres,I);
	sem mutex_E;
	inic(mutex_E,1);
	
	for(int i=0;i<I;i++){
		E[I]=libre;
	}
}
void proceso(void){
	<tareas iniciales>
	wait(impr_libres);
	wait(mutex_E);
	for(int j=0;j<I;j++){
		if(E[j]==libre){
			E[j]=ocupado;
		}
		
		break;
	}
	signal(mutex_E);
	<imprimir>;
	//acaba la impresion
	wait(mutex_E);
	//necesito garantizar la exclusion mutua sobre el recurso E
	E[j]=libre;
	signal(mutex_E)
	
	signal(impr_libres);
	
}