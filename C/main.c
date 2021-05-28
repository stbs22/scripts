#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int* arr;

    int n;
    printf("\ningrese numero: ");
    scanf("%i",&n);

    arr = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        arr[i] = 20 + 2*i;
    }

    int n2;

    printf("\ningrese numero: ");
    scanf("%i",&n2);

    printf("\n%i\n",arr[n2]);
    free(arr);

    return 0;
}