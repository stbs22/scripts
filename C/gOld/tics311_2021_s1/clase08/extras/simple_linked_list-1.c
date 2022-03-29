#include <stdio.h>
#include <stdlib.h>

// lista enlazada
struct Node {
	int data;
	struct Node* next; // puntero del tipo struct Node
};

// recorre lista e imprime el contenido de los nodos
// comenzando con el primero (head)

void printList(struct Node* n)
{
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
	printf("\n");	
}

int main()
{	// crear punteros del tipo struct Node
	struct Node* head = NULL; // primer nodo
	struct Node* second = NULL;
	struct Node* third = NULL; // la cola ("tail")

	// asignar memoria para los nodos
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));


	// asignar valor a data y conectar nodos
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printList(head);

	printf("\n");

	return 0;
}
