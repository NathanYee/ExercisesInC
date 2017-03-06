#include <stdio.h>
#include <limits.h>

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;

  for (i=size-1;i>=0;i--)
  {
    for (j=7;j>=0;j--)
    {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  puts("");
}

int main(){

  int before = 12;
  printf("%d\n", before);

  int after = (before ^ -1) + 1;
  printf("%d\n", after);

  int min = -1;
  printBits(sizeof(min), &min);

  return 0;
}
