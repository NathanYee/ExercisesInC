#include <stdio.h>

int main() {
  int foo[3] = {1,2,3};
  int bar[3];

  for (int i = 0; i < 3; i++) {
    printf("%d\n", foo[i]);
  }

  foo = bar;
  for (int i = 0; i < 3; i++) {
    printf("%d\n", bar[i]);
  }

  return 0;
}
