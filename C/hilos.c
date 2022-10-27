#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *proceso (void *arg)
{
    char *msg = (char *) arg;
    while (1){
        printf ("%s\n", msg);
    }

int main(void){

while (1){
    printf("Hola mundo");
}

while (1){
    printf("Chao mundo");
}

}