// codigo fuente que implementa colas con listas enlazadas
#include "queue.h"

// funcion para crear un nuevo nodo
QNode* newNode(int k) 
{ 
	QNode* temp = ( QNode*)malloc(sizeof( QNode)); 
	temp->data = k; 
	temp->next = NULL; 
	return temp; 
} 

// funcion para crear una cola
Queue* createQueue() 
{ 
	 Queue* q = ( Queue*)malloc(sizeof( Queue)); 
	q->primero = q->ultimo = NULL; 
	return q; 
} 

// Agrega un elemento en la cola (encolar)
void enQueue( Queue* q, int k) 
{ 
	// crea un nuevo nodo
	 QNode* temp = newNode(k); 

	// en caso de que la cola este vacía. El nuevo nodo es ultimo y primero
	if (q->ultimo == NULL) { 
		q->primero = q->ultimo = temp; 
		return; 
	} 

    // Tomamos el actual ultimo inserta el nuevo nodo al final de la cola y lo deja como ultimo
	q->ultimo->next = temp; 
	q->ultimo = temp; 
} 

// Saca un elemento de la cola (des encolar)
void deQueue( Queue* q) 
{ 
	// si la cola está vacía, retorna NULL
	if (q->primero == NULL) 
		return; 

    // guarda el que estaba primero y se actualiza el primero
	 QNode* temp = q->primero; 
	q->primero = q->primero->next; 

    // si primero es nulo (el unico en la cola), el ultimo se deja nulo 
	if (q->primero == NULL) 
		q->ultimo = NULL; 

	free(temp); 
} 