typedef struct node node;

struct node {
    node *left, *right;
    int data;
    int height;
};

void show_nodes(struct node *root);

void show_nodes_preorden(struct node *root);

struct node* newNode(int data);

struct node* insert(struct node* node, int data);

struct node * minValueNode(struct node* node);

struct node * maxValueNode(struct node* node);

struct node* deleteNode(struct node* root, int data);

struct node *insert_balanceado(struct node *node, int data);

struct node *insert2(struct node *node, int data);

struct node* deleteNode_balanceado(struct node* root, int data);
