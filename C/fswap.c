#include <stdio.h>


/* Intercambio de contenido */
/* Swap real */
void swap(int* a, int* b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


int main(void){
	
	int a = 9;
	int b = 4;
	
	printf("\na: %i[%p] - b: %i[%p]\n",a,&a,b,&b);

	/* Intercambio de punteros enteros */
	/* swap qlo malo */
	int temp;
	temp = a;
	a =  b;
	b = temp;

	printf("\nSin Función:\na: %i-[%p] -- b: %i-[%p]\n",a,&a,b,&b);
	
	/* swap real */
	swap(&a,&b);
	
	printf("\nFunción swap:\na: %i-[%p] -- b: %i-[%p]\n",a,&a,b,&b);
	
	return 0;
} 
