#include <limits.h>

#include "lectura.h"

#define V 14
int parent[V];

// Find set of vertex i
int find(int i) {
  while (parent[i] != i) i = parent[i];
  return i;
}

// Does union of i and j. It returns
// false if i and j are already in same
// set.
void union1(int i, int j) {
  int a = find(i);
  int b = find(j);
  parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int** cost) {
  int mincost = 0;  // Cost of min MST.

  // Initialize sets of disjoint sets.
  for (int i = 0; i < V; i++) parent[i] = i;

  // Include minimum weight edges one by one
  int edge_count = 0;
  while (edge_count < V - 1) {
    int min = INT_MAX, a = -1, b = -1;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (find(i) != find(j) && cost[i][j] < min) {
          min = cost[i][j];
          a = i;
          b = j;
        }
      }
    }

    union1(a, b);
    printf("Edge %d:(%d, %d) cost:%d \n", edge_count++, a, b, min);
    mincost += min;
  }
  printf("\n Minimum cost= %d \n", mincost);
}

int** change_to_costs(int** m) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (m[i][j] == 0) {
        m[i][j] = INT_MAX;
      }
    }
  }
  return m;
}

int main(int argc, char* argv[]) {
  int** matriz = leer_archivo(argv[1]);
  print_m(matriz, 14);
  matriz = change_to_costs(matriz);
  print_m(matriz, V);
  kruskalMST(matriz);
  return 0;
}