#include <stdio.h>

int y = 1;

void add_one(int* x);

int main(int argc, char const *argv[]) {
  int x = 4;
  add_one(&x);

  printf("%i\n", x);

  return 0;
}

void add_one(int* x) {
  *x = *x + 1;
}
