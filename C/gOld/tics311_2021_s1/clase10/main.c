#include "funciones.h"
#include "pregunta1.h" 
#include "pregunta2.h"
#include "pregunta3.h"
 
int main(){

    struct p *lista_personas = NULL;
    leer_archivo("data_short.txt", &lista_personas);
    printf("Lista Original\n");
    imprimir_personas(&lista_personas);
    ordenar(&lista_personas);
    printf("Lista Ordenada\n");
    imprimir_personas(&lista_personas);
    int puntaje1 = valida_parte1(&lista_personas);

    struct p *lista_m = NULL;
    struct p *lista_h = NULL;
    divide_lista_genero(&lista_personas, &lista_m, &lista_h);
    printf("Lista Mujeres\n");
    imprimir_personas(&lista_m);
    printf("Lista Hombres\n");
    imprimir_personas(&lista_h);
    int puntaje2 = valida_parte2(&lista_m,&lista_h);

    unir_lista_intercalada(&lista_m,&lista_h,&lista_personas);
    printf("Lista Intercalada\n");
    imprimir_personas(&lista_personas);
    int puntaje3 = valida_parte3(&lista_personas);
    
    printf("PUNTAJE\n---------\n");
    printf("Pregunta 1: %d\n",puntaje1);
    printf("Pregunta 2: %d\n",puntaje2);
    printf("Pregunta 3: %d\n",puntaje3);
    printf("------------\nTOTAL: %d\n",puntaje1+puntaje2+puntaje3);

}
