#include <stdio.h>

int main(void){
  int x = 0;
  printf("--> %i\n",x);
  x++;
  printf("--> %i\n",x);
  x += 1;
  printf("--> %i\n",x);
  x -= -1;
  printf("--> %i\n",x);
  x -= -(!0);
  printf("--> %i\n",x);
  x -= -(!printf(""));
  printf("--> %i\n",x);
  printf("--> %i\n",(!3));
}
