#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int height(struct node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

void show_nodes(struct node *root){
    if(root->left != NULL) show_nodes(root->left);
    printf("%i ",root->data);
    if(root->right != NULL) show_nodes(root->right);
}
void show_nodes_preorden(struct node *root){
    printf("%i ",root->data);
    if(root->left != NULL) show_nodes_preorden(root->left);
    if(root->right != NULL) show_nodes_preorden(root->right);
}

struct node* newNode(int data) {   
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data = data;
  tmp->height = 1;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp; 
} 

struct node* insert(struct node* node, int data) {   
    if (node == NULL) return newNode(data); 
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    
    return node; 
} 

struct node * minValueNode(struct node* node) { 
    struct node* it = node; 
  
    while (it && it->left != NULL) {
        it = it->left; 
    }
    return it; 
} 
struct node * maxValueNode(struct node* node) { 
    struct node* it = node; 
  
    while (it && it->right != NULL) {
        it = it->right; 
    }
    return it; 
} 

struct node* deleteNode(struct node* root, int data) { 
    if (root == NULL) {
        return root; 
    }
  
    if (data < root->data) {
        root->left = deleteNode(root->left, data); 
    } else if (data > root->data){
        root->right = deleteNode(root->right, data); 
    } else { 
        if (root->left == NULL) { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } else if (root->right == NULL) { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct node* temp = minValueNode(root->right); 
        //struct node* temp = maxValueNode(root->left); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

// Balanceado

struct node *rightRotate(struct node *y) {  
    struct node *x = y->left;  
    struct node *z = x->right;  
  
    x->right = y;  
    y->left = z;  
  
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;   
  
    return x;  
}  

struct node *leftRotate(struct node *x){  
    struct node *y = x->right;  
    struct node *z = y->left;  
  
    y->left = x;  
    x->right = z;   
  
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;   
  
    return y;  
}  

int getBalance(struct node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

struct node *insert_balanceado(struct node *node, int data) {  
    if (node == NULL){
        return(newNode(data));  
    }
    if (data < node->data) {
        node->left = insert_balanceado(node->left, data);  
    }else if (data > node->data) {
        node->right = insert_balanceado(node->right, data);  
    }else {
      return node;
    }
    node->height = 1 + max(height(node->left),height(node->right)); 
    int balance = getBalance(node);   
  
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);  
    }
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);  
    }
    if (balance > 1 && data > node->left->data) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
    if (balance < -1 && data < node->right->data) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
    
    return node;  
}  

struct node* insert2(struct node* node, int data) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(data)); 
  
    if (data < node->data) 
        node->left  = insert2(node->left, data); 
    else if (data > node->data) 
        node->right = insert2(node->right, data); 
    else // Equal datas are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = node->left->height - node->right->height;
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && data < node->left->data) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && data > node->right->data) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && data > node->left->data) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && data < node->right->data) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 


struct node* deleteNode_balanceado(struct node* root, int data) {  
    if (root == NULL) {
        return root;  
    }
    if ( data < root->data ) {
        root->left = deleteNode(root->left, data);  
    }else if( data > root->data ) {
        root->right = deleteNode(root->right, data);  
    }else{
        if( (root->left == NULL) || (root->right == NULL) ) {  
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL){  
                temp = root;  
                root = NULL;  
            } else{
                *root = *temp;
            }  
            free(temp);  
        }else{  
            struct node* temp = minValueNode(root->right);  
            root->data = temp->data;  
            root->right = deleteNode(root->right, temp->data);  
        }  
    }  
  
    if (root == NULL) {
        return root;  
    }
    root->height = 1 + max(height(root->left),height(root->right));  
    int balance = height(root->left) - height(root->right);
  
    if (balance > 1 && height(root->left->left) - height(root->left->right) >= 0)  
        return rightRotate(root);  
  
    if (balance > 1 && height(root->left->left) - height(root->left->right) < 0) {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }   
    if (balance < -1 &&  height(root->right->left) - height(root->right->right) <= 0)  
        return leftRotate(root);  
  
    if (balance < -1 &&  height(root->right->left) - height(root->right->right) > 0) {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  
