#include <stdio.h>

void swap(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swapBueno(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv)
{
    int x = 0;
    int y = 20;

    printf("Comienzo\nx: %i - y: %i\n\n", x, y);
    swap(x, y);
    printf("Malo\nx: %i - y: %i\n\n", x, y);
    swapBueno(&x, &y);
    printf("Bueno\nx: %i - y: %i\n", x, y);
    return 0;
}
