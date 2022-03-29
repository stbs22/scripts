#define V 5
#define MAX 30 // tamaño maximo de un lado de la matriz

// arista
typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist, spanlist;

int Graph[MAX][MAX], n;

void print_matrix();
void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();