// test queue.c y stack.c

#include "queue.h"
#include "stack.h"

void test_queue(){
	Queue* q = createQueue(); 
	enQueue(q, 10); 
	enQueue(q, 20); 
	deQueue(q); 
	deQueue(q); 
	enQueue(q, 30); 
	enQueue(q, 40); 
	enQueue(q, 50); 
	deQueue(q); 
    printf("############### PILAS ##############\n");
	printf("primero en la cola: %d \n", q->primero->data); 
	printf("ultimo en la cola: %d \n", q->ultimo->data); 
}

void test_stack(){
	StackNode* top = NULL; 

	push(&top, 10); 
	push(&top, 20); 
	push(&top, 30); 
    printf("############### PILAS ##############\n");
	printf("%d sacado de la pila\n", pop(&top)); 
	printf("último elemento agregado a la pila:  %d\n", peek(top)); 
  
}

// test de las funciones
int main() {
    test_queue();
    test_stack();
	return 0; 
} 
