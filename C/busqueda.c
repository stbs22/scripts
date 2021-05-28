// C program to implement recursive Binary Search 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Dividir y elegir lado en funcion de numeros sucesores a la mitad
//Dividir y analizar si se encuentra en los conjuntos

int min(int a, int b){
    return (a < b ? a : b);
}

void printlist(int arr[], int len){
    
    printf("Lista: \n\n");

    for(int i = 0; i < len; i++){
        printf("Indice: %d -- Valor: %d\n",i ,arr[i]);
    }
}

int LinearSearch(int arr[], int len, int numero) { 

    //la wea se explica sola
    for (int i = 0; i < len; i++){
        if (arr[i] == numero) return i; 
    }

    return -1; 
} 

int BinarySearch(int arr[], int cola, int cabeza, int numero) { // arr[cola,...,cabeza]   
    if (cabeza >= cola) { 

        int mitad = cola + (cabeza - cola) / 2; 

        //retornar la mitad si lo encuentra
        if (arr[mitad] == numero) return mitad; 

        //hacer recursion y buscar en mitad inferior si pertenece
        if (arr[mitad] > numero) return BinarySearch(arr, cola, mitad - 1, numero); 

        //si no pertenece, buscar en mitad superior
        return BinarySearch(arr, mitad + 1 , cabeza, numero); 
    } 
    return -1; 
} 

int ExponentialSearch(int arr[], int cabeza, int numero){
    int nodo = 0;

    if (arr[nodo] == numero) return nodo; // comprobar si elemento nodo corresponde 
    nodo++;

    //incrementar el doble cada vez que arr[node] sea menor que el numero buscado
    //(conciderar si nodo se pasa del largo de la lista)
    while (nodo < cabeza && arr[nodo] <= numero) nodo = nodo*2;

    //al salir del ciclo, realizar busqueda binaria entre el nodo anterior y el actual del numero
    return BinarySearch(arr, nodo / 2, min(nodo, cabeza), numero);
}

void printfibo(int len){
    int i = 2;
    int fibm2 = 0; //inicio de fibonacci
	int fibm1 = 1; 
	int fibM = fibm2 + fibm1; 
    printf("\nf0:0\nf1:1\n");

	while (i <= len) { //cambiar sucesion hasta llegar al final
		fibm2 = fibm1; 
		fibm1 = fibM; 
		fibM = fibm2 + fibm1; 
        printf("f%d:%d\n",i,fibM);
        i++;
	} 
}


int fibonacci_search(int arr[], int len, int numero) { 

	int fibm2 = 0; //inicio de fibonacci
	int fibm1 = 1; 
	int fibM = fibm2 + fibm1; 

	while (fibM < len) { //cambiar sucesion hasta llegar al final
		fibm2 = fibm1; 
		fibm1 = fibM; 
		fibM = fibm2 + fibm1; 
	} 

    printf("\nComenzando con f(n):{%d} - f(n-1):{%d} - f(n-2):{%d}\nindice de largo: %d\nbuscando numero: %d\n\n",fibM,fibm1,fibm2,len,numero);

	int offset = -1; 
    int it = 1;
    //cuando fibM llega a 1, fibm2 llega a su valor minimo
	while (fibM > 1){ 
        
		// valor limite menor de la iteracion
		int i = min(offset+fibm2, len - 1); 
        
        printf("\niteracion %d\nf(n):{%d} = f(n-1):{%d} + f(n-2):{%d}\n",it,fibM,fibm1,fibm2);
        printf("posicion(i): %d de valor: %d\n",i,arr[i]);
        printf("offset: {%d}\n",offset,fibm2);

		if (numero > arr[i]) { 
            printf("mas arriba, offset = {%d} + f(n-2):{%d}\n---\n\n",offset,fibm2) ;
			fibM = fibm1; 
			fibm1 = fibm2; 
			fibm2 = fibM - fibm1; 
			offset = i; 
		} 

		else if (numero < arr[i]) { 
            printf("mas abajo(offset no cambia)\n---\n\n");
			fibM = fibm2; 
			fibm1 = fibm1 - fibm2; 
			fibm2 = fibM - fibm1; 
		} 

		else { // arr[i] == numero
            printf("\napretando cachete con %d\n",i);
            return i;
        }
        it++;

	} 

	/* comparing the last element with x */
	if(fibm1 && arr[offset+1]==numero)return offset+1; 

	/*element not found. return -1 */
	return -1; 
} 



int main(void){

    int arreglo[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99}; 
    
    int len = (sizeof(arreglo))/(sizeof(arreglo[0])) ;

    printlist(arreglo, len);

    int nbuscar = 30;

    printf("\nBuscando: %d - largo: %d\n", nbuscar, len);
    
    printf("\nAnalisis Fibonacci:\n############################\n");
    
    //int pos = binarySearch(arreglo,0,len-1,nbuscar);
    int pos = fibonacci_search(arreglo,len,nbuscar);
    
    printf("\n############################");
    
        
    printfibo(10);
    for(int i = 0; i<100; i++){
        printf("%d,",i);
    }

    if (pos == -1) printf("\nElemento no encontrado\n");
    else printf("\nPosicion: %d\nelemento: %d\n",pos,arreglo[pos]);
    
    //binarySearch(arreglo,0,);
}