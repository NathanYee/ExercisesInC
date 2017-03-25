#include <stdio.h>

int go_to_warp_speed(int speed)
{
  printf("%d\n", speed);
}

int main() {
  go_to_warp_speed(4);
  int (*warp_fn) (int);
  warp_fn = go_to_warp_speed;
  warp_fn(5);
  return 0;
}
