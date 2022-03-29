// codigo fuente que implementa colas con listas enlazadas
#include <stdio.h> 
#include <stdlib.h> 

// estructura para representar un nodo
typedef struct  QNode{ 
	int data; 
	struct QNode* next; 
}QNode;  

// La lista, 1ero almacena nodo más antiguo. ultimo almacena mas nuevo
typedef struct Queue{ 
	QNode *primero, *ultimo; 
}Queue; 

// crea un nuevo nodo con data = k
struct QNode* newNode(int k);
// crea una cola
struct Queue* createQueue();
// Agrega un elemento en la cola (encolar)
void enQueue(struct Queue* q, int k);
// Saca un elemento de la cola (des encolar)
void deQueue(struct Queue* q) ;

