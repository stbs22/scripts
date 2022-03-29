#include <stdio.h>

int main(int argc, char **argv)
{
    int x = 123;
    int *puntero; //int *puntero = &x;

    puntero = &x;

    printf("Valor: %i \nDirección: %p\n", x, &x);
    printf("\nValor puntero: %p \nDirección puntero: %p\nContenido apuntado: %i\n", puntero, &puntero, *puntero);

    *puntero = 25;
    printf("\nx: %i \npuntero: %i\n", x, *puntero);

    return 0;
}