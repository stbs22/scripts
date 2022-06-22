#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Integrantes: Valentina Gomez R., Arianna Hidalgo A., Marina Molina B.

typedef struct { // se definen los elementos  que estructuran a los enemigos o atacantes para ser alamacenados
  char nombreatacante[200];
  int danger_category;
  float atack_prob;
  int letra;
} enemigo;

void swapi(int* a, int* b){ //utilizamos swapi para intercambiar 2 variables de tipo int
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapf(float* a, float* b){//utilizamos swapi para intercambiar 2 variables de tipo float
    float tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void swapNombre(char *nombreA, char *nombreB)//Utilizamos swapNombre para intercambiar las variables de los nombres de los datos de la lista 
{
  char *tmp = (char *)malloc((200) * sizeof(char));
  
  strcpy(tmp, nombreA);
  strcpy(nombreA, nombreB);
  strcpy(nombreB, tmp);
}  


void swapPokemones(enemigo *pokemon1, enemigo *pokemon2){//Utilizamos swapPokemonones para intercambiar los elementos de la lista 
  swapNombre(pokemon1->nombreatacante,pokemon2->nombreatacante);
  swapi(&pokemon1->danger_category, &pokemon2->danger_category);
  swapi(&pokemon1->letra, &pokemon2->letra);
  swapf(&pokemon1->atack_prob, &pokemon2->atack_prob);
}


void insertionSort(enemigo pokemones[], int cantidad_pokemones) //Utilizamos la funcion insertionsort para comparar los datos y asi poder ordenarlos segun danger_category, atack_prob, letra
{
    int i, j, keyD, keyN;
    float keyP;
  
    for (i = 1; i < cantidad_pokemones; i++) {

      keyD = pokemones[i].danger_category;
      keyP = pokemones[i].atack_prob;
      keyN = pokemones[i].letra;
        
      j = i - 1;
      
        while (j >= 0) {
            int uso = 1;
          
            if(pokemones[j].danger_category < keyD && uso == 1){
              uso = 0;
              pokemones[j + 1].danger_category = keyD;
              pokemones[j + 1].atack_prob = keyP;
              pokemones[j + 1].letra = keyN;
              break;
            }
          
            if(pokemones[j].danger_category == keyD && pokemones[j].atack_prob < keyP && uso == 1){
              uso = 0;
              pokemones[j + 1].danger_category = keyD;
              pokemones[j + 1].atack_prob = keyP;
              pokemones[j + 1].letra = keyN;
              break;
            }
          
            if(pokemones[j].danger_category == keyD && pokemones[j].atack_prob == keyP && pokemones[j].letra < keyN && uso == 1){
              uso = 0;
              pokemones[j + 1].danger_category = keyD;
              pokemones[j + 1].atack_prob = keyP;
              pokemones[j + 1].letra = keyN;
              break;
            }
            swapPokemones(&pokemones[j+1],&pokemones[j]);
            j = j - 1;
        }
    }
}


int N_pokemones(FILE *fichero){
  
  int N_filas = 0;
  char temp_fila[200];
  
  while(fgets(temp_fila, 200, fichero)){
      char *temp;
      temp = strtok(temp_fila,"\n");
      N_filas++;
  }
  
  rewind(fichero);
  return N_filas-1;
}


int main(int argc, char *argv[]) {
  
  FILE *input = fopen(argv[1], "r");// se crea el archivo donde se guardaran las variables 
  int cantidad_pokemones = N_pokemones(input);

  enemigo lista[cantidad_pokemones];
  int index = 0;
  char line[1000];
  
  //Saltar primera fila
  int flag = 1;
  
  while(fgets(line, 1000, input)){
    
    if (flag == 0){

      strcpy(lista[index].nombreatacante,strtok(line, ","));
      lista[index].letra = (int)lista[index].nombreatacante[0];
    
      lista[index].danger_category = atoi(strtok(NULL, ","));

      char *prob = strtok(NULL, ",");
      if(prob == NULL) lista[index].atack_prob = 0.0;
      else lista[index].atack_prob = atof(prob);

      index++;
    } 
    flag = 0;
    
    if(feof(input)) break;
  }

  insertionSort(lista, cantidad_pokemones);

  FILE *output = fopen(argv[3], "w");// se crea el archivo de salida donde se almacenan los datos ya ordenados segun danger_category, atack_prob y alfabeticamente de ser necesario
  fprintf(output, "first_name,danger_category,attack_prob");

  for(int i = 0; i < atoi(argv[2]); i++)
    fprintf(output,"\n%s,%d,%f", lista[i].nombreatacante, lista[i].danger_category, lista[i].atack_prob);

  return 0;
}