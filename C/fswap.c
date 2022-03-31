#include <stdio.h>

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
	
	/* Siendo función, espacios de memoria no cambián */	
	int temp;
	temp = a;
	a =  b;
	b = temp;

	printf("\nSin Función:\na: %i[%p] - b: %i[%p]\n",a,&a,b,&b);
	swap(&a,&b);
	printf("\nFunción swap:\na: %i[%p] - b: %i[%p]",a,&a,b,&b);
	
	
	return 0;
} 
