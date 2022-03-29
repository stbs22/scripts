// estructura para representar un nodo
typedef struct StackNode { 
	int data; 
	struct StackNode* next; 
}StackNode; 

void push(StackNode** top, int data) ;

int pop(StackNode** top) ;

int peek( StackNode* top) ;