// Write a function called assemble that takes two uint8_t named most and least, and
// assembles and returns a uint16_t, with the bits from most on the left and the bits from
// least on the right.
// For example, assemble(1, 2) should return 258.

#include <stdio.h>
#include <stdint.h>

uint16_t assemble(uint8_t a, uint8_t b){
  uint16_t a16 = (a << 8);
  uint16_t concat = a16 | b;
  return concat;
}

int main(void) {
  uint8_t a = 1;
  uint8_t b = 2;
  printf("%d\n", assemble(a, b));
  return 0;
}
