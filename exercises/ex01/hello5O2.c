#include <stdio.h>
int main()
{
  int x = 5;
  printf("Hello World\n");
}

/*
 * The -c -O2 flags added even more assembly text. I'm surprised it didn't take
 * away more because it has higher optimization.
 *
 */
