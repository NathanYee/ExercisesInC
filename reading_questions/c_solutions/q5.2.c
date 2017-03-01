#include <stdio.h>
#include <limits.h>

int main(){

  int before = 12;
  printf("%d\n", before);

  int after = (before ^ INT_MIN) + 1;
  printf("%d\n", after);

  return 0;
}
