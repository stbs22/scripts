#include "funciones.h"

void leer_archivo(char* filename, struct p **lista){
    FILE *f = fopen(filename,"r");
    int id;
    char* nombre;
    char* apellido;
    char* email;
    char* genero;
    float altura;
    char aux[1000];
    
    struct p *ultimo = NULL;

    fgets(aux,999,f);

    int count = 0;
    while(fgets(aux,999,f)){
        id = atoi(strtok(aux,"\t"));
        nombre = strtok(NULL,"\t");
        apellido = strtok(NULL,"\t");
        email = strtok(NULL,"\t");
        genero = strtok(NULL,"\t");
        altura = atof(strtok(NULL,"\t"));

        struct p *persona = malloc(sizeof(struct p));

        persona->id = id;
        strcpy(persona->nombre,nombre);
        strcpy(persona->apellido,apellido);
        strcpy(persona->email,email);
        strcpy(persona->genero,genero);
        persona->altura = altura;
        count++;

        if (*lista==NULL){
          *lista = persona;
          persona->next = NULL;
          ultimo = persona;
        }
        else {
          ultimo->next = persona;
          persona->next = NULL;
          ultimo = persona;
        }

        //int c = persona->apellido[0];
        //printf("%d\n",c);

    }
}

void imprimir_personas(struct p **lista)
{
    struct p *persona = *lista;
    while (persona != NULL){
        printf("ID: %i %s %s %f\n",persona->id,persona->nombre,persona->genero,persona->altura);
      persona = persona->next;
    }
}

int valida(struct p **lista, int *valores,int total){
    int is_valido = 1;
    struct p *persona = *lista;
    int i=0;
    for (;i<total;i++){
      if (persona==NULL){is_valido=0;break;}
      //printf("%d %d \n",valores[i],persona->id);
      if(valores[i]!=persona->id) is_valido=0;
      persona=persona->next;
    }
    if (persona!=NULL){is_valido=0;}
    return is_valido;
}

int valida_parte1(struct p **lista){
  int respuesta[] = {7,8,6,9,1,10,5,4,2,3};
  return 10*valida(lista,respuesta,10);
}
int valida_parte2(struct p **lista_m,struct p **lista_h){
  int respuesta_m[] = {8,6,1,10,2};
  int respuesta_h[] = {7,9,5,4,3};
  return 5*valida(lista_m,respuesta_m,5)+5*valida(lista_h,respuesta_h,5);
}
int valida_parte3(struct p **lista){
  int respuesta[] = {8,7,6,9,1,5,10,4,2,3};
  return 10*valida(lista,respuesta,10);
}



