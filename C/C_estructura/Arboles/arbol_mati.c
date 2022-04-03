#include <stdio.h>
#include <stdlib.h>

struct nodo{
    struct nodo* padre;
    struct nodo* izquierdo;
    struct nodo* derecho;
    int nota;

};
void agregar_valor(struct nodo *arbol,int valor);
struct nodo *crear_nodo(struct nodo*padre,float promedio);


int main(){
    struct nodo*arbol;
    arbol= crear_nodo(NULL,32);
    agregar_valor(arbol,50);
    agregar_valor(arbol,20);
    agregar_valor(arbol,10);
}
struct nodo *crear_nodo(struct nodo*padre,float promedio){
    struct nodo *n = malloc(sizeof(struct nodo));
    n->padre=padre;
    n->nota=promedio;
    return n;

}
void agregar_valor(struct nodo *arbol,int valor){
    struct nodo *temp,*pivote;
    int derecho = 0;
    if(arbol!=NULL){
        temp=arbol;
        while(temp!=NULL){
            pivote=temp;
            if (valor>temp->nota){
                temp=temp->derecho;
                derecho=1;
                //derecho 
            }
            else{
                temp=temp->izquierdo;
                derecho=0;
                //izquierdo

            }
        }
        temp=crear_nodo(pivote,valor);
        if(derecho==1){
            pivote->derecho=temp;
            printf("Insertando %i en el lado derecho de %i\n",valor,pivote->nota);

        }
        else{
            pivote->izquierdo=temp;
            printf("Insertando %i en el lado izquierdo de %i\n",valor,pivote->nota);

        }

    }
    else{
        printf("Error, arbol vacio");

    }
}

