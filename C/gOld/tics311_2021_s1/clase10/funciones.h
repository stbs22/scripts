#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct p {
    int id;
    char nombre[50];
    char apellido[50];
    char email[70];
    char genero[20];
    float altura;
    struct p *next;
};

void leer_archivo(char* filename, struct p **lista);

void ordenar(struct p **lista);

void imprimir_personas(struct p **lista);

int valida_parte1(struct p **lista);
int valida_parte2(struct p **lista_m,struct p **lista_h);
int valida_parte3(struct p **lista);

