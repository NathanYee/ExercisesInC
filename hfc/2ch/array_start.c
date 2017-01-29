#include <stdio.h>

int main(int argc, char const *argv[]) {
  int drinks[] = {4, 2, 3};
  printf("1st order: %i drinks\n", drinks[0]);
  printf("1st order: %i drinks\n", *drinks);
  return 0;
}
