#include <stdio.h>
#include <stdlib.h>


typedef struct a{
    int data; 
    struct a *left;
    struct a *right;
}tree;


tree* crear_arbol(int root_data){
    tree* root = NULL;
    tree* branch = (tree*)malloc(sizeof(tree));
    
    branch->data = root_data;
    branch->left = NULL;
    branch->right = NULL;

    root = branch;
    return branch;
}

void izquierda(tree* branch){

    if(branch->left!=NULL) izquierda(data,branch->left);

    tree* new_branch = (tree*)malloc(sizeof(tree));
    
    new_branch->data = 0;
    new_branch->left = NULL;
    new_branch->right = NULL;

    branch->left = new_branch;
}

void derecha(tree* branch){
    if(branch->right!=NULL) izquierda(data,branch->right);

    tree* new_branch = (tree*)malloc(sizeof(tree));
    
    new_branch->data = 0;
    new_branch->left = NULL;
    new_branch->right = NULL;

    branch->right = new_branch;
}

void show_nodes(tree* root){
    if(root->left!=NULL) show_nodes(root->left);
    printf("%i ",root->data);
    if(root->right!=NULL) show_nodes(root->right);
}

int main(int argc, char** argv){

    tree* arbol = crear_arbol(20);

    izquierda(arbol);

    arbol->left->data = 20;

    printf("%i\n",arbol->data);
    show_nodes(arbol);
    free(arbol);
    return 0;
}

/*

struct tree{
    int data; 
    struct tree *left;
    struct tree *right;
};

void show_nodes(struct tree *root){
    if(root->left!=NULL) show_nodes(root->left);
    printf("%i ",root->data);
    if(root->right!=NULL) show_nodes(root->right);
}

int main(int argc, char** argv){
    struct tree* root = NULL;
    struct tree* branch = (struct tree*)malloc(sizeof(struct tree));
    
    branch->data = 20;
    branch->left = NULL;
    branch->right = NULL;

    root = branch;

    //free(root);
    //show_nodes(root);
    
    printf("%i",branch->data);
    
    return 0;
}
*/