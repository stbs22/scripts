// codigo fuente que implementa stacks con listas enlazadas
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "stack.h"

// creacion de un nuevo nodo en memoria
 StackNode* newStackNode(int data) 
{ 
	 StackNode* stackNode = ( StackNode*)malloc(sizeof( StackNode)); 
	stackNode->data = data;
	stackNode->next = NULL; 
	return stackNode; 
} 

// revisa si está vacío
int isEmpty(StackNode* top) 
{ 
	return !top; 
} 

// agregar un elemento
void push(StackNode** top, int data) 
{ 
	 StackNode* temp = newStackNode(data);
	temp->next = *top; 
	*top = temp; 
	printf("%d agregado a la pila\n", data); 
} 

// sacar un elemento
int pop(StackNode** top) 
{ 
	if (isEmpty(*top)) 
		return INT_MIN; // viene de #include <limits.h>
	 StackNode* temp = *top; 
	*top = (*top)->next; 

	int popped = temp->data; // imprimir
	free(temp); 

	return popped; 
} 

// mirar sin sacar
int peek( StackNode* top) 
{ 
	if (isEmpty(top)) 
		return INT_MIN; // viene de #include <limits.h>
	return top->data; 
} 