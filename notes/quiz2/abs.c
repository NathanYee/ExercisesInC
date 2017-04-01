#include <stdint.h>
#include <stdio.h>

int8_t absolute_value(const int16_t x){
  if (x>= 0) {
    return x;
  } else {
    return -x;
  }
}

int main() {
  printf("%d\n", absolute_value(0b0000000011111111));
  return 0;
}
