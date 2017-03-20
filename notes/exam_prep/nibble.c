// Write a function called assemble that takes two uint8_t named most and least, and
// assembles and returns a uint16_t, with the bits from most on the left and the bits from
// least on the right.
// For example, assemble(1, 2) should return 258.

#include <stdio.h>
#include <stdint.h>

uint8_t lowerNibble(uint8_t a){
  static uint8_t b = 0b00001111;
  return a & b;

  // uint16_t a16 = (a << 8);
  // uint16_t concat = a16 | b;
  // return concat;
}

int main(void) {
  uint8_t a = 0b10110101;
  printf("%d\n", lowerNibble(a));
  return 0;
}
