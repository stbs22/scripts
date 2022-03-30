//#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  	
	char var[20];
	
	printf("\nInput: ");
	scanf("%s",&var);
	printf("\n\nVariable almacenada en: %p con valor %s\n",&var,var);
	int boolean = strcmp(var,"ctm");
	printf("\nFunción strcmp con \"ctm\" devuelve: %d\n",boolean);
	
	if (boolean) {
		printf("Es decir Falso\n");
	}else {
		printf("Es decir Verdad\n");
	}

  	return 0;
}
