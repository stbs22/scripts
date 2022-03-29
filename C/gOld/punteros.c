#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 123;
    int *puntero; //int *puntero = &x;

    puntero = &x;
	
	//x
    printf("\n[x = 123]\nValor: %i \nDirección: %p\n", x, &x);
	
	//puntero
    printf("\n[puntero = &x]\n\n[var] Valor puntero: %p \n[&var] Dirección de puntero: %p\n[*var] Contenido apuntado: %i\n", puntero, &puntero, *puntero);

    *puntero = 25;
	
	//cambio
    printf("\n[*puntero = 25]\n\n[nuevo puntero]\nx: %i \npuntero: %i\n\n", x, *puntero);

    return 0;
}
