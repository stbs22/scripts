#include <stdio.h>

void swap(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swapR(int *a, int *b)
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

    printf("x: %i - y: %i", x, y);
    swap(x, y);
    printf("\nx: %i - y: %i\n", x, y);
    swapR(&x, &y);
    printf("\nx: %i - y: %i\n", x, y);
    return 0;
}