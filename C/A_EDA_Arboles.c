#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int** leer_archivo(char* filename) {
  FILE* f;
  char line[1024];
  char* token;
  int cont = 0;
  int src, dst, hop;
  int N;

  int** m;
  f = fopen(filename, "r");

  fgets(line, 1023, f);
  token = strtok(line, ":");
  token = strtok(NULL, ":");
  N = atoi(token);

  m = (int**)malloc(N * sizeof(int*));
  for (int i = 0; i < N; i++) {
    m[i] = (int*)malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
      m[i][j] = 0;
    }
  }

  while (fgets(line, 1023, f) != NULL) {
    if (cont < 4) {
      cont++;
      continue;
    }
    token = strtok(line, "\t");
    src = atoi(token);
    token = strtok(NULL, "\t");
    dst = atoi(token);
    token = strtok(NULL, "\t");
    hop = atoi(token);
    if (hop == 1) {
      m[src][dst] = 1;
    }
  }
  return m;
}

void print_m(int** m, int N) {
  printf("Matriz:\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%i\t", m[i][j]);
    }
    printf("\n");
  }
}


int main(int argc, char** argv){
    
    int var = 0;
    
    FILE *archivo = fopen("/home/_init_/Escritorio/Scripts/GIT/scripts/Data/EDA/NSFNet_alt.txt","r");
    char line[300];

    fgets(line, 300, f);
    token = strtok(line, ":");
    token = strtok(NULL, ":");
    N = atoi(token);

    m = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        m[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            m[i][j] = 0;
        }
    }

    while(fgets(line,300,archivo)){
        var++;
        char* temp = strtok(line,"\t");
        if(var <= 5){
            printf("\n\n-->%s",temp);
        }
        else{
            printf("\n++++\n");
            while(temp != NULL){
                printf(" | %s",temp);
                temp = strtok(NULL,"\t");
            }

        }
    }
    printf("\n");
    return 0;

}