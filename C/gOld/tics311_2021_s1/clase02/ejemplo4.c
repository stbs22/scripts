#include <stdio.h>

void f(int *arreglo)
{
    *(arreglo + 3) = 50;
}

void f2(int arreglo[])
{
    arreglo[3] = 50;
}

void f3(int arreglo[])
{
    *(arreglo + 3) = 50;
}

int main(int argc, char **argv)
{
    int arreglo[5];
    for (int i = 0; i < 5; i++)
    {
        arreglo[i] = 6 + i;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", arreglo[i]);
    }
    printf("\n%i\n", *(arreglo + 2));
    f(arreglo);
    for (int i = 0; i < 5; i++)
    {
        printf("%i ", arreglo[i]);
    }
    printf("\n");
}