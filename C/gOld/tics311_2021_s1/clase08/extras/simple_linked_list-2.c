#include <stdio.h> 
#include <stdlib.h> 

// Lista enlazada 
struct Node { 
	int data; 
	struct Node *next; 
}; 

/* Dada una referencias a nodo head (puntero de puntero) y un valor, 
 * se crea un nodo nuevo y se inserta al inicio */
void push(struct Node** head_ref, int new_data) 
{ 
	// 1. asignar espacio en memorio
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	// 2. asignar data 
	new_node->data = new_data; 

	// 3. asignar "next" del nuevo nodo como head 
	new_node->next = (*head_ref); 

	// 4. puntar "head" de la lista al nodo creado
	(*head_ref) = new_node; 
} 

// Dado un nodo n, crea un nodo y lo inserta despues de este
void insertAfter(struct Node* prev_node, int new_data) 
{ 
	// check si el nodo apunta a NULL
	if (prev_node == NULL) 
	{ 
		printf("the given previous node cannot be NULL"); 
		return; 
	} 

	// asigna memoria para el nodo
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 

	// asigna el valor al nodo
	new_node->data = new_data; 

	// asigna como "next" al nodo apuntando por el nodo anterior
	new_node->next = prev_node->next; 

	// asigna "next" del nodo anterioral nuevo nodo 
	prev_node->next = new_node; 
} 

// Dada una referencias a nodo head (puntero de puntero) y un valor,
//se crea un nodo nuevo y se inserta al inicio
void append(struct Node** head_ref, int new_data) 
{ 
	// asigna memoria para el nodo
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	struct Node *last = *head_ref; // usada en punto 5.

	// asigna valor al nodo
	new_node->data = new_data; 

	//este nodo será el último de la listas, así que apunta a NULL
	new_node->next = NULL; 

	// en caso de que la lista este vacia, asignar nodo como "head"
	if (*head_ref == NULL) 
	{ 
		*head_ref = new_node; 
		return; 
	} 

	// en caso contrario, recorre la lista completa
	while (last->next != NULL) 
		last = last->next; 

	// asigna "next" del último nodo a nuevo
	last->next = new_node; 
	return; 
} 

// This function prints contents of linked list starting from head 
void printList(struct Node *node) 
{ 
while (node != NULL) 
{ 
	printf(" %d ", node->data); 
	node = node->next; 
} 
} 

/* Driver program to test above functions*/
int main() 
{ 
/* Start with the empty list */
struct Node* head = NULL; 

// Insert 6. So linked list becomes 6->NULL 
append(&head, 6); 

// Insert 7 at the beginning. So linked list becomes 7->6->NULL 
push(&head, 7); 

// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
push(&head, 1); 

// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
append(&head, 4); 

// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
insertAfter(head->next, 8); 

printf("\n Created Linked list is: "); 
printList(head); 

return 0; 
} 

