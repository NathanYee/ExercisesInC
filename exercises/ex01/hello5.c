#include <stdio.h>
int main()
{
  int x = 5;
  printf("Hello World\n");
}

/*
 * The int x = 5; added these following assembly lines
 *
 * subq    $16, %rsp
 * movl    $5, -4(%rbp)
 */
