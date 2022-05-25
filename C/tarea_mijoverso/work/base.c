#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
  int id;
  char rut[11];
  char razon_social[200];
  char fecha_actuacion[11];
  char fecha_registro[11];
  char fecha_aprobacion[11];
  int anio;
  char mes[20];
  char comuna[80];
  int region;
  char codigo[40];
  char tipo[80];
  int capital;
  char comuna_social[80];
  int region_social;
} empresa;

void swap(empresa* c1, empresa* c2){
  
  empresa fantasma;
  
  fantasma = *c1;
  *c1 = *c2;
  *c2 = fantasma;
  
}

empresa* ordenar_empresas(empresa* ciudades, int N) {

  empresa* nuevaLista = (empresa *)malloc(N*sizeof(empresa));  
  
  for(int i; i <= N; i++){
	  
  }

  return nuevaLista;
}



int main(void){

	empresa* emprLista = (empresa *)malloc(5*sizeof(empresa));  
	
	empresa uno, dos, tres, cuatro, cinco;

	emprLista[0] = uno;
	emprLista[1] = dos;
	emprLista[2] = tres;	
	emprLista[3] = cuatro;
	emprLista[4] = cinco;

	uno.id= 19; 
	dos.id = 13; 
	tres.id = 16; 
	cuatro.id = 15; 
	cinco.id = 11; 
	
	printf("\n\nAntes:\n\n1.-%i\n2.-%i\n3.-%i\n4.-%i\n5.-%i\n", uno.id, dos.id, tres.id, cuatro.id, cinco.id);
	
	ordenar_empresas(emprLista, 5);
	
	printf("\n\n\nDespues:\n\n1.-%d\n2.-%d\n3.-%d\n4.-%d\n5.-%d\n", uno.id, dos.id, tres.id, cuatro.id, cinco.id);

	return 0;
}
