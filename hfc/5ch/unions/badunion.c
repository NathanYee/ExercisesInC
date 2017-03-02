#include <stdio.h>

typedef union {
  float weight;
  int count;
} cupcake;

int main()
{
  cupcake order = {2};
  printf("Cupcakes quantity count: %i\n", order.count);
  printf("Cupcakes weight float: %f\n", order.weight);
  return 0;
}
