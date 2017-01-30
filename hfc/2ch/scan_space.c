#include <stdio.h>

int main(int argc, char const *argv[]) {
  char first_name[20];
  char last_name[20];
  
  printf("Enter first and last name: ");
  scanf("%19s %19s", first_name, last_name);
  printf("First: %s Last:%s\n", first_name, last_name);

  return 0;
}
