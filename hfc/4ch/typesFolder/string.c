#include <stdio.h>

int main(void){
  char *pointer = "String pointer";
  printf("%s\n", pointer);
  char array[] = "String array";
  printf("%s\n", array);

  // pointer[0] = "J";//
  array[0] = 'J';
  printf("%s\n", array);

  return 0;
}
