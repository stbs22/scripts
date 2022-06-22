#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10

 int max(int a, int b){
     if(a>b)
         return a;
     else
         return b;
 }


typedef struct node{

    float probabilidad;
    int categoria;
    char nombre[20];

    struct node *left;
    struct node *right;

}node;


node* crear_nodo(float probabilidad,int categoria,char nombre[20]){
    
    node *n = (struct node *)malloc(sizeof(node));
 
    n->probabilidad=probabilidad;
    n->categoria=categoria;

    strcpy(n->nombre,nombre);

    n->left=NULL;
    n->right=NULL;
 
    return n;
}


node* right_rotate(node *root){
    node *temp = root->left;
    node *temp2 = temp->right;

    temp->right = root;
    root->left = temp2;
    
    return temp;
}


node* left_rotate(node *root){
    node *temp = root->right;
    node *temp2 = temp->left;

    temp->left = root;
    root->right = temp2;
    
    return temp;
}

int altura(node *root){
    if(root==NULL) return 0;
    return 1+max(altura(root->left),altura(root->right));
}

//insertar con rotaciones
node* insertar(node *root, float probabilidad, int categoria, char* nombre){
    
    if(root==NULL){
        printf("insertando a %s\n",nombre);
        return crear_nodo(probabilidad, categoria, nombre);
    }

    else if(categoria<=root->categoria){
        printf("%s: %i < %i\n",nombre, categoria,root->categoria);
        root->left=insertar(root->left,probabilidad,categoria,nombre);
        
        if(abs( altura(root->left) - altura(root->right) ) > 1){

            if( altura(root->left->left) > altura(root->left->right) ){
                root=right_rotate(root);
            }
            else{
                root=left_rotate(root);
            }
        }
    }
    
    else if(categoria>=root->categoria){
        printf("%s: %i > %i\n",nombre,categoria,root->categoria);
        root->right=insertar(root->right,probabilidad,categoria,nombre);

        if(abs( altura(root->left) - altura(root->right) ) > 1){
            if(altura(root->right->right)>altura(root->right->left)){
                root=left_rotate(root);
            }
            else{
                root=right_rotate(root);
            }
        }
    }
    return root;
}

void post_order(node *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);

        printf("%f %i %s\n",root->probabilidad,root->categoria,root->nombre);
    }
}

void pre_order(node *root){
    if(root!=NULL){
        printf("%f %i %s\n",root->probabilidad,root->categoria,root->nombre);

        pre_order(root->left);
        pre_order(root->right);
    }
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%f %i %s\n",root->probabilidad,root->categoria,root->nombre);
        inorder(root->right);
    }
}


void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%s:%i\n", root->nombre, altura(root) );

    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}


int main(){

    node *root = NULL;

    node *tmp = malloc(sizeof(node));

    tmp->probabilidad = 0.5;
    tmp->categoria = 1;
    strcpy(tmp->nombre, "uno");

    tmp->left = malloc(sizeof(node));
    tmp->left->left = NULL;
    tmp->left->right = NULL;
    tmp->right = malloc(sizeof(node));
    tmp->right->left = NULL;
    tmp->right->right = NULL;

    root = tmp;

    root = insertar(root, 0.8, 8, "Juan");
    print2D(root);
    root = insertar(root, 0.2, 1, "victor");
    print2D(root);
    root = insertar(root, 0.2, 6, "brian");
    print2D(root);
    root = insertar(root, 0.2, 3, "elias");
    print2D(root);
    root = insertar(root, 0.9, 4, "ricardo");
    print2D(root);

    // root = insertar(root, 0.4, 3, "pedro");
    // print2D(root);

    inorder(root);

    
    
    return 0;
}