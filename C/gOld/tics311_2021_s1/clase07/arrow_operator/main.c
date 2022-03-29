// C program to show Arrow operator 
// used in structure 
  
#include <stdio.h> 
#include <stdlib.h> 
  
// Creating the structure 
struct student { 
    char name[80]; 
    int age; 
    float percentage; 
}; 
  
// Creating the structure object 
struct student* estructura = NULL; 
  
// Driver code 
int main() 
{ 
    // Assigning memory to struct variable estructura 
    estructura = (struct student*) 
        malloc(sizeof(struct student)); 
  
    // Assigning value to age variable 
    // of estructura using arrow operator 
    estructura->percentage = 4; 
  
    // Printing the assigned value to the variable 
    printf("%f\n", estructura->percentage); 
  
    return 0; 
} 